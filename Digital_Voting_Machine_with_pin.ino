#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

// Candidate Names
String nameA = "SAKSHAM JAIN";
String nameB = "RITUMJAI KHUTETA";
String nameC = "RAHUL RAWAT";
String nameD = "RISHABH RATHORE";

// Button Pins
#define v1 3
#define v2 4
#define v3 5
#define v4 6
#define resultBtn 7
#define buzzer 8

// LED Pins
#define voteLED 12
#define resultLED 13

// Vote counters
int vote1 = 0, vote2 = 0, vote3 = 0, vote4 = 0;

// Scroll timing
unsigned long lastScroll = 0;
int scrollIndex = 0;

// PIN SYSTEM
String correctPIN = "1111";   // change as you like
String enteredPIN = "";

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.clear();

  pinMode(v1, INPUT_PULLUP);
  pinMode(v2, INPUT_PULLUP);
  pinMode(v3, INPUT_PULLUP);
  pinMode(v4, INPUT_PULLUP);
  pinMode(buzzer, OUTPUT);
  pinMode(resultBtn, INPUT_PULLUP);

  pinMode(voteLED, OUTPUT);
  pinMode(resultLED, OUTPUT);

  // Starting Screen
  lcd.setCursor(0, 0);
  lcd.print(" DIGITAL VOTING ");
  lcd.setCursor(1, 1);
  lcd.print("MACHINE READY!!");
  delay(2000);
  lcd.clear();

  // Submitted By Loop
  showText("SUBMITTED BY:-", nameA);
  showText("SUBMITTED BY:-", nameB);
  showText("SUBMITTED BY:-", nameC);
  showText("SUBMITTED BY:-", nameD);
  showText("SUBMITTED BY:-", "YASH GUPTA");
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("FROM:- AI&DS - C");
  delay(2000);
  lcd.clear();

  // Candidate List Header
  lcd.setCursor(0, 0);
  lcd.print("CANDIDATES LIST!");
  delay(2000);
  lcd.clear();

  // Show full candidate list once
  showText("A:", nameA);
  showText("B:", nameB);
  showText("C:", nameC);
  showText("D:", nameD);
  delay(2000);
}

// MAIN LOOP (NON-BLOCKING)

void loop() {

  // REAL-TIME VOTING (works anytime)
  if (digitalRead(v1) == LOW) { vote1++; showVote("A", nameA); }
  if (digitalRead(v2) == LOW) { vote2++; showVote("B", nameB); }
  if (digitalRead(v3) == LOW) { vote3++; showVote("C", nameC); }
  if (digitalRead(v4) == LOW) { vote4++; showVote("D", nameD); }

  // RESULT BUTTON PRESSED
  if (digitalRead(resultBtn) == LOW) {
    if (enterPIN()) {
        showResults();
    }
}

  // NON-BLOCKING SCROLL DISPLAY
  unsigned long now = millis();

  if (now - lastScroll >= 1200) {
    lastScroll = now;

    lcd.clear();

    if (scrollIndex == 0) {
      lcd.setCursor(0, 0); lcd.print("A: "); lcd.print(nameA); 
      lcd.setCursor(0, 1); lcd.print("Press A Button");
    } else if (scrollIndex == 1) {
      lcd.setCursor(0, 0); lcd.print("B: "); lcd.print(nameB);
      lcd.setCursor(0, 1); lcd.print("Press B Button");
    } else if (scrollIndex == 2) {
      lcd.setCursor(0, 0); lcd.print("C: "); lcd.print(nameC);
      lcd.setCursor(0, 1); lcd.print("Press C Button");
    } else if (scrollIndex == 3) {
      lcd.setCursor(0, 0); lcd.print("D: "); lcd.print(nameD); ;
      lcd.setCursor(0, 1); lcd.print("Press D Button");
    }

    scrollIndex++;
    if (scrollIndex > 3) scrollIndex = 0;
  }
}

// FUNCTIONS
// LED blink on vote
void blinkLED() {
  digitalWrite(voteLED, HIGH);
  delay(500);
  digitalWrite(voteLED, LOW);
}

void beep() {
  digitalWrite(buzzer, HIGH);
  delay(300);
  digitalWrite(buzzer, LOW);
}

void beepwrg() {
  digitalWrite(buzzer, HIGH);
  delay(500);
  digitalWrite(buzzer, LOW);
}

void winnerMelody() {

  int melody[] = {660, 880, 990, 1320, 990, 880, 660};  // Notes
  int duration[] = {150, 150, 200, 250, 200, 150, 300}; // Timing

  for (int i = 0; i < 7; i++) {
    tone(buzzer, melody[i]);
    delay(duration[i]);
    noTone(buzzer);
    delay(50);
  }
}



// Vote confirmation message
void showVote(String symbol, String name) {
  
  blinkLED();
  beep();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("VOTED!! ");
  lcd.print(symbol);
  lcd.setCursor(0, 1);
  lcd.print(name);
  delay(2000);
  lcd.clear();
}

// Show scrolling text
void showText(String title, String text) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(title);
  lcd.setCursor(0, 1);
  lcd.print(text);
  delay(1500);
  lcd.clear();
}

