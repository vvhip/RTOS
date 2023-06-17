#include<Arduino_FreeRTOS.h>
#include<queue.h>

QueueHandle_t queue;

TaskHandle_t Htask1;
TaskHandle_t Htask2;

void setup(){
  Serial.begin(9600);
  queue = xQueueCreate(3,sizeof(char *));
  if(queue != NULL){
    xTaskCreate(Task1,"Task1",256,NULL,1,&Htask1);
    xTaskCreate(Task2,"Task2",256,NULL,1,&Htask2);

    vTaskStartScheduler();
  }
}

void loop(){}

void Task1(void *pvParameters){
  char * string1  = "XIN CHAO";
  char * string2 = "Arduino";
  char * string3 = "FreeRTOS";

  xQueueSendToFront(queue, &string1 , 0);
  xQueueSendToFront(queue,&string2 ,0);
  xQueueSendToFront(queue, &string3 ,0 );

  vTaskDelete(NULL);
}

void Task2(void *pvParameters){
  char * pcReceivedString;
  for(int i = 0 ; i< 3 ; i ++){
    int messageWaiting = uxQueueMessagesWaiting(queue);
    Serial.print("so luong phan tu trong hang doi: ");
    Serial.println(messageWaiting);
    int emptySpaces = uxQueueSpacesAvailable(queue);
    Serial.print("khoang trong : ");
    Serial.println(emptySpaces);
    Serial.println("du lieu nhan");
    xQueueReceive(queue,&pcReceivedString,5);
    Serial.println(pcReceivedString);
    Serial.println("-----------------------");
  }
  vTaskDelete(NULL);
}