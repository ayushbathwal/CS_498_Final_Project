class Stack {   int MaxStack;   int EmptyStack;   int* items;public:   int top;   
   Stack(int);   ~Stack();   void push(int);   int pop();
   int top_stack();};
