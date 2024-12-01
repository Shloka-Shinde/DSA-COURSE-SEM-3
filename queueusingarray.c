typedef struct queue{
    int front, rear, size;
    int *Q;
}Queue;

void init(Queue *q, int size){
    q->front = q->rear = -1;
    q->size = size;
    q->Q = (int*)malloc(sizeof(int)*size);
    return;
}

int isEmpty(Queue q){
    if(q.front == -1) return 1;
    return 0;
}

int isFull(Queue q){
    if(q.rear == q.size -1) return 1;
    return 0;
}
void enQueue(Queue *q, int data){
    if(isFull(*q)) return;
    if(isEmpty(*q)) q->front = 0;
    q->Q[++q->rear] = data;
    return;
}

int deQueue(Queue *q){
    if(isEmpty(*q)) return INT_MIN;
    int data = q->Q[q->front++];
    if(q->front > q->rear){
        q->front = q-> rear = -1;
    }
    return data;
}

int peek(Queue q){
    if(isEmpty(q)) return INT_MIN;
    return q.Q[q.front];
}

void display(Queue q){
    if(isEmpty(q)) return INT_MIN;
    
    for(int i = q.front; i< q.rear+1; i++){
        printd("%d", q.Q[i]);
        
    }
    return;
}













