int inPins[8] ={0,1,2,3,4,5,6,7,}; //set the pins for directional input
int outPinsStandard[8] ={8,9,10,A0,A1,A2,A3,A4}; //set output pins for direction
int outPinsGoofy[8] ={A1,A2,A3,A4,8,9,10,A0}; //sets flipped outputs when switch is on
int switchPin = A5; //set the switch pin
int pinState;
  
void setup()
{
  //set all the appropriate pins to input
 for (int i=0; i < 7; ++i) {
    pinMode(inPins[i],INPUT);
    digitalWrite(inPins[i],HIGH);
 }
 //set all the appropriate pins to output
 for (int i = 0; i < 7; ++i) {
    pinMode(outPinsStandard[i],OUTPUT);
 }
   pinMode(switchPin,INPUT);
   digitalWrite(switchPin,LOW);
}


void loop()
{
  //check each pin
  for (int i = 0; i < 7; ++i) {
    //Checks the state of the current pin
    pinState = digitalRead(inPins[i]); 
    //checks if the switch is flipped   
    if (digitalRead(switchPin)){
      //if the switch is flipped the goofy output pin is written
      digitalWrite(outPinsGoofy[i],pinState);
    } else {
      //if the switch is not flipped the standard output pin is written
      digitalWrite(outPinsStandard[i],pinState);
    }
  }
}