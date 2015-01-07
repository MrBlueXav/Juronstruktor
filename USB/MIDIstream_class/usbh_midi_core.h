/**
 ******************************************************************************
 * @file    usbh_midi_core.h
 * @author	Xavier Halgand
 * @version
 * @date
 * @brief   This file contains all the prototypes for the usbh_midi_core.c
 ******************************************************************************
 *
 *
 ******************************************************************************
 */

/* Define to prevent recursive  ----------------------------------------------*/
#ifndef __USBH_MIDI_CORE_H
#define __USBH_MIDI_CORE_H

/* Includes ------------------------------------------------------------------*/
#include "usbh_core.h"
#include "usbh_stdreq.h"
#include "usb_bsp.h"
#include "usbh_ioreq.h"
#include "usbh_hcs.h"
#include "usbh_usr.h"
#include "midi_interface.h"

/******************************************************************************/
/* States for MIDI State Machine */
typedef enum
{
	MIDI_IDLE= 0,
	MIDI_SEND_DATA,
	MIDI_BUSY,
	MIDI_GET_DATA,
	MIDI_POLL,
	MIDI_ERROR
}
MIDI_State_t;

/******************************************************************************/
typedef struct MIDI_cb
{
	void  (*Init)   (void);
	void  (*Decode) (uint8_t *data);
}
MIDI_cb_t;

/******************************************************************************/
/* Structure for MIDI process */
typedef struct _MIDI_Process
{
	MIDI_State_t	state;
	uint8_t			buff[USBH_MIDI_MPS_SIZE];
	uint8_t			hc_num_in;
	uint8_t 		hc_num_out;
	uint8_t			MIDIBulkOutEp;
	uint8_t			MIDIBulkInEp;
	uint16_t		MIDIBulkInEpSize;
	uint16_t		MIDIBulkOutEpSize;
	MIDI_cb_t      *cb;
}
MIDI_Machine_t;



/******************************************************************************/
/** \brief MIDI Class Driver Event Packet.
 *
 *  Type define for a USB MIDI event packet, used to encapsulate sent and received MIDI messages from a USB MIDI interface.
 *
 *  \note Regardless of CPU architecture, these values should be stored as little endian.
 */
typedef struct
{
	uint8_t Event; /**< MIDI event type, constructed with the \ref MIDI_EVENT() macro. */

	uint8_t  Data1; /**< First byte of data in the MIDI event. */
	uint8_t  Data2; /**< Second byte of data in the MIDI event. */
	uint8_t  Data3; /**< Third byte of data in the MIDI event. */
}
MIDI_EventPacket_t;

/******************************************************************************/
extern USBH_Class_cb_TypeDef  MIDI_cb;

uint8_t MIDI_RcvData(uint8_t *outBuf);

/******************************************************************************/
#endif /* __USBH_MIDI_CORE_H */


/************************ ****************** *****END OF FILE****/

