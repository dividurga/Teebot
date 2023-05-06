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
int timedelay=1000;// variable to store the servo position

void setup() {
  servoset1.attach(8);
  servoset2.attach(9);
  servoset3.attach(10);
  servoset4.attach(11);
  servoset5.attach(12);

  


 // attaches the servo on pins to the servo object
}

void loop() {
  for (pos1 = 0; pos1 <= 150; pos1 += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    servoset1.write(pos1);              // tell servo to go to position in variable 'pos'
    delay(5);                       // waits 15ms for the servo to reach the position
  }
  for (pos1 = 150; pos1 >= 0; pos1 -= 1) { // goes from 180 degrees to 0 degrees
    servoset1.write(pos1);              // tell servo to go to position in variable 'pos'
    delay(5);                       // waits 15ms for the servo to reach the position
  }
  delay(timedelay);
  for (pos2 = 0; pos2 <= 150; pos2 += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    servoset2.write(pos2);              // tell servo to go to position in variable 'pos'
    delay(5);                       // waits 15ms for the servo to reach the position
  }
  for (pos2 = 150; pos2 >= 0; pos2 -= 1) { // goes from 180 degrees to 0 degrees
    servoset2.write(pos2);              // tell servo to go to position in variable 'pos'
    delay(5);                       // waits 15ms for the servo to reach the position
  }
  delay(timedelay);
  
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