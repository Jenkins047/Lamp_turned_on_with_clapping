#define OPAMP A0
#define GATE 3

void setup()
{
    pinMode(GATE, OUTPUT);
    digitalWrite(GATE, LOW);
    Serial.begin(9600);
}

uint8_t gate_state = LOW;
long timeStamp = 0;
double voltage = 0;

void loop()
{
    if(voltage = map(analogRead(OPAMP), 0, 1023, 0, 5) > 4)
    {
        timeStamp = millis();
        delay(5);
        Serial.println("Clap_1!");

        while(1)
        {
            if(voltage = map(analogRead(OPAMP), 0, 1023, 0, 5) > 4)
            {
                if(millis() - timeStamp > 10 && millis() - timeStamp < 1000)
                {
                    gate_state = (gate_state + 1) % 2;
                    digitalWrite(GATE, gate_state);

                    Serial.println("Clap_2!");
                    if(gate_state)
                        Serial.println("Led ON!");
                    else
                        Serial.println("Led OFF!");

                    delay(30);
                    break;
                }
                else
                {
                    break;
                }   
            }

            if(millis() - timeStamp > 1000)
            {
                Serial.println("Break!");
                break;
            }
            
        }
    }
}
