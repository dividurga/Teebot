

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Keypad.h>
#include <Servo.h>




Adafruit_SSD1306 display(128, 64, &Wire, -1);


  //initialise servo objects
Servo servoset1;
Servo servoset2;
Servo servoset3;
Servo servoset4;

int p1 = 0;
int pos2 = 0;
int pos3 = 0;
int pos4 = 0;
int pos5 = 0;
            


char keys[4][4] = {
  { '1', '2', '3', 'A' },
  { '4', '5', '6', 'B' },
  { '7', '8', '9', 'C' },
  { '*', '0', '#', 'D' }
};

byte pin_rows[4] = { 9, 8, 7, 6 };       //connect to the row pinouts of the keypad
byte pin_column[4] = { 5, 4, 3, 2 };  //connect to the column pinouts of the keypad

Keypad keypad = Keypad(makeKeymap(keys), pin_rows, pin_column, 4, 4);

String inputString;
long inputInt;


void setup() {
  Serial.begin(9600);
  inputString.reserve(3);  // maximum number of digit for a number is 3
  servoset1.attach(10);
  servoset2.attach(11);
  servoset3.attach(12);
  servoset4.attach(13);
  servoset1.write(0);                                //prevent the servo jump at startup
  servoset2.write(0);                                //prevent the servo jump at startup
  servoset3.write(0);                                //prevent the servo jump at startup
  servoset4.write(0);  
  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    
    for(;;); // Don't proceed, loop forever
  }
Serial.println("Success");
delay(1000);
  // Show initial display buffer contents on the screen --
  // the library initializes this with an Adafruit splash screen.
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
  
  display.clearDisplay();

  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  // Display static text
  display.println("Enter no. of Tshirts\n\n# to enter\n* to void");
  display.display();

  //code for getting input from keypad
  char key = keypad.getKey();

  if (key) {

    if (key >= '0' && key <= '9') {  // only act on numeric keys
      inputString += key;
      
      display.setCursor(0, 50);
      // Display static text
      display.println(inputString);
      display.display();
     
      
    } else if (key == '#') {
      if (inputString.length() > 0) {
        inputInt = inputString.toInt();  // typecast to int
        
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

  for (int servocount = 0; servocount < inputInt; servocount += 1) {
   Serial.println(servocount);
   
    for (p1 = 0; p1 <= 150; p1 += 1) {  // goes from 0 degrees to 180 degrees
      // in steps of 1 degree
      servoset1.write(p1);
      delay(3);
    }
    for (p1 = 150; p1 >= 0; p1 -= 1) {  // goes from 180 degrees to 0 degrees
      servoset1.write(p1);
      delay(3);
    }
    delay(1000);
    for (pos2 = 0; pos2 <= 150; pos2 += 1) {  // goes from 0 degrees to 180 degrees
      // in steps of 1 degree
      servoset2.write(pos2);  // tell servo to go to position in variable 'pos'
      delay(3);            // waits 15ms for the servo to reach the position
    }
    for (pos2 = 150; pos2 >= 0; pos2 -= 1) {  // goes from 180 degrees to 0 degrees
      servoset2.write(pos2);                  // tell servo to go to position in variable 'pos'
      delay(3);                            // waits 15ms for the servo to reach the position
    }
  } 
  display.clearDisplay();
  key = 0;
  inputInt = 0;
}

