#include <Arduino_FreeRTOS.h>
TaskHandle_t xTask2Handle = NULL;

void setup() {
  // put your setup code here, to run once:
  xTaskCreate(
    vTask1
    , "Task 1"
    , 128
    , NULL //parametre
    , 2
    ,NULL);

      xTaskCreate(
    vTask2
    , "Task 2"
    , 128
    , NULL //parametre
    , 1
    ,&xTask2Handle);

    vTaskStartScheduler();
    
}

void loop() {
  // put your main code here, to run repeatedly:

}

void vTask1(void *pvParameters)
{
  UBaseType_t uxPriority;
  uxPriority=uxTaskPriorityGet(NULL);
  
  Serial.begin(9600);
  
  for(;;)
  {
   Serial.println("Task1 çalıştı");
   Serial.println("Task2 önceliği değişti");
   vTaskPrioritySet(xTask2Handle,(uxPriority+1));
   
  }
}
void vTask2(void *pvParameters)
{
  UBaseType_t uxPriority;
  q
  Serial.begin(9600);
  for(;;)
  {
   Serial.println("Task2 çalıştı");
   Serial.println("Task2 önceliği düşürülyor");
   vTaskPrioritySet(NULL,(uxPriority-2));
   
  }
}
