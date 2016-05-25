//Design a stack with operations on middle element
//Design a stack which supports following operations in O(1) time
//push, pop
//getmiddle -> will return middle element of the stack.
//deleteMiddle() -> Will delete the middle element
//
//Idea is --
//Use doubly link list to implement a stack 
//and maintain extra mid pointer to point middle element

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct List
{
	int data;
	struct List *next;
	struct List *prev;
}DList;

int top = -1;

void push(DList **head, DList **mid, int data)
{
	DList *temp = malloc(sizeof(DList));
	
	temp->data = data;
	temp->next = (*head);
	temp->prev = NULL; 		

	if(temp->next)
			temp->next->prev = temp;

	*head = temp;

	top++;
	
	//In case of single node, lets point mid to head node
	//If Odd number of nodes then don't move mid pointer back 
	//in case of even node move mid pointer back
	//
	if((*head)->next == NULL)//single node
		*mid = *head;	
			
	else if(top % 2)
		*mid = (*mid)->prev;

	//printf("mid data %d\n", (*mid)->data);

	return ;
}


int pop(DList **head, DList **mid)
{
	if(*head == NULL)
		return INT_MAX ; //Stack is empty

	DList *temp = (*head);
	
	*head = (*head)->next;
	
	if(*head)
		(*head)->prev = NULL;

	int data = temp->data;
	free(temp);
	temp = NULL;

	top--;

	//change mid pointer as well
	if(top <= 1)//was either one. two or three nodes
		*mid = *head;		

	else if(!(top % 2))//in case of odd node left, here top = 2 means 3 nodes remaining   
		*mid = (*mid)->next;

	//printf("mid data %d and data %d\n", (*mid)->data, data);
	
	return data;
}

int findmiddle(DList *mid)
{
	int temp = INT_MIN;

	if(mid)
		temp = mid->data;				

	//printf("middle %d\n", temp);
	return temp; 
}


int DeleteMid(DList **head, DList **mid)
{
	if(*mid == NULL)
		return INT_MIN;

	DList *temp = *mid;
	int data = temp->data;

	if(top <= 1)//up to one node
	{
		*mid = (*mid)->next;
		if(*mid)
			(*mid)->prev = NULL;
		
		*head = *mid;
	}			

	else if(!(top%2)) //odd nodes 1->2->3
	{
		*mid = (*mid)->prev;		
		(*mid)->next = temp->next;
		temp->next->prev = *mid;

	}
	else //even nodes 1->2->3->4
	{
		*mid = (*mid)->next;		
		temp->prev->next = *mid;
		(*mid)->prev = temp->prev;
	}
		
	top--;

	//printf("deleted data %d\n", data);	
	free(temp);
	temp = NULL;

	return data;
}


void DisplayDList(DList *node)
{
	while(node)
	{
		printf("%d  ", node->data);
		node = node->next;
	}
	
	printf("\n");

	return ;
}

int main()
{

	DList *head = NULL; //head
	DList *mid = NULL; //middle pointer
	
	push(&head, &mid, 1);
	//findmiddle(mid);
	push(&head, &mid, 2);
	//findmiddle(mid);
	push(&head, &mid, 3);
	//findmiddle(mid);
	push(&head, &mid, 4);
	//findmiddle(mid);
	push(&head, &mid, 5);
	//findmiddle(mid);

	pop(&head, &mid);
	//findmiddle(mid);
	//pop(&head, &mid);
	//pop(&head, &mid);
	//pop(&head, &mid);
	//pop(&head, &mid);
	//pop(&head, &mid);
	
	pop(&head, &mid);
	//findmiddle(mid);
	pop(&head, &mid);
	//findmiddle(mid);

	DeleteMid(&head, &mid);	
	printf("Middle element is = %d\n", findmiddle(mid));

	printf("Printing Stack, where last element is TOP\n"); 
	DisplayDList(head);

	push(&head, &mid, 6);
	printf("Middle element is = %d\n", findmiddle(mid));

	//pop(&head, &mid);
	//findmiddle(mid);
	//pop(&head, &mid);
	//findmiddle(mid);

	return 0;
}
