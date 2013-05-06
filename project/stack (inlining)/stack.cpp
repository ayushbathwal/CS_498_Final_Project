#include "stack.h"#include <iostream>
#include <cstdlib>
#include <stack>

using namespace std;

inline volatile long long RDTSC() {   register long long TSC asm("eax");   asm volatile (".byte 15, 49" : : : "eax", "edx");   return TSC;}

int main(int argc, char** argv){
//Code for initializing an array with random integers
   unsigned long long start_c, end_c;
   
   int size = 0;
   
   cout << "Please enter a valid number for N: ";
   cin  >> size;
   
   int temp[size];
   
   srand ( time(NULL) );
   
   for(int i=0;i<size;i++){	   temp[i] = rand();
   }
//Code for pushing and poping elements in the stack created manually
   start_c=RDTSC();
      Stack s(size); 
   
   for(int i=0;i<100;i++){   
	   for(int i=0;i<size;i++){		   s.push(temp[i]);
	   }
	   
	   for(int i=0;i<size;i++){		   s.pop();
	   }
   }
   end_c=RDTSC();
   
   cout<<"Manual -"<<((end_c-start_c)/100);
   cout<<endl;;
   //Code for pushing and poping elements in the stl stack   
   
   start_c=RDTSC();
   
   stack <int> stl_stack;
   
   for(int i=0;i<100;i++){   
	   for(int i=0;i<size;i++){		   stl_stack.push(temp[i]);
	   }
	   
	   for(int i=0;i<size;i++){		   stl_stack.pop();
	   }
   }
   
   
   
   end_c=RDTSC();
   
   cout<<"STL -"<<((end_c-start_c)/100)<<endl;

	   return 0;}
Stack::Stack(int size) {   MaxStack = size;   EmptyStack = -1;   top = EmptyStack;   items = new int[MaxStack];}Stack::~Stack() {delete[] items;}inline void Stack::push(int c) {   items[++top] = c;}
int Stack::top_stack() {

	return items[top];

}
inline int Stack::pop() {   return items[top--];}
