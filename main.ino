#define OPAMP 3
#define GATE 2

void setup()
{
    pinMode(GATE, OUTPUT);
    digitalWrite(GATE, LOW);
    pinMode(OPAMP, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(3), toggle, RISING);
}

volatile byte pulses = 0;
byte STATE = LOW;

void loop()
{
    if(pulses > 2)
    {
        pulses = 0;
        STATE = (STATE + 1) % 2;
        digitalWrite(GATE, STATE);
    }
}

void toggle()
{
    pulses++;
}