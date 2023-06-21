const int pingPin = 7; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 6; // Echo Pin of Ultrasonic Sensor
const int sensor2_pingPin = 8; // Trigger Pin of Ultrasonic Sensor
const int sensor2_echoPin = 5; // Echo Pin of Ultrasonic Sensor
int led = 10;
int led2 = 11;


void setup() {
  pinMode(led,OUTPUT);
  pinMode(led2,OUTPUT);
;
   Serial.begin(9600); // Starting Serial Terminal
}

void loop() {
   long duration, inches, cm;
   long duration2, inches2, cm2;

   pinMode(pingPin, OUTPUT);
   pinMode(sensor2_pingPin, OUTPUT);

   digitalWrite(pingPin, LOW);

   digitalWrite(sensor2_pingPin, LOW);
   delayMicroseconds(2);

   digitalWrite(pingPin, HIGH);
   digitalWrite(sensor2_pingPin, HIGH);
   delayMicroseconds(10);

   digitalWrite(pingPin, LOW);
   digitalWrite(sensor2_pingPin, LOW);

   pinMode(echoPin, INPUT);
  pinMode(sensor2_echoPin, INPUT);

   duration = pulseIn(echoPin, HIGH);
   duration2 = pulseIn(sensor2_echoPin, HIGH);

   inches = microsecondsToInches(duration);
   inches2 = microsecondsToInches(duration2);
   
   cm = microsecondsToCentimeters(duration);
   cm2 = microsecondsToCentimeters(duration2);
if(cm <= 8) {
  
  digitalWrite(led,HIGH);

}else if (cm > 11 & cm <20){
  digitalWrite(led2,HIGH);
}
else{
  
digitalWrite(led,LOW);
digitalWrite(led2,LOW);

}

if(cm2 <= 20) {
  digitalWrite(led2,HIGH);
}
else{
  
digitalWrite(led2,LOW);

}



   Serial.print(inches);   
   Serial.print("in, ");    
   Serial.print(inches2);
    Serial.print("in2, ");

   Serial.print(cm);
   Serial.print("cm");

      Serial.print(cm2);
   Serial.print("cm");
   Serial.println();
   delay(100);
}
long microsecondsToInches(long microseconds) {
   return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {
   return microseconds / 29 / 2;
}


