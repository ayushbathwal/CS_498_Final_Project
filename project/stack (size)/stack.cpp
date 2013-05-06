#include "stack.h"#include <iostream>
#include <cstdlib>
#include <stack>

using namespace std;

inline volatile long long RDTSC() {   register long long TSC asm("eax");   asm volatile (".byte 15, 49" : : : "eax", "edx");   return TSC;}

int main(int argc, char** argv){
//Code for initializing an array with random integers
   unsigned long long start_c, end_c;
   int sz=0;
   int size = atoi(argv[1]);
   //int *temp=new int[size];
   
   int temp[size];
   
   int i=0;
   
   srand ( time(NULL) );
   for(i=0;i<size;i++){	   temp[i] = rand()%100 ;
	   //cout<<temp[i]<<endl;	}
//Code for pushing and poping elements in the stack created manually
      Stack s(size);    
   for(i=0;i<size;i++){	   	s.push(temp[i]);
	   	
   		start_c=RDTSC();
   			sz=s.top;
   		end_c=RDTSC();
   		cout<<"manual -"<<(end_c-start_c)<<endl;
   
   }
   
   
   
   for(i=0;i<size;i++){	   s.pop();
	}
	
	//Code for pushing and poping elements in the stl stack   
    
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
      return 0;}
Stack::Stack(int size) {   MaxStack = size;   EmptyStack = -1;   top = EmptyStack;   items = new int[MaxStack];}Stack::~Stack() {delete[] items;}inline void Stack::push(int c) {   items[++top] = c;}
int Stack::top_stack() {

	return items[top];

}
inline int Stack::pop() {   return items[top--];}
