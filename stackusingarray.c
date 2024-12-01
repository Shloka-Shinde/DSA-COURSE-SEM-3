typedef struct stack{
    int size, top;
    int *A;
}Stack;

void init(Stack *s, int size){
    if(size<1) return;
    s->size = size;
    s->top = -1;
    s->A=(int*)malloc(sizeof(int)*size);
    return;
}

int isFull(Stack s){
    if(s.top == (s.size -1)) return 1;
    return 0;
}

int isEmpty(Stack s){
    if(s.top == -1) return 1;
    return 0;
}

void push(Stack *s, int data){
    if(isFull(*s)) return;
    s->A[++s->top] = data;
    return;
}

int pop(Stack *s){
    if(isEmpty(*s)) return INT_MIN;
    return s->A[s->top--];
}

int peek(Stack *s){
    if(isEmpty(*s)) return INT_MIN;
    return s.A[s.top];
}

void display(Stack s){
    printf("displaying the stack: ");
    for(int i=0; i<s.top+1; i++){
        printf("%d", s.A[i]);
    }
    
    return;
}
























