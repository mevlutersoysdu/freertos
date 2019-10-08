/*#include <Wire.h>
#include <Adafruit_MMA8451.h>
#include <Adafruit_Sensor.h>
*/
//joystick
int xPin = A0; 
int yPin = A1; 
int butonPin = 2; 
 
int xPozisyon;
int yPozisyon;
int butonDurum;
 //--------------------
 //mesafe sensörü
 int trigPin = 11; /* Sensorun trig pini Arduinonun 6 numaralı ayağına bağlandı */
int echoPin = 10;  /* Sensorun echo pini Arduinonun 7 numaralı ayağına bağlandı */

long sure;
long uzaklik;

//---------------------
//accelometer
//Adafruit_MMA8451 mma = Adafruit_MMA8451();

void setup() {
Serial.begin(9600);
//joystick
pinMode(xPin, INPUT);
pinMode(yPin, INPUT);
pinMode(butonPin, INPUT_PULLUP);

//-------------------
//mesafe sensörü
pinMode(trigPin, OUTPUT); /* trig pini çıkış olarak ayarlandı */
  pinMode(echoPin,INPUT); /* echo pini giriş olarak ayarlandı */

  //accelometer
/*
  Serial.println("Adafruit MMA8451 test!");
  

  if (! mma.begin()) {
    Serial.println("Couldnt start");
    while (1);
  }
  Serial.println("MMA8451 found!");
  
  mma.setRange(MMA8451_RANGE_2_G);
  
  Serial.print("Range = "); Serial.print(2 << mma.getRange());  
  Serial.println("G");

  */
}
 
void loop() {
xPozisyon = analogRead(xPin);
yPozisyon = analogRead(yPin);
butonDurum = digitalRead(butonPin);
 
Serial.print("X Pozisyonu: ");
Serial.print(xPozisyon);
Serial.print(" | Y Pozisyonu: ");
Serial.print(yPozisyon);
Serial.print(" | Buton Durum: ");
Serial.println(butonDurum);
delay(100);

//---------mesafe sensörü 
digitalWrite(trigPin, LOW); /* sensör pasif hale getirildi */
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH); /* Sensore ses dalgasının üretmesi için emir verildi */
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);  /* Yeni dalgaların üretilmemesi için trig pini LOW konumuna getirildi */ 
  sure = pulseIn(echoPin, HIGH); /* ses dalgasının geri dönmesi için geçen sure ölçülüyor */
  uzaklik= sure /29.1/2; /* ölçülen sure uzaklığa çevriliyor */            
  if(uzaklik > 200)
    uzaklik = 200;
  Serial.print("Uzaklik ");  
  Serial.print(uzaklik); /* hesaplanan uzaklık bilgisayara aktarılıyor */
  Serial.println(" CM olarak olculmustur.");  
  delay(500);
  //accelometer

/*
   // Read the 'raw' data in 14-bit counts
  mma.read();
  Serial.print("X:\t"); Serial.print(mma.x); 
  Serial.print("\tY:\t"); Serial.print(mma.y); 
  Serial.print("\tZ:\t"); Serial.print(mma.z); 
  Serial.println();

  /* Get a new sensor event */ 
//  sensors_event_t event; 
  //mma.getEvent(&event);

  /* Display the results (acceleration is measured in m/s^2) */
 /* Serial.print("X: \t"); Serial.print(event.acceleration.x); Serial.print("\t");
  Serial.print("Y: \t"); Serial.print(event.acceleration.y); Serial.print("\t");
  Serial.print("Z: \t"); Serial.print(event.acceleration.z); Serial.print("\t");
  Serial.println("m/s^2 ");
  
  /* Get the orientation of the sensor 
  uint8_t o = mma.getOrientation();
  
  switch (o) {
    case MMA8451_PL_PUF: 
      Serial.println("Portrait Up Front");
      break;
    case MMA8451_PL_PUB: 
      Serial.println("Portrait Up Back");
      break;    
    case MMA8451_PL_PDF: 
      Serial.println("Portrait Down Front");
      break;
    case MMA8451_PL_PDB: 
      Serial.println("Portrait Down Back");
      break;
    case MMA8451_PL_LRF: 
      Serial.println("Landscape Right Front");
      break;
    case MMA8451_PL_LRB: 
      Serial.println("Landscape Right Back");
      break;
    case MMA8451_PL_LLF: 
      Serial.println("Landscape Left Front");
      break;
    case MMA8451_PL_LLB: 
      Serial.println("Landscape Left Back");
      break;
    }
  Serial.println();
  delay(500);*/
}
