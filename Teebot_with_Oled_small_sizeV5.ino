/**************************************************************************
 
This is the Oled-compatible code (small size so that the SSD1306 0.96 I2C Oled can handle)

Check out Teebot_with_Oled_full_doc for proper documentation

Written by Divija Durga, with help from the contributions of the open source community. 

 **************************************************************************/
// importing libraries
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Keypad.h>
#include <Servo.h>



// initialise oled (width, height, param,-1 for reset)
Adafruit_SSD1306 display(128, 64, &Wire, -1);


//initialise servos
int pos[4] = { 0, 0, 0, 0 };
Servo servo[4];
const byte servoPins[] = { 10, 11, 12, 13 };
int j = 0;


char keys[4][4] = {
  { '1', '2', '3', 'A' },
  { '4', '5', '6', 'B' },
  { '7', '8', '9', 'C' },
  { '*', '0', '#', 'D' }
};

byte pin_rows[4] = { 9, 8, 7, 6 };    //connect to the row pinouts of the keypad
byte pin_column[4] = { 5, 4, 3, 2 };  //connect to the column pinouts of the keypad

Keypad keypad = Keypad(makeKeymap(keys), pin_rows, pin_column, 4, 4);

String inputString;
int inputInt;


void setup() {
  Serial.begin(9600);
  inputString.reserve(3);  // maximum number of digit for a number is 3
  //loop to attach servos to pins
  for (int n = 0; n < 4; n++) {
    servo[n].attach(servoPins[n]);
  }
  for (int m = 0; m < 4; m++) {
    servo[m].write(0);
  }


  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {

    for (;;)
      ;  // Don't proceed, loop forever
  }
  Serial.println("Success");
  delay(1000);
  display.clearDisplay();
  printDisplay("Teebot\n at your\n Service!", 30, 10, 2);
  delay(3000);
  display.clearDisplay();
}

void loop() {

  display.clearDisplay();
  printDisplay("Enter no. of Tshirts\n\n# to enter\n* to void",0,10,1);

  //code for getting input from keypad
  char key = keypad.getKey();
  Serial.println(key);
  char inputChar[4];
  if (key) {

    if (key >= '0' && key <= '9') {  // only act on numeric keys
      inputString += key;
      inputString.toCharArray(inputChar, inputString.length()+1);//so that my printDisplay function can handle
      printDisplay(inputChar,0,50,1);
      delay(1000);
      inputString="";


    } else if (key == '#') {
      if (inputString.length() > 0) {
        inputInt = inputString.toInt();  // typecast to int
        // Display static text
        printDisplay(inputChar,0,50,1);
        delay(1000);  // clear input
      }
    } else if (key == '*') {
      inputString = "";  // clear input
    }
    else if (key=='A'){
      for (int i = 0; i < 4; i++) {
      for (pos[i]; pos[i] <= 150; pos[i]++) {  // goes from 0 degrees to 150 degrees
        // in steps of 1 degree
        servo[i].write(pos[i]);
        delay(3);
      }
      for (pos[i] = 150; pos[i] >= 0; pos[i] -= 1) {  // goes from 150 degrees to 0 degrees
        servo[i].write(pos[i]);
        delay(3);
      }
      delay(1000);
      
    }
    }
  }

  for (int servocount = 0; servocount < inputInt; servocount += 1) {
    Serial.println(servocount);
    display.clearDisplay();
    printDisplay("Lay the Tshirt",0,30,1);

    delay(5000);
    display.clearDisplay();
    printDisplay("Folding...",0,30,1);
    for (int j = 0; j < 4; j++) {
      for (pos[j]; pos[j] <= 150; pos[j]++) {  // goes from 0 degrees to 150 degrees
        // in steps of 1 degree
        servo[j].write(pos[j]);
        delay(3);
      }
      for (pos[j] = 150; pos[j] >= 0; pos[j] -= 1) {  // goes from 150 degrees to 0 degrees
        servo[j].write(pos[j]);
        delay(3);
      }
      delay(1000);
      Serial.println(j);
    }
  }
  display.clearDisplay();
  key = 0;
  inputInt = 0;
}


void printDisplay(char str[], int cursx, int cursy, int size) {
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(size);
  display.setCursor(cursx, cursy);
  display.println(str);
  display.display();
}