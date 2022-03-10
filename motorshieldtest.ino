
const int MotorPinA = 12; // for motor A
const int MotorSpeedPinA = 3; // for motor A
const int MotorBrakePinA = 9; // for motor A


const int CW  = HIGH;
const int CCW = LOW;

void setup() {
  // motor A pin assignment
  pinMode(MotorPinA, OUTPUT);
  pinMode(MotorSpeedPinA, OUTPUT);
  pinMode(MotorBrakePinA, OUTPUT);

  Serial.begin(9600);//  seial monitor initialized 

}

void loop() {

  //start motor A at maximum speed
  digitalWrite(MotorPinA, HIGH);// set direction
      Serial.println("Direction CW"); 
  analogWrite(MotorSpeedPinA, 127);// set speed at maximum
      Serial.println("Speed 100");
//  delay(5000);// run for 5 seconds
//  digitalWrite(MotorBrakePinA, HIGH);// brake
//      Serial.println("Brake applied");
//  delay(5000);  
//  digitalWrite(MotorBrakePinA, LOW);
//  digitalWrite(MotorPinA, LOW);
//  analogWrite(MotorSpeedPinA, 255/2);
//  delay(5000);// run for 5 seconds
//  digitalWrite(MotorBrakePinA, HIGH);
//  delay(500);
//  digitalWrite(MotorBrakePinA, LOW);

}// loop end
