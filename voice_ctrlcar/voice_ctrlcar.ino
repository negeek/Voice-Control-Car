String readvoice;
int mA1=5;
int mA2=6;
int mB1=11;
int mB2=10;

void setup() {
// BT.begin(9600);
 Serial.begin(9600);
pinMode(mA1, OUTPUT);
pinMode(mA2, OUTPUT);
pinMode(mB1, OUTPUT);
pinMode(mB2, OUTPUT);

}
void forward(){
  digitalWrite(mA1, HIGH);
digitalWrite(mA2, LOW);
digitalWrite(mB1, HIGH);
digitalWrite(mB2, LOW);
}
void back(){
  
digitalWrite(mA1, LOW);
digitalWrite(mA2, HIGH);
digitalWrite(mB1, LOW);
digitalWrite(mB2, HIGH);
}
void stopp(){
  digitalWrite(mA1, LOW);
digitalWrite(mA2, LOW);
digitalWrite(mB1, LOW);
digitalWrite(mB2, LOW);
}

void left(){
 digitalWrite(mA1, HIGH);

delay(1000);
 digitalWrite(mA1, HIGH);
//digitalWrite(mA2, LOW);
digitalWrite(mB1, HIGH);
//digitalWrite(mB2, LOW);
}
void right(){
  digitalWrite(mB1, HIGH);
//digitalWrite(mB2, LOW);

delay(1000);

  digitalWrite(mA1, HIGH);
//digitalWrite(mA2, LOW);
digitalWrite(mB1, HIGH); 
//digitalWrite(mB2, LOW);
}
//-----------------------------------------------------------------------// 
void loop() {
  while (Serial.available()){  //Check if there is an available byte to read
  delay(10); //Delay added to make thing stable
  char c = Serial.read(); //Conduct a serial read
  readvoice += c; 
  } 
  if (readvoice.length() > 0) {
    Serial.println(readvoice);

  if(readvoice == "forward")
  {
    forward();
  }

  else if(readvoice == "back")
  {
   back();
  }

  else if (readvoice == "left")
  {
    
   left();
  }

 else if ( readvoice == "right")
 {
  right(); 
 }

 else if (readvoice == "stop")
 {
  stopp(); 
 }


 readvoice="";}} //Reset the variable
