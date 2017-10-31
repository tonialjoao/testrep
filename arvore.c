#include <stdio.h>
#include <stdlib.h>

typedef struct NODO
{
	char info;
	struct NODO *Esq;
    struct NODO *Dir;
    int indice;
}NODO;

typedef struct Pilha
{
	struct NODO *elementos[20];
	int top;
}Pilha;


void push (Pilha *p, NODO *n)
{
	p->elementos[++p->top] = n;
}

NODO *pop (Pilha *p)
{
	if(p->top == -1)
		return NULL;
	NODO *elemento;
	elemento = malloc(sizeof(NODO));
	elemento = p->elementos[p->top];
	--p->top;
	return elemento;
}

void pesquisa(NODO *ARV){
    //strcmp()

}

char strArv[100] = "ABD**EF**G**C*H*I**"; // transfora a string da arvore em global

int main(void)
{
	int i, n = 20;
	char tmp, lado;
	Pilha *p;
	NODO *ARV, *pai, *novo;
	p = malloc(sizeof(Pilha));
	p->top = -1;
	printf("str da ARV: %s\n", strArv);
	ARV = malloc(sizeof(NODO));
	ARV->info = strArv[0];
	ARV->Esq = ARV->Dir = NULL;

	//nodo pau
	pai = malloc(sizeof(NODO));
	pai =  ARV;

	//contruÃ§Ã£o da arvore
	
	lado = 'E';
	for (i = 0; i < n; ++i)
	{
		tmp = strArv[i];
		printf("%c\n", tmp);
		if(tmp == '*')
		{
			if (lado == 'E')
			{
				lado = 'D';
			}
			else if (lado == 'D')
			{
				pai = pop(p);
				if (pai == NULL)
				{
					if(pai == NULL)
						break; //finalizou a contrulÃ§ao
					printf("--PAI: %c\n", pai->info);
				}
			}
		}
		else
		{
			novo = malloc(sizeof(NODO));
			novo ->info = tmp;
			novo->Dir = novo->Esq = NULL;

			if(lado == 'E')
			{
				pai->Esq = novo;
				push(p, pai);

			}
			else if(lado == 'D')
			{
				pai->Dir = novo;
				lado = 'E';			
			}
			pai = novo;

		}
	}





	system("pause");
	return 0;
}