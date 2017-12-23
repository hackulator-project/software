# Hackulator  
The hackulator is an open source project. The aim is to make a replacement of the TI-84 calculator. Plus, the final cost should be around $50 to build it yourself. If you want to obtain and assemble the hardware for the hackulator it is available at [https://github.com/hackulator-project/hardware](https://github.com/hackulator-project/hardware).  
  
# Compiling  
First, follow instructions [here](https://learn.adafruit.com/adafruit-feather-m0-adalogger/setup) to set up your arduino ide to compile for the board. Then, open this .ino file in Arduino IDE. Then, click "Verify". Make sure it compiles correctly, or something is wrong with your setup. Once it's verified, then plug in the board using a micro usb cable. Now, upload the code. Now, reset the arduino. Hopefully, if you wired everything correctly, the hackulator will turn on.  
  
# Usage  
Use the hackulator like a normal calculator. Or, type "420666" then enter to access the secret menu. Of course, you could change this secret code by modifying the source code. In this menu, you can listen to music or view notes.  
  
# Dependencies
This project uses:  
* **SD**  
* **[Keypad](https://playground.arduino.cc/Code/Keypad)**  
* **SPI**  
* **Adafruit_ILI9341**  
* **Adafruit_GFX**  
* **[quickmafs](https://github.com/hackulator-project/quickmafs)**
