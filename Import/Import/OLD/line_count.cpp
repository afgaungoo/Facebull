
#include "stdio.h"
#include "stdafx.h"

#ifndef FILE_IN "D:\\Matlab\\Assigments\\MATLAB\\Facebull\\06_3.in"
#define FILE_IN "D:\\Matlab\\Assigments\\MATLAB\\Facebull\\06_3.in"
#endif

static int no_of_lines;

int line_count()
{
	// Included for testing; are defined in Import (will be defined in main)
	FILE *file_pointer;
	file_pointer=fopen(FILE_IN,"r");
	

	int index=-1, machine=0;
	char c='0';
	//fpos_t position, new_position;
	////////////////////////////////////////////////////////////////////
	// Need to count lines for sizing storage array	
	// A line should be a char containing string, followed by a \n. 
	// Or read the last machine number! (read backwards char by char until it reads an M, then read the int)



	while (c != 'M'){
	fseek(file_pointer, index--, SEEK_END); 
	//index--;
	//fscanf(file_pointer, "%c", &c);
	c=getc(file_pointer);
	//printf("%c", c);
	}
	fscanf(file_pointer, "%d", &no_of_lines);
	printf("%d", ++no_of_lines);
	//scanf("%c", &c);



	return no_of_lines;
}