bool enterPIN() {
  enteredPIN = "";
  lcd.clear();
  lcd.print("ENTER PIN:");
  delay(1000);

  while (enteredPIN.length() < 4) {
    lcd.setCursor(0,1);
    
    // Print * instead of the actual numbers
    for (int i = 0; i < enteredPIN.length(); i++) {
      lcd.print("*");
    }

    if (digitalRead(v1) == LOW) { enteredPIN += "1"; blinkLED(); beep(); delay(300); }
    if (digitalRead(v2) == LOW) { enteredPIN += "2"; blinkLED(); beep(); delay(300); }
    if (digitalRead(v3) == LOW) { enteredPIN += "3"; blinkLED(); beep(); delay(300); }
    if (digitalRead(v4) == LOW) { enteredPIN += "4"; blinkLED(); beep(); delay(300); }
  }

  lcd.clear();
  if (enteredPIN == correctPIN) {
    lcd.print("PIN ACCEPTED");
    beep();
    delay(1000);
    return true;
  } else {
    lcd.print("WRONG PIN!");
    beepwrg();
    delay(300);
    beepwrg();
    delay(1000);
    return false;
  }
}

// FULL RESULT PROCESS
void showResults() {
  digitalWrite(resultLED, HIGH);
  delay(200);

  lcd.clear();
  int total = vote1 + vote2 + vote3 + vote4;

  // 1. Total Votes
  lcd.setCursor(0, 0);
  lcd.print("TOTAL VOTES:");
  lcd.setCursor(0, 1);
  lcd.print(total);
  delay(2000);
  lcd.clear();

  if (total == 0) {
    lcd.print("No Votes Casted");
    delay(2000);
    lcd.clear();
    digitalWrite(resultLED, LOW);
    return;
  }

  // 2. Each candidate's votes
  lcd.clear(); lcd.print("A: "); lcd.print(nameA); lcd.setCursor(0,1); lcd.print("Votes: "); lcd.print(vote1); delay(2000);
  lcd.clear(); lcd.print("B: "); lcd.print(nameB); lcd.setCursor(0,1); lcd.print("Votes: "); lcd.print(vote2); delay(2000);
  lcd.clear(); lcd.print("C: "); lcd.print(nameC); lcd.setCursor(0,1); lcd.print("Votes: "); lcd.print(vote3); delay(2000);
  lcd.clear(); lcd.print("D: "); lcd.print(nameD); lcd.setCursor(0,1); lcd.print("Votes: "); lcd.print(vote4); delay(2000);

  // 3. Determine winner
  int maxVote = vote1;
  String winner = nameA;

  if (vote2 > maxVote) { maxVote = vote2; winner = nameB; }
  if (vote3 > maxVote) { maxVote = vote3; winner = nameC; }
  if (vote4 > maxVote) { maxVote = vote4; winner = nameD; }

  // 4. Find 2nd highest for margin
  int secondMax = 0;
  if (vote1 != maxVote) secondMax = max(secondMax, vote1);
  if (vote2 != maxVote) secondMax = max(secondMax, vote2);
  if (vote3 != maxVote) secondMax = max(secondMax, vote3);
  if (vote4 != maxVote) secondMax = max(secondMax, vote4);

  int VOTES = maxVote - secondMax;

    // ---- TIE CHECK ----
  int votesArr[4] = {vote1, vote2, vote3, vote4};
  String namesArr[4] = {nameA, nameB, nameC, nameD};

  // Count how many candidates have maxVote
  int tieCount = 0;
  String tieNames = "";

  for (int i = 0; i < 4; i++) {
    if (votesArr[i] == maxVote) {
      tieCount++;
      tieNames += namesArr[i] + " ";
    }
  }

  // If tie between 2 or more candidates
  if (tieCount > 1) {
    lcd.clear();
    lcd.print("TIE OCCURRED!");
    delay(2000);

    lcd.clear();
    lcd.print("Tie Votes:");
    lcd.setCursor(0, 1);
    lcd.print(maxVote);
    delay(2000);

    // Show tied candidates one-by-one
    for (int i = 0; i < 4; i++) {
      if (votesArr[i] == maxVote) {
        lcd.clear();
        lcd.print("TIED:");
        lcd.setCursor(0, 1);
        lcd.print(namesArr[i]);
        delay(2000);
      }
    }

    // Infinite loop showing tie status
    while (true) {
      lcd.clear();
      lcd.print("TIE BETWEEN:");
      lcd.setCursor(0, 1);
      lcd.print("CANDIDATES!");
      delay(1200);

      for (int i = 0; i < 4; i++) {
        if (votesArr[i] == maxVote) {
          lcd.clear();
          lcd.print(namesArr[i]);
          lcd.setCursor(0, 1);
          lcd.print("Votes: ");
          lcd.print(maxVote);
          delay(1200);
        }
      }
    }
  }


  // 5. Display Winner
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("WINNER:");
  lcd.setCursor(0, 1);
  lcd.print(winner);
  scrollText(winner, 1);
  winnerMelody();
  delay(3000);

  // 6. Display Margin
  lcd.clear();
  lcd.print("WON BY:");
  lcd.setCursor(0, 1);
  lcd.print(VOTES);
  lcd.print(" VOTES");
  delay(3000);

  while (true) {
  // Winner
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("WINNER:");
  lcd.setCursor(0, 1);
  lcd.print(winner);
  winnerMelody(); 
  delay(500);

  // Margin
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("WON BY:");
  lcd.setCursor(0, 1);
  lcd.print(VOTES);
  lcd.print(" VOTES");
  delay(500);
}

}