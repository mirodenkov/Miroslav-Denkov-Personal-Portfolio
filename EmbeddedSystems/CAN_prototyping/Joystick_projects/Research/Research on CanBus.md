# Question to answer
## How can the CAN bus read data asynchronously, unlike I2C?
---
These two communication modules differentiate themselves in the way they fundamentally operate . I2C is what we call a *synchronous* communication model. The "master" microcontroller has a SCL (Serial Clock Line) which generates clock pulses that every device on the bus uses to time data bits. The "slave" devices always follow this clock rhythm. This makes the Inter-Integrated Circuit model much less robust, because when the "master" goes offline the entire network goes down.

CAN differentiates itself by its *asynchronous* nature. It does not rely on a clock that times when it should read and write data. Rather, the bus watches the signal edges using bit-level synchronization. This means that the CAN frame has a start bit and an end bit, everything timed internally. This way we can make the communication much more flexible, because the nodes do not have to wait for a master clock. Also, because messages are self-contained (with error detection and ACK bit), it makes the model much more robust in the scenarios it is used(mainly in the automobile industry). Lastly, CAN is really well-suited for real time communication since it supports prioritized arbitration, which means that high-priority message get through first, without waiting for a clock alignment.

 ---
To summarize, while I2C needs a clock, CAN decides which device to speak first, based purely on rules in the data itself, thus everyone listens and syncs up by themselves.




