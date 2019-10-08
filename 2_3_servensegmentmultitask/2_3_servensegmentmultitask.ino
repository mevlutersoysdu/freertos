#include <Arduino_FreeRTOS.h>

int trigPin = 12; /* Sensorun trig pini Arduinonun 6 numaralı ayağına bağlandı */
int echoPin = 13;  /* Sensorun echo pini Arduinonun 7 numaralı ayağına bağlandı */

long sure;
long uzaklik;

void setup() {
  // put your setup code here, to run once:
pinMode(2, OUTPUT); //Segmentde "A" kısmı
  pinMode(3, OUTPUT); //Segmentde "B" kısmı
  pinMode(4, OUTPUT); //Segmentde "C" kısmı
  pinMode(5, OUTPUT); //Segmentde "D" kısmı
  pinMode(6, OUTPUT); //Segmentde "E" kısmı
  pinMode(7, OUTPUT); //Segmentde "F" kısmı
  pinMode(8, OUTPUT); //Segmentde "G" kısmı
  pinMode(9, OUTPUT); //Segmentde "DP" kısmı (Nokta kısmı)

pinMode(trigPin, OUTPUT); /* trig pini çıkış olarak ayarlandı */
  pinMode(echoPin,INPUT); /* echo pini giriş olarak ayarlandı */
  Serial.begin(9600); /* Seri haberlesme baslatildi */
xTaskCreate(
    vTaskDisplay
    , "task 1"
    , 128
    ,NULL
    ,1
    ,NULL);
    
  // put your setup code here, to run once:
  xTaskCreate(
    vTaskMesafe
    , "task 2"
    , 128
    ,NULL
    ,2
    ,NULL);
    
}

void loop() {
  // put your main code here, to run repeatedly:

}
void vTaskDisplay(void *pvParameters)
{
   byte seven_seg_digits[10][8] = { 
  { 0,0,0,0,0,0,1,1 },  // = 0
  { 1,0,0,1,1,1,1,1 },  // = 1
  { 0,0,1,0,0,1,0,1 },  // = 2
  { 0,0,0,0,1,1,0,1 },  // = 3
  { 1,0,0,1,1,0,0,1 },  // = 4
  { 0,1,0,0,1,0,0,1 },  // = 5
  { 0,1,0,0,0,0,0,1 },  // = 6
  { 0,0,0,1,1,1,1,1 },  // = 7
  { 0,0,0,0,0,0,0,1 },  // = 8
  { 0,0,0,1,1,0,0,1 }   // = 9
};
 for(;;)
  {
    for (byte count = 10; count > 0; --count) 
    {
      byte pin = 2;
      for (byte segCount = 0; segCount < 8; ++segCount) 
      {
        digitalWrite(pin, seven_seg_digits[count][segCount]);
        ++pin;
      }
      vTaskDelay(1000/ portTICK_PERIOD_MS);
    }
  }
}
void vTaskMesafe(void *pvParameters)
{
  for(;;)
  {
    digitalWrite(trigPin, LOW); /* sensör pasif hale getirildi */
    vTaskDelay(5/ portTICK_PERIOD_MS);
    digitalWrite(trigPin, HIGH); /* Sensore ses dalgasının üretmesi için emir verildi */
    vTaskDelay(10/ portTICK_PERIOD_MS);
    digitalWrite(trigPin, LOW);  /* Yeni dalgaların üretilmemesi için trig pini LOW konumuna getirildi */ 
    sure = pulseIn(echoPin, HIGH); /* ses dalgasının geri dönmesi için geçen sure ölçülüyor */
    uzaklik= sure /29.1/2; /* ölçülen sure uzaklığa çevriliyor */            
    if(uzaklik > 200)
      uzaklik = 200;
    Serial.print("Uzaklik ");  
    Serial.print(uzaklik); /* hesaplanan uzaklık bilgisayara aktarılıyor */
    Serial.println(" CM olarak olculmustur.");  
    vTaskDelay(500/ portTICK_PERIOD_MS);
  }
}
