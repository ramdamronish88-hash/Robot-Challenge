#define red 8 //assigning 8 as red
#define green 3 //assigning 11 as green
#define yellow 6 //assigning 6 as yellow
#include <Servo.h> //using library
Servo right;
Servo left;
int val = 0; //assigning the initial value of Val as 0
int button = 13; //assigning button as 13
int buttonState = 0; //assigning the initial value of buttonState as 0(will be useful to check weather the switch is pressed or not)
void setup() {
right.attach(11); //right wheel
left.attach(12); // left wheel
pinMode(red, OUTPUT); //red LED
pinMode(green, OUTPUT); //green LED
pinMode(yellow, OUTPUT); //yellow LED
pinMode(button, INPUT); //button
Serial.begin(9600); //begins printing photoresistor
}
void loop() {
buttonState = digitalRead(button); //checking if switch is pressed or not
if (buttonState == HIGH){ //when the switch is pressed
while(1){ //making the Arduino skip checking button checking after switch is pressed
val = analogRead(2); //reading value from the photoresistor
Serial.println(val); //Serial Monitor begins printing the value read by photoresistor
if (val> 700) //when light is shined
{
spin(); delay(1500); //the robot spins
}
if (val< 400) //when shadow casts on the Arduino
{
reverse(); delay(1000); //robot goes in reverse
}

else { //when ambient light shined
forward(); delay(1000); //robot goes forward
}
}
}
}
void forward(){ // goes forward with green LED on
right.writeMicroseconds(1005);
left.writeMicroseconds(1890);
digitalWrite(green, HIGH); delay(100);
digitalWrite(red, LOW); delay(100);
digitalWrite(yellow, LOW); delay(100);
}
void reverse(){ //goes in reverse with yellow LED on
right.writeMicroseconds(1700);
left.writeMicroseconds(1300);
digitalWrite(green, LOW); delay(100);
digitalWrite(red, LOW); delay(100);
digitalWrite(yellow, HIGH); delay(100);
}
void spin(){ //goes in spin with red LED on
right.writeMicroseconds(2000);
left.writeMicroseconds(2000);
digitalWrite(green, LOW); delay(100);
digitalWrite(red, HIGH); delay(100);
digitalWrite(yellow, LOW); delay(100);
}