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

void Sil(int sayi)
{
	stack *temp=top;
	stack *temp2=NULL;
	if(top->veri==sayi)
	{
		top=top->next;
		free(temp);
		return;
	}
	while(temp->next!=NULL && temp->next->veri!=sayi)
	{
		temp=temp->next;
	}
	if(temp->next==NULL)
	{
		printf("Sayi Bulunamadi\n");
		return;
	}
	temp2=temp->next;
	temp->next=temp->next->next;
	free(temp2);
}
void SilQueue(int sayi)
{
	queue *temp=top2;
	queue *temp2=NULL;
	if(top2->veri==sayi)
	{
		top2=top2->next;
		free(temp);
		return;
	}
	while(temp->next!=NULL && temp->next->veri!=sayi)
	{
		temp=temp->next;
	}
	if(temp->next==NULL)
	{
		printf("Sayi Bulunamadi\n");
		return;
	}
	temp2=temp->next;
	temp->next=temp->next->next;
	free(temp2);
}
void Bul(int sayi)
{
	stack *temp=top;
	stack *temp2=NULL;
	int i=1;
	while(temp->next!=NULL)
	{
		
		if(temp->veri==sayi)
		{
			printf("Stack yapisinda %d konumunda bulundu",i);
			return;
		}
		i++;
		temp=temp->next;
	}
	if(temp->veri==sayi)
	{
		printf("Stack yapisinda %d konumunda bulundu",i);
		return;
	}
	printf("Sayi Bulunamadi");
}
void BulQueue(int sayi)
{
	queue *temp=top2;
	queue *temp2=NULL;
	int i=1;
	while(temp->next!=NULL)
	{
		
		if(temp->veri==sayi)
		{
			printf("Queue yapisinda %d konumunda bulundu",i);
			return;
		}
		i++;
		temp=temp->next;
	}
	if(temp->veri==sayi)
	{
		printf("Queue yapisinda %d konumunda bulundu",i);
		return;
	}
	printf("Sayi Bulunamadi");
}
int main()
{
	
	int sayi,islem;
	do
	{
		printf("1-) Ekle\n");
		printf("2-) Bul ve Sil\n");
		printf("3-) Bul ve Goster\n");
		printf("4-) Tumunu Listele\n");
		printf("Islem seciniz = ");
		scanf("%d",&islem);
		if(islem==1)
		{
			printf("Sayi Girin = ");
			scanf("%d",&sayi);
			push(sayi);
			enQueue(sayi);
		}
		else if(islem==2)
		{
			printf("Silinecek Sayi girin= ");
			scanf("%d",&sayi);
			Bul(sayi);
			Sil(sayi);
			printf("\n");
			BulQueue(sayi);
			SilQueue(sayi);
			
		}
		else if(islem==3)
		{
			printf("Bulunacak Sayi girin= ");
			scanf("%d",&sayi);
			Bul(sayi);
			printf("\n");
			BulQueue(sayi);
		}
		else if(islem==4)
		{
			Yazdir();
		}
		printf("\n--------------\n");
	}while(islem>=1&&islem<=4);
}
