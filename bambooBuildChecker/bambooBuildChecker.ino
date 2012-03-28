int successPin = 8;
int buildingPin = 9;
int failPin = 10;
int val;

void setup()
{
 pinMode(successPin, OUTPUT); // sets the digital pin as output
 pinMode(buildingPin, OUTPUT); // sets the digital pin as output
 pinMode(failPin, OUTPUT); // sets the digital pin as output
 Serial.begin(9600);
 Serial.flush();
}

void loop()
{
  if (Serial.available())
  {
    val = Serial.read();
   
    if (val == 110) // n = 110 in dec
    {
      building();
    }
    else if (val == 109) //109 = m in dec
    {
      fail(); 
    }
    else if (val == 108)
    { 
      succeed();     
    }
    else
    {
      allOff();           
    } 
  }
}

void fail() {
  digitalWrite(buildingPin, LOW);
  digitalWrite(successPin, LOW);
  digitalWrite(failPin, HIGH);   
}

void succeed() {
  digitalWrite(buildingPin, LOW);
  digitalWrite(successPin, HIGH);
  digitalWrite(failPin, LOW);   
}

void building() {

  digitalWrite(buildingPin, HIGH);
  digitalWrite(successPin, LOW);
  digitalWrite(failPin, LOW);
}

void allOff() {
  digitalWrite(buildingPin, LOW);
  digitalWrite(successPin, LOW);
  digitalWrite(failPin, LOW);   
}
