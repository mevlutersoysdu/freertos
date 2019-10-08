#include <frt.h>

#include <Arduino_FreeRTOS.h>

void vSenderTask( void *pvParameters );
void  vReceiverTask( void *pvParameters );

QueueHandle_t xQueue;

// the setup function runs once when you press reset or power the board
void setup() 
{

  xQueue = xQueueCreate( 5, sizeof( int32_t ) );
  if( xQueue != NULL )
  {
  // Now set up two tasks to run independently.
  //BaseType_t türünde değer döndüren görevler  
   xTaskCreate( 
     vReceiverTask
      ,  (const portCHAR *)"vReceiverTask"   // A name just for humans
      ,  128  // Stack size
      ,  NULL
      ,  3  // priority
      ,  NULL );
    xTaskCreate( 
     vSenderTask
      ,  (const portCHAR *)"sender1"   // A name just for humans
      ,  128  // Stack size
      ,  (void *) 100
      ,  1  // priority
      ,  NULL );
       xTaskCreate( 
     vSenderTask
      ,  (const portCHAR *)"sender2"   // A name just for humans
      ,  128  // Stack size
      ,  (void *) 150
      ,  1  // priority
      ,  NULL );
       xTaskCreate( 
     vSenderTask
      ,  (const portCHAR *)"sender3"   // A name just for humans
      ,  128  // Stack size
      ,  (void *) 200
      ,  1  // priority
      ,  NULL );
       xTaskCreate( 
     vSenderTask
      ,  (const portCHAR *)"sender4"   // A name just for humans
      ,  128  // Stack size
      ,  (void *) 250
      ,  2  // priority
      ,  NULL );
   
   

   
      vTaskStartScheduler();
  }
  else
  {
     Serial.begin(9600);
    Serial.print("Kuyruk oluşmadı");
  }
  // Now the task scheduler, which takes over control of scheduling individual tasks, is automatically started.
}


void loop()
{
  // Empty. Things are done in Tasks.
}

/*--------------------------------------------------*/
/*---------------------- Görev Tanımları ---------------------*/
/*--------------------------------------------------*/

void vSenderTask(void *pvParameters)  // This is a task.
{
  
  //Değişken tanımları
  
  int32_t IValueToSend;
  BaseType_t xStatus;
  IValueToSend=(int32_t) pvParameters;
  Serial.begin(9600);

  for (;;) // 
  {
    xStatus=xQueueSendToBack(xQueue, &IValueToSend, 0);

    if(xStatus!=pdPASS)
    {
      Serial.println("Kuyruğa gönderilemedi");
    }
  }
}
void vReceiverTask(void *pvParameters)  // This is a task.
{
  
  //Değişken tanımları
  
  int32_t IReceivedValue;
  BaseType_t xStatus;
  const TickType_t xTicksToWait=pdMS_TO_TICKS(100);
  
  
  
Serial.begin(9600);
  for (;;) // 
  {
    if( uxQueueMessagesWaiting( xQueue ) != 0 )
      {
        Serial.println("Kuyruk boş olmalı");
        
      }
      xStatus = xQueueReceive( xQueue, &IReceivedValue, xTicksToWait );
      if( xStatus == pdPASS )
      {

        Serial.print( "Received = ");
        Serial.println(IReceivedValue);
      }
      else
      {

        Serial.println( "Kuyruktan alınamadı.\r\n" );
      }
  }
}
