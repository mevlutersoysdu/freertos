#include <Arduino_FreeRTOS.h>


void vGorev1(void *pvParameters);
void vGorev2(void *pvParameters);
void vGorev3(void *pvParameters);
void vGorev4(void *pvParameters);
bool durum=false;
void setup() {
  // put your setup code here, to run once:
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  
xTaskCreate(  vGorev1,
              (const portCHAR *)"Gorev 1",
              100,
              NULL,
              1,
              NULL);
xTaskCreate(  vGorev2,
              (const portCHAR *)"Gorev 2",
              100,
              NULL,
              2,
              NULL);
xTaskCreate(  vGorev3,
              (const portCHAR *)"Gorev 3",
              100,
              NULL,
              3,
              NULL);
xTaskCreate(  vGorev4,
              (const portCHAR *)"Gorev 4",
              100,
              NULL,
              4,
              NULL);
              
}

void loop() {
  // put your main code here, to run repeatedly:

}
void vGorev1(void *pvParameters)
{
  TickType_t xLastWakeTime;
  xLastWakeTime = xTaskGetTickCount();
  Serial.begin(9600);
  (void) pvParameters;
  for(;;)
  {
    if (durum==false)
    {
      vTaskDelay(1000/ portTICK_PERIOD_MS);
    }
    digitalWrite(2,LOW);
    
    Serial.println("Görev1");
    vTaskDelay(3000/ portTICK_PERIOD_MS);
    //vTaskDelayUntil( &xLastWakeTime, 1000/ portTICK_PERIOD_MS );
    digitalWrite(2,HIGH);
     vTaskDelay(1000/ portTICK_PERIOD_MS);
     //vTaskDelayUntil( &xLastWakeTime, 4000/ portTICK_PERIOD_MS );
    durum=true;
  }
}

void vGorev2(void *pvParameters)
{
   TickType_t xLastWakeTime;
  xLastWakeTime = xTaskGetTickCount();
  Serial.begin(9600);
  (void) pvParameters;
  for(;;)
  {
    if (durum==false)
    {
      vTaskDelay(2000/ portTICK_PERIOD_MS);
    }
    digitalWrite(3,LOW);
    
    Serial.println("Görev2");
    vTaskDelay(3000/ portTICK_PERIOD_MS);
    //vTaskDelayUntil( &xLastWakeTime, 2000/ portTICK_PERIOD_MS );
  
    digitalWrite(3,HIGH);
    //vTaskDelayUntil( &xLastWakeTime, 6000/ portTICK_PERIOD_MS );
  
     vTaskDelay(1000/ portTICK_PERIOD_MS);
     durum=true;
  }
}

void vGorev3(void *pvParameters)
{
   TickType_t xLastWakeTime;
  xLastWakeTime = xTaskGetTickCount();
  Serial.begin(9600);
  (void) pvParameters;
  for(;;)
  {
    if (durum==false)
    {
      vTaskDelay(3000/ portTICK_PERIOD_MS);
    }
    digitalWrite(4,LOW);
    
    Serial.println("Görev3");
    //vTaskDelayUntil( &xLastWakeTime, 3000/ portTICK_PERIOD_MS );
  
    vTaskDelay(3000/ portTICK_PERIOD_MS);
    digitalWrite(4,HIGH);
    //vTaskDelayUntil( &xLastWakeTime, 7000/ portTICK_PERIOD_MS );
  
     vTaskDelay(1000/ portTICK_PERIOD_MS);
     durum=true;
  }
}

void vGorev4(void *pvParameters)
{
   TickType_t xLastWakeTime;
  xLastWakeTime = xTaskGetTickCount();
  Serial.begin(9600);
  (void) pvParameters;
  for(;;)
  {
    if (durum==false)
    {
      vTaskDelay(4000/ portTICK_PERIOD_MS);
    }
    digitalWrite(5,LOW);
    Serial.println("Görev4");
    //vTaskDelayUntil( &xLastWakeTime, 4000/ portTICK_PERIOD_MS );
  
    vTaskDelay(3000/ portTICK_PERIOD_MS);
    digitalWrite(5,HIGH);
    //vTaskDelayUntil( &xLastWakeTime, 8000/ portTICK_PERIOD_MS );
  
     vTaskDelay(1000/ portTICK_PERIOD_MS);
     durum=true;
  }
}
