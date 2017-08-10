/* Standard includes. */
#include <stdio.h>

/* Kernel includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#include "FreeRTOSConfig.h"


void taskprint(void *pPrm){
	char *str = (char*) pPrm;
	uint32_t cnt = 0;

	for(;;){
		printf(str);
		printf(" %u", cnt++);
		fflush(stdout);
		printf("\r\n");
		fflush(stdout);

		vTaskDelay((100));
	}
}


void main_blinky(void){


	for(;;)
		;
}
/*-----------------------------------------------------------*/

