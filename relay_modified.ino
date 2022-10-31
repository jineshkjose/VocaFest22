const int relay1=2;
const int relay2=3;
const int relay3=4;
const int relay4=5;
const int relay5=6;
String NUM;
String drug;
String num;


void setup() {
  // put your setup code here, to run once: 
pinMode(relay1, OUTPUT);
pinMode(relay2, OUTPUT);
pinMode(relay3, OUTPUT);
pinMode(relay4, OUTPUT);
pinMode(relay5, OUTPUT);
Serial.begin(9600);
Serial3.begin(9600);

digitalWrite(relay1, LOW);
digitalWrite(relay2,  LOW);
digitalWrite(relay3, LOW);
digitalWrite(relay4,  LOW);
digitalWrite(relay5,  LOW);

delay(1000);
digitalWrite(relay1, HIGH);
digitalWrite(relay2,  HIGH);
digitalWrite(relay3,  HIGH);
digitalWrite(relay4,   HIGH);
digitalWrite(relay5,   HIGH);

Serial.println("Serial PC ready ");
 Serial3.println("Bluetooth  ready ");
   
}

void loop() {


while (Serial.available()) { 
  // get the new byte:
char inChar = (char)Serial.read();

if(inChar=='a')
{
  digitalWrite(relay1, LOW);
  digitalWrite(relay2, HIGH);
  digitalWrite(relay3, HIGH);
  digitalWrite(relay4, HIGH);
  digitalWrite(relay5, HIGH);
}

else if(inChar=='b')
{
  digitalWrite(relay1, HIGH);
  digitalWrite(relay2, LOW);
  digitalWrite(relay3, HIGH);
  digitalWrite(relay4, HIGH);
  digitalWrite(relay5, HIGH);
}

else if(inChar=='c')
{
  digitalWrite(relay1, HIGH);
  digitalWrite(relay2, HIGH);
  digitalWrite(relay3, LOW);
  digitalWrite(relay4, HIGH);
  digitalWrite(relay5, HIGH);
}

else if(inChar=='d')
{
  digitalWrite(relay1, HIGH);
  digitalWrite(relay2, HIGH);
  digitalWrite(relay3, HIGH);
  digitalWrite(relay4, LOW);
  digitalWrite(relay5, HIGH);
}

else if(inChar=='e')
{
  digitalWrite(relay1, HIGH);
  digitalWrite(relay2, HIGH);
  digitalWrite(relay3, HIGH);
  digitalWrite(relay4, HIGH);
  digitalWrite(relay5, LOW);
}

else if(inChar=='f')
{
  digitalWrite(relay1, HIGH);
  digitalWrite(relay2, HIGH);
  digitalWrite(relay3, HIGH);
  digitalWrite(relay4, HIGH);
  digitalWrite(relay5, HIGH);
}

else if(inChar=='g')
{
  digitalWrite(relay1, LOW);
  digitalWrite(relay2, LOW);
  digitalWrite(relay3, LOW);
  digitalWrite(relay4, LOW);
  digitalWrite(relay5, LOW);
}

}

while (Serial3.available()) { 
  // get the new byte:
char inChar = (char)Serial3.read();

if(inChar=='a')
{
  digitalWrite(relay1, LOW);
  digitalWrite(relay2, HIGH);
  digitalWrite(relay3, HIGH);
  digitalWrite(relay4, HIGH);
  digitalWrite(relay5, HIGH);
}

else if(inChar=='b')
{
  digitalWrite(relay1, HIGH);
  digitalWrite(relay2, LOW);
  digitalWrite(relay3, HIGH);
  digitalWrite(relay4, HIGH);
  digitalWrite(relay5, HIGH);
}

else if(inChar=='c')
{
  digitalWrite(relay1, HIGH);
  digitalWrite(relay2, HIGH);
  digitalWrite(relay3, LOW);
  digitalWrite(relay4, HIGH);
  digitalWrite(relay5, HIGH);
}

else if(inChar=='d')
{
  digitalWrite(relay1, HIGH);
  digitalWrite(relay2, HIGH);
  digitalWrite(relay3, HIGH);
  digitalWrite(relay4, LOW);
  digitalWrite(relay5, HIGH);
}

else if(inChar=='e')
{
  digitalWrite(relay1, HIGH);
  digitalWrite(relay2, HIGH);
  digitalWrite(relay3, HIGH);
  digitalWrite(relay4, HIGH);
  digitalWrite(relay5, LOW);
}

else if(inChar=='f')
{
  digitalWrite(relay1, HIGH);
  digitalWrite(relay2, HIGH);
  digitalWrite(relay3, HIGH);
  digitalWrite(relay4, HIGH);
  digitalWrite(relay5, HIGH);
}

while ( Serial3.available() == 0) {} // waiting for input
NUM = Serial3.readString();  // stores mobile number to send SMS
Serial.println(NUM);         // Prints number
drug = NUM[0];
Serial.println(drug);         // Prints drug
num = NUM.substring(1,11);
Serial.println(num);         // Prints number

}
}
  
