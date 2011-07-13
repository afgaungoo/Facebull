#include "stdlib.h"
#include "stdafx.h"
#include "stdio.h"
#include "Initialise Network.h"
#include "math.h"
#include "Import Functions.h"
#include "Data Types.h"
#include "time.h"
#include "tchar.h"
#include "windows.h"
#include <winbase.h>
#include <winnt.h>
//#include "sc.h"
//#include "dgraph.h"


using namespace std;

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define UNDEFINED -1

/////////////////////////////////////////////////////////////////


//int strongconnect(int v, int index, struct scNode* scArray, int* stack, arc*** source_array_in, arc** network_in);

/* Prototypes of functions only visible within this file. */
void sc_recursive(int v);

/* Pointers to the current graphs vertices and result structure arrays,
 * accessed by sc_recursive().
 */
dgraph_vertex_t *vertices;
int *sc_vertices, *sets_s, *sets_f;

/* Stack used for generating SC components.  The sp[v] array gives the position
 * of vertex v in sc_stack[].  The top of stack is specified by tos, which
 * indexes the next unused entry in sc_stack.
 */
int *sc_stack, *sp, tos;

/* Visit numbers and low link numbers used when determining SC components. */
int *visit_nos, *low_link_nos;

/* Counters for
 *  - the number of visited vertices.
 *  - the number of vertices written to the vertices[] array i9n the
 *    SC component result.
 *  - the number of sets of vertices in the SC component result.
 */
int n_visited, n_written, n_sets;




//////////////////////////////////////////////////////////////////////





void Initialise_Network(){

	//	calloc()
}

/////////////////// XORSHIFT
//unsigned long xor128(){
//static unsigned long x=123456789, y=362436069, z=521288629, w=88675123;
//unsigned long t;
//t=(xˆ(x<<11));x=y;y=z;z=w; 
//w=(wˆ(w>>19))ˆ(tˆ(t>>8));
//return w;
//}



/////////////////MWC
unsigned long mwc(){
	static unsigned long x=123456789,y=362436069,z=77465321,c=13579;

	unsigned long long t;
	t=916905990LL*x+c; x=y; y=z; c=(t>>32); return z=(t&0xffffffff);
}


///////////////////////another random number generator
//
//unsigned random(){ // look at using bitwise masks for fast modulation of random number
//  
////	timeval t1;								Only works in LINUX
////gettimeofday(&t1, NULL);
////seed=(t1.tv_usec * t1.tv_sec);
//
//
//	///////////////////////This is the good stuff?
//
//SYSTEMTIME st;
//GetSystemTime(&st);
////unsigned seed=(st.wMilliseconds * st.wSecond);	//milliseconds not enough
//
//
//	
//
//
//
//
//  ////// Accurate stuff
//
//
// int count,a;
//LARGE_INTEGER ticksPerSecond;
//LARGE_INTEGER tick;   // A point in time
//LARGE_INTEGER start_ticks, end_ticks, cputime;   
//
//QueryPerformanceCounter(&start_ticks); 
//QueryPerformanceFrequency(&ticksPerSecond);
/////////////////////printing stuff
////printf ("\ Value of CLOCKS_PER_SEC is :    %f  ticks/sec\n",CLOCKS_PER_SEC   );
////
////  ////get the high resolution counter's accuracy
////  if (!QueryPerformanceFrequency(&ticksPerSecond))
//// printf("\tno go QueryPerformance not present");
////printf ("\tfreq test:   %I64Ld ticks/sec\n",ticksPerSecond    );
////  ////what time is it?
////  if (!QueryPerformanceCounter(&tick) ) printf("no go counter not installed");  
////printf ("\QueryPerformanceCounter testpoint :   %I64Ld  ticks\n",tick);
//////////////////////////////end
//
//  /* start foo()  */ 
// 
// 
//  /* end foo( ) */
// 
//
//
////printf ("\tElapsed CPU time test:   %.9f  sec  ticks %d\n",
////((float)cputime.QuadPart/(float)ticksPerSecond.QuadPart),cputime.QuadPart); 
//  
//
//
//unsigned seed;
//
//
//QueryPerformanceCounter(&end_ticks); 
//cputime.QuadPart = end_ticks.QuadPart- start_ticks.QuadPart;
//
//  seed=end_ticks.QuadPart* st.wSecond;
//
//  
//  seed ^= (seed<<13);
//  seed ^= (seed>>17);
//  seed ^= (seed<<5);
//
//  return seed;
//}


