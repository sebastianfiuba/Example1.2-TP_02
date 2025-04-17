#include "mbed.h"
#include "arm_book_lib.h"

int main()
{
   DigitalIn gasDetector(D2);
   DigitalIn overTempDetector(D3);

   /*!

        \note{   
            
            Objeto: &gpio
            Mensaje: PinName pin, PinMode mode
            Metodo 1: read() Lee el pin
            Metodo 2: mode(PinMode pull) Cambia el tipo
            Metodo 3: is_connected() Devuelve si esta conectado el pin
            Metodo 4:
            Clase: DigitalIn
            Herencia: gpio()

            Operador 3: operator int(), Devuelve el valor del pin del objeto

            Constructor 1:  DigitalIn(PinName pin) y gpio_init_in(&gpio, pin), Inicializa un objeto con un pin como entrada
            Constructor 2: DigitalIn(PinName pin, PinMode mode) y gpio_init_in_ex(&gpio, pin, mode), Inicializa un objeto con un pin como entrada y le asigna un tipo
            
            
            Sobrecarga (de funciones): DigitalIn(PinName pin), DigitalIn(PinName pin, PinMode mode)

        }
   
   */
   
   DigitalOut alarmLed(LED1);

      /*!

        \note{   
            
            Objeto: &gpio
            Mensaje: PinName pin, value
            Metodo 1: write(int value) Pone el pin en un valor dado (0,1)
            Metodo 2: read() Lee el pin
            Metodo 3: is_connected() Devuelve si esta conectado el pin
            Clase: DigitalOut
            Herencia: gpio()

            Operador 1: DigitalOut &operator= (int value), Devuele el valor del pin del objeto
            Operador 2: DigitalOut &operator= (DigitalOut &rhs), Pone el valor del pin un objeto(&rhs) al pin de otro objeto (&operator)
            Operador 3: operator int(), Devuelve el valor del pin del objeto

            Constructor 1: DigitalOut(PinName pin) y gpio_init_out(&gpio, pin), Crea un objeto con un pin
            Constructor 2: DigitalOut(PinName pin, int value) y gpio_init_out_ex(&gpio, pin, value), Crea un objeto con un pin y un valor inicial
            
            Sobrecarga (de funciones)  : DigitalOut(PinName pin), DigitalOut(PinName pin, int value) 
            Sobrecarga (de operadores) : DigitalOut &operator= (int value),DigitalOut &operator= (DigitalOut &rhs), pone el valor del pin un objeto(&rhs) al pin de otro objeto (&operator)
        }
   
   */
   
    gasDetector.mode(PullDown);   
    overTempDetector.mode(PullDown);

    bool print_msg_1 = true;
    bool print_msg_2 = true;

    while (true) {
      
        if ( gasDetector || overTempDetector ) {
            alarmLed = ON;
            if(print_msg_1){
                printf("%s\n",(gasDetector == 1) ? "La alarma esta prendida y se detecta gas" : "La alarma esta prendida y no se detecta gas");
                print_msg_2 = true; 
                print_msg_1 = false;   
            }

        } 
        else {
            alarmLed = OFF;
            if(print_msg_2){
                printf("La alarma esta apagada y no se detecta gas\n");
                print_msg_1 = true;
                print_msg_2 = false;
            }       

        }
    }
}