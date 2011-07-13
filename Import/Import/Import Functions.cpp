#include "stdafx.h"
#include "Import Functions.h"
#include "Data Types.h"

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int count_lines_in_file(FILE *file_pointer)
{
	int index=-1, machine=0;
	char c='0';
	//fpos_t position, new_position;
	////////////////////////////////////////////////////////////////////
	// Need to count lines for sizing storage array	
	// A line should be a char containing string, followed by a \n. 
	// Or read the last machine number! (read backwards char by char until it reads an M, then read the int)
	
	int line_number;
	
	while (c != 'M'){
		fseek(file_pointer, index--, SEEK_END); 
		//index--;
		//fscanf_s(file_pointer, "%c", &c);
		c=getc(file_pointer);
		//printf("%c", c);
	}
	fscanf_s(file_pointer, "%d", &line_number);
	++line_number;
	
	return line_number;
}


void lookup_store(struct arc* lookup, int newMachine, int newSource, int newTarget, int newCost){
	lookup[newMachine].machine = newMachine;
	lookup[newMachine].source = newSource;
	lookup[newMachine].target = newTarget;
	lookup[newMachine].cost = newCost;
}


int no_of_nodes(struct arc* lookup, int lineCount){
	int nodes = 0;
	for (int i = 0; i < lineCount; i++){
		nodes = MAX(nodes, lookup[i].source);
	}
	
	return nodes;
}




struct arc** initialise_source_array(int nodeCount){ // Will be initialised full of garbage (not now I'm using calloc)
	struct arc** source_array=(arc**)calloc(nodeCount,sizeof(int));
	return source_array;
}


void array_store(struct arc** source_array, struct arc* arc_pointer, int array_position){
	source_array[array_position] = arc_pointer;
	
}


int arrange_list(struct arc* lookup_array, struct arc** source_array, int x, int l, int lineCount){
	int position=0;	
	int size=0;
	for (int i=0; i<lineCount; i++){
		
		if (l==0){
			if ((lookup_array[i]).source==x)
			{
				array_store(source_array, &(lookup_array[i]), position++);
				size=position;
			}
		}
		else if (l==1){
			if ((lookup_array[i]).target==x)
			{
				array_store(source_array, &(lookup_array[i]), position++);
				size=position;
			}}
	}
	return size;
}
