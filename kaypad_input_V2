

#include <Keypad.h>
#include <Servo.h>

Servo servoset1;
Servo servoset2;
Servo servoset3;
Servo servoset4;
Servo servoset5;// create servo object to control a servo

int pos1 = 0;
int pos2=0;
int pos3=0;
int pos4=0;
int pos5=0;
int timedelay=1000;// variable to store delay between servos
int skip=4; //delay between each servo angle
const int ROW_NUM = 4; //four rows
const int COLUMN_NUM = 4; //four columns

char keys[ROW_NUM][COLUMN_NUM] = {
  {'1','2','3', 'A'},
  {'4','5','6', 'B'},
  {'7','8','9', 'C'},
  {'*','0','#', 'D'}
};

byte pin_rows[ROW_NUM] = {9, 8, 7, 6}; //connect to the row pinouts of the keypad
byte pin_column[COLUMN_NUM] = {5, 4, 3, 2}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), pin_rows, pin_column, ROW_NUM, COLUMN_NUM );

String inputString;
long inputInt;

void setup() {
  Serial.begin(9600);
  inputString.reserve(10); // maximum number of digit for a number is 10
  servoset1.attach(10);
  servoset2.attach(11);
  servoset3.attach(12);
  servoset4.attach(13);
  servoset1.write(0);//prevent the servo jump at startup
  servoset2.write(0);//prevent the servo jump at startup

}

void loop() {
  Serial.println("Enter number of tshirts to be folded: ");
  char key = keypad.getKey();

  if (key) {

    if (key >= '0' && key <= '9') {     // only act on numeric keys
      inputString += key;               // append new character 
    } else if (key == '#') {
      if (inputString.length() > 0) {
        inputInt = inputString.toInt(); // YOU GOT AN INTEGER NUMBER
        Serial.println(inputInt);
        inputString = "";               // clear input

      }
    } else if (key == '*') {
      inputString = "";                 // clear input
    }
  }
  
  // running loop for the servos
  for (int servocount=0;servocount<inputInt; servocount+=1){
    for (pos1 = 0; pos1 <= 150; pos1 += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    servoset1.write(pos1);              
    delay(skip);                       
  }
  for (pos1 = 150; pos1 >= 0; pos1 -= 1) { // goes from 180 degrees to 0 degrees
    servoset1.write(pos1);              
    delay(skip);                       
  }
  delay(timedelay);
  for (pos2 = 0; pos2 <= 150; pos2 += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    servoset2.write(pos2);              // tell servo to go to position in variable 'pos'
    delay(skip);                       // waits 15ms for the servo to reach the position
  }
  for (pos2 = 150; pos2 >= 0; pos2 -= 1) { // goes from 180 degrees to 0 degrees
    servoset2.write(pos2);              // tell servo to go to position in variable 'pos'
    delay(skip);                       // waits 15ms for the servo to reach the position
  }
  Serial.println(servocount);
  delay(5000);
  /*
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
  */ 
    
  }
  key=0;
  inputInt=0;
}
