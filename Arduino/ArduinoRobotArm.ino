#include <Servo.h>

Servo yservo;  
Servo xservo;
Servo yyservo;
int ypos = 0;
int xpos= 0;

void setup(){
  yyservo.attach(4);
  xservo.attach(11); 
  yservo.attach(10);  
  Serial.begin(9600); 
  Serial.println("Rolling");
 
}

void loop() {
  static int v = 0; // value to be sent to the servo (0-180)
  if ( Serial.available() > 0) {
    char ch = Serial.read(); // read in a character from the serial port and assign to ch
    switch(ch) { // switch based on the value of ch
      case '0'...'9': // if it's numeric
        v = v * 10 + ch - '0';
        /*
           so if the chars sent are 45x (turn x servo to 45 degs)..
           v is the value we want to send to the servo and it is currently 0
           The first char (ch) is 4 so
           0*10 = 0 + 4 - 0 = 4;
           Second char is 4;
           4*10 = 40 + 5 = 45 - 0 = 45;
           Third char is not a number(0-9) so we  drop through...
        */
        break;
      case 'x': // if it's x
      
        xservo.write(v);
        v = 0;
        break;
      case 'y':
        yservo.write(v);
        //yyservo.write(v);
        v = 0;
        break;
    }
  }
}

