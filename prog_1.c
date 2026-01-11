#include <stdio.h>
#include <stdlib.h>
#define MAX 20
char stack[MAX];
int top = -1;
int paranthesisCount = 0;
int curlyParanthesisCount = 0;
int bigParanthesisCount = 0;

int isFull(){
    return top == MAX - 1;
}

int isEmpty(){
    return top == -1;
}

void push(char value){
    if(isFull()){
        printf("The stack is full.\n");
    }
    else{
        if(value == '(' || value == ')'){
            paranthesisCount++;
        }
        else if(value == '{' || value == '}'){
            curlyParanthesisCount++;
        }
        else if(value == '[' || value == ']'){
            bigParanthesisCount++;
        }
        stack[++top] = value;
        printf("%c has been pushed.\n",value);
    }
}

char pop(){
    if(isEmpty()){
        printf("The stack is empty.\n");
        return '\0';
    }
    else{
        char popped = stack[top--];
        printf("%c has been popped.\n",popped);
        return popped;
    }
}

void display(){
    if(isEmpty()){
        printf("Stack is empty.\n");
    }
    else{
        printf("Stack elements:\n");
        for (int i = 0; i <= top; i++)
        {
            printf("%c\n", stack[i]);
        }
        printf("\n");
    }
}

int main(){
    char test[30] = "a+({b+c";
    for(int i = 0; test[i] != '\0'; i++){
        push(test[i]);
    }
    display();
    if(paranthesisCount % 2 == 0 && curlyParanthesisCount % 2 == 0 && bigParanthesisCount % 2 == 0){
        printf("The mathematical expression has balanced number of paranthesis.\n");
    }
    else{
        printf("The mathematical expression doesn't have balanced number of paranthesis.\n");
    }
    return 0;
}