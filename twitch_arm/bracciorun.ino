


#include <Braccio.h>
#include <Servo.h>

Servo base;
Servo shoulder;
Servo elbow;
Servo wrist_rot;
Servo wrist_ver;
Servo gripper;

int degree_base;
int degree_shoulder;
int degree_elbow;
int degree_wrist_rot;
int degree_wrist_ver;
int degree_gripper;

void move() {
   Braccio.ServoMovement(10, degree_base, degree_shoulder,  degree_elbow, degree_wrist_ver, degree_wrist_rot, degree_gripper); 
}
void setup() {
  //Initialization functions and set up the initial position for Braccio
  //All the servo motors will be positioned in the "safety" position:
  //Base (M1):90 degrees
  //Shoulder (M2): 45 degrees
  //Elbow (M3): 180 degrees
  //Wrist vertical (M4): 180 degrees
  //Wrist rotation (M5): 90 degrees
  //gripper (M6): 10 degrees
  Braccio.begin();
  Serial.begin(9600);
  degree_base = 90;
  degree_shoulder = 45;
  degree_elbow = 180;
  degree_wrist_ver = 180;
  degree_wrist_rot = 90;
  degree_gripper = 10;
  move();
  
}

void bcw(){
    if (degree_base < 180) degree_base +=30;
  move();
}

void bccw(){
  if (degree_base > 0) degree_base -=30;
  move();
}
void sup(){
  if (degree_shoulder < 165) degree_shoulder +=15;
  move();
}

void sdwn(){
  if (degree_shoulder > 15) degree_shoulder -=15;
  move();
}

void eup(){
  if (degree_elbow < 180) degree_elbow +=30;
  move();
}

void edwn(){
  if (degree_elbow > 0) degree_elbow -=30;
  move();
}

void wrup(){
  if (degree_wrist_ver < 180) degree_wrist_ver +=30;
  move();
}

void wrdwn(){
  if (degree_wrist_ver > 0) degree_wrist_ver -=30;
  move();
}

void wrcw(){
  if (degree_wrist_rot < 180) degree_wrist_rot +=30;
  move();
}

void wrccw(){
  if (degree_wrist_rot > 0) degree_wrist_rot -=30;
  move();
}

void gro(){
  degree_gripper = 10;
  move();
}

void grc(){
  degree_gripper = 73;
  move();
}


void loop() {
   /*
   Step Delay: a milliseconds delay between the movement of each servo.  Allowed values from 10 to 30 msec.
   M1=base degrees. Allowed values from 0 to 180 degrees
   M2=shoulder degrees. Allowed values from 15 to 165 degrees
   M3=elbow degrees. Allowed values from 0 to 180 degrees
   M4=wrist vertical degrees. Allowed values from 0 to 180 degrees
   M5=wrist rotation degrees. Allowed values from 0 to 180 degrees
   M6=gripper degrees. Allowed values from 10 to 73 degrees. 10: the toungue is open, 73: the gripper is closed.
  */
 if (Serial.available() > 0) {
     int keystroke = Serial.read();
     switch (keystroke) {
        case 65:
          sup();
          break;
        case 66:
          sdwn();
          break;
         case 67:
          eup();
          break;
         case 68:
          edwn();
          break;
           case 69:
           wrup();
          break;
           case 70:
           wrdwn();
          break;
          case 71:
          wrcw();
          break;
          case 72:
          wrccw();
          break;
          case 73:
          gro();
          break;
          case 74:
          grc();
          break;
          case 75:
          bcw();
          break;
          case 76:
          bccw();
          break;
     }
  }

}
