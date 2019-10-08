#include <Arduino_FreeRTOS.h>
#include <Servo.h>
Servo servo1;
Servo servo2;
Servo servo3;
//void vTaskFunction(void *pvParameters);
static const char *pcTextForTask1="Task1 çalıştı";
static const char *pcTextForTask2="Task2 çalıştı";

void setup() {
  // put your setup code here, to run once:

  xTaskCreate(
    vTaskFunction
    , "task 1"
    , 128
    ,(void*)pcTextForTask1
    ,1
    ,NULL);
    
  // put your setup code here, to run once:
  xTaskCreate(
    vTaskFunction
    , "task 2"
    , 128
    ,(void*)pcTextForTask2
    ,2
    ,NULL);
    servo1.attach(9);
    servo2.attach(10);
    servo3.attach(11);
    
}

void loop() {
  // put your main code here, to run repeatedly:

}
void vTaskFunction(void *pvParameters)
{
  char *pcTaskName;
  Serial.begin(9600);
  pcTaskName=(void *)pvParameters;
  for(;;)
  {
    Serial.println(pcTaskName);
    servo1.write(100);
    servo2.write(100);
    servo3.write(100);
   vTaskDelay(1000/ portTICK_PERIOD_MS);
   servo1.write(20);
   servo2.write(20);
   servo3.write(20);
   vTaskDelay(1000/ portTICK_PERIOD_MS);
  }
}

