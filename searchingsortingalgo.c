//bubble sort using arrays

void bubblesortarray(Array *a){
    int length = a->length; swapped = 0;
    for(int i=0; i<length; i++){
        swapped = 0;
        for(int j=0; j=length-i-1;j++){
            int temp = a->A[j];
            a->A[j] = a->A[j+1];
            a->A[j+1] = temp;
            swapped = 1;
        }
        if(!swapped) break;
    }
    return;
}

//bubble sort using linked list

void bubblesortlinkedlist(List *l){
    if(!(*l)) return;
    int len = length(*l);
    int swapped = 0;
    Node *p= NULL;
    Node *q= NULL;
    Node *s= NULL;
    for(int i=0; i<len;i++){
        p = *l;
        q=p->next;
        swapped = 0;
        while(q != s){
            if(p->data > q->data){
                swapNodes(l,p,q);
                swapped = 1;
            }
            p = q;
            q = p->next;
        }
        s = p;
        if(!swapped) return;
    }
    return;
}

// selection sort using Array

void selectionsortarray(Array *a){
    int length = a->length;
    for(int i=0; i<length; i++){
        int smallestIndex = i;
        for(int j=i+1; j<length; j++){
            if(a->A[smallestIndex]>a->A[j]){
                smallestIndex = j;
            }
        }
        int temp = a->A[smallestIndex];
        a->A[smallestIndex] = a->A[i];
        a->A[i] = temp;
    }
    return;
}

//selection sort using linked List

void selectionsortlinkedlist(List *l){
    if(!(*l)) return;
    
    Node *p = *l;
    Node *q = NULL;
    Node *s = NULL;
    while(p->next){
        s=p;
        q=p->next;
        while(q){
            if(s->data > q->data){
                s=q;
            }
            q=q->next;
        }
        swapNodes(l, p, s);
        p = s;
        p = p->next;
    }
    return;
}

//insertion sort using Array

void insertionsortarray(Array *a){
    int length = a->length;
    for(int i=0; i<length;i++){
        int key = a->A[i];
        int j = i-1;
        while(j>=0 &&a->A[j]>key){
            a->A[j+1] = a->A[j];
            j--;
        }
        a->A[j+1] = key;
    }
    return;
}

//insertion sort using linked List

void insertionsortlinkedlist(List *l){
    if(!(*l)) return;
    Node *p = *l;
    Node *q = p->next;
    while(q){
        p=*l;
        int index = 0;
        while(p->data < q->data && p!=q){
            p=p->next;
            index++;
        }
        if(p==q){
            q=q->next;
            continue;
        }
        Node *r = q->next;
        removeandInsert(l,q,index);
        q=r;
    }
    return;
}

//quicksort using array 

swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(Array *a, int low, int high){
    int pivot = a->A[high]; // choosing last element as pivot
    int i = (low - 1); //index of smaller element
    for(int j = low; j<high; j++){
        if(a->A[j] < pivot){
            i++;
            swap(&a->A[i], &a->A[j]);
        }
    }
    swap(&a->A[i+1], &a->A[high]);
    return i+1;
}

void quicksortarray(Array *a, int low, int high){
    if(low<high){
        int pi = partition(a, low, high);
        quicksortarray(a,low,pi-1);
        quicksortarray(a,pi+1,high);
    }
}







//linear search using Array

int linearsearcharray(Array a, int data){
    if(a.length==0) return INT_MIN;
    int length = a.length;
    for(int i=0;i<length;i++){
        if(a.A[i] == data){
            return i;
        }
    }
    return INT_MIN;
}

//linear search using linked list

int linearsearchlinkedlist(List l, int data){
    if(!l) return INT_MIN;
    int i=0;
    while(l){
        if(l->data == data){
            return i;
        }
        i++;
    }
    l=l->next;
}

//binary search using array

int binarysearcharray(Array a, int data){
    int left = 0;
    int right = a.length - 1;
    while(left<=right){
        int mid = left + (right - left)/2;
        if(a.A[mid] == data){
            return mid;
        } else if(a.A[mid] < data) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return INT_MIN;
}

//binary search using linked List

Node *findmiddle(Node *start, Node *end){
    if(start) return NULL;
    Node *slow = start;
    Node *fast = start;
    while(fast != end && fast->next != end){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}


int binarysearchlinkedlist(List l, int data){
    Node *start = l;
    Node *end = NULL;
    while(start!=end){
        Node *mid = findmiddle(start,end);
        if(mid->data == data){
            return 1;
        }
        if(data<mid->data){
            end = mid;
        } else{
            start = mid->next;
        }
    }
    return INT_MIN;
}



// last year ese q on binary search

void sort(int arr[], int n){
    if(n<=1) return;
    for(int i =0; i<n; i++){
        for(int j=0; j<n; j++){
            if (arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    return;
}

int binarysearch(int arr[], int n, int key){
    if(n<=0) return;
    
    sort(arr,n);
    int start = 0;
    int end = n-1;
    while(start<=end){
        int mid=start + (end-start)/2;
        if(arr[mid] == key){
            return 1;
        }else if{
            
        }
    }
}




