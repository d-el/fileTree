/*!****************************************************************************
 * @file		processDir.c
 * @author		d_el - Storozhenko Roman
 * @version		V1.0
 * @date		22 авг. 2017 г.
 * @copyright	GNU Lesser General Public License v3
 * @brief		--
 */

/*!****************************************************************************
 * Include
 */
#include "processDir.h"
#include "dirent.h"
#include "stdlib.h"
#include "stdio.h"
#include <stdarg.h>

/*!****************************************************************************
 * MEMORY
 */
int asprintf(char **strp, const char *fmt, ...);

/*!****************************************************************************
 * @brief
 */
int asprintf(char ** __restrict__ ret,
                     const char * __restrict__ format,
                     ...) {
  va_list ap;
  int len;
  va_start(ap,format);
  /* Get Length */
  len = _vsnprintf(NULL,0,format,ap);
  if (len < 0) goto _end;
  /* +1 for \0 terminator. */
  *ret = malloc(len + 1);
  /* Check malloc fail*/
  if (!*ret) {
    len = -1;
    goto _end;
  }
  /* Write String */
  _vsnprintf(*ret,len+1,format,ap);
  /* Terminate explicitly */
  (*ret)[len] = '\0';
  _end:
  va_end(ap);
  return len;
}

int process_dir_r(filestruct level){
	if(level.fullname == NULL){
		if(level.name != NULL){
			level.fullname = level.name;
		}
		else{
			level.fullname = ".";
		}
	}
	int errcnt = 0;

	DIR *current = opendir(level.fullname);
	if(current == NULL){
		return 1;
	}
	struct dirent *entry;
	while(entry = readdir(current)){
		if(entry->d_name[0] == '.'){
			continue;
		}
		filestruct next_level = level;
		next_level.name = entry->d_name;
		asprintf(&next_level.fullname, "%s/%s", level.fullname, entry->d_name);
		if(entry->d_type == DT_DIR){
			next_level.depth++;
			if(level.directory_action != NULL){
				level.directory_action(next_level);
				errcnt += process_dir_r(next_level);
			}
		}
		else if(entry->d_type == DT_REG && level.file_action){
			level.file_action(next_level);
			errcnt += next_level.error;
		}
		free(next_level.fullname);
	}
	closedir(current);
	return errcnt;
}



/*************** LGPL ************** END OF FILE *********** D_EL ************/
