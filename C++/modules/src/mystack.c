char stack[100];
int p = -1;

void push(char c){
    stack[++p] = c;
}

char pop(){
    if(p<0) return -1;
    return stack[p--];
}