unsigned random(int mod){

	SYSTEMTIME st;
	GetSystemTime(&st);
	LARGE_INTEGER tick;
	QueryPerformanceCounter(&tick);
	srand(tick.QuadPart);

	return(rand() % mod);

}

//int Tarjan(struct arc** network_in, struct arc*** source_array_in){ //returns 0 if not Strongly Connected, 1 if SC
//	int s=0;
//	int index=0;
//	
//
//
//	struct scNode* scArray=(scNode*)calloc(nodeCount, sizeof(struct scNode));
//	
//	printf("nodeCount: %i, sizeof(scNode): %i\n", nodeCount, sizeof(scNode));
//	//printf("%i\n", no_of_lines);
//	//scNode* scArray;
//	//scArray = (scNode*)malloc(nodeCount * sizeof(scNode));
//	//memset(scArray, 0, nodeCount * sizeof(scNode));
//	
//	int* stack=(int*)calloc(no_of_lines, sizeof(int));
//	struct scNode v;
//
//	
//
//	/*struct scnode test_node = scarray[1];
//	printf("%d%s", scarray[1].index, "\n");
//	printf("%d%s", scarray[1].lowlink, "\n");
//	printf("%d%s", scarray[1].node, "\n");*/
//	
//	
//	//scArray[0].index=0;
//
//	/*printf("%i\n", scArray[0].index);
//	printf("%i\n", scArray[0].lowlink);
//	printf("%i\n", scArray[0].node);
//
//	printf("%d%s", scArray[1].index, "\n");
//	printf("%d%s", scArray[1].lowlink, "\n");
//	printf("%d%s", scArray[1].node, "\n");
//
//
//	printf("%d%s", scArray[2].index, "\n");
//	printf("%d%s", scArray[2].lowlink, "\n");
//	printf("%d%s", scArray[2].node, "\n");*/
//	
//	
//
//	for (int i=0; i<nodeCount; i++){
//		if (scArray[i].index==0){		// if v index is undefined
//			s=strongconnect(i, index, scArray, stack, source_array_in, network_in);
//			printf("%d\n",s);
//		}
//	}
//
//
//
//	free(scArray);
//	free(stack);
//	
//	return(s);
//}
//
//
//int strongconnect(int v, int index, struct scNode* scArray, int* stack, arc*** source_array_in, arc** network_in){
//	int s=0;
//	int topOfStack=-1;
//	scArray[v].index=index;
//	scArray[v].lowlink=index++;
//	//push stack(v)
//	stack[++topOfStack]=v;
//
//
//	int i=0;
//
//	for(int j=0; j<network_size; j++){
//		
//
//		//// for each (v,w)
//		if (source_array_in[v][i] != NULL){				//v=node number, i=arc with v at its head ???should be a pointer?
//			if (&(*(source_array_in[v][i])).machine==&(*network_in[j]).machine){				// I don't think this referencing is correct
//			//if (&*(source_array_in[v][i])==&*(network_in[j]).source)){	//???
//			int w=(*(source_array_in[v][i])).target;
//				if (scArray[w].index==0){
//					strongconnect(w, index, scArray, stack, source_array_in, network_in);
//					scArray[v].lowlink= MIN(scArray[v].lowlink, scArray[w].lowlink);
//				}
//
//				else {
//					for(int m=0; m<=topOfStack; m++){
//						if (stack[m]==w){
//						scArray[v].lowlink= MIN(scArray[v].lowlink, scArray[w].index);
//						break;
//						}
//					}
//				}
//			};
//		};
//		i++;
//	};
//	
//	int x=0;
//	if (scArray[v].lowlink==scArray[v].index){ //everything should now be in the stack up to w=v if SC
//		
//		
//		///////////// View the stack
//		printf("\n%d", topOfStack);
//		for (int i=0; i<=topOfStack; i++){
//			printf("%s%d\n", "The stack contains:", stack[i]);}
//		//////////////////////////////////
//		
//		
//		
//		int m;
//		
//		for (int n=0; n<nodeCount; n++){
//			for (m=0; m<=topOfStack; m++){ // is each node in the network in the stack?
//				if (n==stack[m]){x++;  break;}
//				
//				if (stack[m]==v && x==nodeCount){return(3);}//end of SC component
//				}
//				
//				if(m==(topOfStack)){return(0);}
//				//else if(m==(topOfStack)){return(0);} 
//			}
//			printf("%s%d\n","x=",x);
//			if (x==nodeCount){return(5);}
//		//	}	
//	
//		
//	//	return(1);	
//	}
//
//	
//	return(1);
//}


















