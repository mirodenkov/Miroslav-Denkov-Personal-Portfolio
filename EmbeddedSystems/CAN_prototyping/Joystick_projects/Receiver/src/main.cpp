#include <SPI.h>
#include "mcp_can.h"
#define StopLight 3 // Arduino pin driving the LED
#define Highbeam 4

const int SPI_CS_PIN = 10; // MCP2515 CS pin

// Define CAN message IDs
#define LEFT_ID   0x01
#define RIGHT_ID  0x02
#define UP_ID     0x03
#define DOWN_ID   0x04
#define CENTER_ID 0x00

bool keepBlinking = false;

unsigned long rxId;
byte len = 0;
byte buf[8];

void readCanMessage();

MCP_CAN CAN(SPI_CS_PIN);

void setup()
{
    Serial.begin(115200);
    pinMode(StopLight, OUTPUT);
    pinMode(Highbeam, OUTPUT);

    // Initialize CAN at 500 kbps with an 8 MHz crystal
    while (CAN.begin(MCP_ANY, MCP_8MHZ, CAN_500KBPS) != CAN_OK)
    {
        Serial.println("CAN BUS Init Failed");
        delay(100);
    }
    CAN.setMode(MCP_NORMAL);
    Serial.println("CAN BUS Init OK!");
}

void loop()
{
    // Poll for a new CAN frame
    if (CAN.checkReceive() == CAN_MSGAVAIL)
    {
        readCanMessage();

        // Print debug info
        Serial.print("Received CAN ID: 0x");
        Serial.println(rxId, HEX);

        // Compare CAN ID and control devices
        if (rxId == LEFT_ID)
        {
            Serial.println("Stop light Blinking");
            while (rxId == LEFT_ID)
            {
                digitalWrite(StopLight, HIGH);
                delay(300);
                digitalWrite(StopLight, LOW);
                delay(300);
                
                // Check for new message to break the loop
                if (CAN.checkReceive() == CAN_MSGAVAIL)
                {
                    readCanMessage();
                    if (rxId == CENTER_ID)
                        break;
                }
            }
        }
        else if (rxId == UP_ID)
        {
            digitalWrite(Highbeam, HIGH);
            Serial.println("Highbeam On");
        }
        else if (rxId == DOWN_ID)
        {
            digitalWrite(Highbeam, LOW);
            Serial.println("Highbeam Off");
        }
        else if (rxId == CENTER_ID)
        {
            digitalWrite(StopLight, LOW);
            Serial.println("Stop light OFF");
        }
        else
        {
            Serial.print("Received unknown ID: 0x");
            Serial.println(rxId, HEX);
        }

        Serial.println();
    }
}

void readCanMessage()
{
    // Read the incoming CAN message into rxId, len, and buf[]
    CAN.readMsgBuf(&rxId, &len, buf);
    // We only care about the message ID now, not the payload
}