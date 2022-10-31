String inputString = "";         // a String to hold incoming data
String OptionString="";
String MobNoString="";

bool stringComplete = false;  // whether the string is complete

void setup() {
  // initialize serial: @a,1234567890F#
  Serial.begin(9600);
  // reserve 200 bytes for the inputString:
  inputString.reserve(200);
}

void loop() {
  // print the string when a newline arrives:
  if (stringComplete) {
    Serial.println(inputString);
    OptionString=inputString.substring(0,2);
   
    MobNoString=inputString.substring(3,13);
     Serial.println(OptionString);
    Serial.println(MobNoString);
    
    if(OptionString=="@a")
    {
      Serial.println("Relay1");
    }
    
    // clear the string:
    inputString = "";
    stringComplete = false;
  }
}


void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag so the main loop can
    // do something about it:
    if (inChar == '#') {
      stringComplete = true;
    }
  }
}