/*** File:  sc.c - Tarjan's Strongly Connected Components Algorithm ***/
/*
 *   Shane Saunders
 */








/* sc() - Generates SC components using Tarjan's algorithm.
 * The result is returned as a pointer to a sc_result_t structure.  The SC
 * components are stored as two arrays:
 *   - sets_s[i] gives the starting position in the vertices[] array of SC
 *     component i.
 *   - sets_f[i] gives the finishing position in the vertices[] array of SC
 *     component i.
 *   - vertices[] is used for storing the vertex numbers of vertices in the
 *     SC components.
 * For example if there are three SC components the vertices in each are stored
 * as follows:
 *   - SC0:  vertices[sets_s[0]] ... vertices[sets_f[0]].
 *   - SC1:  vertices[sets_s[1]] ... vertices[sets_f[1]].
 *   - SC2:  vertices[sets_s[2]] ... vertices[sets_f[2]].
 * Note that array entries sets[3] onwards are set to UNDEFINED.
 */

sc_result_t *sc(dgraph_t *g){
  
	int i, v, n;
    sc_result_t *result;

    n = g->n;
    vertices = g->vertices;  /* accessed by sc_recursive() */
    
    /* Allocate space for arrays to represent the search result. */
    result =(sc_result_t*) malloc(sizeof(sc_result_t));
    sc_vertices = result->vertices =(int*) malloc(n * sizeof(int));
    sets_s = result->sets_s =(int*) malloc(n *sizeof(int));
    sets_f = result->sets_f = (int*)malloc(n *sizeof(int));

    /* Allocate space for arrays used while generating the result. */
    sc_stack =(int*) malloc(n * sizeof(int));
    sp =(int*) malloc(n * sizeof(int));
    visit_nos =(int*) malloc(n * sizeof(int));
    low_link_nos =(int*) malloc(n * sizeof(int));
    
    /* Initialise necessary array entries to UNDEFINED.
     *  - sets_s[] and sets_f[] array entries are UNDEFINED, until data is
     *    written into them.
     *  - visit_nos[] array entries are UNDEFINED, until a vertex has been
     *    visited,
     *  - sp[v] is UNDEFINED unless v is in the stack.
     */
    for(i = 0; i < n; i++) {
	sets_s[i] = sets_f[i] = visit_nos[i] = sp[i] = UNDEFINED;
    }

    /* Array sizes in the result structure. */
    result->size = n;
    
    /* Tarjan's algorithm proceeds as a recursive depth first search.  Note
     * that the sc_recursive() function accesses the current graph through the
     * global variable `vertices'.  If parts of the graph were not reached
     * sc_recursive() will be called again, until all vertices have been
     * reached.
     */
    tos = 0;
    n_written = n_visited = 0;
    n_sets = 0;
    
	printf("%s", "\nBefore recursion");
	for(v = 0; v < n; v++) {
		if(visit_nos[v] == UNDEFINED) {sc_recursive(v);}
    }
    result->n_sets = n_sets;
	printf("%s", "\nAfter recursion");
    /* Free space taken up by arrays used while generating the result. */
    free(sc_stack);
    free(sp);
    free(visit_nos);
    free(low_link_nos);

	printf("%d SC components:\n\n", n_sets);
	//sc_result_print(result);
	//sc_result_free(result);


    return (result);
}


