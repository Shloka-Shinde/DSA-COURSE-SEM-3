typedef struct node{
    int data;
    struct node * next;
}Node;

typedef struct queue{
    Node *front;
    Node *rear;
}Queue;

void init(Queue *q){
    q->front = NULL;
    q->rear = NULL;
}

int isEmpty(Queue q){
    if(!q.front) return 1;
    return 0;
}

int peek(Queue q){
    if(isEmpty(q)) return INT_MIN;
    return q.front->data;
}


void enQueue(Queue *q, int data){
    Node *nn = (Node*)malloc(sizeof(Node));
    if(!nn) return;
    nn->data = data;
    nn->next = NULL;
    
    if(isEmpty(*q)){
        q->front = nn;
        q->rear = nn;
        return;
    }
    q->rear->next = nn;
    q->rear = nn;
    return;
}

int deQueue(Queue *q){
    if(isEmpty(*q)) return INT_MIN;
    Node *p = q->front;
    int data = p->data;
    if(q->front = q->rear){
        q->front = q->rear = NULL;
    }else {
        q->front = q->front->next;
    }
    free(p);
    return data;
}

void display(Queue q){
    if(isEmoty(q)) return;
    
    printf("displaying the queue: ");
    Node *p = q.front;
    while(p){
        printf("%d", p->data);
        p = p->next;
    }
    return;
}




















