#include <Arduino.h>
#include "LED.h"
#include "Scene.h"
/*LED declarations*/
LED ledGreen(5);
LED ledYellow(18);
LED ledRed(19);
String input = "";
struct SceneTaskParams
{
  Scene *scene;
  int sceneNumber;
};

Scene scene(&ledGreen, &ledYellow, &ledRed);

void ThreadCommandProcessing(void *pvParameters);
void ExecuteScene(void *pvParameters);

void setup()
{
  /*Set leds to OUTPUT*/
  ledGreen.setPinmode();
  ledYellow.setPinmode();
  ledRed.setPinmode();
  /////////////////////
  /*Set serial*/
  Serial.begin(115200);
  Serial.println("Type: 'scene 1' or 'scene 2', 'stop 0', 'stop 1' etc.");
  Serial.println("There are 3 scenes, if you type 0 on a 'start' or 'stop', the command affects every scene");
  xTaskCreate(ThreadCommandProcessing, "Command Processing thread", 2048, NULL, 1, NULL); // has to run forever
}

void loop()
{
}

void ExecuteScene(void *pvParameters)
{

  SceneTaskParams *params = static_cast<SceneTaskParams *>(pvParameters);
  params->scene->startScene(params->sceneNumber);

  delete params;     
  vTaskDelete(NULL);
}

void ThreadCommandProcessing(void *pvParameters)
{
  while (true)
  {
    if (Serial.available())
    {
      char c = Serial.read();

      input += c;

      if (c == '\n')
      {
        input.trim();
        /*debug*/
        Serial.print("Trimmed input: '");
        Serial.print(input);
        Serial.println("'");
        ///////////////////////
        if (input.startsWith("start "))
        {
          int sceneNumber = input.substring(6).toInt();

          Serial.println("Scene command detected."); // Debug print
          SceneTaskParams *params = new SceneTaskParams{&scene, sceneNumber};
          xTaskCreate(ExecuteScene, "Scene execution", 2048, params, 1, NULL);
          Serial.println("Started scene " + String(sceneNumber));
        }

        else
        {
          Serial.println("Unknown command: " + input);
        }
        input = "";
      }
    }
    vTaskDelay(10 / portTICK_PERIOD_MS);
  }
}