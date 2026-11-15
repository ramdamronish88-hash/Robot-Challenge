#define red 10 //replacing 8 with red
#define green 9 //replacing 11 with green
#define yellow 6 //replacing 6 with yellow
#include<Servo.h>
Servo right; //right wheel
Servo left; //left wheel
int button = 13; //button is assigned to pin 13
int buttonState = 0; //initial value of buttonState is 0
void setup() {
right.attach(11); //assigns right motor to pin 3
left.attach(12); //assigns left motor to pin 12
pinMode(button,INPUT); //switch
pinMode(green, OUTPUT); //green LED
pinMode(yellow, OUTPUT); //yellow LED
pinMode(red, OUTPUT); //red LED
}
void loop() {
buttonState = digitalRead(button); //checking if switch is pressed or not
if (buttonState == HIGH)
{ //when switch is pressed
forward(); delay(2000); //robot goes in forward direction
spin(); delay(2000); //robot spins
stopservo(); delay(50); //robot stops for a while
reverse(); delay(2000); //the robot goes in reverse
stopservo(); delay(100);//fully stops the wheels from turning
leftturn(); delay(1500); //turns left
rightturn(); delay(1500); //turns right
leftturn(); delay(1500); //turns left
rightturn(); delay(1500); //turns right
led(); delay(1000); //led's blink in a fun pattern
exit(0); //arduino stops the program
}
}
void reverse(){ //goes in straight line
right.writeMicroseconds(1890);
left.writeMicroseconds(1005);
}
void spin(){ //robot spins
right.writeMicroseconds(2000);
left.writeMicroseconds(2000);
}
void forward(){ //robot goes in reverse
right.writeMicroseconds(1005);
left.writeMicroseconds(1890);
}
void stopservo(){ //servos stop rotating
right.writeMicroseconds(1500);
left.writeMicroseconds(1500);
}
void leftturn()//function for left turn move  
{  
right.writeMicroseconds(1000);//sets right servo to left trun  
left.writeMicroseconds(1700);//sets left servo to left turn   
}
void rightturn() //function for right turn move  
{  
right.writeMicroseconds(1250);//sets right servo to right turn  
left.writeMicroseconds(1950);//sets left servo to right turn 
}    

void led(){ //making led's blink
right.detach();
left.detach();
digitalWrite(red, HIGH);
delay(100);
digitalWrite(yellow, HIGH);
delay(100);
digitalWrite(green, HIGH);
delay(100);
digitalWrite(red, LOW);
delay(100);
digitalWrite(yellow, LOW);
delay(100);
digitalWrite(green, LOW);
delay(100);
digitalWrite(red, HIGH);
delay(100);
digitalWrite(yellow, HIGH);
delay(100);
digitalWrite(green, HIGH);
delay(100);
digitalWrite(red, LOW);
delay(100);
digitalWrite(yellow, LOW);
delay(100);
digitalWrite(green, LOW);
delay(100);
}