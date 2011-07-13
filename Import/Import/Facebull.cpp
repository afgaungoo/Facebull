#include "stdlib.h"
#include "stdafx.h"
#include "math.h"
#include "Import Functions.h" //data types.h is included in here...
#include "Data Types.h"
#include "Facebull.h"
#include "Initialise Network.h"

//#include "dgraph.h"


#define FILE_IN "D:\\Matlab\\Assigments\\MATLAB\\Facebull\\06_4.in"

int nodeCount;
int no_of_lines;
int network_size;
int network_test_size;
int newEntry;
int nodeCount_cur;
//int nodeList;

int main(int argc, _TCHAR* argv[])
{

	int machine, a, source, target, cost, c, n;
	FILE *file_pointer;

	n=0;
	//file_pointer=fopen(FILE_IN,"r");
	fopen_s(&file_pointer, FILE_IN, "r");

	no_of_lines = count_lines_in_file(file_pointer);


	// Main part; Reads a line and calls lookup_store
	rewind(file_pointer);


	struct arc* lookup=(arc*) malloc(no_of_lines * sizeof(struct arc));

	while (c=getc(file_pointer) != EOF){

		if (n++==0) {
			ungetc(c,file_pointer);}


		fscanf_s(file_pointer, "%*c");
		if (fscanf_s(file_pointer, "%d", &machine) == EOF){break;}

		fscanf_s(file_pointer, "%*1s");
		fscanf_s(file_pointer, "%d", &source);

		fscanf_s(file_pointer, "%*1s");
		fscanf_s(file_pointer, "%d", &target);

		fscanf_s(file_pointer, "%d", &cost);


		lookup_store(lookup, machine, source, target, cost);


	}
	fclose(file_pointer);



	///////////////////////////// To disp whole list, iterate through
	for (int i = 0; i < no_of_lines; i++){
		printf("%d %d %d %d %s", (lookup[i]).machine, (lookup[i]).source, (lookup[i]).target, (lookup[i]).cost,  "\n");
	}
	////////////////////////////////////////////////////////



	nodeCount=no_of_nodes(lookup, no_of_lines) + 1;
	struct arc*** source_array=(arc***)calloc(nodeCount,sizeof(int)); //source array now a pointer to an array of pointers...
	struct arc*** target_array=(arc***)calloc(nodeCount,sizeof(int));
	int* size_of_source_array=(int*)calloc(nodeCount, sizeof(int));
	int* size_of_target_array=(int*)calloc(nodeCount, sizeof(int));


	for (int j=0; j<nodeCount; j++){
		// do for each node
		source_array[j]=initialise_source_array(nodeCount);
		target_array[j]=initialise_source_array(nodeCount);


		size_of_source_array[j]=arrange_list(lookup, source_array[j], j, 0, no_of_lines);// 0 at end (but 1) for source, 1 for target
		size_of_target_array[j]=arrange_list(lookup, target_array[j], j, 1, no_of_lines);// 0 at end (but 1) for source, 1 for target
	}


	////////////////////// Initialise Network 

	struct arc** network=(arc**) calloc((no_of_lines), sizeof(int));
	network_size=0;

	nodeCount_cur=0;
	//////////////////////////////network test
	//printf("%s", "\n \n");
	for (int i=0; i<3; i++){
		newEntry=random(no_of_lines);
		printf("%d %s", newEntry, "\n");
		if ((network[newEntry]) == NULL){network_size++;}
		network[newEntry]=&(lookup[newEntry]);

		//nodeList
		
	}
	//
	printf("%s%d%s","\n",network_size,"\n");
	for (int i=0; i<no_of_lines; i++){
		if ((network[i]) != NULL){
			printf("%d %d %d %d %s", (*network[i]).machine, (*network[i]).source, (*network[i]).target, (*network[i]).cost,  "\n");
		}
	}


	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	


	/////////////////////// Tarjan Test
	//network[1]=&(lookup[1]);	// this should return 1 for 06_4
	//network[4]=&(lookup[4]);
	//network[6]=&(lookup[6]);
	//network[9]=&(lookup[9]);
	//network[11]=&(lookup[11]);
	//network[13]=&(lookup[13]);
	//network_size=6;

	//printf("\n%d\n", nodeCount);


	//This is all wrong. Really, really wrong. What were you smoking?
	//Need to take in network_size (maybe), and network. Then need to arrange them by vertex (they SHOULD be arranged by source already, though the problem didn't specify this. 
	//
	//sc_data_convert (size_of_source_array, source_array);


	


	///////////////////////////// pointer test
	/*printf("%s", "\n \n");
	printf("%d %s", (*(source_array[4][0])).machine, "\n");
	printf("%d %s", &(*(source_array[4][0])).machine, "\n");
	printf("%d %s", lookup[10].machine, "\n");
	printf("%d %s", &lookup[10].machine, "\n");
	*/
	

	printf("%s", "\nEnd of Tarjan");
	///////////////////////// END
	scanf_s("%d", &a);

	return 0;
}