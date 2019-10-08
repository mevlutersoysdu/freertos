#include <Arduino_FreeRTOS.h>
static const char *pcTextForTask=" Görev1 çalıştı";
volatile uint32_t ulIdleCycleCount = 0ul;
void vTaskFunction(void *pvParameters);
void vApplicationIdleHook( void )
{
  ulIdleCycleCount++;
}
void setup() {
  // put your setup code here, to run once:
xTaskCreate(
  vTaskFunction
  ,"Task 1"
  ,128
  ,(void *)pcTextForTask
  ,1
  ,NULL);

  vTaskStartScheduler();
}

void loop() {
  // put your main code here, to run repeatedly:

}
void vTaskFunction(void *pvParameters)
{
  char *pcTaskName;
  const TickType_t xDelay250ms=pdMS_TO_TICKS(250);
  Serial.begin(9600);
  pcTaskName=(char *) pvParameters;
  for(;;)
  {
    Serial.print(pcTaskName);
  Serial.println(ulIdleCycleCount);
//vPrintStringAndNumber( pcTaskName, ulIdleCycleCount );
    vTaskDelay(xDelay250ms);
  }
}

