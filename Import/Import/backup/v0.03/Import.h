//#include "stdafx.h"
//#include "math.h"
//#include "stdlib.h"
//#include "stdlib.h"
//#include "stdafx.h"
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define FILE_IN "D:\\Matlab\\Assigments\\MATLAB\\Facebull\\06_4.in"

	struct arc {
		int machine;
		int source;
		int target;
		int cost;
		};


static int no_of_lines;

int line_count();

///////// Initialise_lookup ///////////////////////need to Malloc!!
//struct arc* lookup;

void lookup_store(struct arc* lookup, int newMachine, int newSource, int newTarget, int newCost);

int no_of_nodes(struct arc* lookup);

struct arc** initialise_source_array(int no_of_nodes);

void array_store(struct arc** source_array, struct arc* arc_pointer, int array_position);

int arrange_list(struct arc* lookup_array, struct arc** source_array, int x, int l);

//void import();