#include <Arduino_FreeRTOS.h>



//TickType_t xTimeInTicks = pdMS_TO_TICKS( 3000 );
void vTask1(void *pvParameters);
void vTask2(void *pvParameters);

void setup() {
  // put your setup code here, to run once:
xTaskCreate(  vTask1,
              (const portCHAR *)"Task 1",
              100,
              NULL,
              1,
              NULL);
xTaskCreate(  vTask2,
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
void vTask1(void *pvParameters)
{
  (void) pvParameters;
 const char *pcTaskName="Task1 çalıştı";
Serial.begin(9600);
  for(;;)
  {
    Serial.println(pcTaskName);

   vTaskDelay(1000/ portTICK_PERIOD_MS);
  }
}
void vTask2(void *pvParameters)
{
  (void) pvParameters;
  const char *pcTaskName="Task2 çalıştı";

  for(;;)
  {
   Serial.println(pcTaskName);

   vTaskDelay(1000/ portTICK_PERIOD_MS);
  }
}

