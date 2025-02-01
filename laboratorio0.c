#include <stdint.h>
#include <stdio.h>

int N=12;
//Se define una union que permita el manejo de un dato de 24 bits,
//en este caso se usará para el nivel del tanque de reserva.
typedef union nt{
    int8_t bytes[3];
    int32_t nivel_tanque_reserva;
}niveltanque;

typedef struct info
    {
        uint8_t bateria;
        int16_t temperatura;
        niveltanque reserva;          
        uint32_t nivel_tanque_principal;
        uint16_t checksum;
        
    }datos;
datos funcion(uint8_t array[N]);


int main(){

}


datos funcion(uint8_t array[N]){

    datos ordenar;
    ordenar.bateria=array[0];
    ordenar.temperatura=(int16_t)(array[1]<<8|array[2]);
    ordenar.reserva.bytes[0]=(int8_t)array[3];
    ordenar.reserva.bytes[1]=(int8_t)array[4];
    ordenar.reserva.bytes[2]=(int8_t)array[5];
    ordenar.nivel_tanque_principal=array[6]<<24|array[7]<<16|array[8]<<8|array[9]; 
    ordenar.checksum=array[10]<<8|array[11];
    return ordenar;

}