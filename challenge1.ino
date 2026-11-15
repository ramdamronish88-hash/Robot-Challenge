#include<Servo.h>//include servo library  
Servo A;//servo right 
Servo B;//servo left void 
void setup() {  
A.attach(11);//right servo is connected to pin 3  
B.attach(12 );//left servo is connected to pin 12  
Serial.begin(9600);//initialize serial communication  
}  
void loop() {   
int switchstatus=digitalRead(13);//reads digital value of pin 13   
if(switchstatus==1)  
{   
forward();//calls forward function   
delay(600);//wait for 600 ms   
leftturn();//calls left turn function   
delay(4200);//wait for 4200 ms  sn 
rightturn();//calls for right turn function  
delay(4910);//wait for 4980 ms    
leftturn();//calls for forward function   
delay(2800);//wait for 2800 ms  
exit(0);//calls for exit function  
}  
}   

  
  
void forward(){ //function to move forward  
A.writeMicroseconds(1005);//sets right servo to move forward  
B.writeMicroseconds(1890);//sets left servo to move forward  
}  
void leftturn()//function for left turn move  
{  
A.writeMicroseconds(1000);//sets right servo to left trun  
B.writeMicroseconds(1700);//sets left servo to left turn   
}
void rightturn() //function for right turn move  
{  
A.writeMicroseconds(1250);//sets right servo to right turn  
B.writeMicroseconds(1950);//sets left servo to right turn 
}    
void exit()  
{  
A.writeMicroseconds(1500);//sets the right servo  to stop  
B.writeMicroseconds(1500);//sets the left servo to stop  
} 