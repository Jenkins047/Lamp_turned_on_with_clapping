#define OPAMP A0
#define GATE 3

void setup()
{
    pinMode(GATE, OUTPUT);
    digitalWrite(GATE, LOW);
}

uint8_t gate_state = LOW;
byte event = 0;

void loop()
{
    if(map(analogRead(OPAMP), 0, 1023, 0, 5) > 3)
    {
        event++;
        delay(26);
    }

    if(event >= 2)
    {
        event = 0;
        gate_state = (gate_state + 1) % 2;
        digitalWrite(GATE, gate_state);
    }

}
