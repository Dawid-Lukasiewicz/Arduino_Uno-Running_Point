/*Dawid Łukasiewicz
Program wykonuje funkcję biegającego punktu
Wykonane na płytce Arduino Uno Rev 3
Data: 25.06.2021
*/

void setup()
{
    pinMode(2, INPUT_PULLUP);              //Initialazing Pin 2 as input for switch
    for (unsigned int i = 8; i <= 13; i++) //Initialazing Pins 8 to 13 as outputs for LEDS
    {
        pinMode(i, OUTPUT);
    }
}
uint16_t counter = 7;          //Variable to count which diode to turn off and turn on
uint16_t toggle_direction = 0; //Variable to remember direction of running point

void loop()
{
    if (digitalRead(2) == HIGH) //If swich is not pressed
    {

        if (counter >= 13) //Opposite direction
        {
            toggle_direction = 1;
        }
        else if (counter <= 8) //Default direction
        {
            toggle_direction = 0;
        }
        if (toggle_direction == 0) //If default direction
        {
            digitalWrite(counter++, LOW); //Turn off previous diode
            digitalWrite(counter, HIGH);  //Turn on next diode
        }
        else
        {
            digitalWrite(counter--, LOW); //Turn off previous diode
            digitalWrite(counter, HIGH);  //Turn on next diode
        }
        delay(500);
    }
    else //If pressed button
    {
        for (unsigned int i = 8; i < 14; i++)
        {
            digitalWrite(i, HIGH); //Turn on all diodes
        }
        while (digitalRead(2) == LOW) //Wait till button unpressed
        {
            delay(100); //To make sure the input is stabile
        }
        for (unsigned int i = 8; i < 14; i++)
        {
            digitalWrite(i, LOW); //Turn off all diodes
        }
        if (toggle_direction == 0) //Set counter to start again from the same diode
            counter--;
        else
            counter++;
    }
}