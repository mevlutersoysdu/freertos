#include <Arduino_FreeRTOS.h>

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
void setup() {
  // put your setup code here, to run once:
//joystick
pinMode(xPin, INPUT);
pinMode(yPin, INPUT);
pinMode(butonPin, INPUT_PULLUP);

//-------------------
//mesafe sensörü
pinMode(trigPin, OUTPUT); /* trig pini çıkış olarak ayarlandı */
  pinMode(echoPin,INPUT); /* echo pini giriş olarak ayarlandı */
xTaskCreate(  mesafeOku,
              (const portCHAR *)"Task 1",
              100,
              NULL,
              1,
              NULL);
xTaskCreate(  joystickOku,
              (const portCHAR *)"Task 2",
              100,
              NULL,
              2,
              NULL);
              vTaskStartScheduler();
              
}


void loop() {
  // put your main code here, to run repeatedly:

}
void mesafeOku(void *pvParameters)
{
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
  vTaskDelay(500);
}
void joystickOku(void *pvParameters)
{
  xPozisyon = analogRead(xPin);
yPozisyon = analogRead(yPin);
butonDurum = digitalRead(butonPin);
 
Serial.print("X Pozisyonu: ");
Serial.print(xPozisyon);
Serial.print(" | Y Pozisyonu: ");
Serial.print(yPozisyon);
Serial.print(" | Buton Durum: ");
Serial.println(butonDurum);
vTaskDelay(100);
}
