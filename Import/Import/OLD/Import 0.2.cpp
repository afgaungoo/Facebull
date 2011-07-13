// Import.cpp
//

#include "stdlib.h"
#include "stdafx.h"
#include "math.h"
#include "line_count.h"



int main(int argc, _TCHAR* argv[])
{
	
	int machine, a, source, target, cost, c, n;
	FILE *file_pointer;
	
	n=0;
	file_pointer=fopen(FILE_IN,"r");
	

	
	no_of_lines=line_count();
	
	





// Main part; Reads a line and calls lookup_store
	rewind(file_pointer);
	
	
	struct arc* lookup = initialise_lookup();

	


	while (c=getc(file_pointer) != EOF){
		
	if (n++==0) {
		ungetc(c,file_pointer);}
	

	fscanf(file_pointer, "%*c");
	if (fscanf(file_pointer, "%d", &machine) == EOF){break;}

	fscanf(file_pointer, "%*1s");
	fscanf(file_pointer, "%d", &source);

	fscanf(file_pointer, "%*1s");
	fscanf(file_pointer, "%d", &target);

	fscanf(file_pointer, "%d", &cost);
	
	
	lookup_store(lookup, machine, source, target, cost);
	
	
	}
	
	
	

	///////////////////////////// To disp whole list, iterate through
	for (int i=0; i<no_of_lines; i++){
		
		printf("%d %d %d %d %s", (lookup[i]).machine, (lookup[i]).source, (lookup[i]).target, (lookup[i]).cost,  "\n");
	
	}
	
	////////////////////////////////////////////////////////

	int nodes=0;
		nodes=no_of_nodes(lookup);

struct arc** source_array=initialise_source_array(nodes);
		
printf("%d %s", source_array,"\n");
arrange_list(lookup, source_array);//


//array_store(source_array, lookup, array_position);		
		
//printf("%d %s", nodes,"\n");

/// Show the source_nodes array	
for (int i=0; i<1; i++){
		
		//printf("%d %d %d %d %s", (*(source_array[i])).machine, (*(source_array[i])).source, (*(source_array[i])).target, (*(source_array[i])).cost,  "\n");
	
	}






		scanf("%d", &a);


	fclose(file_pointer);

	return 0;
}

