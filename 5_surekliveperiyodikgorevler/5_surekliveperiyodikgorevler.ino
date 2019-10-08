  #include <Arduino_FreeRTOS.h>
void vSurekliTask(void *pvParameters);
void vPeriyodikTask(void *pvParameters);
static const char *pcTextForTask1="Surekli Görev1 çalıştı";
static const char *pcTextForTask2="Surekli Görev2 çalıştı";
static const char *pcTextForTask3="Periyodik Görev çalıştı";

void setup() {
  

  xTaskCreate(
    vSurekliTask
    , "task 1"
    , 128
    ,(void*)pcTextForTask1
    ,1
    ,NULL);
    
  
  xTaskCreate(
    vSurekliTask
    , "task 2"
    , 128
    ,(void*)pcTextForTask2
    ,2
    ,NULL);

    
    xTaskCreate(
    vPeriyodikTask
    , "task 3"
    , 128
    ,(void*)pcTextForTask3
    ,2
    ,NULL);
    
}

void loop() {
  // put your main code here, to run repeatedly:

}
void vSurekliTask(void *pvParameters)
{
  char *pcTaskName;
  TickType_t xLastWakeTime;
  const TickType_t xDelay10ms=pdMS_TO_TICKS(1000);
  int i;
  Serial.begin(9600);
  pcTaskName=(char *)pvParameters;
  for(;;)
  {
    //vTaskDelay(xDelay10ms);
    
    //xLastWakeTime=xTaskGetTickCount();
    Serial.print(xLastWakeTime);
    Serial.println(pcTaskName);
   
   
  }
}
void vPeriyodikTask(void *pvParameters)
{
  TickType_t xLastWakeTime;
  const TickType_t xDelay3ms=pdMS_TO_TICKS(1000);
  char *pcTaskName;
  int i;
  Serial.begin(9600);
  pcTaskName=(char *)pvParameters;
  xLastWakeTime=xTaskGetTickCount();
  for(;;)
  {
      vTaskDelayUntil(&xLastWakeTime,xDelay3ms);
    
   
     Serial.print(xLastWakeTime);
    Serial.println(pcTaskName);
   
  
    /*Bu görev her 100ms de bir yürütülür. 
     *xLastWeekTime ms yi tick türüne dönüştürmek için kullanılır
     */
      
    }
}


