/* Standard includes. */
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include "processDir.h"

void print_dir(filestruct in){
	for(int i = 0; i < in.depth - 1; i++){
		printf("    ");
	}
	printf("\xC3\xC4%s\n", in.name);	//├─
	for(int i = 0; i < in.depth - 1; i++){
		printf("    ");
	}
	printf("\xC0\xC4\xC4\xC4\xBF\n");	//└──┐
}

void print_file(filestruct in){
	for(int i = 0; i < in.depth; i++){
		printf("    ");
	}
	printf("\xB3%s\n", in.name);
}

int main(int argc, char **argv){
	setvbuf(stdout, NULL, _IONBF, 0);	//not buffered

	char *start = (argc > 1) ? argv[1] : ".";
	printf("Tree for %s\n", start ? start : "this path");
	process_dir(.name = start, .file_action = print_file, .directory_action = print_dir);

	return 0;
}
