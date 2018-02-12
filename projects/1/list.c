#include <stdlib.h>
#include "list.h"

List* newList()
{
    List *l = (List*)malloc(sizeof(List*));
    l->head = NULL;
    l->size = 0;
    return l;
}

int isEmpty(List *l)
{
    return l->size == 0;
}

int pop(List *l)
{
    ListNode *head = l->head;
    int result = head->value;
    l->head = head->next;
    l->size--;

    return result;
}

void push(List *l, int value)
{
    ListNode *newHead = (ListNode*)malloc(sizeof(ListNode*));
    newHead->value = value;
    newHead->next = l->head;
    l->head = newHead;
    l->size++;
}