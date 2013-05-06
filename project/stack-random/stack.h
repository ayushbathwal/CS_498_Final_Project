class Stack {   int MaxStack;   int EmptyStack;   int top;   int* items;public:   Stack(int);   ~Stack();   void push(int);   int pop();
   int top_stack();
   int size();};
