
---
# Thermo 3 click

Thermo 3 click carries TMP102, a digital temperature sensor IC with a tiny footprint of only 1.6mm x 1.6mm.

<p align="center">
  <img src="https://download.mikroe.com/images/click_for_ide/thermo3_click.png" height=300px>
</p>

[click Product page](https://www.mikroe.com/thermo-3-click)

---


#### Click library 

- **Author**        : MikroE Team
- **Date**          : Feb 2020.
- **Type**          : I2C type


# Software Support

We provide a library for the Thermo3 Click 
as well as a demo application (example), developed using MikroElektronika 
[compilers](https://shop.mikroe.com/compilers). 
The demo can run on all the main MikroElektronika [development boards](https://shop.mikroe.com/development-boards).

Package can be downloaded/installed directly form compilers IDE(recommended way), or downloaded from our LibStock, or found on mikroE github account. 

## Library Description

> This library contains API for Thermo3 Click driver.

#### Standard key functions :

- Config Object Initialization function.
> void thermo3_cfg_setup ( thermo3_cfg_t *cfg ); 
 
- Initialization function.
> THERMO3_RETVAL thermo3_init ( thermo3_t *ctx, thermo3_cfg_t *cfg );


#### Example key functions :

- Gets temperature.
> float get_temperature ( thermo3_t *ctx );


## Examples Description

> This application read the temperature.

**The demo application is composed of two sections :**

### Application Init 

> Initialization driver enables - I2C.

```c

void application_init ( void )
{
    log_cfg_t log_cfg;
    thermo3_cfg_t cfg;

    //  Logger initialization.

    log_cfg.level = LOG_LEVEL_DEBUG;
    LOG_MAP_USB_UART( log_cfg );
    log_init( &logger, &log_cfg );
    log_info( &logger, "---- Application Init ----" );

    //  Click initialization.

    thermo3_cfg_setup( &cfg );
    THERMO3_MAP_MIKROBUS( cfg, MIKROBUS_1 );
    thermo3_init( &thermo3, &cfg );
}
  
```

### Application Task

> This is an example which demonstrates the use of Thermo 3 Click board. Detects the temperature and write on usb uart changes for every 3 sec.

```c

void application_task ( void )
{
    float read_temp;

    read_temp = get_temperature( &thermo3 );

    log_printf( &logger, "Temperature: %.2f C\r\n", read_temp );
    Delay_ms( 3000 );
}  

```


The full application code, and ready to use projects can be  installed directly form compilers IDE(recommneded) or found on LibStock page or mikroE GitHub accaunt.

**Other mikroE Libraries used in the example:** 

- MikroSDK.Board
- MikroSDK.Log
- Click.Thermo3

**Additional notes and informations**

Depending on the development board you are using, you may need 
[USB UART click](https://shop.mikroe.com/usb-uart-click), 
[USB UART 2 Click](https://shop.mikroe.com/usb-uart-2-click) or 
[RS232 Click](https://shop.mikroe.com/rs232-click) to connect to your PC, for 
development systems with no UART to USB interface available on the board. The 
terminal available in all Mikroelektronika 
[compilers](https://shop.mikroe.com/compilers), or any other terminal application 
of your choice, can be used to read the message.



---
