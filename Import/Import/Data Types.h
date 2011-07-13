struct arc {
	int machine;
	int source;
	int target;
	int cost;
};

typedef struct scNode {
	int node;
	int index;
	int lowlink;
} scNode;

extern int nodeCount;
extern int no_of_lines;
extern int network_size;
extern int network_test_size;
extern int nodeCount_cur; //nodeCount in current network
//extern int nodeList;