/*
 * osci_error.c
 *
 *  Created on: 24. 12. 2019
 *      Author: dot
 */
#include "osci_error.h"
void OSCI_error_loop(char* str)
{
	// Loop here on error, str should be visible in the debugger.
	// Put breakpoint here if you want to read the notification.
	while(1);
}

void OSCI_error_notify(char *str)
{
	// str should be visible in the debugger.
	// Put breakpoint here if you want to read the notification.
	return;
}
