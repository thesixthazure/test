#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 
typedef struct ShoppingItem
{
	char name[50];
	int quantity;
	struct ShoppingItem* next;
}Node;

Node* shoppingList = NULL;
Node* shoppingList2 = NULL;


//1 �����Ʒ
void addItem(char itemName[], int itemQuantity)
{
	Node* newItem = (Node*)malloc(sizeof(Node));
	strcpy(newItem->name, itemName);
	newItem->quantity = itemQuantity;

	if (!shoppingList)
	{
		shoppingList = newItem;
		newItem->next = NULL;
	}
	else
	{
		newItem->next = shoppingList->next;
		shoppingList->next = newItem;
	}


}

void addItem2(char itemName[], int itemQuantity)
{
	Node* newItem = (Node*)malloc(sizeof(Node));
	strcpy(newItem->name, itemName);
	newItem->quantity = itemQuantity;

	if (!shoppingList2)
	{
		shoppingList2 = newItem;
		newItem->next = NULL;
	}
	else
	{
		newItem->next = shoppingList2->next;
		shoppingList2->next = newItem;
	}


}


//2 ɾ����Ʒ
void removeItem(char itemName[])
{

	printf("ɾ����Ʒ����嵥��\n");
	Node* p=shoppingList;
	Node* pre=NULL;

	while (p)
	{
		if (strcmp(p->name, itemName)==0)
		{
			if (pre != NULL)
			{
				pre->next = p->next;
			}
			else
			{
				shoppingList = p->next;
			}
			free(p);
			break;
		}
		pre = p;
		p = p->next;
	}


}

//3 ��������嵥
void myprintf()
{

	Node* current = shoppingList;
	int c = 0;

	printf("�����嵥��\n");
	while (current)
	{
		c++;
		printf("%s %d\n", current->name, current->quantity);
		current = current->next;
	}
	if (c == 0)
	{
		printf("û����Ʒ��\n");
	}
	
}

void myprintf2()
{

	Node* current = shoppingList2;
	int c = 0;

	printf("�����嵥��\n");
	while (current)
	{
		c++;
		printf("%s %d\n", current->name, current->quantity);
		current = current->next;
	}
	if (c == 0)
	{
		printf("û����Ʒ��\n");
	}

}

//4 �޸���Ʒ����
void updataQuantity(char itemName[], int newItemQuantity)
{
	printf("�޸���Ʒ��������嵥��\n");

	Node* p = shoppingList;
	while (p)
	{
		if (strcmp(p->name, itemName) == 0)
		{
			p->quantity = newItemQuantity;
			break;
		}
		p = p->next;
	}
}

//5 ��չ����嵥
void clearList()
{
	Node* temp;
	while (shoppingList)
	{
		temp = shoppingList;
		shoppingList = shoppingList->next;
		free(temp);
	}
}

//6 ������Ʒ����
int totalQuantity()
{
	Node* p = shoppingList;
	int total=0;
	while (p)
	{
		total += p->quantity;
		p = p->next;
	}
	return total;
}


//7 ������Ʒ
void findItem(char itemName[])
{
	Node* p = shoppingList;
	
	printf("������Ʒ��%s\n", itemName);
	while (p)
	{
		if (strcmp(p->name, itemName) == 0)
		{
			printf("%s - ������%d\n",p->name, p -> quantity);
			return;
		}
		p = p->next;
	}

	printf("δ�ҵ���Ʒ\n");
}

//8 �������嵥
void sortList()
{
	Node* p = shoppingList;
	Node* nextItem = NULL;
	char tempName[50];
	int tempQuantity;

	while (p)
	{
		nextItem = p->next;
		while (nextItem)
		{
			if (strcmp(p->name, nextItem->name) > 0)
			{
				strcpy(tempName, p->name);
				strcpy(p->name, nextItem->name);
				strcpy(nextItem->name, tempName);

				tempQuantity = p->quantity;
				p->quantity = nextItem->quantity;
				nextItem->quantity = tempQuantity;
			}
			nextItem = nextItem->next;
		}
		p = p->next;

	}
}

//9 �ϲ������嵥
void  mergeLists(Node** list1,Node** list2)
{
	Node* p = *list1;
	if (!*list1)
	{
		*list1= *list2;
	}
	else
	{
		while (p->next)
		{
			p = p->next;
		}
		p->next = *list2;
		*list2 = NULL;
	}
	
	
}

//10 ɾ����Ʒ,0Ϊɾ��һ����1Ϊɾ�����
void deleteItem(char itemName[], int deleteAll)
{
	Node* p = shoppingList;
	Node* pre = NULL;

	while (p)
	{
		if (strcmp(p->name, itemName) == 0)
		{
			if (pre == NULL)
			{
				Node* temp = shoppingList;
				shoppingList = shoppingList->next;
				free(temp);
				p = shoppingList;
				if (!deleteAll) break;
			}
			else
			{
				pre->next = p->next;
				free(p);
				p = pre->next;
				if (!deleteAll) break;
			}
		}
		else
		{
			pre = p;
			p = p->next;
		}
	}
}


