\mainpage Main Page

---
# Motion 3 click

Motion 3 Click is a Click board™ based on EKMC1606112, PIR motion sensor from Panasonic Corporation that's used as human motion detector. Also featured on Motion 3 Click bord is TLP241A photorelay from Toshiba that is used to provide a reinforced galvanic isolation for the external signals used to drive some external high power electronic equipment when motion is detected. It's allowing up to 40V between the SSR contacts in OFF state, and currents up to 2A while in ON state, thanks to a very low ON-state resistance. Motion 3 Click board™ is supported by a mikroSDK compliant library, which includes functions that simplify software development. This Click board™ comes as a fully tested product, ready to be used on a system equipped with the mikroBUS™ socket.

<p align="center">
  <img src="https://download.mikroe.com/images/click_for_ide/motion3_click.png" height=300px>
</p>

[click Product page](https://www.mikroe.com/motion-3-click)

---


#### Click library

- **Author**        : Jelena Milosavljevic
- **Date**          : Jun 2021.
- **Type**          : GPIO type


# Software Support

We provide a library for the Motion3 Click
as well as a demo application (example), developed using MikroElektronika
[compilers](https://www.mikroe.com/necto-studio).
The demo can run on all the main MikroElektronika [development boards](https://www.mikroe.com/development-boards).

Package can be downloaded/installed directly from *NECTO Studio Package Manager*(recommended way), downloaded from our [LibStock&trade;](https://libstock.mikroe.com) or found on [Mikroe github account](https://github.com/MikroElektronika/mikrosdk_click_v2/tree/master/clicks).

## Library Description

> This library contains API for Motion3 Click driver.

#### Standard key functions :

- `motion3_cfg_setup` Config Object Initialization function.
```c
void motion3_cfg_setup ( motion3_cfg_t *cfg );
```

- `motion3_init` Initialization function.
```c
MOTION3_RETVAL motion3_init ( motion3_t *ctx, motion3_cfg_t *cfg );
```

#### Example key functions :

- `motion3_enable` This function enables/disables motion sensor by setting EN pin state.
```c
void motion3_enable ( motion3_t *ctx, uint8_t state );
```

- `motion3_detect_state` This function returns INT pin state.
```c
uint8_t motion3_detect_state ( motion3_t *ctx );
```

## Example Description

> This example demonstrates the use of Motion 3 click boards.

**The demo application is composed of two sections :**

### Application Init

> Initializes the driver and enables the motion sensor.

```c

void application_init ( void ) {
    log_cfg_t log_cfg;  /**< Logger config object. */
    motion3_cfg_t motion3_cfg;  /**< Click config object. */

    // Logger initialization.

    LOG_MAP_USB_UART( log_cfg );
    log_cfg.level = LOG_LEVEL_DEBUG;
    log_cfg.baud = 115200;
    log_init( &logger, &log_cfg );
    log_info( &logger, " Application Init " );

    // Click initialization.

    motion3_cfg_setup( &motion3_cfg );
    MOTION3_MAP_MIKROBUS( motion3_cfg, MIKROBUS_1 );
    if ( motion3_init( &motion3, &motion3_cfg ) == DIGITAL_OUT_UNSUPPORTED_PIN ) {
       
        log_error( &logger, " Application Init Error. " );
        log_info( &logger, " Please, run program again... " );

        for ( ; ; );
    }
    
    motion3_enable( &motion3, MOTION3_MODULE_ENABLE );
    Delay_ms( 100 );
    log_printf( &logger, "The sensor is ready.\r\n" );
    log_printf( &logger, "-----------------------\r\n" );
}

```

### Application Task

> It checks if the sensor has detected movement and therefore displays the desired message on the USB UART.

```c

void application_task ( void ) {
    uint8_t int_status;

    int_status = motion3_detect_state( &motion3 );

    if ( int_status == MOTION3_DETECT_OBJECT )
    {
        log_printf( &logger, "Motion detected!\r\n" );
        log_printf( &logger, "-----------------------\r\n" );
        while ( int_status == MOTION3_DETECT_OBJECT ) {
           
            int_status = motion3_detect_state( &motion3 );
        }
        log_printf( &logger, "The sensor is ready.\r\n" );
        log_printf( &logger, "-----------------------\r\n" );
        Delay_ms( 100 );
    }
}


```

The full application code, and ready to use projects can be installed directly from *NECTO Studio Package Manager*(recommended way), downloaded from our [LibStock&trade;](https://libstock.mikroe.com) or found on [Mikroe github account](https://github.com/MikroElektronika/mikrosdk_click_v2/tree/master/clicks).

**Other Mikroe Libraries used in the example:**

- MikroSDK.Board
- MikroSDK.Log
- Click.Motion3

**Additional notes and informations**

Depending on the development board you are using, you may need
[USB UART click](https://www.mikroe.com/usb-uart-click),
[USB UART 2 Click](https://www.mikroe.com/usb-uart-2-click) or
[RS232 Click](https://www.mikroe.com/rs232-click) to connect to your PC, for
development systems with no UART to USB interface available on the board. UART
terminal is available in all MikroElektronika
[compilers](https://shop.mikroe.com/compilers).

---
