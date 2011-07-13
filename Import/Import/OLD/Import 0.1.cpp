// Import.cpp : Defines the entry point for the console application.
//

#include "stdlib.h"
//#include "stdio.h"
#include "stdafx.h"
#include "line_count.h"
//#include "lookup_store.cpp"
//#ifndef FILE_IN "D:\\Matlab\\Assigments\\MATLAB\\Facebull\\06_3.in"
//#define FILE_IN "D:\\Matlab\\Assigments\\MATLAB\\Facebull\\06_3.in"
//#endif
//int *lookup_pointer;
//static int no_of_lines=0;




int main(int argc, _TCHAR* argv[])
{
	
	int newMachine, a, newSource, newTarget, newCost, c, n;
	FILE *file_pointer;
	
	n=0;
	file_pointer=fopen(FILE_IN,"r");
	

	
	no_of_lines=line_count();
	
	





// Main part; Reads a line and calls lookup_store
	rewind(file_pointer);
	
	
	//// Initialise dummy node of lookup table; head is the pointer to the first node in the list
	struct arc* head = initialise_lookup();
	struct arc* tail = head;
	


	while (c=getc(file_pointer) != EOF){
		
	if (n++==0) {
		ungetc(c,file_pointer);}
	

	fscanf(file_pointer, "%*c");
	if (fscanf(file_pointer, "%d", &newMachine) == EOF){break;}

	fscanf(file_pointer, "%*1s");
	fscanf(file_pointer, "%d", &newSource);

	fscanf(file_pointer, "%*1s");
	fscanf(file_pointer, "%d", &newTarget);

	fscanf(file_pointer, "%d", &newCost);
	
	printf("%d %s", head, "\n" );
	head = lookup_store(head, newMachine, newSource, newTarget, newCost);
	}
	

	///////////////////////////// To disp whole list, iterate through
	struct arc* head_temp=head;
	for (int i=0; i<no_of_lines; i++){
		
		printf("%d %d %d %d %s", (*head_temp).machine, (*head_temp).source, (*head_temp).target, (*head_temp).cost,  "\n");
	head_temp = (*head_temp).next;
	}
	head_temp=head;
	////////////////////////////////////////////////////////


	scanf("%d", &a);


	fclose(file_pointer);
	
	
	
	
	
	return 0;
}

