#include "stack.h"
#include <cstdlib>
#include <stack>

using namespace std;

inline volatile long long RDTSC() {

int main(int argc, char** argv)
//Code for initializing an array with random integers
   unsigned long long start_c, end_c;
   
   int size = 0;
   
   cout << "Please enter a valid number for N: ";
   cin  >> size;
   
   int temp[size];
   
   srand ( time(NULL) );
   
   for(int i=0;i<size;i++){
   }
//Code for pushing and poping elements in the stack created manually
   start_c=RDTSC();
   
   
   for(int i=0;i<100;i++){
	   for(int i=0;i<size;i++){
	   }
	   
	   for(int i=0;i<size;i++){
	   }
   }
   end_c=RDTSC();
   
   cout<<"Manual -"<<((end_c-start_c)/100);
   cout<<endl;;
   
   
   start_c=RDTSC();
   
   stack <int> stl_stack;
   
   for(int i=0;i<100;i++){
	   for(int i=0;i<size;i++){
	   }
	   
	   for(int i=0;i<size;i++){
	   }
   }
   
   
   
   end_c=RDTSC();
   
   cout<<"STL -"<<((end_c-start_c)/100)<<endl;

	

int Stack::top_stack() {

	return items[top];

}
