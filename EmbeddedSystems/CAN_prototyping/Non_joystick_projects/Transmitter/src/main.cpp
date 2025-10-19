#include <SPI.h>
#include "mcp_can.h"
#define spiCSPin 10

MCP_CAN CAN(spiCSPin);

String inputString = "";
bool IsStringFinished = false;
byte buf[8] = {0};
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
}

void loop()
{
    if (IsStringFinished)
    {
        Serial.print("You typed: ");
        Serial.println(inputString);
        inputString.getBytes(buf, 8);

        uint8_t bufLength = inputString.length();

        if (CAN.sendMsgBuf(0x43, 0, bufLength, buf) == CAN_OK)
        {
            Serial.print("Sending command: ");
            Serial.println(inputString);
        }
        else
        {
            Serial.println("Send failed!");
        }
        inputString = "";
        IsStringFinished = false;
        Serial.println("\nType again:");
    }

    while (Serial.available())
    {
        char inChar = (char)Serial.read();
        if (inChar == '\n')
        {
            IsStringFinished = true;
            break;
        }
        else
        {
            inputString += inChar;
        }
    }
}