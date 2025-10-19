#ifndef SCENE_H
#define SCENE_H
#include "LED.h"
#include <vector>
#include <map>

// structure that stores scene behaviour data
struct Behaviour
{
    LED *led;
    /*time in milliseconds where the LED stays on/off*/
    uint32_t onTime;
    uint32_t offTime;
};

class Scene
{
    // Note to self: with "using" the compiler treats every SceneDefine as Behaviour vector
    // The SceneDefine (think of it as Scene definition) is a vector that stores scene behaviour
    // each element has the behaviour of a single LED
    using SceneDefine = std::vector<Behaviour>;
    // Note to self: Think of a map as a phonebook
    // This map stores the scenes themselves, they will be easier to search for because we always know which
    // scene number to choose (1,2,3), it would technically be faster than iterating an array/vector
    std::map<int, SceneDefine> scenes;

public:
    //The SceneDefine& means I only pass a reference, it is better than passing a pointer
    //becuase I cannot put NULL in the arguments and it looks better when you call
    //the method :p
    void defineScene(int id, const SceneDefine& scene_definition);
    void executeScene(int id);
};

#endif