#include <stdio.h>

#include <stdlib.h>

struct DoublyLinkedList
{
	int data;
	struct DoublyLinkedList *prev;
	struct DoublyLinkedList *next;
};
/*
--------------------------
Create a new node
--------------------------
*/
struct DoublyLinkedList *createNode(int n)
{
	struct DoublyLinkedList *newNodeptr;
	newNodeptr = (struct DoublyLinkedList *)
		malloc(sizeof(struct DoublyLinkedList));
	newNodeptr->data = n;
	newNodeptr->prev = NULL;
	newNodeptr->next = NULL;
	return newNodeptr;
}

/*
--------------------------------
add a node at the end of a doubly linked list.
Tailptr is the address of the pointer to the end of the current list.
After adding the node, tail points to the new node inserted.
--------------------------------
*/

void appendNode(struct DoublyLinkedList **tailptr, int n)
{
	struct DoublyLinkedList *newNode;
	newNode = createNode(n);
	newNode->prev = *tailptr;
	(*tailptr)->next = newNode;
	*tailptr = newNode;
}

void initializeList(
	struct DoublyLinkedList **headptr,
	struct DoublyLinkedList **tailptr,
	int n)
{
	struct DoublyLinkedList *newNode;
	newNode = createNode(n);
	*headptr = newNode;
	*tailptr = newNode;
	return;
}

void printList(
	struct DoublyLinkedList *head,
	struct DoublyLinkedList *tail)
{
	struct DoublyLinkedList *curr = head;
	while (curr != NULL)
	{
		if (curr->next != NULL)
			printf("%d,", curr->data);
		else
			printf("%d", curr->data);

		curr = curr->next;
	}
	return;
}

/*
---------------------------------------
remove the node that contains data as n
---------------------------------------
*/

void removeData(
	struct DoublyLinkedList **headptr,
	struct DoublyLinkedList **tailptr,
	int n)
{
	struct DoublyLinkedList *temp = *headptr, *prev;

	// If head node itself holds the key to be deleted
	if (temp != NULL && temp->data == n)
	{
		*headptr = temp->next; // Changed head
		if (*headptr)
			(*headptr)->prev = NULL; // if list is not empty, set prev of new head to NULL
		free(temp);					 // free old head
		return;
	}

	// Search for the key to be deleted, keep track of the previous node
	while (temp != NULL && temp->data != n)
	{
		prev = temp;
		temp = temp->next;
	}

	// If key was not present in linked list
	if (temp == NULL)
		return;

	// Unlink the node from linked list
	prev->next = temp->next;

	// Update prev of next node if it's not the last node
	if (temp->next != NULL)
		temp->next->prev = prev;

	// Update tail if last node is deleted
	if (*tailptr == temp)
		*tailptr = prev;

	free(temp); // Free memory
}


int main()
{
	int n;
	int i = 0;
	int m;
	struct DoublyLinkedList *head, *tail;
	scanf("%d", &n);
	if (n <= 0)
	{
		return 0;
	}
	scanf("%d", &m);
	initializeList(&head, &tail, m);

	for (i = 1; i < n; i++)
	{
		/* read the remaining elements */
		scanf("%d", &m);
		appendNode(&tail, m);
	}

	scanf("%d", &n);
	removeData(&head, &tail, n);
	printList(head, tail);
	return 0;
}
