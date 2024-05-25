#include <Arduino.h>

uint8_t data[] = "hello world!";

void Serial_write(uint8_t *data, uint16_t length);

void setup()
{
    Serial.begin(115200);
}

void loop()
{
    Serial_write(data, sizeof(data));
    delay(1000);
}

void Serial_write(uint8_t *data, uint16_t length)
{
    for (int i = 0; i < length; i++)
    {
        while (!(USART1->SR & USART_SR_TXE)); // Wait for transmit data register empty
        USART1->DR = data[i];
    }
}