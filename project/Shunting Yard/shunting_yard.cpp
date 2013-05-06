#include<iostream>
#include<string>
#include<sstream>
#include<cmath>
#include<stack>
#include<queue>
#include <stdlib.h> 
using namespace std;

inline volatile long long RDTSC() {   register long long TSC asm("eax");   asm volatile (".byte 15, 49" : : : "eax", "edx");   return TSC;}

int push,pop;
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
	stack<string> opfs;
	
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
			opfs.push(part);
			push++;
		}
		else
		{
			char op = part[0];
			int prec = get_prec(op);
			bool left = is_left(op);
			if(op != '(' && op != ')')
			{
				while(!opfs.empty() && (left && prec <= get_prec(opfs.top()[0])) || (!left && prec < get_prec(opfs.top()[0])))
				{
					output.push(opfs.top());
					push++;
					opfs.pop();
					pop++;
				}
				string temp (1, op);
				opfs.push(temp);
				push++;
			}
			
			if(opfs.size() == 0 || op == '(')
			{
				string temp (1, op);
				opfs.push(temp);
				push++;
			}
			
			if(op == ')')
			{
				while(opfs.top()[0] != '(')
				{
					output.push(opfs.top());
					push++;
					opfs.pop();
					pop++;
				}
				opfs.pop();
				
				if(is_func(opfs.top()))
				{
					output.push(opfs.top());
					push++;
					opfs.pop();
					pop++;
				}
			}
		}
	}
	
	while(!opfs.empty())
	{
		output.push(opfs.top());
		push++;
		opfs.pop();
		pop++;
	}
	
	stack<float> eval;
	while(!output.empty())
	{
		output_data out = output.front();
		output.pop();
		pop++;
		
		if(out.is_num)
		{
			eval.push(out.num);
			push++;
		}
		else if(is_func(out.opf))
		{
			float num = eval.top();
			eval.pop();
			pop++;
			
			float res = operate(num, out.opf);
			
			eval.push(res);
			push++;
		}
		else
		{
			float num1 = eval.top();
			eval.pop();
			pop++;
			float num2 = eval.top();
			eval.pop();
			pop++;
			
			float res = operate(num2, num1, out.opf[0]);
			
			eval.push(res);
			push++;
		}
	}
	end_c=RDTSC();
	cout << eval.top() << endl;
	cout <<"Pushes - "<<push<<endl;
	cout <<"Pops - "<<pop<<endl;
	cout <<"STL - "<<(end_c-start_c)<<endl;
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
