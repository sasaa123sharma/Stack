//Implemenet special stack which gives min in O(1) time and sing O(1) space
//
//
//Idea is take en extra variable min and keep updating the min value at particukar moment
//
//While Pushing 
//in case of first element, push element and keep same in min
//otherwise if incoming data is less than cur min, push (2*data - min ) in to stack and upadte min with new data 
//else min will be same and push same data on the stack as it comes
//
//
//While popping
//If popped element is less or equal to min element
//then actual popped element would be equal to min
//and update min with 2*min - popped data
//
//Flaw - stack may not contain actual data at any moment

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 10

typedef struct stack
{
	int top;
	int size;
	int min;
	int *arr;
}Stack;


void push(Stack *stack, int data)
{
	if(stack->top == MAX -1)
	{
		printf("stack is full\n");
		return;
	}
	//If it is first elem
	if(stack->top == -1)
	{
		stack->min = data;
	}
	else if(stack->min > data)
	{
		int temp = stack->min;
		stack->min = data;
		data = 2*data - temp;		
	}

	stack->top++;
	stack->arr[stack->top] = data;
	return ;
}


int pop(Stack *stack)
{
	if(stack->top == -1)
	{
		printf("stack is empty\n");
		return INT_MIN;
	}
	
	int data = stack->arr[stack->top];
	stack->top--;

	if(data < stack->min)	
	{	
		int temp = data;
		data = stack->min;
		stack->min = 2*stack->min - temp;
	}

	return data;
}


int GetMin(Stack *stack)
{
	if(stack->top == -1)
		return INT_MIN;

	return stack->min;
}

void StackDisp(Stack stack)
{
	if(stack.top == -1)
	{
		printf("stack is empty\n");
		return;
	}	
	int i = 0;
	printf("stack --\n");
	//printf("stck.top =%d\n", stack.top);
	while(i <= stack.top)
	{
		printf("%d  ", stack.arr[i]);		
		i++;
	}
	
	printf("\n");

	return;
}

int main()
{
	int min = 0;
	Stack stck;
	stck.top = -1;
	stck.size = 10;
	stck.min = 0;

	stck.arr = malloc(sizeof(int) *MAX);
	
	//push(&stck, 1);
	push(&stck, 5);
	printf("min = %d\n", GetMin(&stck));
	//push(&stck, 2);
	push(&stck, 4);
	printf("min = %d\n", GetMin(&stck));
	push(&stck, 3);
	printf("min = %d\n", GetMin(&stck));
	push(&stck, 5);
	printf("min = %d\n", GetMin(&stck));
	push(&stck, 6);
	printf("min = %d\n", GetMin(&stck));
	push(&stck, 7);
	printf("min = %d\n", GetMin(&stck));
	push(&stck, 2);
	printf("min = %d\n", GetMin(&stck));
	push(&stck, 1);
	printf("min = %d\n", GetMin(&stck));
	//printf("%d\n", stck.top);
	StackDisp(stck);
	printf("popped data = %d\n", pop(&stck));
	StackDisp(stck);
	
	printf("min = %d\n", GetMin(&stck));
	printf("popped data = %d\n", pop(&stck));
	printf("min = %d\n", GetMin(&stck));
	printf("popped data = %d\n", pop(&stck));
	printf("min = %d\n", GetMin(&stck));
	printf("popped data = %d\n", pop(&stck));
	printf("min = %d\n", GetMin(&stck));
	printf("popped data = %d\n", pop(&stck));
	printf("min = %d\n", GetMin(&stck));
	printf("popped data = %d\n", pop(&stck));
	printf("min = %d\n", GetMin(&stck));
	printf("popped data = %d\n", pop(&stck));
	printf("min = %d\n", GetMin(&stck));
	printf("popped data = %d\n", pop(&stck));
	printf("min = %d\n", GetMin(&stck));
	return 0;
}
