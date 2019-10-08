#include <Arduino_FreeRTOS.h>

const TickType_t xDelayMS250 = pdMS_TO_TICKS( 250 );
const TickType_t xDelayMS500 = pdMS_TO_TICKS( 500 );
const TickType_t xDelayMS1000 = pdMS_TO_TICKS( 1000 );
void vTask1(void *pvParameters);
void vTask2(void *pvParameters);

void setup() {
 
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
              3,
              NULL);
              vTaskStartScheduler();//boşta görev aktif edilir
              
}

void loop() {
  // put your main code here, to run repeatedly:

}
void vTask1(void *pvParameters)
{
  TickType_t xLastWakeTime;
  (void) pvParameters;
 const char *pcTaskName="Task1 çalıştı";
  xLastWakeTime = xTaskGetTickCount();
Serial.begin(9600);
  for(;;)
  {
    Serial.println(pcTaskName);

   vTaskDelayUntil( &xLastWakeTime, pdMS_TO_TICKS( 250 ) );
  }
}
void vTask2(void *pvParameters)
{
  TickType_t xLastWakeTime;
  (void) pvParameters;
  const char *pcTaskName="Task2 çalıştı";
 xLastWakeTime = xTaskGetTickCount();
  for(;;)
  {
   Serial.println(pcTaskName);

   vTaskDelayUntil( &xLastWakeTime, pdMS_TO_TICKS( 250 ) );
  }
}

