// character stack using dll for infix zto postfix

int operatorPrecedence(char c){
    switch(c){
        case '(': 
        return INT_MIN;
        case '-':
        case '+':
        return 0;
        case '*':
        case '/':
        case '%':
        return 1;
        case '^':
        return 2;
    }
}

int isOperator(char c){
    switch(c) {
        case '-':
        case '+':
        case '*':
        case '/':
        case '%':
        case '^':
        return 1;
        default: 
        return 0;
    }
}

char *infixtopostfix(char *str, int n){
    Stack s;
    init(&s);
    
    int i=0; j=0;
    char c;
    char *answer = (char*)malloc(sizeof(char)*n);
    while((c==str[i]) != '\0'){
        if(c == ''){
            i++;
            continue;
        }
        if(c == '('){
        push(&s, c);
        i++;
        continue;
        }
        if(c == ')'){
            while(peek(s) != ')'){
                answer[j++] = pop(&s);
                answer[j++] = ' ';
            }
            pop(&s, c);
            i++;
            continue;
        }
        if(isOperator(c)) {
            while(!isEmpty(s) && operatorPrecedence(peek(s) >= operatorPrecedence(c))){
                answer[j++] = pop(&s);
                answer[j++] = ' ';
            }
            push(&s, c);
            i++;
            continue;
        }
        answer[j++] = c;
        if(!isalnum(str[++i] && str[i]!= '.') asnwer[j++] = ' ';
        
    }
    
    while(!isEmpty(s)){
        answer[j++] = pop(&s);
        
    }
    return answer;
}












