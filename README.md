# Arduino Door response notification
An Arduino script to add LED notification to AC door entry system. This script notifies via LEDs when the doorbell is rung, The Phone is picked up and when the door release button is pressed. Tested with a Bell 801 phone. This is a 12V AC phone so I had to put in Voltage Dividers before I could get analog inputs into the Arduino.
Terminals of Phone:
* **I** Call
* **R** Speech Out (Mic)
* **O** Common
* **T** Speech In (Speaker)
* **Z** Lock

These pin connections are notified in variable names.
