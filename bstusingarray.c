typedef struct bst{
    int *arr;
    int size;
}bst;

void init(bst *t, int size){
    t->size = size;
    t->arr = (int*)malloc(sizeof(int)*size);
    for(int i=0;i<size;i++){
        t->arr[i] = INT_MIN;
    }
}

void insert(bst *t, int val){
    int i=0;
    if(t->arr[i] == INT_MIN){
        t->arr[i] = val;
        return;
    }
    while(i < t->size && t->arr[i] !=INT_MIN){
        if(t->arr[i] > val){
            i = 2*i + 1;
        }else {    
            i = 2*i + 2;
        }
    }
    if(i != t->size){
        t->arr[i] = val;
    }
}

void inorder(bst *root, int index){
    if(index >= root->size) return;
    inorder(root,2*index+1); //left child
    printf("%d", root->arr[index]); //visit node
    inorder(root,2*index+2); //right child 
}

void preorder(bst *root, int index){
    if(index >= root->size) return;
    printf("%d",root->arr[index]); //visit node
    preorder(root,2*index+1); //left child
    preorder(root,2*index+2); //right child
}

void postorder(bst *root, int index){
    if(index >= root->size) return;
    preorder(root,2*index+1); //left child
    preorder(root,2*index+2); //right child
    printf("%d",root->arr[index]); //visit node
} 

//non recursive function to count leaf nodes
int count_leaf(bst *t){
    int count = 0;
    for(int i=0; i<t->size; i++){
        if(t->arr[i]!=INT_MIN){
            int left = 2*i + 1;
            int right = 2*i + 2;
            if((left >= t->size || t->arr[left] == INT_MIN) && (right >= t->size || t->arr[right] == INT_MIN)  {
                count++;
            }
        }
    }
    return count;
}

//non recursive function to count non leaf nodes

int count_nonleaf(bst *t){
    int count = 0;
    for(int i =0; i<t->size; i++){
        if(t->arr[i]!=INT_MIN){
            int left = 2*i + 1;
            int right = 2*i + 2;
            if(left <t->size && t->arr[left] != INT_MIN || right<t->size && t->arr[right] != INT_MIN){
                count++;
            }
        }
    }
    return count;
}

//recursive function to calculate height of bst

int height(bst *t, int index){
    if(index >= t->size || t->arr[index] == INT_MIN) return -1;
    int lefth=height(t,2*i + 1);
    int righth=height(t,2*i + 2);
    if(lefth>righth){
        return lefth + 1;
    }else {
        return righth + 1;
    }
}

//non recursive function to calculate height of bst

int height(bst *t){
    if(t->arr[0] == INT_MIN) return -1;
    int max_height = 0;
    for(int i=0; i<t->size;i++){
        if(t->arr[i]!=INT_MIN){
            int height = 0;
            int index = i;
            while(index > 0){
                height++;
                index = (index-1)/2; //move to parent
            }
            if(height > max_height) {
                max_height = height;
            }
        }
    }
    return max_height;
}
















