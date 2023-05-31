#include <Arduino_FreeRTOS.h>
// Khai báo nhiệm vụ:
void TaskBlink1( void *pvParameters );
void TaskBlink2( void *pvParameters );
void Taskprint( void *pvParameters );
void setup() {
  Serial.begin(9600);
// Thiết lập tác vụ để chạy độc lập
  xTaskCreate(
    TaskBlink1
    ,  "task1"   
    ,  128  
    ,  NULL
    ,  1  
    ,  NULL );
  xTaskCreate(
    TaskBlink2
    ,  "task2"
    ,  128  
    ,  NULL
    ,  1  
    ,  NULL );
  xTaskCreate(
    Taskprint
    ,  "task3"
    ,  128  
    ,  NULL
    ,  1  
    ,  NULL );
vTaskStartScheduler();
}
void loop()
{
}
void TaskBlink1(void *pvParameters)  // tác vụ 1
{
  pinMode(13, OUTPUT);
  while(1)
  {
    Serial.println("Task1");
    digitalWrite(13, HIGH);   
    vTaskDelay( 200 / portTICK_PERIOD_MS ); 
    digitalWrite(13, LOW);    
    vTaskDelay( 200 / portTICK_PERIOD_MS ); 
  }
}
void TaskBlink2(void *pvParameters)  // tác vụ 2
{
  pinMode(7, OUTPUT);
  while(1)
  {
    Serial.println("Task2");
    digitalWrite(7, HIGH);   
    vTaskDelay( 300 / portTICK_PERIOD_MS ); 
    digitalWrite(7, LOW);   
    vTaskDelay( 300 / portTICK_PERIOD_MS ); 
  }
}
void Taskprint(void *pvParameters)  // tác vụ 3
{
  int counter = 0;
  while(1)
  {
  counter++;
  Serial.println(counter); 
  vTaskDelay(500 / portTICK_PERIOD_MS);    
}
}