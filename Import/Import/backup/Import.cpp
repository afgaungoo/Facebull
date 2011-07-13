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
	fclose(file_pointer);
	
	

	///////////////////////////// To disp whole list, iterate through
	/*for (int i=0; i<no_of_lines; i++){
		
		printf("%d %d %d %d %s", (lookup[i]).machine, (lookup[i]).source, (lookup[i]).target, (lookup[i]).cost,  "\n");
	
	}
	*/
	////////////////////////////////////////////////////////

	int nodes=no_of_nodes(lookup) + 1;
	struct arc*** source_array=(arc***)calloc(nodes,sizeof(int)); //source array now a pointer to an array of pointers...
	struct arc*** target_array=(arc***)calloc(nodes,sizeof(int));
	int* size_of_source_array=(int*)calloc(nodes, sizeof(int));
	int* size_of_target_array=(int*)calloc(nodes, sizeof(int));


for (int j=0; j<nodes; j++){
// do for each node
source_array[j]=initialise_source_array(nodes);
target_array[j]=initialise_source_array(nodes);


size_of_source_array[j]=arrange_list(lookup, source_array[j], j, 0);// 0 at end for source, 1 for target
size_of_target_array[j]=arrange_list(lookup, target_array[j], j, 1);// 0 at end for source, 1 for target
}
		


/// Show the source_nodes array	
//for (int j=0; j<nodes; j++){
//int i=0;
//while ((source_array[j][i]) != NULL){	
//		printf("%d %d %d %d %s", (*(source_array[j][i])).machine, (*(source_array[j][i])).source, (*(source_array[j][i])).target, (*(source_array[j][i])).cost,  "\n");
//	//printf("%d %s", size_of_source_array[j], "\n");
//i++;
//	}
//}



////Show the target_nodes array
//for (int j=0; j<nodes; j++){
//int i=0;
//while ((target_array[j][i]) != NULL){	
//		printf("%d %d %d %d %s", (*(target_array[j][i])).machine, (*(target_array[j][i])).source, (*(target_array[j][i])).target, (*(target_array[j][i])).cost,  "\n");
////	printf("%d %s", size_of_source_array[j], "\n");
//i++;
//	}
//}




		scanf("%d", &a);


	

	return 0;
}

