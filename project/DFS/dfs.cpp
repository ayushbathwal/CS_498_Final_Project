#include <iostream>
#include <cstdlib>
#include <sstream>
#include <math.h>
#include <stack>

#define ROOT_NODE 1 
#define STARTING_LEVEL 1
 
int push,pop;

int num_nodes=1;

inline volatile long long RDTSC() {


class stack_m {
   int top_stack_m();
   int size_m();
   bool isEmpty_m();
   

stack_m::stack_m(int size) {
int stack_m::size_m() {
int stack_m::top_stack_m() {

	return items[top];

}


bool stack_m::isEmpty_m(){

   if(top==-1)
   	return true;
   else 
   	return false;


}
        int **A;
        void DFS_stl(int , int);
        void populate_graph(int ,int , int ,int );



    stack_m s(size);
    //cout<<"PUSH"<<endl;
    push++;
        //cout<<"POP"<<endl;
        pop++;
                //cout<<"PUSH"<<endl;
                push++;

void Graph::DFS_stl(int x, int required){
    bool temp=true;
        s.pop();

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
		

}

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
   
	int no_edges = pow (max_child,(max_lvl+1));
    
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
		for(int i=0;i<10;i++){
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
		for(int i=0;i<10;i++){
		}
		end_c=RDTSC();
		cout<<"Cycles for STL- "<<((end_c-start_c)/10)<<endl;
	}
	