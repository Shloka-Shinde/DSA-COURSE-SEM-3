typedef struct Queue{
    int front, rear, size, length;
    int *Q;
}Queue;
 
void init(Queue *q, int size){
    q->front = q->rear = -1;
    q->size = size;
    q->length = 0;
    q->Q =(Node*)malloc(sizeof(Node));
    
    return;
}

int isEmpty(Queue q){
    if(q.length == 0) return 1;
    return 0;
}

int isFull(Queue q){
    if(q.length == q.size) return 1;
    return 0;
}

void enQueue(Queue *q, int data){
    if(isFull(*q)) return;
    if(isEmpty(*q)) q->front =0;
    q->rear = ++q->rear % size;
    q->Q[q->rear] = data;
    q->length++;
    return;
}

int deQueue(Queue *q){
    if(isEmpty(*q)) return INT_MIN;
    int data = q->Q[q->front];
    q->front = ++q->front % size;
    q->length--;
    return data;
}

void display(Queue q){
    if(isEmpty(q)) return;
    Node *p = q.front;
    printf("printing the queue:");
    for(int i=q.front; i< q.rear+q.length;i++){
        printf("%d", q.Q[i%q.size]);
    }
}