/* sc_recursive() - Tarjan's SC component algorithm, proceeds as a depth
 * first search from vertex v in the graph.  Updates the result structure's
 * arrays through the global variables sc_vertices, sets_s, sets_f.
 */
void sc_recursive(int v)
{
	printf("%s", "\nrecursive");
    dgraph_edge_t *edge_ptr;
    int w;

    /* Add vertex v to the result, and increase the counter for the number of
     * vertices in the result.
     */
    low_link_nos[v] = visit_nos[v] = n_visited;
    n_visited++;
	printf("%s", "\nflag 1");
    /* Place v on the stack. */
    sc_stack[tos] = v;
    sp[v] = tos;
    tos++;
    printf("%s", "\nflag2");
    /* Note the algorithm is like a recursive DFS from each w in OUT(v) that is
     * still unvisited.
     */
    edge_ptr = vertices[v].first_edge;
    printf("%s", "\nflag2a");
	while(edge_ptr) {
        w = edge_ptr->vertex_no;
	printf("%s", "\nflag3");
        if(visit_nos[w] == UNDEFINED) {
	    sc_recursive(w);
		printf("%s", "\nflag4");
	    /* Update low_link no. */
	    if(low_link_nos[w] < low_link_nos[v])
		low_link_nos[v] = low_link_nos[w];
	}
	else if(visit_nos[w] < visit_nos[v] && sp[w] != UNDEFINED) {

	    /* Update low_link no. */
            if(visit_nos[w] < low_link_nos[v]) low_link_nos[v] = visit_nos[w];
	}
	printf("%s", "\nflag5");
        edge_ptr = edge_ptr->next;
    }

    /* If all vertices in v's SC component have been found. */
    if(low_link_nos[v] == visit_nos[v]) {
        int vpos = sp[v];
        int i;

	sets_s[n_sets] = n_written;
	printf("%s", "\nflag6");
        /* The SC component vertices are stored from the top of the stack, down
	 * to v.  Wite these to the result structure.
	 */        
        for(i = vpos; i < tos; i++) {
            sc_vertices[n_written] = sc_stack[i];
            n_written++;
        }
        printf("%s", "flag7");
        /* Now remove these vertices from the stack. */
        for(i = vpos; i < tos; i++) sc_stack[i] = UNDEFINED;
        tos = vpos;

	sets_f[n_sets] = n_written - 1;
	n_sets++;
    }
}


/* sc_result_free() - Frees space used by a SC component result structure.
 */
void sc_result_free(sc_result_t *r)
{
    free(r->vertices);
    free(r->sets_s);
    free(r->sets_f);
    free(r);
}


/* sc_result_print() - Displays the SC components stored in an SC component
 * result structure.
 */
void sc_result_print(sc_result_t *r)
{
    int i, j, n_sets;

    n_sets = r->n_sets;
    
    printf("%d SC components:\n\n", n_sets);
    for(i = 0; i < n_sets; i++) {
	printf("SC%d =", i);
	for(j = r->sets_s[i]; j <= r->sets_f[i]; j++) {
            printf(" %3d", r->vertices[j]);
	}
	putchar('\n');
    }
}

