#define FILE_IN "D:\\Matlab\\Assigments\\MATLAB\\Facebull\\06_3.in"

	struct arc {
		int machine;
		int source;
		int target;
		int cost;
		struct arc* next;
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



struct arc* head = NULL;
head =(arc*) malloc(sizeof(struct arc));


head->machine = NULL;
	head->source = NULL;
	head->target = NULL;
	head->cost = NULL;

head->next=NULL;



	return head;

}





struct arc* lookup_store(struct arc* head, int newMachine, int newSource, int newTarget, int newCost){
	static int line_no=0;
	
	//calloc & free ???
//Using a struct


/////////////////////Initialise link list

//	void Push(struct node*& head, int data) {
//struct arc* newArc = malloc(sizeof(struct arc));
//newNode->data = data;
//newNode->next = head; // No extra use of * necessary on head -- the compiler
//head = newNode; // just takes care of it behind the scenes.


struct arc* newArc;
//newArc=head;

	newArc = (arc*) malloc(sizeof(struct arc)); // allocate
	newArc->machine = newMachine;
	newArc->source = newSource;
	newArc->target = newTarget;
	newArc->cost = newCost;
	
	//newArc->next = head; // tail //link next to the tail // add arcs to the tail end
	
	//head=newArc;		// tail now becomes 
	//////////////////////////////////////	tail=tail->next;		// tail now becomes 

	newArc->next = head; // The '*' to dereferences back to the real head
head = newArc; // ditto



	return head;

}