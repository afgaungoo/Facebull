
static int[no_of_lines, 4] lookup;

int lookup_store(int machine, int source, int target, int cost)
{
	static int line_no=0;
	
	lookup[line_no, 1]=machine;
	lookup[line_no, 2]=source;
	lookup[line_no, 3]=target;
	lookup[line_no++, 4]=cost;



	return 0;

}