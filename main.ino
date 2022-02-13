#define OPAMP 3
#define GATE 2

void setup()
{
    pinMode(GATE, OUTPUT);
    digitalWrite(GATE, LOW);
    pinMode(OPAMP, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(OPAMP), time, CHANGE);
}

unsigned long start = 0, stop = 0xFFFFFFFFFFFFFFFF;
uint8_t gate_state = LOW;

void loop()
{
    if(stop - start < 25)
    {
        gate_state = (gate_state + 1) % 2;
        digitalWrite(GATE, gate_state);
        stop = 0xFFFFFFFFFFFFFFFF;
        start = 0;

        attachInterrupt(digitalPinToInterrupt(OPAMP), time, CHANGE);
    }
}

void time()
{
    detachInterrupt(digitalPinToInterrupt(OPAMP));
    
    uint8_t state = digitalRead(OPAMP);
    
    if(state == HIGH)
        start = millis(); //start counter
    else
        stop = millis(); //stop counter
}