//void sc_data_convert (int* size_of_node_array, struct arc*** node_array_in)
//{	// allocate memory for SC data structs
//	//if (nodeCount_cur<nodeCount){printf("\n\n%s\n", "not enough node"); return;}
//
//	//Using total number of nodes/arcs instead of how many in the subgraph?
//
//	
//	dgraph_edge_t* sc_edgeArray = (dgraph_edge_t*) malloc(sizeof(dgraph_edge_t)*nodeCount);
//	dgraph_vertex_t* sc_vertexArray = (dgraph_vertex_t*) malloc(sizeof(dgraph_vertex_t)*nodeCount);
//	dgraph_t* sc_graph = (dgraph_t*) malloc(sizeof(dgraph_t)); 
//
//
//	////////// Stuff goes here //////////////////////////////////////////////
//	(*sc_graph).n=nodeCount;
//	(*sc_graph).vertices=sc_vertexArray;
//	//printf("\n\n%d\n", (*sc_graph).n);
//	//printf("%d\n", (*sc_graph).vertices);
//	
//	// pointer arithmetic may be wrong!
//	/*(sc_vertexArray[0]).first_edge=sc_edgeArray;
//	(sc_vertexArray[0]).last_edge=
//	(sc_vertexArray[1]).first_edge=
//	(sc_vertexArray[1]).last_edge=
//	(sc_vertexArray[n]).first_edge=
//	(sc_vertexArray[n]).last_edge=
//	*/
//	dgraph_edge_t* fEdge = sc_edgeArray; //first edge location for each node(cumulative) 
//	//void* fEdge = &(sc_edgeArray[0].vertex_no); 
//	//printf("%d\n", (*(fEdge)).dist);
//	int a=0;
//	int x=0;
//	
//	for (int n=0; n<nodeCount; n++){
//	
//		//if (n!=0){sc_vertexArray[n].first_edge = sc_edgeArray + size_of_node_array[n-1];}
//		//else {sc_vertexArray[n].first_edge = sc_edgeArray;}
//		//need to iterate though previous nodes and previous edges
//		
//	
//	//	printf("%d\n", sc_vertexArray[n].first_edge);
//	//	printf("%d\n", sc_vertexArray[n].last_edge);
//		//sc_vertexArray[n].last_edge = sc_edgeArray + size_of_node_array[n];
//	
//		
//
//		
//        for (a=0; a<size_of_node_array[n]; a++){
//            
//            /*sc_edgeArray[0].vertex_no=
//            sc_edgeArray[0].dist=
//            sc_edgeArray[0].next=
//            sc_edgeArray[1].vertex_no=
//            sc_edgeArray[1].dist=
//            sc_edgeArray[1].next=*/
//            
//            sc_edgeArray[x].vertex_no = (*node_array_in[n][a]).target;
//            sc_edgeArray[x].dist = (*node_array_in[n][a]).cost;
//            //sc_edgeArray[x].next = &sc_edgeArray[++x];
//            
//            //printf("%d\n", sc_edgeArray[x].vertex_no);
//            //printf("%d\n", sc_edgeArray[x].dist);
//
//
//            if (x!=size_of_node_array[n]) {
//                sc_edgeArray[x].next = &sc_edgeArray[++x];
//            }
//            else {
//                sc_edgeArray[x++].next=0;// = 0;
//            }// &sc_edgeArray[0];}  // I don't get this
//        }
//		
//		printf("%d\n", (*(fEdge-1)).dist);// works fine
//		//printf("%d\n", (*(fEdge)).next);
//		sc_vertexArray[n].first_edge = fEdge;
//		fEdge = fEdge + size_of_node_array[n];
//		sc_vertexArray[n].last_edge = fEdge-1;
//    }
//
////	printf("%d\n", (*(sc_vertexArray[3].first_edge)).dist); //error!
//	
////	printf("%d\n", (*(sc_vertexArray[1].first_edge)).dist);
//	//printf("%d\n", (*(sc_vertexArray[0].last_edge)).dist);
//
//
//	//sc(sc_graph);
//	////////// End Stuff/////////////////////////////////////////////////
//
//	//free(sc_edgeArray);
//	//free(sc_vertexArray);
//	
//	//free(sc_graph);
//	
//
//
//}


//Linked List data convert
void sc_data_convert (int* size_of_node_array, struct arc*** node_array_in)
{
	int i;
	

}
