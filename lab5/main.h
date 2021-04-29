typedef struct 
{
    int *element;
    int top;
    int size;
} stack_t;

stack_t* create_node(const int size);
void deleteStack(stack_t** st);
void resize(stack_t *st);
void push(stack_t* st, const int elem);
int peek(stack_t* st);
int pop(stack_t* st);
void fill(int* arr,const int size, stack_t* st);
void fillThird(stack_t* st1, stack_t* st2, stack_t* st3);
