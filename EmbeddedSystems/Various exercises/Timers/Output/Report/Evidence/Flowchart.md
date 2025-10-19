
```
@startuml
start
:Initialize;

partition "Setup" {
  :SystemClock_Config();
  :SysTick_Init();
  :GPIOx_Init();
  :timer_LED_init();
  :timer_Servo_init();
}

partition "Loop"{
  repeat
    :LED_Breathe();
    :servo_move();
  repeat while
}

@enduml

```

![[Pasted image 20250511121211.png]]