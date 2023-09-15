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


//1 添加商品
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


//2 删除商品
void removeItem(char itemName[])
{

	printf("删除商品后的清单：\n");
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

//3 输出购物清单
void myprintf()
{

	Node* current = shoppingList;
	int c = 0;

	printf("购物清单：\n");
	while (current)
	{
		c++;
		printf("%s %d\n", current->name, current->quantity);
		current = current->next;
	}
	if (c == 0)
	{
		printf("没有商品！\n");
	}
	
}

void myprintf2()
{

	Node* current = shoppingList2;
	int c = 0;

	printf("购物清单：\n");
	while (current)
	{
		c++;
		printf("%s %d\n", current->name, current->quantity);
		current = current->next;
	}
	if (c == 0)
	{
		printf("没有商品！\n");
	}

}

//4 修改商品数量
void updataQuantity(char itemName[], int newItemQuantity)
{
	printf("修改商品数量后的清单：\n");

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

//5 清空购物清单
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

//6 计算商品数量
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


//7 查找商品
void findItem(char itemName[])
{
	Node* p = shoppingList;
	
	printf("查找商品：%s\n", itemName);
	while (p)
	{
		if (strcmp(p->name, itemName) == 0)
		{
			printf("%s - 数量：%d\n",p->name, p -> quantity);
			return;
		}
		p = p->next;
	}

	printf("未找到商品\n");
}

//8 排序购物清单
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

//9 合并购物清单
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

//10 删除商品,0为删除一个，1为删除多个
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
	//测试用，注释的内容可以一次性使用全部的功能函数接口
	



	//——————————————————————————
	//char apple[20] ="苹果";
	//char banana[20] = "香蕉";
	//char book[20] = "书";
	//char rice[20] = "米饭";
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

	////删除后恢复一下
	//printf("恢复后：\n");
	//addItem(book, 2);
	//addItem(apple, 3);
	//addItem(rice, 2);
	//addItem(banana, 7);
	//addItem(rice, 2);
	//myprintf();
	//printf("\n");

	//
	//printf("商品数量是：%d\n", totalQuantity());
	//printf("\n");

	//findItem(apple);
	//printf("\n");

	//printf("排序后的购物清单：\n");
	//sortList();
	//myprintf();
	//printf("\n");


	//printf("合并两个清单，将另一个刚创建的并到先前的清单\n");
	//char a[20] = "萝卜";
	//char b[20] = "玩具";
	//char c[20] = "水杯";
	//char d[20] = "矿泉水";

	//addItem2(a, 2);
	//addItem2(b, 3);
	//addItem2(c, 2);
	//addItem2(d, 7);
	//addItem2(d, 7);
	//printf("第二个清单：\n");
	//myprintf2();
	//printf("\n");
	//printf("连接后:\n");
	//mergeLists(shoppingList, shoppingList2);
	//myprintf();
	//printf("\n");

	//printf("删除商品后的清单：\n");
	//deleteItem(rice, 1);
	//myprintf();
	//--------------------------------------------------------------------------
	printf("————————---------------欢迎来到购物清单界面———————————-------———\n");
	printf("\n");
	int x=1;
	char good[20];
	int num;
	

	while (x)
	{
		printf("请选择你要进行的操作：1-添加商品                2-移除商品           3-查看购物清单\n");
		printf("                      4-修改清单中商品的数量    5-清空购物车         6-计算商品总数量  \n");
		printf("                      7-查找商品                8-排序清单           9-链接两个清单(list2已经创建好) \n");
		printf("                      10-删除商品\n");

		scanf("%d", &x);
		switch (x)
		{
		case 1:
		{
			printf("输入添加商品的名字和数量:");
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
			printf("输入要修改商品的名称和数量：\n");
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
			printf("商品的总数量是：%d", totalQuantity());
			printf("\n");
			break;
		}
		case 7:
		{
			char select_name[20];
			printf("输入要查找商品的名称");
			scanf("%s", &select_name);
			findItem(select_name);
			printf("\n");
			break;
		}
		case 8:
		{
			sortList();
			printf("排序后的清单：\n");
			myprintf();
			printf("\n");
			break;
		}
		case 9:
		{
			printf("先创建第二个清单\n");
			printf("\n");
			char a[20] = "萝卜";
			char b[20] = "玩具";
			char c[20] = "水杯";
			char d[20] = "矿泉水";

			addItem2(a, 2);
			addItem2(b, 3);
			addItem2(c, 2);
			addItem2(d, 7);
			addItem2(d, 7);
			printf("第二个清单：\n");
			myprintf2();

			printf("\n");
			printf("连接后:\n");
			mergeLists(&shoppingList, &shoppingList2);
			myprintf();
			printf("\n");
			break;

		}
		case 10:
		{
			char delete_name[20];
			int num;
			printf("输入要删除的商品名称和一个数字，数字0表示仅删除一个，数字1表示删除多个同名商品\n");
			scanf("%s%d", &delete_name, &num);
			printf("删除商品后的清单：\n");
			deleteItem(delete_name, num);
			myprintf();
			printf("\n");
			break;

		}
		}

	}




	return 0;

}