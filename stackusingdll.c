typedef struct node{
    char data;
    struct node*next, node*prev;
}Node;

typedef struct stack{
    Node* base, *top;
}Stack;

void init(Stack *s){
    s->base = NULL;
    s->top = NULL;
    return;
}

int isEmpty(Stack s){
    if(s.base == NULL) return 1;
    
    return 0;
}

void push(Stack *s, char data){
    Node *nn =(Node*)malloc(sizeof(Node));
    if(!nn) return;
    nn->data = data;
    nn->next =NULL;
    nn->prev=NULL;
    if(isEmpty(*s)){
        s->base = nn;
        s->top = nn;
        return;
    }
    else{
        nn->prev = s->top;
        s->top->next = nn;
        s->top = nn;
    }
    return;
}

int pop(Stack *s){
    if(isEmpty(*s)) return CHAR_MIN;
    Node *p = s->top;
    s->top = s->top->prev;
    if(s->top) s->top->next=NULL;
    else s->base = NULL;
    
    char data = p->data;
    free(p);
    return data;
}

int peek(Stack s){
    if(isEmpty(s)) return CHAR_MIN;
    return s.top->data;
}

void display(Stack s){
    if(isEmpty(s)) return;
    printf("displaying the stack:");
    for(Node *p=s.base; p!=NULL; p = p->next)
    printf("%d", p->data);
    
    return;
}











