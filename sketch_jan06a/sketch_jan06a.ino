////
/*
Program ktory przelacza dwie diody led
komendy wysyla sie portem szergowym
*/
////
#define Led1 10
#define Led2 2

//struktura do przechowywania danych, dodana dla uproszczenia przesylania danych
struct dataLogic{
  bool switchLed1;
  bool switchLed2;
} dataS = {false,false};

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

//przelacznik ledow
void ledSwitch(){
  String rxData = Serial.readStringUntil('\n');
  //sterowanie dioda 1
  if(rxData == "led1"){
    if(dataS.switchLed1){
      digitalWrite(Led1,LOW);
      dataS.switchLed1 = false;
    }
    else{
      digitalWrite(Led1,HIGH);
      dataS.switchLed1 = true;
    }
  }
  //sterowanie dioda 2
  else if(rxData == "led2"){
    if(dataS.switchLed2){
      digitalWrite(Led2,LOW);
      dataS.switchLed2 = false;
    }
    else{
      digitalWrite(Led2,HIGH);
      dataS.switchLed2 = true;
    }
  }
  else
    Serial.println("EXCEPTION: BAD COMMAND!");
  
  //wysylanie ramki z stanami diod    <-TBD
  sendFrame(&dataS);  
}

//Tu bedzie wysylanie ramki z danymi <-TBD
void sendFrame(const struct dataLogic * dataS){
  //Serial.println(dataS->switchLed1);
  //Serial.println(dataS->switchLed2);
  int frame = dataS->switchLed1;
  frame = frame<<1;
  frame = frame | dataS->switchLed2;
  Serial.println(frame);
}
