
int trigPin = 12; /* Sensorun trig pini Arduinonun 6 numaralı ayağına bağlandı */
int echoPin = 13;  /* Sensorun echo pini Arduinonun 7 numaralı ayağına bağlandı */

long sure;
long uzaklik;


void setup() {               
  
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
}

void loop() {
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
  
  
 // "9" Sayısını yazar.
 digitalWrite(2, 0);
 digitalWrite(3, 0);
 digitalWrite(4, 0);
 digitalWrite(5, 1);
 digitalWrite(6, 1);
 digitalWrite(7, 0);
 digitalWrite(8, 0);
 digitalWrite(9, 1);
 delay(1000);
 // "8" Sayısını yazar.
 digitalWrite(2, 0);
 digitalWrite(3, 0);
 digitalWrite(4, 0);
 digitalWrite(5, 0);
 digitalWrite(6, 0);
 digitalWrite(7, 0);
 digitalWrite(8, 0);
 digitalWrite(9, 1);
 delay(1000);
 // "7" Sayısını yazar.
 digitalWrite(2, 0);
 digitalWrite(3, 0);
 digitalWrite(4, 0);
 digitalWrite(5, 1);
 digitalWrite(6, 1);
 digitalWrite(7, 1);
 digitalWrite(8, 1);
 digitalWrite(9, 1);
 delay(1000);
 // "6" Sayısını yazar.
 digitalWrite(2, 0);
 digitalWrite(3, 1);
 digitalWrite(4, 0);
 digitalWrite(5, 0);
 digitalWrite(6, 0);
 digitalWrite(7, 0);
 digitalWrite(8, 0);
 digitalWrite(9, 1);
 delay(1000);
 // "5" Sayısını yazar.
 digitalWrite(2, 0);
 digitalWrite(3, 1);
 digitalWrite(4, 0);
 digitalWrite(5, 0);
 digitalWrite(6, 1);
 digitalWrite(7, 0);
 digitalWrite(8, 0);
 digitalWrite(9, 1);
 delay(1000);
 // "4" Sayısını yazar.
 digitalWrite(2, 1);
 digitalWrite(3, 0);
 digitalWrite(4, 0);
 digitalWrite(5, 1);
 digitalWrite(6, 1);
 digitalWrite(7, 0);
 digitalWrite(8, 0);
 digitalWrite(9, 1);
 delay(1000);
 // "3" Sayısını yazar.
 digitalWrite(2, 0);
 digitalWrite(3, 0);
 digitalWrite(4, 0);
 digitalWrite(5, 0);
 digitalWrite(6, 1);
 digitalWrite(7, 1);
 digitalWrite(8, 0);
 digitalWrite(9, 1);
 delay(1000);
 // "2" Sayısını yazar.
 digitalWrite(2, 0);
 digitalWrite(3, 0);
 digitalWrite(4, 1);
 digitalWrite(5, 0);
 digitalWrite(6, 0);
 digitalWrite(7, 1);
 digitalWrite(8, 0);
 digitalWrite(9, 1);
 delay(1000);
 // "1" Sayısını yazar.
 digitalWrite(2, 1);
 digitalWrite(3, 0);
 digitalWrite(4, 0);
 digitalWrite(5, 1);
 digitalWrite(6, 1);
 digitalWrite(7, 1);
 digitalWrite(8, 1);
 digitalWrite(9, 1);
 delay(1000);
 // "0" Sayısını yazar.
 digitalWrite(2, 0);
 digitalWrite(3, 0);
 digitalWrite(4, 0);
 digitalWrite(5, 0);
 digitalWrite(6, 0);
 digitalWrite(7, 0);
 digitalWrite(8, 1);
 digitalWrite(9, 1);
 delay(1000);

   // Sadece "nokta" yazar.
 digitalWrite(2, 1);
 digitalWrite(3, 1);
 digitalWrite(4, 1);
 digitalWrite(5, 1);
 digitalWrite(6, 1);
 digitalWrite(7, 1);
 digitalWrite(8, 1);
 digitalWrite(9, 0);
 delay(1000);
  // Hiçbir şey yazmaz. 
 digitalWrite(2, 1);
 digitalWrite(3, 1);
 digitalWrite(4, 1);
 digitalWrite(5, 1);
 digitalWrite(6, 1);
 digitalWrite(7, 1);
 digitalWrite(8, 1);
 digitalWrite(9, 1);
 delay(1000);
   

 }
