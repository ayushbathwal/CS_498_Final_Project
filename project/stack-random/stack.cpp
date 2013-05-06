#include "stack.h"#include <iostream>
#include <cstdlib>
#include <stack>

using namespace std;

inline volatile long long RDTSC() {   register long long TSC asm("eax");   asm volatile (".byte 15, 49" : : : "eax", "edx");   return TSC;}



int main(int argc, char** argv){

   //Code for initializing an array with random integers
   unsigned long long start_c, end_c;
   struct access {
  	int number;
  	char c;
   } ;
   
   
   int size = 0;
   int counter=0;
   int num_elements=0;
   int struct_counter=0;
   int num_pushes=0;
   int num_pops=0;
   
   cout << "Please enter a valid number for N: ";
   cin  >> size;
   access *arr=new access[size];
   arr[0].number=4;
   arr[0].c='f';
   
   srand ( time(NULL) );
   //This part of the code creates a random set of pushes and pops.
	   while (counter!=size){
	   		
	   		if(struct_counter==size)
	   			break;
	   		
	   		//cout<<struct_counter<<endl;
		   	int temp= 1 + (rand() % (int)(size - 1 + 1));
		   	int decider = 1 + (rand() % (int)(2 - 1 + 1));
		   	if(decider==1){
		   	
		   		if((temp+num_elements)>size)
		   		;	
		   		else
		   		{
		   			
		   			arr[struct_counter].number=temp;
		   			arr[struct_counter].c='u';
		   			counter=counter+temp;
		   			num_elements=num_elements+temp;
		   			struct_counter++;
		   			num_pushes+=temp;
		   		}
		   	}
		   	else
		   	{
		   		if(temp>num_elements)
		   		;
		   		else
		   		{
		   			arr[struct_counter].number=temp;
		   			arr[struct_counter].c='o';
		   			counter=counter+temp;
		   			num_elements=num_elements-temp;
		   			struct_counter++;
		   			num_pops+=temp;
		   		}
		   	
		   	}
	  }
	  	
	  	
	  cout<<"Number of accesses made to stack - "<<counter<<endl;
	  cout<<"Number of PUSHES - "<<num_pushes<<endl;
	  cout<<"Number of POPS - "<<num_pops<<endl;
   
   
   
   //Code for pushing and poping elements in the stack created manually
   start_c=RDTSC();
      Stack s(size);
   
   for(int i=0;i<struct_counter;i++)
   {	
   		if(arr[i].c=='u')
   		{
   			for(int j=0;j<arr[i].number;j++)
   			{
   				s.push(10);
   			}
   		}
   		else
   		{
   			for(int j=0;j<arr[i].number;j++)
   			{
   				s.pop();
   			}
   		}
   } 
   
  
   end_c=RDTSC();
   
   cout<<"Manual -"<<(end_c-start_c)<<endl;
   
   
   //Code for pushing and poping elements in the stl stack   
   
   start_c=RDTSC();
   
   stack <int> stl_stack;
   
   for(int i=0;i<struct_counter;i++)
   {	
   		if(arr[i].c=='u')
   		{
   			for(int j=0;j<arr[i].number;j++)
   			{
   				stl_stack.push(10);
   			}
   		}
   		else
   		{
   			for(int j=0;j<arr[i].number;j++)
   			{
   				stl_stack.pop();
   			}
   		}
   } 
   
   
   end_c=RDTSC();
   
   cout<<"STL -"<<((end_c-start_c))<<endl;
   

	   return 0;}
Stack::Stack(int size) {   MaxStack = size;   EmptyStack = -1;   top = EmptyStack;   items = new int[MaxStack];}Stack::~Stack() {
	delete[] items;
}void Stack::push(int c) {   items[++top] = c;}
int Stack::top_stack() {

	return items[top];

}
int Stack::pop() {   return items[top--];}

int Stack::size(){
	return (top+1);
}
