#ifndef LIST_H
#define LIST_H
typedef struct listNode
{
    int value;
    struct listNode *next;
} ListNode;

// List has stack methods, but supports iteration as linked list
typedef struct list
{
    int size;
    ListNode *head;
} List;

List* newList();
int isEmpty(List*);
int pop(List*);
void push(List*, int);
#endif