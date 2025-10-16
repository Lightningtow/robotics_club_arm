#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards


const bool LOGGING = true;
const String bar = "============";
const String clearScreen = "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
const int truncateLength = 4;
void logThis(String msg) {
  if(LOGGING) Serial.println(msg);
}
// go tools -> serial monitor to show tab to see logging output
 // print is the one you want, or println which adds a newline after every thing. do NOT use write which is weird binary stuff
void logThis(double msg) {
  if(LOGGING) Serial.println(msg, truncateLength); // print is the one you want, or println which adds a newline after every thing. do NOT use write which is weird binary stuff
}
void logThis(String str, double num) {
  if(LOGGING) {
        Serial.print(str + " = ");
    Serial.println(num, truncateLength); // print is the one you want, or println which adds a newline after every thing. do NOT use write which is weird binary stuff

}}
void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  Serial.begin(9600);
  // Serial.println(clearScreen);
  Serial.println("beginning of program");
  
}
int getAngle(int step) { // takes int between 500 and 2500 and returns it as an angle between 0 and 270
  int baseStep = step - 500;
  int percent = (baseStep / 2000) * 100;   // what percentage of 2000 is x
  int angle = (percent / 100) * 270;
  return angle;
}
 // takes an angle between 0 and 270 and returns it as a value between 500 and 2500
 // this works but jumping from 0 to 270 and back creates like a power surge sort of thing for going too fast, need to loop and delay it
int getMS(int angle) {
  int percent = (angle / 270) * 100;
  int ms = (percent / 100) * 2000 + 500;
  return ms;
}
// arguments: the servo to rotate, and an angle from 0 to 270. do NOT remove the & from the parameter, or this func won't do anything
void rotateAngle(Servo& servo, int angle) {
// as written this func won't let you rotate with more accuracy than (at worst) 10 steps away (as in the 500 - 2500 range)
  const int stepSize = 10;
  const int delayMS = 15; // in milliseconds
  int percent = (angle / 270) * 100;
  int target = (percent / 100) * 2000 + 500;
  int currentPos = servo.readMicroseconds();
  logThis("rotating to " + String(angle));
  logThis("current pos is " + String(currentPos) + ", target is " + String(target));


  if (currentPos < target ) {
    logThis("currentPos < target");
    for (int i = currentPos; i <= target; i += stepSize) {
      logThis("i is " + String(i) + " target is " + String(target));
      myservo.writeMicroseconds(i);
      delay(delayMS);

    }
  }
  else { // if currentpos >= target
    logThis("if currentpos >= target");
    for (int i = currentPos; i >= target; i -= stepSize) {
            logThis("i is " + String(i) + " target is " + String(target));

      myservo.writeMicroseconds(i);
      delay(delayMS);

    }
  }

}
void STOP() { while (true){}}; // call this function to freeze movement. no idea why arduino doesnt have a built in kill func







//500 to 2500
//myservo.
  int loops = 0;
void loop() {
  test();
  STOP();
  logThis("loop starting");
  loops += 1;
  // if (loops <= 100) {STOP();}
  delay(1000);


  // STOP();
  // first spin to neutral
  myservo.writeMicroseconds(500);
  
  // delay(1000);
  // myservo.write(90);
    logThis(bar);

  // rotateAngle(myservo, 0);
    // delay(1000);
  logThis(bar);

  // rotateAngle(myservo, 135);


  rotateAngle(myservo, 270);
  logThis(bar);

    rotateAngle(myservo, 0);
    // delay(1000);
  STOP();



//   for (pos = 0; pos <= codeAngle; pos += 1) { // goes from 0 degrees to 180 degrees
//     // in steps of 1 degree
//     myservo.writeMicroseconds(pos);              // tell servo to go to position in variable 'pos'
//     delay(15);                       // waits 15ms for the servo to reach the position
//   }
//   for (pos = codeAngle; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
//     //Serial.print(pos);
//     myservo.write(pos);              // tell servo to go to position in variable 'pos'
//     delay(15);                       // waits 15ms for the servo to reach the position
//   }
}