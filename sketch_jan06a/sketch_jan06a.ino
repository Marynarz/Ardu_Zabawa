////
/*
Program switch on or off led, if receive command "led1" or "led2" on serial port.
*/
////
#define Led1 10
#define Led2 2
bool switchLed1 = false;
bool switchLed2 = false;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("---PIERWSZY PROGRAM---");
  pinMode(Led1,OUTPUT);
  pinMode(Led2,OUTPUT);
  
  digitalWrite(Led1,LOW);
  digitalWrite(Led2,LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available() >0)
    ledSwitch();
  
}

void ledSwitch(){
  String rxData = Serial.readStringUntil('\n');
  if(rxData == "led1"){
    if(switchLed1){
      digitalWrite(Led1,LOW);
      switchLed1 = false;
    }
    else{
      digitalWrite(Led1,HIGH);
      switchLed1 = true;
    }
  }
  else if(rxData == "led2"){
    if(switchLed2){
      digitalWrite(Led2,LOW);
      switchLed2 = false;
    }
    else{
      digitalWrite(Led2,HIGH);
      switchLed2 = true;
    }
  }
  else
    Serial.println("EXCEPTION: BAD COMMAND!");  
}
