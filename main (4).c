typedef struct heap{
    int *h;
    int size;
    int rear;
}heap;

void init(heap *h1, int k){
    h1->h=(int *)malloc(sizeof(int)*k);
    h1->rear = -1;
    h1->size=k;
    return;
}

int parent(int index){
    return ((index -1)/2);
}

void swaph(heap *h1, int a, int b){
    //swaps element of heap having index as a and b.
    if(a>=h1->size || b>=h1->size) return;
    else{
        int k=h1->h[a];
        h1->h[a] = h1->h[b];
        h1->h[b] = k;
        return;
    }
    return;
}

void insert(heap *h1, int k){
    if(h1->rear == h1->size -1) return;
    h1->rear++;
    h1->h[h1->rear] = k;
    int i=h1->rear;
    while(i>0 && h1->h[i]>h1->h[parent(i)]){
        swaph(h1, i, parent(i));
        i=parent(i);
    }
    return;
}

void print(heap h1){
    for(int i=0; i<=h1.rear;i++){
        printf("%d\t", h1.h[i]);
    }
    printf("\n");
    return;
}

void heapify(heap *h1){
    //heapify using top down approach converts array into heap.
    if(h1->rear==0 || h1->rear==-1) return;
    int j=0;
    while(j<= (h1->rear)){
        int lchild=2*j+1;
        int rchild=2*j+2;
        if(lchild > h1->rear) return;
        if(rchild > h1->rear){
            if(h1->h[j] < h1->h[lchild]){
                swaph(h1,j,lchild);
                j=lchild;
            }
            return;
        }
        if((h1->h[j] > h1->h[lchild]) && (h1->h[j] > h1->h[rchild])) return;
        if(h1->h[lchild] > h1->h[rchild]){
            swaph(h1, j, lchild);
        }else{
            swaph(h1,j,rchild);
            j=rchild;
        }
    }
}

void delete_max(heap *h1){
    if(h1->rear == -1) return;
    
    //replace root (maxm element) with the last element
    h1->h[0] = h1->h[h1->rear];
    //reduce the heap size
    h1->rear--;
    
    //heapify from top(index 0) to restore the max heap property
    heapify(h1);
    return;
}

void heap_sort(heap *h1){
    int k=h1->rear;
    if(h1->rear == -1) return;
    for(int i=h1->rear ; i>0;i--){
        swaph(h1,i,0);
        h1->rear--;
        heapify(h1);
    }
    h1->rear = k;
    printf(*h1);
    return;
}






