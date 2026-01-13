#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#define MAX 50
int top = -1;
char stack[MAX];
char postfixExp[100];
int evalStack[MAX];
int evalTop = -1;

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


void pushEval(int value){
    if(evalTop == MAX - 1){
        printf("Eval Stack Overflow\n");
    }
    else{
        evalStack[++evalTop] = value;
    }
}

int popEval(){
    if(evalTop == -1){
        printf("Eval Stack Underflow\n");
        return -1;
    }
    else{
        return evalStack[evalTop--];
    }
}

int evaluatePostfix(char* exp){
    int i = 0;
    while(exp[i] != '\0'){
        if(isdigit(exp[i])){
            pushEval(exp[i] - '0');
        }
        else{
            int val1 = popEval();
            int val2 = popEval();
            switch(exp[i]){
                case '+': pushEval(val2 + val1); break;
                case '-': pushEval(val2 - val1); break;
                case '*': pushEval(val2 * val1); break;
                case '/': pushEval(val2 / val1); break;
                case '^': pushEval((int)pow(val2, val1)); break;
            }
        }
        i++;
    }
    return popEval();
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
    char test[30] = "2+3*4-5^2/5"; // 2+12-25/5 = 14-5 = 9
    checkExpression(test);
    printf("Postfix Expression: %s\n", postfixExp);
    printf("Evaluation Result: %d\n", evaluatePostfix(postfixExp));
    return 0;
}