#include <iostream>#include <ctime>#include <malloc.h> 
#include <cstdlib>
#include <sstream>
#include <math.h>
#include <stack>
 using namespace std;

inline volatile long long RDTSC() {   register long long TSC asm("eax");   asm volatile (".byte 15, 49" : : : "eax", "edx");   return TSC;}

class stack_m {   int MaxStack;   int EmptyStack;   int top;   int* items;public:   stack_m(int);   ~stack_m();   void push_m(int);   int pop_m();
   int top_stack_m();
   int size_m();
   };

stack_m::stack_m(int size) {   MaxStack = size;   EmptyStack = -1;   top = EmptyStack;   items = new int[MaxStack];}stack_m::~stack_m() {delete[] items;}
int stack_m::size_m() {   return (top+1);}void stack_m::push_m(int c) {   items[++top] = c;}
int stack_m::top_stack_m() {

	return items[top];

}
int stack_m::pop_m() {   return items[top--];}
class sort {    private:                    public:
        int *arr;
        int length;        sort(int);        ~sort();        void q_sort();
        void q_sort_m();
        void SwapElement(int,int);}; 

sort::sort(int size) {   arr = new int[size];
   length = size;}

sort::~sort() {    delete [] arr;} 

int main()
{
	unsigned long long start_c, end_c, temp_c;
	temp_c=0;
	int n=0;    
    cout << "Please enter a valid number for N: ";
   	cin  >> n;
   	int temp[n];
    sort obj(n);
    srand ( time(NULL) );
    
   
    for (int i=0;i<n;i++)
    {
        obj.arr[i]=rand();
        temp[i]=obj.arr[i];
    }
    
    for(int l=0;l<10;l++)
    {
    	for (int j=0;j<n;j++)
    	{	
    		obj.arr[j]=temp[j];
    
    	}
    
		start_c=RDTSC();
		obj.q_sort();
		end_c=RDTSC();
		temp_c=temp_c+(end_c-start_c);
    }
    
    cout<<"STL - "<<(temp_c/10)<<endl;
    
    temp_c=0;
    
    for(int l=0;l<10;l++)
    {
    	for (int j=0;j<n;j++)
    	{	
    		obj.arr[j]=temp[j];
    
    	}
    
		start_c=RDTSC();
		obj.q_sort_m();
		end_c=RDTSC();
		temp_c=temp_c+(end_c-start_c);
    }
    cout<<"Manual - "<<(temp_c/10)<<endl;
   
}

void sort:: q_sort()
{
    stack <int> stack_stl;
    int pivot;
    int pivotIndex = 0;
    int leftIndex = pivotIndex + 1;
    int rightIndex = length - 1;

    stack_stl.push(pivotIndex);//Push always with left and right
    stack_stl.push(rightIndex);

    int leftIndexOfSubSet, rightIndexOfSubset;
	leftIndexOfSubSet = rightIndexOfSubset =0;
    while (stack_stl.size() > 0)
    {
        rightIndexOfSubset = stack_stl.top();//pop always with right and left
        stack_stl.pop();
        leftIndexOfSubSet = stack_stl.top();
        stack_stl.pop();

        leftIndex = leftIndexOfSubSet + 1;
        pivotIndex = leftIndexOfSubSet;
        rightIndex = rightIndexOfSubset;

        pivot = arr[pivotIndex];

        if (leftIndex > rightIndex)
          continue;

        while (leftIndex < rightIndex)
        {
            while ((leftIndex <= rightIndex) && (arr[leftIndex] <= pivot))
             leftIndex++;	//increment right to find the greater 
				//element than the pivot
            while ((leftIndex <= rightIndex) && (arr[rightIndex] >= pivot))
               rightIndex--;//decrement right to find the 
				//smaller element than the pivot

            if (rightIndex >= leftIndex)   //if right index is 
					//greater then only swap
                        SwapElement(leftIndex, rightIndex);
        }

        if (pivotIndex <= rightIndex)
           if( arr[pivotIndex] > arr[rightIndex])
               SwapElement(pivotIndex, rightIndex);
               
        if (leftIndexOfSubSet < rightIndex)
        {
           stack_stl.push(leftIndexOfSubSet);
           stack_stl.push(rightIndex - 1);
        }

        if (rightIndexOfSubset > rightIndex)
        {
            stack_stl.push(rightIndex + 1);
            stack_stl.push(rightIndexOfSubset);
        }
    }
}

void sort:: q_sort_m()
{
    stack_m stack_man(length);
    int pivot;
    int pivotIndex = 0;
    int leftIndex = pivotIndex + 1;
    int rightIndex = length - 1;

    stack_man.push_m(pivotIndex);//Push always with left and right
    stack_man.push_m(rightIndex);

    int leftIndexOfSubSet, rightIndexOfSubset;
	leftIndexOfSubSet = rightIndexOfSubset =0;
    while (stack_man.size_m() > 0)
    {
        rightIndexOfSubset = stack_man.top_stack_m();//pop always with right and left
        stack_man.pop_m();
        leftIndexOfSubSet = stack_man.top_stack_m();
        stack_man.pop_m();

        leftIndex = leftIndexOfSubSet + 1;
        pivotIndex = leftIndexOfSubSet;
        rightIndex = rightIndexOfSubset;

        pivot = arr[pivotIndex];

        if (leftIndex > rightIndex)
          continue;

        while (leftIndex < rightIndex)
        {
            while ((leftIndex <= rightIndex) && (arr[leftIndex] <= pivot))
             leftIndex++;	//increment right to find the greater 
				//element than the pivot
            while ((leftIndex <= rightIndex) && (arr[rightIndex] >= pivot))
               rightIndex--;//decrement right to find the 
				//smaller element than the pivot

            if (rightIndex >= leftIndex)   //if right index is 
					//greater then only swap
                        SwapElement(leftIndex, rightIndex);
        }

        if (pivotIndex <= rightIndex)
           if( arr[pivotIndex] > arr[rightIndex])
               SwapElement(pivotIndex, rightIndex);
               
        if (leftIndexOfSubSet < rightIndex)
        {
           stack_man.push_m(leftIndexOfSubSet);
           stack_man.push_m(rightIndex - 1);
        }

        if (rightIndexOfSubset > rightIndex)
        {
            stack_man.push_m(rightIndex + 1);
            stack_man.push_m(rightIndexOfSubset);
        }
    }
}

void sort::SwapElement(int left, int right)
{
    int temp = arr[left];
    arr[left] = arr[right];
    arr[right] = temp;
}
