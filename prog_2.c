#include <stdio.h>
#include <stdlib.h>
#define MAX 50
int top = -1;
char stack[MAX];
char postfixExp[100];

int isEmpty(){
	return top == -1;
}

int isFull(){
	return top == MAX - 1;
}

void push(char value){
	if(isFull()){
		printf("Stack overflow\n");
	}
	else{
		stack[++top] = value;
		printf("%c Pushed to stack.\n",value);
	}
}

int pop () {
    if (isEmpty ()) {
        printf("Stack Underflow: No elements to pop.\n");
        return -1;
    } 
    else {
        char popped = stack[top --];
        printf("%c popped from stack\n", popped);
        return popped;
    }
}

void display(){
	if(isEmpty()){
		printf("Stack is empty.\n");
	}
	else{
		printf("The stack element is as follow:\n");
		for(int i = 0; i <= top; i++){
			printf("%c\n",stack[i]);
		}
	}
}

int precedence(char c){
    if(c == '^')
        return 3;
    else if(c == '*' || c == '/')
        return 2;
    else if(c == '+' || c == '-')
        return 1;
    else
        return -1;
}

void checkExpression(char exp[]){
    int i, j = 0;
    for (i = 0; exp[i] != '\0'; i++)
    {
        if(exp[i] == '('){
            push(exp[i]);
        }
        else if(exp[i] == ')'){
            while(!isEmpty() && stack[top] != '('){
                postfixExp[j++] = pop();
            }
            if(!isEmpty() && stack[top] == '(')
                pop();
        }
        else if(precedence(exp[i]) != -1){
            while(!isEmpty() && precedence(stack[top]) >= precedence(exp[i])){
                postfixExp[j++] = pop();
            }
            push(exp[i]);
        }
        else{
            postfixExp[j++] = exp[i];
        }
    }
    while(!isEmpty()){
        postfixExp[j++] = pop();
    }
    postfixExp[j] = '\0';
}

int main(){
    char test[30] = "a+(b+c)";
    checkExpression(test);
    printf("Postfix Expression: %s\n", postfixExp);
    return 0;
}