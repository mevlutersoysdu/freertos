#include <frt.h>

#include <Arduino_FreeRTOS.h>

void vSenderTask( void *pvParameters );
void  vReceiverTask( void *pvParameters );

QueueHandle_t xQueue;

typedef enum
{
  eSender1,
  eSender2
}DataSource_t;

typedef struct
{
  uint8_t ucValue;
  DataSource_t eDataSource;
}Data_t;

static const Data_t xStructToSend[2]=
{
  {100,eSender1},
  {200,eSender2}
};



// the setup function runs once when you press reset or power the board
void setup() 
{

  xQueue = xQueueCreate( 3, sizeof( int32_t ) );
  if( xQueue != NULL )
  {
  // Now set up two tasks to run independently.
  //BaseType_t türünde değer döndüren görevler  
   xTaskCreate( 
     vReceiverTask
      ,  (const portCHAR *)"vReceiverTask"   // A name just for humans
      ,  128  // Stack size
      ,  NULL
      ,  1  // priority
      ,  NULL );
    xTaskCreate( 
     vSenderTask
      ,  (const portCHAR *)"sender1"   // A name just for humans
      ,  128  // Stack size
      ,  &(xStructToSend[0])
      ,  2  // priority
      ,  NULL );
       xTaskCreate( 
     vSenderTask
      ,  (const portCHAR *)"sender2"   // A name just for humans
      ,  128  // Stack size
      ,  &(xStructToSend[1])
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
  
  BaseType_t xStatus;
  const TickType_t xTicksToWait=pdMS_TO_TICKS(100);
  for(;;)
  {
    xStatus = xQueueSendToBack( xQueue, pvParameters, xTicksToWait );
    //pvParameters göderilmekte olan struct' ın adresidir.
    //3. parametre görevin blockedda kalma süresini belirler.
    
    if( xStatus != pdPASS )
    {
      Serial.println("Kuyruğa gönderilemedi");
    }
  }
}
void vReceiverTask(void *pvParameters)  // This is a task.
{
  
  //Değişken tanımları
  
  Data_t xReceivedStructure;
  BaseType_t xStatus;
  
  
  
  
Serial.begin(9600);
  for (;;) // 
  {
    if( uxQueueMessagesWaiting( xQueue ) != 3 )
      {
        Serial.println("Kuyruk dolu olmalı");
        
      }
      xStatus = xQueueReceive( xQueue, &xReceivedStructure, 0 );
      if( xStatus == pdPASS )
      {

        if( xReceivedStructure.eDataSource == eSender1 )
        {
          Serial.print( "From Sender 1 = ");
          Serial.println(xReceivedStructure.ucValue );
        }
        else
        {
          Serial.print( "From Sender 2 = ");
          Serial.println(xReceivedStructure.ucValue );
        }
      }
      else 
      { 
        /* Nothing was received from the queue. This must be an error as this
        task should only run when the queue is full. */
        Serial.println( "değer kuyruktan okunamadı.\r\n" );
      }
  }
}
