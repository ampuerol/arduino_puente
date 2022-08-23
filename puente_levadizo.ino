int switchstate1 = 0;
int switchstate2 = 0;

int amin = 90;
int amax = 160;

//sensores de luz.
// variable to hold sensor value
int sensorValue1;
int sensorValue2;
// variable to calibrate low value
int sensorLow = 1023;
// variable to calibrate high value
int sensorHigh = 0;
// LED pin

//servomotor
// include the servo library
#include <Servo.h>
//servomotor
Servo myServo;  // create a servo object

void setup() {
// put your setup code here, to run once:

  // declare the LED pins as outputs
  pinMode(2, OUTPUT); //Verde
  pinMode(3, OUTPUT); //Rojo
  pinMode(4, OUTPUT); //Amarillo

  pinMode(10, INPUT);
  pinMode(11, INPUT);
  
  //Sensores luz
  // Make the LED pin an output and turn it on
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);
  
  myServo.attach(9); // attaches the servo on pin 9 to the servo object
  Serial.begin(9600); // open a serial connection to your computer

  // calibrate for the first five seconds after program runs
  while (millis() < 5000) {
    // record the maximum sensor value
    sensorValue1 = analogRead(A1);
    sensorValue2 = analogRead(A2);
    if (sensorValue1 > sensorHigh) {
      sensorHigh = sensorValue1;
      }
    if (sensorValue2 > sensorHigh) {
      sensorHigh = sensorValue2;
      }
    // record the minimum sensor value
    if (sensorValue1 < sensorLow) {
      sensorLow = sensorValue1;
      } 
    if (sensorValue2 < sensorLow) {
      sensorLow = sensorValue2;
      }
    Serial.print("sensorHigh: ");
    Serial.println(sensorHigh);
    Serial.print("sensorLow: ");
    Serial.println(sensorLow);
  }
  // turn the LED off, signaling the end of the calibration period
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);
}

void loop() {
// put your main code here, to run repeatedly:

 {
 //Sensores.
 //read the input from A0 and store it in a variable
 sensorValue1 = analogRead(A1);
 //read the input from A0 and store it in a variable
 sensorValue2 = analogRead(A2);
 }
 switchstate1 = digitalRead(11);
 switchstate2 = digitalRead(10);

    if (switchstate1==LOW) {
  
      if (sensorValue1<700) {
        // set the servo position
        digitalWrite(4, HIGH); // turn the yellow LED on pin 4 on
        digitalWrite(2, LOW); // turn the green LED on pin 2 off
        delay(3000);
        myServo.write(amax);
        digitalWrite(3, HIGH); // turn the red LED on pin 3 on
        }
     if (sensorValue2<700) {
        // set the servo position
        delay(3000);
        myServo.write(amin);
        digitalWrite(4, HIGH); // turn the yellow LED on pin 4 on
        digitalWrite(3, LOW); // turn the red LED on pin 3 off
   
        delay(3000);
        digitalWrite(4, LOW); // turn the yellow LED on pin 4 off
        digitalWrite(2, HIGH); // turn the green LED on pin 2 on
        delay(15);
        }
     }
     else {
        if (switchstate2==HIGH){
        myServo.write(amax);
        digitalWrite(3, HIGH); // turn the red LED on pin 3 on
        digitalWrite(2, LOW); // turn the green LED on pin 2 off
        delay(15);
        }
        else {
        myServo.write(amin);
        digitalWrite(4, HIGH); // turn the yellow LED on pin 4 on
        digitalWrite(3, LOW); // turn the red LED on pin 3 off
        delay(3000);
        digitalWrite(4, LOW); // turn the yellow LED on pin 4 off
        digitalWrite(2, HIGH); // turn the green LED on pin 2 on
        delay(15);
        }
     }
}
