/* * * * * * * * * * * * * *
    Functions to implement
    calculate(): take input from outtext buffer then put answer in outtext buffer | anirudh do this
 *                         *
    
 *                         *
 * * * * * * * * * * * * * *
*/

#include <Key.h> //keypad
#include <Keypad.h>
#include <SPI.h> //sd card and display
#include <Adafruit_ILI9341.h> //display
#include <Adafruit_GFX.h>
#include <SD.h> //sdcard

#define TFT_DC 9  //connect display spi DC and CS to this
#define TFT_CS 10
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC); //define the display
char *outtext = (char*)malloc(512); //whatever u type ends up here

const byte ROWS = 4; //define keypad
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1', '2', '3', '+'},
  {'4', '5', '6', '-'},
  {'7', '8', '9', '*'},
  {'S', '0', '<', '/'}
};
byte rowPins[ROWS] = {5, 6, 12, 13};
byte colPins[COLS] = {A1, A2, A3, A4};
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void clrscr() { //clear screen
  tft.fillScreen(0x0000);
  tft.setCursor(0, 0);
}
void noteviewer() {
  //Behavior: Display notes. Press 0 to exit.
  if (!SD.begin(4)) {
    return;
  }
  File notes = SD.open("/notes.txt");
  char c;
  bool a = true;
  while(a) {
    c=notes.read(); //load a char to c
    if(c != -1) { //Not end of file
      tft.print((char)c); //typecast to char just in case
    } else {
      char key = keypad.getKey();
      if (key == '0') {
        return; //exit when 0 pressed btw return will exit the function
      }
    }
  }
}
void musicplayer() {
  /*clrscr();
  if (!SD.begin(4)) {
    return;
  }
  tft.println("Press 1 to shuffle music, press 0 to exit");
  while(1) {
  char key = keypad.getKey();
  if (key != NO_KEY) {
    if (key == '0') {
      return;
    }
    if (key == '1') {
      while (1) {
        int count = 0;
        File music = SD.open("/music.wav");
        const int S = 1024;
        short buffer[S];
        while (music.available()) {
          // read from the file into buffer
          music.read(buffer, sizeof(buffer));

          // Prepare samples
          int volume = 1024;
          Audio.prepare(buffer, S, volume);
          // Feed samples to audio
          Audio.write(buffer, S);

          // Every 100 block print a '.'
          count++;
          if (count == 100) {
            Serial.print(".");
            count = 0;
          }
        }
        music.close();
      }
      return;
    }
  }
}*/
  tft.println("not implemented halp");
  return;
}
void setup() {
  tft.begin();
  tft.setRotation(1);
  clrscr();
}
const char *calcloop() {
  while (1) {
    char key = keypad.getKey();
    if (key != NO_KEY) {
      if (key == '<' && keypad.getState() == PRESSED) {
        outtext[strlen(outtext) - 1] = 0;
        clrscr();
        tft.print("> ");
        tft.print(outtext);
      }
      if (key == '<' && keypad.getState() == HOLD) {
        tft.println("");
        if (!strcmp(outtext, "420666")) { //type 420666 enter for secret menu
          tft.println("Hackulator Menu");
          tft.println("0) exit this menu");
          tft.println("1) Choose music to play");
          tft.println("2) View cheat notes");
          while (1) {
            char lol = keypad.getKey();
            if (lol != NO_KEY) {
              if (lol == '0') {
                return "c";
              } else if (lol == '1') {
                musicplayer();
                break;
              } else if (lol == '2') {
                noteviewer();
                break;
              }

            }
          }
        }
        else {
          tft.println("");
          calculate();
          tft.println(outtext);
        }
      }
      if (key <= 57 && key >= 48) {
        tft.print((char)key);
        strcat(outtext, (const char*)key);
      }
    }
  }
}
void loop() {
  tft.print("> ");
  calcloop();
}
