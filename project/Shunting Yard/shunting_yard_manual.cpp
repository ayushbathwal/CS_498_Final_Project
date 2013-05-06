#include<iostream>
#include<string>
#include<sstream>
#include<cmath>
#include<queue>
#include <stdlib.h> 
using namespace std;

inline volatile long long RDTSC() {   register long long TSC asm("eax");   asm volatile (".byte 15, 49" : : : "eax", "edx");   return TSC;}
int push,pop;

class Stack_string {   int MaxStack;   int EmptyStack;   int top;   string* items;public:   Stack_string(int);   ~Stack_string();   void push_string(string);   string pop_string();
   string top_stack_string();
   bool empty_string();
   int size_string();};

Stack_string::Stack_string(int size) {   MaxStack = size;   EmptyStack = -1;   top = EmptyStack;   items = new string[MaxStack];}Stack_string::~Stack_string() {delete[] items;}void Stack_string::push_string(string c) {   items[++top] = c;}
string Stack_string::top_stack_string() {

	return items[top];

}
string Stack_string::pop_string() {   return items[top--];}

bool Stack_string::empty_string() {   if(top==-1)
   	return true;
   else 
   	return false;}

int Stack_string::size_string() {   return (top+1);}

class Stack_float {   int MaxStack;   int EmptyStack;   int top;   float* items;public:   Stack_float(int);   ~Stack_float();   void push_float(float);   float pop_float();
   float top_stack_float();};

Stack_float::Stack_float(int size) {   MaxStack = size;   EmptyStack = -1;   top = EmptyStack;   items = new float[MaxStack];}Stack_float::~Stack_float() {delete[] items;}void Stack_float::push_float(float c) {   items[++top] = c;}
float Stack_float::top_stack_float() {

	return items[top];

}
float Stack_float::pop_float() {   return items[top--];}

bool is_func(string);
bool is_op(string);
bool is_left(char);
int get_prec(char);
float operate(float, string);
float operate(float, float, char);
struct output_data
{
	float num;
	string opf;
	bool is_num;
	
	output_data(float n)
	{
		num = n;
		is_num = true;
	}
	
	output_data(string o)
	{
		opf = o;
		is_num = false;
	}
};
int main()
{
	push=pop=0;
	unsigned long long start_c, end_c;
	cout << "Input Expression: ";
	string in;
	getline(cin, in);
	stringstream str (in);
	
	queue<output_data> output;
	Stack_string opfs(100);
	
	string part;
	start_c=RDTSC();
	while(str >> part)
	{
		if(!is_func(part) && !is_op(part))
		{
			output_data temp ((float)atof(part.c_str()));
			output.push(temp);
			push++;
		}
		else if(is_func(part))
		{
			opfs.push_string(part);
			push++;
		}
		else
		{
			char op = part[0];
			int prec = get_prec(op);
			bool left = is_left(op);
			if(op != '(' && op != ')')
			{
				while(!opfs.empty_string() && (left && prec <= get_prec(opfs.top_stack_string()[0])) || (!left && prec < get_prec(opfs.top_stack_string()[0])))
				{
					output.push(opfs.top_stack_string());
					push++;
					opfs.pop_string();
					pop++;
				}
				string temp (1, op);
				opfs.push_string(temp);
				push++;
			}
			
			if(opfs.size_string() == 0 || op == '(')
			{
				string temp (1, op);
				opfs.push_string(temp);
				push++;
			}
			
			if(op == ')')
			{
				while(opfs.top_stack_string()[0] != '(')
				{
					output.push(opfs.top_stack_string());
					push++;
					opfs.pop_string();
					pop++;
				}
				opfs.pop_string();
				
				if(is_func(opfs.top_stack_string()))
				{
					output.push(opfs.top_stack_string());
					push++;
					opfs.pop_string();
					pop++;
				}
			}
		}
	}
	
	while(!opfs.empty_string())
	{
		output.push(opfs.top_stack_string());
		push++;
		opfs.pop_string();
		pop++;
	}
	
	Stack_float eval (100);
	while(!output.empty())
	{
		output_data out = output.front();
		output.pop();
		pop++;
		
		if(out.is_num)
		{
			eval.push_float(out.num);
			push++;
		}
		else if(is_func(out.opf))
		{
			float num = eval.top_stack_float();
			eval.pop_float();
			pop++;
			
			float res = operate(num, out.opf);
			
			eval.push_float(res);
			push++;
		}
		else
		{
			float num1 = eval.top_stack_float();
			eval.pop_float();
			pop++;
			float num2 = eval.top_stack_float();
			eval.pop_float();
			pop++;
			
			float res = operate(num2, num1, out.opf[0]);
			
			eval.push_float(res);
			push++;
		}
	}
	end_c=RDTSC();
	cout << eval.top_stack_float() << endl;
	cout <<"Pushes - "<<push<<endl;
	cout <<"Pops - "<<pop<<endl;
	cout <<"Manual - "<<(end_c-start_c)<<endl;
	
	return 0;
}
//checks whether the string is a function or not.
bool is_func(string check)
{
	if(check == "sin" || check == "cos" || check == "log")
		return true;
	return false;
}
//checks whether the string is an operator or not.
bool is_op(string check)
{
	if(check.length() > 1)
		return false;
	
	switch(check[0])
	{
		case '+':
		case '-':
		case '*':
		case '/':
		case '^':
		case '(':
		case ')':
			return true;
		default:
			return false;
	}
}
bool is_left(char op)
{
	switch(op)
	{
		case '+':
		case '-':
		case '*':
		case '/':
			return true;
		default:
			return false;
	}
}
int get_prec(char op)
{
	switch(op)
	{
		case '^':
			return 2;
		case '*':
		case '/':
			return 1;
		case '+':
		case '-':
			return 0;
		default:
			return -1;
	}
}
//evaluates a function.
float operate(float num, string func)
{
	if(func == "sin")
		return sin(num);
	else if(func == "cos")
		return cos(num);
	else if(func == "log")
		return log10(num);
	
	return 0;
}
//evaluates an operator.
float operate(float num1, float num2, char op)
{
	switch(op)
	{
		case '+':
			return num1 + num2;
		case '-':
			return num1 - num2;
		case '*':
			return num1 * num2;
		case '/':
			return num1 / num2;
		case '^':
			return pow(num1, num2);
		default:
			return 0;
	}
}
