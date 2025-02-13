#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


enum Pines_GPIO
    {
        CS   = 0xA0, // Chip Select
        INT1 = 0xA1,
        INT2 = 0xA2,
        INT3 = 0xA3,
        INT4 = 0xA4
    };

    enum Pines_SPI
    {
        SDO = 0xE0, //Serial Data Output
        SDI = 0xE1, //Serial Data Input
        SCK = 0xE2  //Serial Clock
    };

    typedef enum 
    {
        R1 = 0xFF,
        R2 = 0x10,
        R3 = 0x11,
        R4 = 0x20
    }Registro;

    struct Device_Definition
    {
        uint8_t Gravity_size_definition : 2;
        uint8_t Extra_Interrupt_Enable : 1;
        uint8_t Device_State : 1;
        uint8_t : 4;
    };

    struct Gravity_L
    {
        uint8_t : 2;
        uint8_t Lower_bits_of_measurement : 6;
    };

    typedef struct
    {
        uint8_t Tap_Enable : 1;
        uint8_t Gravity_Change_Enable : 1;
        uint8_t Inactivity_Enable : 1;
        uint8_t Double_Tap_Enable : 1;
        uint8_t : 4;
    }enabler;  
    
    // Tipos de dato que se reciben del acelerometro
    typedef union datos
    {
        struct Device_Definition *Device;
        struct Gravity_L Gravity_LR;
        union Interrupt
        {
        enabler Interrupt_Configure;
        uint8_t Interrupt_Configure_Completo;
        };

        union Gravity
        {
            enabler Gravity_H;
            uint8_t Gravity_H_completo;
        };

    }datos;
    