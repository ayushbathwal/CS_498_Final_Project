#include "stack.h"
#include <cstdlib>
#include <stack>

using namespace std;

inline volatile long long RDTSC() {

int main(int argc, char** argv)
//Code for initializing an array with random integers
   unsigned long long start_c, end_c;
   int sz=0;
   int size = atoi(argv[1]);
   //int *temp=new int[size];
   
   int temp[size];
   
   int i=0;
   
   srand ( time(NULL) );
   for(i=0;i<size;i++){
	   //cout<<temp[i]<<endl;
//Code for pushing and poping elements in the stack created manually
   
   for(i=0;i<size;i++){
	   	
   		start_c=RDTSC();
   			sz=s.top;
   		end_c=RDTSC();
   		cout<<"manual -"<<(end_c-start_c)<<endl;
   
   }
   
   
   
   for(i=0;i<size;i++){
	}
	
	
    
    stack <int> stl_stack;
    for(i=0;i<size;i++){
	   stl_stack.push(temp[i]);
	   start_c=RDTSC();
        sz=stl_stack.size();
       end_c=RDTSC();
       cout<<"STL -"<<(end_c-start_c)<<endl;
    
	}
	
	
	
	for(i=0;i<size;i++){
	
	   stl_stack.pop();
	}
   

int Stack::top_stack() {

	return items[top];

}
