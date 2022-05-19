#include <stdio.h>
#include <stdlib.h>
struct stack{
	int veri;
	stack *next;
};
struct queue{
	int veri;
	queue *next;
};
stack *top=NULL;
queue *top2=NULL;
void push(int sayi)
{
	if(top==NULL)
	{
		top=(stack *)malloc(sizeof(stack));
		top->veri=sayi;
		top->next=NULL;
	}
	else
	{
		stack *temp=(stack *)malloc(sizeof(stack));
		temp->next=top;
		temp->veri=sayi;
		top=temp;
	}
}
void enQueue(int sayi)
{
	if(top2==NULL)
	{
		top2=(queue *)malloc(sizeof(queue));
		top2->veri=sayi;
		top2->next=NULL;
	}
	else
	{
		queue *temp=(queue *)malloc(sizeof(queue));
		temp->veri=sayi;
		temp->next=NULL;
		queue *temp2=top2;
		while(temp2->next!=NULL)
			temp2=temp2->next;
		temp2->next=temp;
	}
}
void Pop()
{
	stack *temp;
	temp=top;
	top=top->next;
	free(temp);
}

void deQueue()
{
	queue *temp;
	temp=top2;
	top2=top2->next;
	free(temp);
}
void Yazdir()
{
	stack *temp;
	temp=top;
	while(temp!=NULL)
	{
		printf("%d - ",temp->veri);
		temp=temp->next;
	}
	printf("\n-----------\n");
	queue *temp2;
	temp2=top2;
	while(temp2!=NULL)
	{
		printf("%d - ",temp2->veri);
		temp2=temp2->next;
	}
}
int main()
{
	int sayi;
	int islem;
	do
	{
		printf("1-)Ekle\n");
		printf("2-)Cikar\n");
		printf("3-)Cikis\n");
		printf("Secim = ");
		scanf("%d",&islem);
		if(islem==1)
		{
			printf("Sayi Girin =  ");
			scanf("%d",&sayi);
			push(sayi);
			enQueue(sayi);
			Yazdir();
		}
		else if(islem==2)
		{
			Pop();
			deQueue();
			Yazdir();
		}
		else if(islem==3)
		{
			break;
		}
		printf("\n");
	}while(islem<=3&&islem>=1);
}
