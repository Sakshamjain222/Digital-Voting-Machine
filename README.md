# Digital-Voting-Machine
🎯 Digital Voting Machine – Arduino Based

A secure and fully functional Electronic Voting Machine (EVM) built using Arduino, LCD, and push buttons. Includes real-time vote counting, PIN-protected result access, winner detection, tie handling, scrolling UI, buzzer feedback, and LED indicators.

🔥 Features

➤ 4-Candidate Voting System (A, B, C, D)

➤ Secure PIN System to access results

➤ Real-time voting confirmation with LED + buzzer

➤ Scrolling LCD menu showing candidate list

➤ Winner detection with vote margin

➤ Tie detection mode (infinite loop display)

➤ Beep sounds + winning melody

➤ Non-blocking timing using millis()

🛠 Hardware Required

Arduino UNO / Nano

LiquidCrystal_I2C 16×2 LCD

5 push buttons (4 voting + 1 result button)

Buzzer

2 LEDs (Vote LED + Result LED)

Jumper wires

10K resistors (if not using INPUT_PULLUP)

🔌 Pin Configuration
Component	Pin
Candidate A Button	D3
Candidate B Button	D4
Candidate C Button	D5
Candidate D Button	D6
Result Button	D7
Buzzer	D8
Vote LED	D12
Result LED	D13
LCD I2C	SDA/SCL
📸 How It Works

Boot screen → Submitted By → Candidate List

Voter presses button → vote recorded → confirmation screen

Press result button → enter PIN → display results

System shows:

Total Votes

Votes for each candidate

Winner & margin
      
Tie results (if any)

📦 Full Source Code


Digital_Voting_Machine_with_pin.ino      
