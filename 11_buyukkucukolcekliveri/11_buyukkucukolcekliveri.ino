#include <frt.h>
#include <Arduino_FreeRTOS.h>


  void vSenderTask1( void *pvParameters );
  void vSenderTask2( void *pvParameters );
  void  vReceiverTask( void *pvParameters );

  static QueueHandle_t xQueue1 = NULL, xQueue2 = NULL;
  static QueueSetHandle_t xQueueSet = NULL;

void setup() 
{
  xQueue1=xQueueCreate(1, sizeof(char *));
  xQueue2=xQueueCreate(1, sizeof (char *));

  xQueueSet=xQueueCreateSet(1*2);

 xQueueAddToSet( xQueue1, xQueueSet );
xQueueAddToSet( xQueue2, xQueueSet );
  
  xTaskCreate( vSenderTask1, "sender1",128,NULL,1,NULL);
   xTaskCreate( vSenderTask2, "sender1",128,NULL,1,NULL);

   xTaskCreate( vReceiverTask, "receiver",128,NULL,2,NULL);
   

   
      vTaskStartScheduler();
  }
 
 


void loop()
{
  // Empty. Things are done in Tasks.
}

/*--------------------------------------------------*/
/*---------------------- Görev Tanımları ---------------------*/
/*--------------------------------------------------*/

void vSenderTask1(void *pvParameters)  // This is a task.
{
  
  const TickType_t xBlockTime = pdMS_TO_TICKS( 100 );
const char * const pcMessage = "Message from vSenderTask1\r\n";

for(;;)
{
  vTaskDelay(xBlockTime);
  xQueueSend(xQueue1,&pcMessage,0);
}
}

void vSenderTask2(void *pvParameters)  // This is a task.
{
  
  const TickType_t xBlockTime = pdMS_TO_TICKS( 200 );
const char * const pcMessage = "Message from vSenderTask2\r\n";

for(;;)
{
  vTaskDelay(xBlockTime);
  xQueueSend(xQueue2,&pcMessage,0);
}
}
void vReceiverTask(void *pvParameters)  
{
  QueueHandle_t xQueueThatContainsData;
  char *pcReceivedString;
  for( ;; )
  {

    xQueueThatContainsData = ( QueueHandle_t ) xQueueSelectFromSet( xQueueSet,portMAX_DELAY );
    xQueueReceive( xQueueThatContainsData, &pcReceivedString, 0 );
    Serial.println(pcReceivedString);
  }
}
