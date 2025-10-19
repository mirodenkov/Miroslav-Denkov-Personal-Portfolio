#include "Scene.h"
#include "Arduino.h"

void Scene::defineScene(int id, const SceneDefine &scene_definition)
{
    scenes[id] = scene_definition;
}
void Scene::executeScene(int id)
{
    auto iteration = scenes.find(id);
    if (iteration == scenes.end())
    {
        return; // scene not found
    }

    for (auto &behaviour : iteration->second)
    {
        behaviour.led->on();
        vTaskDelay(behaviour.onTime / portTICK_PERIOD_MS);
        behaviour.led->off();
        vTaskDelay(behaviour.offTime / portTICK_PERIOD_MS);
    }
}