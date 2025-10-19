#include <SPI.h>
#include "mcp_can.h"

const int SPI_CS_PIN = 10; // MCP2515 CS pin
const int LED_PIN = 2;     // Arduino pin driving the LED

MCP_CAN CAN(SPI_CS_PIN);

void setup()
{
    Serial.begin(115200);
    pinMode(LED_PIN, OUTPUT);

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
        unsigned long rxId;
        byte len = 0;
        byte buf[8];

        // Read the incoming CAN message into rxId, len, and buf[]
        CAN.readMsgBuf(&rxId, &len, buf);

        // Copy the payload bytes into a null-terminated C-string
        // (len is guaranteed by MCP2515 to be ≤ 8)
        char msg[9]; // we allocate one extra byte for ‘\0’
        for (byte i = 0; i < len; i++)
        {
            msg[i] = (char)buf[i];
        }
        msg[len] = '\0'; // terminate

        // Convert to Arduino String for easy comparison
        String dataStr = String(msg);

        // Print debug info
        Serial.print("Received CAN ID: 0x");
        Serial.println(rxId, HEX);
        Serial.print("Raw bytes (");
        Serial.print(len);
        Serial.print("): ");
        for (byte i = 0; i < len; i++)
        {
            if (buf[i] < 0x10)
                Serial.print('0');
            Serial.print(buf[i], HEX);
            Serial.print(' ');
        }
        Serial.println();
        Serial.print("As ASCII: ");
        Serial.println(dataStr);

        // Compare and drive the LED
        if (dataStr == "on")
        {
            digitalWrite(LED_PIN, HIGH);
            Serial.println("LED turned ON");
        }
        else if (dataStr == "off")
        {
            digitalWrite(LED_PIN, LOW);
            Serial.println("LED turned OFF");
        }
        else
        {
            Serial.println("Received something else");
        }

        Serial.println();
    }
}