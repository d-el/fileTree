/*!****************************************************************************
 * @file		m.c
 * @author		d_el - Storozhenko Roman
 * @version		V1.0
 * @date		10.08.2017
 * @copyright	GNU Lesser General Public License v3
 * @brief		--
 */

/*!****************************************************************************
 * Include
 */
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include <windows.h>

/*!****************************************************************************
 * MEMORY
 */

/*!****************************************************************************
 * @brief
 */

int main(void) {
	setvbuf(stdout, NULL, _IONBF, 0);	//not buffered
	uint32_t i = 0;

	while(1){
		printf("> %u, Hello World!!!\n", i++); /* prints Hello World!!! */
		Sleep(500);
	}
}

/*************** LGPL ************** END OF FILE *********** D_EL ************/
