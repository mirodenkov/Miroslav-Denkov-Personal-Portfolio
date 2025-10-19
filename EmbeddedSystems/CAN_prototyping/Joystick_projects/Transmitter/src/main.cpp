#include <SPI.h>
#include "mcp_can.h"
#include "SparkFun_Qwiic_Joystick_Arduino_Library.h"
#define spiCSPin 10

MCP_CAN CAN(spiCSPin);
JOYSTICK joystick;

volatile int x = 0;
volatile int y = 0;
int state = 0;
int prevState = 99;

int checkState();
void sendCanMessage(byte messageID);

typedef enum
{
    Center,
    Left,
    Right,
    Up,
    Down,
    Ignore
} States;
void setup()
{
    Serial.begin(115200);

    while (CAN_OK != CAN.begin(MCP_ANY, MCP_8MHZ, CAN_500KBPS))
    {
        Serial.println("CAN BUS init Failed");
        delay(100);
    }
    CAN.setMode(MCP_NORMAL);
    Serial.println("CAN BUS Shield Init OK!");

    if (joystick.begin() == false)
    {
        Serial.println("Joystick does not appear to be connected. Please check wiring. Freezing...");
        while (1)
            ;
    }
}

void loop()
{
    state = checkState();
    switch (state)
    {
    case Center:
        if (prevState != state)
        {
            sendCanMessage(0x00); // Message ID for Center
        }
        break;

    case Left:
        if (prevState != state)
        {
            sendCanMessage(0x01); // Message ID for Left
        }
        break;

    case Right:
        if (prevState != state)
        {
            sendCanMessage(0x02); // Message ID for Right
        }
        break;

    case Up:
        if (prevState != state)
        {
            sendCanMessage(0x03); // Message ID for Up
        }
        break;

    case Down:
        if (prevState != state)
        {
            sendCanMessage(0x04); // Message ID for Down
        }
        break;

    default:
        break;
    }
    delay(100);
}

void sendCanMessage(byte messageID)
{
    byte data[1] = {messageID}; 

    CAN.sendMsgBuf(messageID, 0, 1, data);

    // Print readable message for debugging
    Serial.print("Sending command ID: 0x");
    Serial.print(messageID, HEX);
    Serial.print(" (");
    switch (messageID)
    {
    case 0x00:
        Serial.print("Center");
        break;
    case 0x01:
        Serial.print("Left");
        break;
    case 0x02:
        Serial.print("Right");
        break;
    case 0x03:
        Serial.print("Up");
        break;
    case 0x04:
        Serial.print("Down");
        break;
    default:
        Serial.print("Unknown");
        break;
    }
    Serial.println(")");

    prevState = state;
}

int checkState()
{
    x = joystick.getHorizontal();
    y = joystick.getVertical();
    if (x == 508 && y == 513)
    {
        return Center;
    }
    else if (x == 508 && y == 0)
    {
        return Left;
    }
    else if (x == 508 && y == 1023)
    {
        return Right;
    }
    else if (x == 1023 && y == 513)
    {
        return Up;
    }
    else if (x == 0 && y == 513)
    {
        return Down;
    }
    else
    {
        return Ignore;
    }
}