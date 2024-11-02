unsigned long startMillis=0;
unsigned long currentMillis=0;
float Voltage1 = 0.0;
float filteredValue1 = 0.0;
float Voltage2 = 0.0;
float filteredValue2 = 0.0;
float Voltage3 = 0.0;
void setup() {
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT); 
  pinMode(5, OUTPUT); 
  Serial.begin(115200);
  startMillis = millis();
}
void loop() {
  
  int flow = 150; // 110 - 255, 0 - 5V
  float control = flow * 5/255;

  currentMillis = millis();

  for (int i = 0; i < 50; i++) {
       filteredValue1 += analogRead(A0);
       delayMicroseconds(100);
  }
  filteredValue1 /= 50;

  for (int i = 0; i < 50; i++) {
       filteredValue2 += analogRead(A1);
       delayMicroseconds(100);
  }
  filteredValue2 /= 50;
 
  if (currentMillis - startMillis <= 2000)  
  {digitalWrite(3,HIGH);
   digitalWrite(4,HIGH);
   analogWrite(5,flow);
   
  //  Serial.print("pump on & valve off "); 
  }

  if (currentMillis - startMillis > 2000 && currentMillis - startMillis < 5000)  
  {digitalWrite(3,LOW);
   digitalWrite(4,LOW);
   digitalWrite(5,0);
  //  Serial.print("pump off & valve on ");    
  }
  
  if (currentMillis - startMillis >= 5000)
  {startMillis = currentMillis;}

  currentMillis = currentMillis / 1000.0;
  Voltage1 = (filteredValue1 * 5.0) / 1024.0 ;
  Voltage2 = (filteredValue2 * 5.0) / 1024.0 ;
  Voltage3 = Voltage2 - Voltage1 ;

  // Serial.print(control);
  // Serial.print(" ");
  Serial.println(Voltage1);
  delay(10); 

}
