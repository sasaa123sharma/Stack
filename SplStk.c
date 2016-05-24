// Design a special stack which gives GetMin() in O(1)
// And other operations should be there as normal stack..

//Idea is -> Use two stacks
//first one will contain normal elements
//second one i.e. special stack will contain min element at that point
//While pushing element in first stack, 
//push first element in both stacks as it is
//If new element is lesser than the top of special stack
//then only push this new element in special stack else push the top of special stack again in to special stack
//While popping any element from main stack, pop top of special stack also
//
// we can optimizs this further 
// While pushing element n first stack(except first element) push element on the special stack only if it is lesser than the top of special stack 
// While popping pop element from special stack if top of it is equal to top of first stack else don't pop from special stack 
//
//

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 10

int iTop = -1;
int iSplTop = -1;

int Stack[MAX] = {0};
int SplStk[MAX] = {0};

int splpop()
{
	if(iSplTop == -1)
		return INT_MIN;
	
	return SplStk[iSplTop--];
}

void splpush(int data)
{	
	if(iSplTop == MAX-1)
		return ;
	SplStk[++iSplTop] = data;
	return ;
}

int pop()
{	
	if(iTop == -1)
		return INT_MIN;
	
	if(Stack[iTop] == SplStk[iSplTop])
		splpop();

	return Stack[iTop--];
}


void push(int data)
{	
	if(iTop == MAX-1)
		return ;

	if(iSplTop == -1)	
		splpush(data);

	else if(data < SplStk[iSplTop])
		splpush(data);

	Stack[++iTop] = data;
	return ;
}


int getmin()
{
	if(iSplTop == -1)
		return INT_MIN;
	
	return SplStk[iSplTop];
}


int main()
{
	push(10);
	push(5);
	push(20);
	push(30);
	
	printf("%d\n", getmin());
	
	pop();
	pop();

	printf("%d\n", getmin());

	pop();

	printf("%d\n", getmin());

	return 0;
}

