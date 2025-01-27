#include <BluetoothSerial.h>

BluetoothSerial SerialBT;
String deviceName = "RobotController";

// DEFINE MOTOR PINS 
#define  LEFT_MOTOR_FOREWARD 21
#define  RIGHT_MOTOR_FOREWARD 5
#define  LEFT_MOTOR_BACKWARD 16
#define  RIGHT_MOTOR_BACKWARD 17

void setup() {
  Serial.begin(9600);
  Serial2.begin(19200);
  SerialBT.begin(deviceName);
  Serial.println("Bluetooth Device Ready");

  // SET PIN MODE 
  pinMode(RIGHT_MOTOR_FOREWARD, OUTPUT);
   pinMode(LEFT_MOTOR_BACKWARD, OUTPUT);
    pinMode(RIGHT_MOTOR_BACKWARD, OUTPUT);
     pinMode(LEFT_MOTOR_FOREWARD, OUTPUT);
    //  initialize wheel state
    digitalWrite(RIGHT_MOTOR_FOREWARD, 0);
        digitalWrite(LEFT_MOTOR_FOREWARD, 0);
        digitalWrite(RIGHT_MOTOR_BACKWARD, 0);
        digitalWrite(LEFT_MOTOR_BACKWARD, 0);

}

void loop() {
  if (SerialBT.available()) {
    char command = SerialBT.read();
    
    // Forward commands to main serial
    Serial.write(command);
    
    // Optional: Direct command processing
    switch(command) {
      case 'F': 
        // CONTROL MOTOR FORWARD
        Serial2.print('F');
        // digitalWrite(RIGHT_MOTOR_FOREWARD, 1);
        // digitalWrite(LEFT_MOTOR_FOREWARD, 1);
        // digitalWrite(RIGHT_MOTOR_BACKWARD, 0);
        // digitalWrite(LEFT_MOTOR_BACKWARD, 0);
          digitalWrite(RIGHT_MOTOR_FOREWARD, 1);
        digitalWrite(LEFT_MOTOR_FOREWARD, 1);
         digitalWrite(LEFT_MOTOR_BACKWARD, 0);
        digitalWrite(RIGHT_MOTOR_BACKWARD, 0);
        

       break;
      case 'B': 
        // CONTROL MOTOR BACKWARD
        Serial2.print('b');
        digitalWrite(RIGHT_MOTOR_FOREWARD, 0);
        digitalWrite(LEFT_MOTOR_FOREWARD, 0);
         digitalWrite(LEFT_MOTOR_BACKWARD, 1);
        digitalWrite(RIGHT_MOTOR_BACKWARD, 1);
       break;
      case 'L': 
      // CONTROL MOTOR LEFT
      Serial2.print('l');
     digitalWrite(RIGHT_MOTOR_FOREWARD, 1);
        digitalWrite(LEFT_MOTOR_FOREWARD, 0);
         digitalWrite(LEFT_MOTOR_BACKWARD, 1);
        digitalWrite(RIGHT_MOTOR_BACKWARD, 0);

       break;
      case 'R': 
      //CONTROL MOTOR RIGHT 
      Serial2.print('r');
       digitalWrite(RIGHT_MOTOR_FOREWARD, 0);
        digitalWrite(LEFT_MOTOR_FOREWARD, 1);
         digitalWrite(LEFT_MOTOR_BACKWARD, 0);
        digitalWrite(RIGHT_MOTOR_BACKWARD, 1);
       break;
      case 'P': 
      //CONTROL MOTOR STOP
      Serial2.print('P');
       digitalWrite(RIGHT_MOTOR_FOREWARD, 0);
        digitalWrite(LEFT_MOTOR_FOREWARD, 0);
         digitalWrite(LEFT_MOTOR_BACKWARD, 0);
        digitalWrite(RIGHT_MOTOR_BACKWARD, 0);
       break;
      default: Serial.print(command);
        digitalWrite(RIGHT_MOTOR_FOREWARD, 0);
        digitalWrite(LEFT_MOTOR_FOREWARD, 0);
        digitalWrite(RIGHT_MOTOR_BACKWARD, 0);
        digitalWrite(LEFT_MOTOR_BACKWARD, 0);
       break;
    }
  }
}