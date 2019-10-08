#include <Arduino_FreeRTOS.h>
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
   vTaskDelay(1000/ portTICK_PERIOD_MS);
  }
}

