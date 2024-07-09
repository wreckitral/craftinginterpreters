#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct node {
    char* data;
    struct node* prev;
    struct node* next;
} Node;

// A double pointer to the head of the list,
// pointer to the node which the new node is going to be inserted
// str is the data of the node
void insert(Node** list, Node* prev, const char* str)
{
    Node* node = malloc(sizeof(Node)); // make new Node
    node->data = malloc(strlen(str) + 1); // assign memory in size of str + 1 for the '\0'
    strcpy(node->data, str); // copy the assigned memory size to the str value

    if (prev == NULL) // if true, new node should be inserted in the beginning of the list
    {
        if (*list != NULL) (*list)->prev = node; // checks if the list if empty or not, if its not then the new node will be the head of the list
        node->prev = NULL; // now the new node prev is assigned to null
        node->next = *list; // and the new node next is assigned to the current node
        *list = node; // lastly change the head of the list to new node
    } else {
        node->next = prev->next; // the new node next is assigned to pointer to next from the current node
        if (node->next != NULL) node->next->prev = node; // is not inserted at the end, the next node's prev is node
        prev->next = node; // the current node's next is the new node
        node->prev = prev; // the new node prev is the current node
    }
}

void printList(Node* list)
{
    while (list != NULL) // as long as the head of the list is not empty or as long as the list is still going
    {
        printf("%p [prev %p] [%s] [next %p]\n", list, list->prev, list->data, list->next); // print the lindkedlist data
        list = list->next; // mode the pointer to the next of every node
    }

}

int main()
{
    Node *list = NULL;

    insert(&list, NULL, "one");
    insert(&list, NULL, "two");

    printList(list);
}
