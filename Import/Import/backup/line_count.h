#include "math.h"

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define FILE_IN "D:\\Matlab\\Assigments\\MATLAB\\Facebull\\06_3.in"

	struct arc {
		int machine;
		int source;
		int target;
		int cost;
		};


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
	++no_of_lines;
	//printf("%d", ++no_of_lines);
	//scanf("%c", &c);



	return no_of_lines;
}


///////// Initialise_lookup ///////////////////////need to Malloc!!
struct arc* initialise_lookup(){
	struct arc* lookup=(arc*) malloc(no_of_lines * sizeof(struct arc));
	return lookup;
}





void lookup_store(struct arc* lookup, int newMachine, int newSource, int newTarget, int newCost){
	
	lookup[newMachine].machine = newMachine;
	lookup[newMachine].source = newSource;
	lookup[newMachine].target = newTarget;
	lookup[newMachine].cost = newCost;
}


int no_of_nodes(struct arc* lookup){
	int nodes=0;
	for (int i=0; i<no_of_lines; i++){
	nodes = MAX(nodes, lookup[i].source);
	}

	return nodes;
}




struct arc** initialise_source_array(int no_of_nodes){ // Will be initialised full of garbage (not now I'm using calloc)
	struct arc** source_array=(arc**)calloc(no_of_nodes,sizeof(int));//sizeof(struct arc));
	//for (int i=0; i<nodes * sizeof(struct arc); i++){
	//source_array[i] = NULL;}
	return source_array;
}


void array_store(struct arc** source_array, struct arc* arc_pointer, int array_position){
	source_array[array_position] = arc_pointer;
		
}


int arrange_list(struct arc* lookup_array, struct arc** source_array, int x, int l){
int position=0;	
int size=0;
for (int i=0; i<no_of_lines; i++){
	
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
