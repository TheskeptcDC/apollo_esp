#include <BluetoothSerial.h>

BluetoothSerial SerialBT;
String deviceName = "RobotController";

void setup() {
  Serial.begin(9600);
  SerialBT.begin(deviceName);
  Serial.println("Bluetooth Device Ready");
}

void loop() {
  if (SerialBT.available()) {
    char command = SerialBT.read();
    
    // Forward commands to main serial
    Serial.write(command);
    
    // Optional: Direct command processing
    switch(command) {
      case 'F': Serial.println("Forward Command"); break;
      case 'B': Serial.println("Backward Command"); break;
      case 'L': Serial.println("Left Command"); break;
      case 'R': Serial.println("Right Command"); break;
      case 'S': Serial.println("Stop Command"); break;
    }
  }
}