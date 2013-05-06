#include <iostream>#include <ctime>#include <malloc.h> 
#include <cstdlib>
#include <sstream>
#include <math.h>
#include <stack>

#define ROOT_NODE 1 
#define STARTING_LEVEL 1
 using namespace std;
int push,pop;

int num_nodes=1;

inline volatile long long RDTSC() {   register long long TSC asm("eax");   asm volatile (".byte 15, 49" : : : "eax", "edx");   return TSC;}


class stack_m {   int MaxStack;   int EmptyStack;   int top;   int* items;public:   stack_m(int);   ~stack_m();   void push_m(int);   int pop_m();
   int top_stack_m();
   int size_m();
   bool isEmpty_m();
   };

stack_m::stack_m(int size) {   MaxStack = size;   EmptyStack = -1;   top = EmptyStack;   items = new int[MaxStack];}stack_m::~stack_m() {delete[] items;}
int stack_m::size_m() {   return (top+1);}void stack_m::push_m(int c) {   items[++top] = c;}
int stack_m::top_stack_m() {

	return items[top];

}
int stack_m::pop_m() {   return items[top--];} 

bool stack_m::isEmpty_m(){

   if(top==-1)
   	return true;
   else 
   	return false;


} class Graph {    private:        int n;            public:
        int **A;        Graph(int size = 2);        ~Graph();        bool isConnected(int, int);        void addEdge(int x, int y);        void DFS(int , int, int);
        void DFS_stl(int , int);
        void populate_graph(int ,int , int ,int );}; 


 Graph::Graph(int size) {    int i, j;    if (size < 2) n = 2;    else n = size;    A = new int*[n];    for (i = 0; i < n; ++i)        A[i] = new int[n];    for (i = 0; i < n; ++i)        for (j = 0; j < n; ++j)            A[i][j] = 0;}  Graph::~Graph() {    for (int i = 0; i < n; ++i)    delete [] A[i];    delete [] A;}  bool Graph::isConnected(int x, int y) {    return (A[x-1][y-1] == 1);}  void Graph::addEdge(int x, int y) {    A[x-1][y-1] = A[y-1][x-1] = 1;}  void Graph::DFS(int x, int required, int size){    
    stack_m s(size);    bool *visited = new bool[n+1];    int i;    for(i = 0; i <= n; i++)        visited[i] = false;    s.push_m(x);
    //cout<<"PUSH"<<endl;
    push++;    visited[x] = true;    if(x == required) return;    //cout << "Depth first Search starting from vertex ";    //cout << x << " : " << endl;    while(!s.isEmpty_m()){        int k = s.pop_m();
        //cout<<"POP"<<endl;
        pop++;        if(k == required) break;        //cout<<k<<" ";        for (i = n; i >= 0 ; --i)            if (isConnected(k, i) && !visited[i]) {                s.push_m(i);
                //cout<<"PUSH"<<endl;
                push++;                visited[i] = true;            }    }    //cout<<endl;    delete [] visited;}

void Graph::DFS_stl(int x, int required){    stack <int> s;    bool *visited = new bool[n+1];    int i;    for(i = 0; i <= n; i++)        visited[i] = false;    s.push(x);    visited[x] = true;    if(x == required) return;    //cout << "Depth first Search starting from vertex ";    //cout << x << " : " << endl;
    bool temp=true;    while(!(temp=s.empty())){        int k = s.top();
        s.pop();        if(k == required) break;        //cout<<k<<" ";        for (i = n; i >= 0 ; --i)            if (isConnected(k, i) && !visited[i]) {                s.push(i);                visited[i] = true;            }    }    //cout<<endl;    delete [] visited;} 

void Graph::populate_graph(int max_level,int current_level, int parent,int max_child) {

	if(max_level<current_level)
		return ;
	else{
	
		int num_children= 2 + (rand() % (int)(max_child - 2 + 1));
		
		//cout<<"num-child -> "<<num_children<<endl;
		
		for( int i = 0 ; i<num_children ; i++){
			
			num_nodes++;
			//cout<<parent<< " " <<num_nodes<<endl;
			
			addEdge(parent,num_nodes);
			populate_graph(max_level,(current_level+1), num_nodes, max_child);
		
		
		}
	} 
		

} int main(){

	unsigned long long start_c, end_c;
	push=pop=0;
	
	string input = "";
	int max_lvl= 0;
	int max_child = 0;
	int start_dfs = 0;
	int end_dfs = 0;
	
	cout << "Please enter a valid number for max level: ";
   	getline(cin, input);
	
    stringstream myStream(input);
	if(myStream >> max_lvl)
	{	
		cout << "Please enter a valid number for max number of children: ";
	   	getline(cin, input);
	
		stringstream myStream(input);
		myStream >> max_child;
		cout<<"max_ch -> "<<max_child<<" max_lvl -> "<<max_lvl<<endl;
	}
   
	int no_edges = pow (max_child,(max_lvl+1));    Graph g(no_edges);
    
    srand ( time(NULL) );
		
    g.populate_graph(max_lvl,ROOT_NODE,STARTING_LEVEL,max_child);
    
    
    cout<<"The graph has been populated and the total number of nodes = "<<num_nodes<<endl;
    
        
    for(int j=0;j<3;j++)
	{
		cout << "Please enter a valid number for starting node (it has to be between 1 and the above total # of nodes: ";
   		cin  >> start_dfs;
	
		cout << "Please enter a valid number for ending node (it has to be between 1 and the above total # of nodes: ";
		cin  >> end_dfs;
			
		start_c=RDTSC();
		for(int i=0;i<10;i++){			g.DFS(start_dfs, end_dfs, no_edges);
		}
		end_c=RDTSC();
		//cout<<"PUSH "<<push<<endl;
		//cout<<"POP "<<pop<<endl;
		cout<<"Cycles for manual- "<<((end_c-start_c)/10)<<endl;
	}
	
	for(int j=0;j<3;j++)
	{
		cout << "Please enter a valid number for starting node (it has to be between 1 and the above total # of nodes: ";
   		cin  >> start_dfs;
	
		cout << "Please enter a valid number for ending node (it has to be between 1 and the above total # of nodes: ";
		cin  >> end_dfs;
			
		start_c=RDTSC();
		for(int i=0;i<10;i++){			g.DFS_stl(start_dfs, end_dfs);
		}
		end_c=RDTSC();
		cout<<"Cycles for STL- "<<((end_c-start_c)/10)<<endl;
	}
	    return 0;}
