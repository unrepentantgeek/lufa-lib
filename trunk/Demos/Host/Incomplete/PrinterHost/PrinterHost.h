/*
             LUFA Library
     Copyright (C) Dean Camera, 2009.
              
  dean [at] fourwalledcubicle [dot] com
      www.fourwalledcubicle.com
*/

/*
  Copyright 2009  Dean Camera (dean [at] fourwalledcubicle [dot] com)

  Permission to use, copy, modify, and distribute this software
  and its documentation for any purpose and without fee is hereby
  granted, provided that the above copyright notice appear in all
  copies and that both that the copyright notice and this
  permission notice and warranty disclaimer appear in supporting
  documentation, and that the name of the author not be used in
  advertising or publicity pertaining to distribution of the
  software without specific, written prior permission.

  The author disclaim all warranties with regard to this
  software, including all implied warranties of merchantability
  and fitness.  In no event shall the author be liable for any
  special, indirect or consequential damages or any damages
  whatsoever resulting from loss of use, data or profits, whether
  in an action of contract, negligence or other tortious action,
  arising out of or in connection with the use or performance of
  this software.
*/

#ifndef _MASS_STORE_HOST_H_
#define _MASS_STORE_HOST_H_

	/* Includes: */
		#include <avr/io.h>
		#include <avr/wdt.h>
		#include <avr/pgmspace.h>
		#include <avr/power.h>
		#include <stdio.h>

		#include "ConfigDescriptor.h"

		#include <LUFA/Version.h>
		#include <LUFA/Drivers/Misc/TerminalCodes.h>
		#include <LUFA/Drivers/USB/USB.h>
		#include <LUFA/Drivers/Peripheral/SerialStream.h>
		#include <LUFA/Drivers/Board/LEDs.h>

	/* Macros: */
		/** LED mask for the library LED driver, to indicate that the USB interface is not ready. */
		#define LEDMASK_USB_NOTREADY      LEDS_LED1

		/** LED mask for the library LED driver, to indicate that the USB interface is enumerating. */
		#define LEDMASK_USB_ENUMERATING  (LEDS_LED2 | LEDS_LED3)

		/** LED mask for the library LED driver, to indicate that the USB interface is ready. */
		#define LEDMASK_USB_READY        (LEDS_LED2 | LEDS_LED4)

		/** LED mask for the library LED driver, to indicate that an error has occurred in the USB interface. */
		#define LEDMASK_USB_ERROR        (LEDS_LED1 | LEDS_LED3)

		#define PROTOCOL_UNIDIRECTIONAL      0x01
		#define PROTOCOL_BIDIRECTIONAL       0x02
		#define PROTOCOL_IEEE1284            0x03
		
		#define GET_DEVICE_ID                0

	/* Type Defines: */
		typedef struct
		{
			uint16_t Length;
			uint8_t  String[128];
		} Device_ID_String_t;

	/* External Variables: */
		extern uint8_t PrinterProtocol;
	
	/* Function Prototypes: */
		void EVENT_USB_DeviceAttached(void);
		void EVENT_USB_DeviceUnattached(void);
		void EVENT_USB_DeviceEnumerationComplete(void);
		void EVENT_USB_HostError(uint8_t ErrorCode);
		void EVENT_USB_DeviceEnumerationFailed(uint8_t ErrorCode, uint8_t SubErrorCode);

		void SetupHardware(void);

		void USB_Printer_Host(void);

		bool GetDeviceID(void);

#endif
