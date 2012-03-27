// led wired + to pin 12, resistor to positive +5v

int successPin = 8; // Output connected to digital pin 12
int buildingPin = 9; // Output connected to digital pin 12
int failPin = 10; // Output connected to digital pin 12
int mail = LOW; // Is there new mail?
int val; // Value read from the serial port
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
 // Read from serial port
 if (Serial.available())
 {
   val = Serial.read();

   if (val == 110) // n = 110 in dec
   {
     digitalWrite(buildingPin, HIGH);
     digitalWrite(successPin, LOW);
     digitalWrite(failPin, LOW);
   }
   else if (val == 109) //109 = m in dec
   {
     digitalWrite(buildingPin, LOW);
     digitalWrite(successPin, LOW);
     digitalWrite(failPin, HIGH);   
   }
   else if (val == 108)
   {
     digitalWrite(buildingPin, LOW);
     digitalWrite(successPin, HIGH);
     digitalWrite(failPin, LOW);        
   } 
 }
 

 // Set the status of the output pin
 delay(10);
}

