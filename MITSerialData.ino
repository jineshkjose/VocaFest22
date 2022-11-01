String inputString = "";         // a String to hold incoming data
String OptionString="";
String MobNoString="";
String MsgString="";

const int relay1=2;
const int relay2=3;
const int relay3=4;
const int relay4=5;
const int relay5=6;

bool stringComplete = false;  // whether the string is complete

void SendMessage(String Mno)
{
  Serial.println ("Sending Message please wait....");
  Serial2.println("AT+CMGF=1");    //Text Mode initialisation 
  delay(1000);
  Serial.println ("Set SMS Number");
 // Serial2.println("AT+CMGS=\"+919400086378\"\r"); // Receiver's Mobile Number

 Serial2.print("AT+CMGS=\"+91");
Serial2.print(Mno);
Serial2.print("\"\r"); // Receiver's Mobile Number
  delay(1000);
  Serial.println (MsgString);
   Serial2.println (MsgString);
   
  //Serial2.println("Thank you for visiting our stall");// Messsage content
  delay(100);
  Serial.println ("Done");
  Serial2.println((char)26);//   delay(1000);
  Serial.println ("Message sent succesfully");
}

void setup() {

  pinMode(relay1, OUTPUT);
pinMode(relay2, OUTPUT);
pinMode(relay3, OUTPUT);
pinMode(relay4, OUTPUT);
pinMode(relay5, OUTPUT);

  // initialize serial: @a,1234567890F#
  Serial.begin(9600);
    Serial2.begin(9600);
   Serial3.begin(9600);
  // reserve 200 bytes for the inputString:
  inputString.reserve(200);

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


  Serial.println("System Ready");
  Serial3.println("Bluetooth Ready");

 
}

void loop() {
  // print the string when a newline arrives:
  if (stringComplete) {

    inputString.trim();
    Serial.println(inputString);
    OptionString=inputString.substring(0,2);
   
    MobNoString=inputString.substring(3,13);
     Serial.print("optionstr= ");
     Serial.println(inputString.substring(0,2));
     Serial.print("Mobno= ");
   Serial.println(MobNoString);

     
    if(OptionString=="@a")
    {
      digitalWrite(relay1, LOW);
  digitalWrite(relay2, HIGH);
  digitalWrite(relay3, HIGH);
  digitalWrite(relay4, HIGH);
  digitalWrite(relay5, HIGH);
  
      Serial.println("Relay1");
      MsgString="option one selected";
    }

    else if(OptionString=="@b")
    {
       digitalWrite(relay1, HIGH);
  digitalWrite(relay2, LOW);
  digitalWrite(relay3, HIGH);
  digitalWrite(relay4, HIGH);
  digitalWrite(relay5, HIGH);
      Serial.println("Relay2");

       MsgString="option two selected";
    }

    else if(OptionString=="@c")
    {
      digitalWrite(relay1, HIGH);
  digitalWrite(relay2, HIGH);
  digitalWrite(relay3, LOW);
  digitalWrite(relay4, HIGH);
  digitalWrite(relay5, HIGH);
  
      Serial.println("Relay3");
       MsgString="option three selected";
    }

    else if(OptionString=="@d")
    {

       digitalWrite(relay1, HIGH);
  digitalWrite(relay2, HIGH);
  digitalWrite(relay3, HIGH);
  digitalWrite(relay4, LOW);
  digitalWrite(relay5, HIGH);
  
      Serial.println("Relay4");
       MsgString="option four selected";
    }

    else if(OptionString=="@e")
    {
      digitalWrite(relay1, HIGH);
  digitalWrite(relay2, HIGH);
  digitalWrite(relay3, HIGH);
  digitalWrite(relay4, HIGH);
  digitalWrite(relay5, LOW);
  
      Serial.println("Relay5");

       MsgString="option five selected";
    }

    else if(OptionString=="@f")
{
  digitalWrite(relay1, HIGH);
  digitalWrite(relay2, HIGH);
  digitalWrite(relay3, HIGH);
  digitalWrite(relay4, HIGH);
  digitalWrite(relay5, HIGH);
}

else if(OptionString=="@g")
{
  digitalWrite(relay1, LOW);
  digitalWrite(relay2, LOW);
  digitalWrite(relay3, LOW);
  digitalWrite(relay4, LOW);
  digitalWrite(relay5, LOW);
}

MobNoString.trim();
 Serial.println(inputString.length());
    if(inputString.length()==14)
    {
      //SendMessage(MobNoString);

       Serial2.print ("ATD");
       Serial2.print (MobNoString);
       Serial2.println (";\r");
      Serial.println("sending sms to "+MobNoString);
      Serial.println (MsgString);
    }
    // clear the string:
    inputString = "";
    OptionString="";
    stringComplete = false;
  }
}


void serialEvent3() {
   OptionString="";
  while (Serial3.available()) {
    // get the new byte:
    char inChar = (char)Serial3.read();
    //Serial.print(inChar);
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag so the main loop can
    // do something about it:
    if (inChar == '#') {
      // inputString += '\0';
      stringComplete = true;
    }
  }
}
