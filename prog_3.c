#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int value) {
    struct Node* newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

struct Node* insertEnd(struct Node* head, int value) {
    struct Node* temp = head;
    struct Node* newNode = createNode(value);
    if (head == NULL){
        return newNode;
    }
    while (temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

void reverseTraverse(struct Node* head) {
    if (head == NULL){
        return;
    }
    reverseTraverse(head->next);
    printf("%d ", head->data);
}

int main() {
    struct Node* head = NULL;
    head = insertEnd(head, 10);
    head = insertEnd(head, 20);
    head = insertEnd(head, 30);
    head = insertEnd(head, 40);
    printf("Reverse Traversal of Linked List:\n");
    reverseTraverse(head);
    return 0;
}
