typedef struct stack{
    int *arr;
    int top;
    int size;
}Stack;

void init(Stack *s){
    s->arr=(int*)malloc(sizeof(int)*size);
    s->size=size;
    s->top = -1;
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

typedef struct Queue{
    stack s;
    stack t;
}Queue;

Queue *QueueCreate(){
    Queue *q=(Queue *)malloc(sizeof(Queue));
    init(&(q->s));
    init(&(q->t));
    return q;
}

void QueuePush(Queue *obj, int x){
    stack *st1 = &(obj->s);
    push(st1, x);
}

int QueuePop(Queue *obj){
    stack *st1 = &(obj->s);
    stack *st2 = &(obj->t);
    while(st1->top != -1) {
        push(st2, pop(st1));
    }
    int i = pop(st2);

    while(st2->top != -1) {
        push(st1, pop(st2));
    }

    return i;

}

int QueuePeek(Queue *obj){
    stack *st1 = &(obj->s);
    stack *st2 = &(obj->t);

    while(st1->top != -1) {
        push(st2, pop(st1));
    }

    int i = st2->arr[st2->top];

    while(st2->top != -1) {
        push(st1, pop(st2));
    }

    return i;

}

bool QueueEmpty(Queue *obj){
    stack *st1 = &(obj->s);
    stack *st2 = &(obj->t);

    if(st->top == -1 && st2->top == -1) {
        return true;
    }

    return false;

}

void QueueFree(Queue* obj) {
    return ;
}


















