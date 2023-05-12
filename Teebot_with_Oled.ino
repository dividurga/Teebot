

#include <Keypad.h>
#include <Servo.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define SCREEN_WIDTH 128  // OLED display width, in pixels
#define SCREEN_HEIGHT 64  // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
Servo servoset1;
Servo servoset2;
Servo servoset3;
Servo servoset4;
Servo servoset5;  // create servo object to control a servo
int j = 0;
int pos1 = 0;
int pos2 = 0;
int pos3 = 0;
int pos4 = 0;
int pos5 = 0;
int timedelay = 1000;      // variable to store delay between servos
int skip = 4;              //delay between each servo angle
const int ROW_NUM = 4;     //four rows
const int COLUMN_NUM = 4;  //four columns

char keys[ROW_NUM][COLUMN_NUM] = {
  { '1', '2', '3', 'A' },
  { '4', '5', '6', 'B' },
  { '7', '8', '9', 'C' },
  { '*', '0', '#', 'D' }
};

byte pin_rows[ROW_NUM] = { 9, 8, 7, 6 };       //connect to the row pinouts of the keypad
byte pin_column[COLUMN_NUM] = { 5, 4, 3, 2 };  //connect to the column pinouts of the keypad

Keypad keypad = Keypad(makeKeymap(keys), pin_rows, pin_column, ROW_NUM, COLUMN_NUM);

String inputString;
long inputInt;

void oledPrint(String x) {
  display.clearDisplay();

  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  // Display static text
  display.println(x);
  display.display();
}
void setup() {
  Serial.begin(9600);
  inputString.reserve(10);  // maximum number of digit for a number is 10
  servoset1.attach(10);
  servoset2.attach(11);
  servoset3.attach(12);
  servoset4.attach(13);
  servoset1.write(0);                                //prevent the servo jump at startup
  servoset2.write(0);                                //prevent the servo jump at startup
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {  // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for (;;)
      ;
  }
  display.clearDisplay();

  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(30, 10);
  // Display static text
  display.println("Teebot\n at your\n Service!");
  display.display();
  delay(3000);
}


void loop() {
  Serial.println("Enter number of tshirts to be folded: ");
  //display.clearDisplay();

  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  // Display static text
  display.println("Enter no. of Tshirts\n\n# to enter\n* to void");
  display.display();

  char key = keypad.getKey();

  if (key) {

    if (key >= '0' && key <= '9') {  // only act on numeric keys
      inputString += key;
      Serial.println(inputString);

      display.setTextSize(1);
      display.setTextColor(WHITE);
      display.setCursor(0 + j, 50);
      // Display static text
      display.println(inputString);
      display.display();
      j += 1;
      delay(1000);
    } else if (key == '#') {
      if (inputString.length() > 0) {
        inputInt = inputString.toInt();  // YOU GOT AN INTEGER NUMBER
        Serial.println(inputInt);
        display.setTextSize(1);
        display.setTextColor(WHITE);
        display.setCursor(0, 50);
        // Display static text
        display.println(inputInt);
        display.display();
        inputString = "";
        delay(1000);  // clear input
      }
    } else if (key == '*') {
      inputString = "";  // clear input
    }
  }

  // running loop for the servos
  for (int servocount = 0; servocount < inputInt; servocount += 1) {
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0, 30);
    // Display static text
    display.println("Lay Tshirt!");
    display.display();
    delay(5000);
    display.clearDisplay();
    display.println("Folding...");
    display.display();

    for (pos1 = 0; pos1 <= 150; pos1 += 1) {  // goes from 0 degrees to 180 degrees
      // in steps of 1 degree
      servoset1.write(pos1);
      delay(skip);
    }
    for (pos1 = 150; pos1 >= 0; pos1 -= 1) {  // goes from 180 degrees to 0 degrees
      servoset1.write(pos1);
      delay(skip);
    }
    delay(timedelay);
    for (pos2 = 0; pos2 <= 150; pos2 += 1) {  // goes from 0 degrees to 180 degrees
      // in steps of 1 degree
      servoset2.write(pos2);  // tell servo to go to position in variable 'pos'
      delay(skip);            // waits 15ms for the servo to reach the position
    }
    for (pos2 = 150; pos2 >= 0; pos2 -= 1) {  // goes from 180 degrees to 0 degrees
      servoset2.write(pos2);                  // tell servo to go to position in variable 'pos'
      delay(skip);                            // waits 15ms for the servo to reach the position
    }
    Serial.println(servocount);
    
  for (pos3 = 0; pos3 <= 150; pos3 += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    servoset3.write(pos3);              // tell servo to go to position in variable 'pos'
    delay(5);                       // waits 15ms for the servo to reach the position
  }
  for (pos3 = 150; pos3 >= 0; pos3 -= 1) { // goes from 180 degrees to 0 degrees
    servoset3.write(pos3);              // tell servo to go to position in variable 'pos'
    delay(5);                       // waits 15ms for the servo to reach the position
  }
  delay(timedelay);
  for (pos4 = 0; pos4 <= 150; pos4 += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    servoset4.write(pos4);              // tell servo to go to position in variable 'pos'
    delay(5);                       // waits 15ms for the servo to reach the position
  }
  for (pos4 = 150; pos4 >= 0; pos4 -= 1) { // goes from 180 degrees to 0 degrees
    servoset4.write(pos4);              // tell servo to go to position in variable 'pos'
    delay(5);                       // waits 15ms for the servo to reach the position
  }
  delay(timedelay);for (pos5 = 0; pos5<= 150; pos5 += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    servoset5.write(pos5);              // tell servo to go to position in variable 'pos'
    delay(5);                       // waits 15ms for the servo to reach the position
  }
  for (pos5 = 150; pos5 >= 0; pos5 -= 1) { // goes from 180 degrees to 0 degrees
    servoset5.write(pos5);              // tell servo to go to position in variable 'pos'
    delay(5);                       // waits 15ms for the servo to reach the position
  }
  delay(timedelay);
  
  }
  display.clearDisplay();

  key = 0;
  inputInt = 0;
}