int main()
{
	//�����ã�ע�͵����ݿ���һ����ʹ��ȫ���Ĺ��ܺ����ӿ�
	



	//����������������������������������������������������
	//char apple[20] ="ƻ��";
	//char banana[20] = "�㽶";
	//char book[20] = "��";
	//char rice[20] = "�׷�";
	//addItem(book, 2);
	//addItem(apple, 3);
	//addItem(rice, 2);
	//addItem(banana, 7);
	//myprintf();
	//
	//printf("\n");
	//removeItem(banana);
	//myprintf();

	//printf("\n");
	//updataQuantity(apple, 10);
	//myprintf();

	//printf("\n");
	//clearList();
	//myprintf();
	//printf("\n");

	////ɾ����ָ�һ��
	//printf("�ָ���\n");
	//addItem(book, 2);
	//addItem(apple, 3);
	//addItem(rice, 2);
	//addItem(banana, 7);
	//addItem(rice, 2);
	//myprintf();
	//printf("\n");

	//
	//printf("��Ʒ�����ǣ�%d\n", totalQuantity());
	//printf("\n");

	//findItem(apple);
	//printf("\n");

	//printf("�����Ĺ����嵥��\n");
	//sortList();
	//myprintf();
	//printf("\n");


	//printf("�ϲ������嵥������һ���մ����Ĳ�����ǰ���嵥\n");
	//char a[20] = "�ܲ�";
	//char b[20] = "���";
	//char c[20] = "ˮ��";
	//char d[20] = "��Ȫˮ";

	//addItem2(a, 2);
	//addItem2(b, 3);
	//addItem2(c, 2);
	//addItem2(d, 7);
	//addItem2(d, 7);
	//printf("�ڶ����嵥��\n");
	//myprintf2();
	//printf("\n");
	//printf("���Ӻ�:\n");
	//mergeLists(shoppingList, shoppingList2);
	//myprintf();
	//printf("\n");

	//printf("ɾ����Ʒ����嵥��\n");
	//deleteItem(rice, 1);
	//myprintf();
	//--------------------------------------------------------------------------
	printf("����������������---------------��ӭ���������嵥���桪��������������������-------������\n");
	printf("\n");
	int x=1;
	char good[20];
	int num;
	

	while (x)
	{
		printf("��ѡ����Ҫ���еĲ�����1-�����Ʒ                2-�Ƴ���Ʒ           3-�鿴�����嵥\n");
		printf("                      4-�޸��嵥����Ʒ������    5-��չ��ﳵ         6-������Ʒ������  \n");
		printf("                      7-������Ʒ                8-�����嵥           9-���������嵥(list2�Ѿ�������) \n");
		printf("                      10-ɾ����Ʒ\n");

		scanf("%d", &x);
		switch (x)
		{
		case 1:
		{
			printf("���������Ʒ�����ֺ�����:");
			scanf("%s%d", &good,&num);
			addItem(good, num);
			myprintf();
			printf("\n");
			break;
		}
		case 2:
		{
			char r_good[20];
			scanf("%s", r_good);
			removeItem(r_good);
			myprintf();
			printf("\n");
			break;
		}
		case 3:
		{
			myprintf();
			printf("\n");
			break;
		}
		case 4:
		{
			char updata_name[20];
			int updata_quantity;
			printf("����Ҫ�޸���Ʒ�����ƺ�������\n");
			scanf("%s%d", &updata_name, &updata_quantity);
			updataQuantity(updata_name, updata_quantity);
			printf("\n");
			break;
		}
		case 5:
		{
			clearList();
			printf("\n");
			break;
		}
		case 6:
		{
			printf("��Ʒ���������ǣ�%d", totalQuantity());
			printf("\n");
			break;
		}
		case 7:
		{
			char select_name[20];
			printf("����Ҫ������Ʒ������");
			scanf("%s", &select_name);
			findItem(select_name);
			printf("\n");
			break;
		}
		case 8:
		{
			sortList();
			printf("�������嵥��\n");
			myprintf();
			printf("\n");
			break;
		}
		case 9:
		{
			printf("�ȴ����ڶ����嵥\n");
			printf("\n");
			char a[20] = "�ܲ�";
			char b[20] = "���";
			char c[20] = "ˮ��";
			char d[20] = "��Ȫˮ";

			addItem2(a, 2);
			addItem2(b, 3);
			addItem2(c, 2);
			addItem2(d, 7);
			addItem2(d, 7);
			printf("�ڶ����嵥��\n");
			myprintf2();

			printf("\n");
			printf("���Ӻ�:\n");
			mergeLists(&shoppingList, &shoppingList2);
			myprintf();
			printf("\n");
			break;

		}
		case 10:
		{
			char delete_name[20];
			int num;
			printf("����Ҫɾ������Ʒ���ƺ�һ�����֣�����0��ʾ��ɾ��һ��������1��ʾɾ�����ͬ����Ʒ\n");
			scanf("%s%d", &delete_name, &num);
			printf("ɾ����Ʒ����嵥��\n");
			deleteItem(delete_name, num);
			myprintf();
			printf("\n");
			break;

		}
		}

	}




	return 0;

}