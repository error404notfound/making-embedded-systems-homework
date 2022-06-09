/*
 * file_USB_driver.h
 *
 *  Created on: Jun 9, 2022
 *      Author: jennie.stenhouse
 */

#ifndef INC_DRIVERS_FILE_USB_DRIVER_H_
#define INC_DRIVERS_FILE_USB_DRIVER_H_

#include "fatfs.h"
#include "usb_host.h"
#include "util.h"


#include "string.h"
#include "stdio.h"


/* mounts the USB*/
void Mount_USB (void);

/* unmounts the USB*/
void Unmount_USB (void);

/* Start node to be scanned (***also used as work area***) */
FRESULT Scan_USB (char* pat);

/* Only supports removing files from home directory. Directory remover to be added soon */
FRESULT Format_USB (void);

/* JS check file exists */
FRESULT Check_File(char *name );
/* write the data to the file
 * @ name : is the path to the file*/
FRESULT Write_File (char *name, char *data);

/* read data from the file
 * @ name : is the path to the file*/
FRESULT Read_File (char *name);

/* creates the file, if it does not exists
 * @ name : is the path to the file*/
FRESULT Create_File (char *name);

/* Removes the file from the USB
 * @ name : is the path to the file*/
FRESULT Remove_File (char *name);

/* creates a directory
 * @ name: is the path to the directory
 */
FRESULT Create_Dir (char *name);

/* checks the free space in the USB*/
void Check_USB_Details (void);

/* updates the file. write pointer is set to the end of the file
 * @ name : is the path to the file
 */
FRESULT Update_File (char *name, char *data);




#endif /* INC_DRIVERS_FILE_USB_DRIVER_H_ */
