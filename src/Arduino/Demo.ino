const int pingPin = 7;
// Trigger Pin of Ultrasonic Sensor const
const int echoPin = 6;
const int getPin = 4;
// Echo Pin of Ultrasonic Sensor
void setup(){
  Serial.begin(74880);
  pinMode(getPin,INPUT);
  pinMode(8,OUTPUT);
// Starting Serial Terminal
 }
void loop()
{
  long duration, cm;
  int n = digitalRead(getPin);
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(pingPin, LOW);
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
  cm = microsecondsToCentimeters(duration);
  if(cm>=420||cm==1){ 
    analogWrite(A0,0);
   }
  else{
    Serial.print("#var getslong ");
    Serial.print(cm);
    Serial.print("\r");
    if(cm<5){
      digitalWrite(8,HIGH);
      delay(500);
      digitalWrite(8,LOW);  
    }
    delay(1000);
  }
} 
long microsecondsToCentimeters(long microseconds){
  return microseconds / 29 / 2;
}
