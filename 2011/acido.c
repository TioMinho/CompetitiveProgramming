#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Abordagem Ad-Hoc ---> Computador Não Tem Memória Suficiente
int verifyBounds(char* fita, int size, int boundsNum)
{
	if(size == 1)
		return boundsNum;
	
	int biggestSeq = boundsNum;

	for(int i = 0; i < size - 1; i++)
	{
		int tempBounds = boundsNum;

		for(int j = i+1, lim = 2*j; j < lim; j++)
		{
			if((fita[2*i-(j-1)] == 'C' && fita[j] == 'F') ||
				(fita[2*i-(j-1)] == 'F' && fita[j] == 'C') ||
				(fita[2*i-(j-1)] == 'B' && fita[j] == 'S') || 
				(fita[2*i-(j-1)] == 'S' && fita[j] == 'B'))
			{
				tempBounds++;
			}
			else
				break;
		}

		if(tempBounds != boundsNum)
		{
			short diff = tempBounds - boundsNum;
			char *left = "", *right = "";

			left = (char*) malloc(sizeof(char) * (i+1)-diff);
			memcpy(left, &fita[0], (i+1)-diff);
			left[(i+1)-diff] = '\0';

			right = (char*) malloc(sizeof(char)* size-(i+1)+diff);
			memcpy(right, &fita[(i+1)+diff], size-(i+1)+diff);
			right[size-(i+1)+diff] = '\0';

			strcat(left, right);

			int temp = verifyBounds(left, size - 2*(tempBounds - boundsNum), tempBounds);
			
			if(temp >= biggestSeq);
				biggestSeq = temp;

			free(left);
			free(right);
		}

	}		

	return biggestSeq;
}

// Abordagem Gulosa (Sempre que há duas ligações, essa escolha é ótima)
typedef struct Stack BaseStack;
typedef struct Node BaseNode;

struct Node {
	char base;
	BaseNode* next;
};

struct Stack {
	BaseNode* header;
};

void push(BaseStack* stack, char base) {
	BaseNode* newBase = (BaseNode*) malloc(sizeof(BaseNode));
	
	newBase->base = base;
	newBase->next = stack->header;

	stack->header = newBase;
}

void pop(BaseStack* stack) {
	if(stack != NULL) 
	{	
		BaseNode* removido = stack->header;

		stack->header = removido->next;

		free(removido);
	}	
}


int stackVerify(char* fita, int size) 
{
	BaseStack baseStack;
	
	push(&baseStack, fita[0]);
	int numLigacoes = 0;

	for(int i = 1; i < size; i++) 
	{	
		char temp = baseStack.header->base;
		if(	baseStack.header != NULL &&
			((temp == 'B' && fita[i] == 'S') ||
 			(temp == 'S' && fita[i] == 'B') ||
 			(temp == 'F' && fita[i] == 'C') ||
 			(temp == 'C' && fita[i] == 'F'))) 
		{
			numLigacoes++;
			pop(&baseStack);
		}
		else
			push(&baseStack, fita[i]);
	}

	return numLigacoes;
}

int main()
{
	char* fitaRNAA = NULL;
	ssize_t bffer;
	ssize_t sSize;

	getline(&fitaRNAA, &bffer, stdin);

	printf("%d\n", strlen(fitaRNAA));

	int boundsNum = stackVerify(fitaRNAA, sSize-1);

	printf("%d\n", boundsNum);

	return 0;
}