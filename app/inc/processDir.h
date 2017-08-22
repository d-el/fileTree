/*!****************************************************************************
 * @file		processDir.h
 * @author		d_el - Storozhenko Roman
 * @version		V1.0
 * @date		22 авг. 2017 г.
 * @copyright	GNU Lesser General Public License v3
 * @brief		--
 */
#ifndef processDir_H
#define processDir_H

/*!****************************************************************************
 * Include
 */
#include "stdint.h"

/*!****************************************************************************
 * Define
 */

/*!****************************************************************************
 * Enumeration
 */

/*!****************************************************************************
 * Typedef
 */
typedef int64_t off64_t;

struct filestruct;
typedef void (*level_fn) (struct filestruct uctpath);

typedef struct filestruct{
	char		*name, *fullname;
	level_fn	directory_action, file_action;
	int			depth, error;
	void		*data;
}filestruct;

/*!****************************************************************************
 * Exported variables
 */

/*!****************************************************************************
 * Macro functions
 */

/*!****************************************************************************
 * Function declaration
 */
#define process_dir(...) process_dir_r((filestruct){__VA_ARGS__})
int process_dir_r(filestruct level);

#endif //processDir_H
/*************** LGPL ************** END OF FILE *********** D_EL ************/
