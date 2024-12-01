typedef struct node{
    int data;
    struct node *left;
    struct node *right;
}Node;

typedef Node *tree;

void init(tree *t){
    *t = NULL;
    return;
}

Node *generateNode(int data){
    Node *nn = (Node*)malloc(sizeof(Node));
    if(!nn) return NULL;
    nn->data = data;
    nn->left = NULL;
    nn->right = NULL;
    return nn;
}

void preorder(Tree *t){
    printf("%d", t->data);
    preorder(t->left);
    preorder(t->right);
    return;
}

void inorder(Tree *t){
    inorder(t->left);
    printf("%d", t->data);
    inorder(t->right);
    return;
}

void postorder(tree *t){
    postorder(t->left);
    postorder(t->right);
    printf("%d", t->data);
    return;
}

int count(tree t){
    if(!t) return 0;
    return 1 + count(t->left) + count(t->right);
}

//non recursive insert
void insert(tree *t, int data){
    if(!(*t)){
        *t = generateNode(data);
        return;
    }
    Node *p = *t, *q = NULL;
    while(p){
        q = p;
        if(p->data > data){
            p = p->left;
        }else if(p->data < data){
            p = p->right;
        }else{
            printf("the element already exists");
            return;
        }
    }
    if(data > q->data){
        q->right = generateNode(data);
    }else {
        q->left = generateNode(data);
    }
    return;
}

//recursive insert
void insert(Node **root, int val{
    if(*root == NULL){
        *root = generateNode(val);
    }else if((*root)->val > val){
        insert(&(*root)->left, val);
    }else{
        insert(&(*root)->right, val);
    }
}


int search(tree *t, int data){
    if(!(*t)) return 0;
    
    if(t->data == data) return 1;
    Node *p = t;
    while(p){
        if(p->data == data){
            return 1;
        }else if(p->data > data){
            p = p->left;
        }else{
            p=p->right;
        }
    }
    return 0;
}

void delete(Tree *t, int data){
    if(!(*t)) return;
    Node *p = *t; *q = *t;
    char direction;
    while(p->data != data){
        q = p;
        if(p->data > data){
        p = p->left;
        direction = 'l';
       }else {
        p = p->right;
        direction = 'r';
       }
    }
    // handling the case when node has 0 child
    
    if(p->left == NULL && p->right == NULL){
        if(p==q){
            *t = NULL;
            free(p);
            printf("the tree is empty now");
            return;
        }
        free(p);
        if(direction == 'r'){
            q->right = NULL;
        }else {
            q->left = NULL;
        }
        return;
    }
    
    //handling the case when node has 1 child
    
    if(p->left == NULL){
        if(p==q) {
            *t = p->right;
        }else if(direction = 'r'){
            q->right = p->right;
        }else {
            q->left = p->right;
        }
        free(p);
        return;
    }
    
    if(p->right == NULL){
        if(p==q){
           *t = p->left; 
        }else if(direction = 'l'){
            q->right = p->left;
        }else {
            q->left = p->left;
        }
        free(p);
        return;
    }
    
    //handling the case when node has 2 children
    //checking for the smallest number in the right subtree
    
    q = p->right;
    Node *r = p;
    direction = 'r';
    while(q->left){
        r = q;
        direction = 'l';
        q = q->left;
    }
    p->data = q->data;
    if(direction == 'l'){
        r->left = q->right;
    }else {
        r->right = q->left;
    }
    free(q);
    return;
}




