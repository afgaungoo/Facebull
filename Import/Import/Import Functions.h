//#include "Data Types.h"
struct arc;

int count_lines_in_file(FILE *file_pointer);

void lookup_store(struct arc* lookup, int newMachine, int newSource, int newTarget, int newCost);

int no_of_nodes(struct arc* lookup, int lineCount); //new

struct arc** initialise_source_array(int no_of_nodes);

void array_store(struct arc** source_array, struct arc* arc_pointer, int array_position);

int arrange_list(struct arc* lookup_array, struct arc** source_array, int x, int l, int lineCount); //new

