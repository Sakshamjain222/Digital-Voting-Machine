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

Paste this inside your GitHub repo as evm.ino:

[PASTE THE ENTIRE CODE YOU PROVIDED — DO NOT MODIFY]


(Your code is already well written; no changes needed for GitHub.)

📄 License

MIT License (recommended for personal/student projects)

🚀 Next Improvements (Optional for GitHub)

You can add these sections if you want your repo to look even more professional:

Screenshots of LCD

Circuit diagram (Fritzing)

PCB design

Version history

Troubleshooting section

If you want, I can also:

✅ Format the entire repository structure
✅ Add a professional Fritzing circuit diagram
✅ Rewrite the code to be more optimized
✅ Add photos / ASCII circuit diagrams
Just tell me!

You said:
create a readme.md file
ChatGPT said:

Here is your GitHub-ready README.md — clean, professional, and formatted properly.

Digital Voting Machine (Arduino EVM)

A fully functional Digital Voting Machine (EVM) built using Arduino, LCD, and push buttons.
Includes secure PIN-based result access, real-time vote counting, winner detection, tie handling, buzzer feedback, LEDs, and a scrolling LCD interface.

🚀 Features

4-Candidate voting system (A, B, C, D)

PIN-protected result unlocking

Real-time vote confirmation with LED + buzzer

Scrolling candidate list on LCD

Winner detection with vote margin

Automatic tie detection and display

Winning melody playback

Non-blocking UI using millis()

Fully beginner-friendly circuit

🛠 Components Required
Component	Quantity
Arduino UNO / Nano	1
16×2 I2C LCD	1
Push buttons	5 (4 voting + 1 result)
Buzzer	1
LEDs	2 (Vote LED + Result LED)
Resistors (10k)	Optional (if not using internal pull-ups)
Jumper Wires	As required
🔌 Pin Configuration
Component	Arduino Pin
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

Displays boot screen & "Submitted By" names

Shows candidate list in a scrolling format

Voter presses a button → vote recorded

LCD confirms vote with name + symbol

Press Result Button, enter 4-digit PIN

System shows:

Total votes

Votes per candidate

Winner + margin

Tie results (if any)

Final screen loops winner/margin with melody

📄 Source Code

Paste your code into a file named evm.ino in the repository.

📘 Libraries Used

Wire.h

LiquidCrystal_I2C.h

Install the LCD I2C library if not already present.

🔧 Setup

Build the circuit as per pin connections

Upload the .ino file to Arduino

Restart the board

Vote using the buttons!

Press the Result Button, enter the PIN to view results

🏆 Future Enhancements (Optional)

Add SD card logging

Add fingerprint / RFID authentication

OLED display version

Web dashboard for live results

Encrypted vote storage

📜 License

This project is released under the MIT License.
Feel free to modify and improve it.
