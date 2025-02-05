

---
# UPS click

UPS click is a supercapacitor charger click that provides continuous power for a load connected to the output terminals.

<p align="center">
  <img src="https://download.mikroe.com/images/click_for_ide/ups_click.png" height=300px>
</p>

[click Product page](https://www.mikroe.com/ups-click)

---


#### Click library 

- **Author**        : MikroE Team
- **Date**          : Dec 2019.
- **Type**          : GPIO type


# Software Support

We provide a library for the Ups Click 
as well as a demo application (example), developed using MikroElektronika 
[compilers](https://shop.mikroe.com/compilers). 
The demo can run on all the main MikroElektronika [development boards](https://shop.mikroe.com/development-boards).

Package can be downloaded/installed directly form compilers IDE(recommended way), or downloaded from our LibStock, or found on mikroE github account. 

## Library Description

> This library contains API for Ups Click driver.

#### Standard key functions :

- Config Object Initialization function.
> void ups_cfg_setup ( ups_cfg_t *cfg ); 
 
- Initialization function.
> UPS_RETVAL ups_init ( ups_t *ctx, ups_cfg_t *cfg );

#### Example key functions :

- Functions for settings chip mode
> void usp_set_mode ( ups_t *ctx, uint8_t mode );
 
- Functions for reading PGD state
> uint8_t ups_get_power_good ( ups_t *ctx );


## Examples Description

> This application is charger, that provides continuous power for a load connected to the output terminals.

**The demo application is composed of two sections :**

### Application Init 

> Initializes Driver init and setting chip mode as ACTIVE

```c

void application_init ( void )
{
    log_cfg_t log_cfg;
    ups_cfg_t cfg;

    //  Logger initialization.

    log_cfg.level = LOG_LEVEL_DEBUG;
    LOG_MAP_USB_UART( log_cfg );
    log_init( &logger, &log_cfg );
    log_info(&logger, "---- Application Init ----");

    //  Click initialization.

    ups_cfg_setup( &cfg );
    UPS_MAP_MIKROBUS( cfg, MIKROBUS_1 );
    ups_init( &ups, &cfg );

    usp_set_mode( &ups, UPS_MODE_ACTIVE );
}
  
```

### Application Task

> Checks the state of PGD (Power Good), PGD goes high when Vout is within 6% of target value (4.98V)

```c

void application_task ( )
{
    uint8_t pgd_state;

    pgd_state = ups_get_power_good( &ups );

    if ( pgd_state != 0 )
    {
        log_printf( &logger, "---> Power Good \r\n" );
    }
    Delay_1sec( );
} 

```

The full application code, and ready to use projects can be  installed directly form compilers IDE(recommneded) or found on LibStock page or mikroE GitHub accaunt.

**Other mikroE Libraries used in the example:** 

- MikroSDK.Board
- MikroSDK.Log
- Click.Ups

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
