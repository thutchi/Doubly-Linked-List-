// Doubly Linked List.c : Defines the entry point for the console application.
//

#define _CRTDBG_MAP_ALLOC
#include <stdio.h>
#include <stdlib.h>
#include <crtdbg.h>

typedef struct node
{
	int data;
	struct node * next;
	struct node * last;
}Node;

//insert
void insert(int data, Node ** current_node);
//delete
// find 
//destroy
void destroy(Node ** current_node);
//print
void print(Node * current_node);
int main()
{
	Node * current_node = NULL;
	insert(1, &current_node);
	insert(2, &current_node);
	insert(10, &current_node);
	insert(50, &current_node);
	insert(6, &current_node);
	insert(8, &current_node);
	print(current_node);
	destroy(&current_node);
	_CrtDumpMemoryLeaks();
    return 0;
}

void insert(int data, Node ** current_node)
{
	if (*current_node == NULL)
	{
		*current_node = malloc(sizeof(Node));
		(*current_node)->next = NULL;
		(*current_node)->last = NULL;
		(*current_node)->data = data;
	}
	else
	{
		Node * temp = *current_node;
		Node * new_node = malloc(sizeof(Node));
		while (temp -> next != NULL)
		{
			temp = temp->next;

		}
		temp->next = new_node;
		new_node -> last = temp;
		new_node->data = data;
		new_node->next = NULL;
		
	}
}

void print(Node * current_node)
{
	if (current_node == NULL)
	{
		printf("There is nothing here\n");
		return;
	}
	Node * temp = current_node;
	while (temp != NULL)
	{
		printf("%d , ", temp->data);
		temp = temp->next;
	}
}

void destroy(Node ** current_node)
{
	Node * temp = *current_node;
	while (temp != NULL)
	{
		temp = temp->next;
		free(*current_node);
		*current_node = temp;
	}
}