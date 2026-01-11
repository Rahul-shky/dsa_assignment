#include <stdio.h>
#include <stdlib.h>
#define MAX 10
int stack[MAX];
int top = -1;

int isFull(){
    return top == MAX - 1;
}

int isEmpty(){
    return top == -1;
}

void push(int value){
    if(isFull()){
        printf("The stack is full.\n");
    }
    else{
        stack[++top] = value;
        printf("%d has been pushed.\n",value);
    }
}

int pop(){
    if(isEmpty()){
        printf("The stack is empty.\n");
        return -1;
    }
    else{
        int popped = stack[top--];
        printf("%d has been popped.\n",popped);
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
            printf("%d\n", stack[i]);
        }
        printf("\n");
    }
}

int main(){
    push(10);
    push(20);
    push(100);
    display();
    pop();
    display();
    return 0;
}