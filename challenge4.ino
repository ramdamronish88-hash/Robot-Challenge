#include<Servo.h> //using library
Servo right; //right servo
Servo left; //left servo.
int button = 13; //assigns 13 to button
int buttonState = 0; //makes the initial value for buttonState 0
void setup() {
right.attach(11); //attaching pin 3 to right Servo
left.attach(12); //attaching pin 12 to left Servo
pinMode(button, INPUT); //assigns button as a input
}
void loop() {
buttonState= digitalRead(button); //checking if switch is pressed or not
Serial.println(button);
if(buttonState == HIGH) //when switch is pressed
{
forward(); delay(1100); //goes forward
leftturn(); delay(500); //takes sharp left turn
forward(); delay(900); //goes forward
leftturn(); delay(410); //takes sharp turn left
forward(); delay(1500); //goes forward
rightturn(); delay(530); //takes a right turn
forward(); delay(930); //goes straight to the final point
rightturn(); delay(490); //takes a right turn
forward(); delay(1100); //goes straight to the final point
stopservo(); delay(1000); //comes to rest
}
else{
stopservo(); //robot waits for the switch to be pressed
}
}
void forward(){ //goes in a straight line
right.writeMicroseconds(1005);
left.writeMicroseconds(1890);
}

void leftturn(){ //takes a leftturn
right.writeMicroseconds(1000);
left.writeMicroseconds(1500);
}
/*void pickup(){ //makes a half circle to pick the object
right.writeMicroseconds(1135);
left.writeMicroseconds(1685);
}
void picked(){ //after picking the object it straightens itself
right.writeMicroseconds(1000);
left.writeMicroseconds(1000);
}*/
void rightturn(){ //takes a right turn to go to the last point
right.writeMicroseconds(1500);
left.writeMicroseconds(2000);
}
void stopservo(){ //servos stop moving
right.writeMicroseconds(1500);
left.writeMicroseconds(1500);
}