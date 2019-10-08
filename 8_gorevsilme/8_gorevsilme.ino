#include <Arduino_FreeRTOS.h>
TaskHandle_t xTask2Handle = NULL;
const TickType_t xDelay100ms = pdMS_TO_TICKS( 100UL );
void setup() {
  // put your setup code here, to run once:
  xTaskCreate(
    vTask1
    , "Task 1"
    , 128
    , NULL //parametre
    , 1
    ,NULL);

     
 xTaskCreate(
    vTask2
    , "Task 2"
    , 128
    , NULL //parametre
    , 2
    ,&xTask2Handle);
    
    vTaskStartScheduler();
    
}

void loop() {
  // put your main code here, to run repeatedly:

}

void vTask1(void *pvParameters)
{
 
  
  Serial.begin(9600);
  
  for(;;)
  {
   Serial.println("Task1 çalıştı");
   
   vTaskDelay( xDelay100ms );
   
   
  }
}
void vTask2(void *pvParameters)
{
  
  Serial.begin(9600);
  for(;;)
  {
   Serial.println("Task2 çalıştı");
   vTaskDelay( xDelay100ms );
   vTaskDelete(NULL);
   Serial.println("......");
  }
}

