//#include "seqlist.h"

//#include "slist.h"

//#include "sclist.h"

#include "dclist.h"

//#include "stack.h"

//#include "queue.h"

//#include "bintree.h"

void menuSeqlist()
{
	printf("**********************************************************\n");
	printf("***      [0] quit_system           [1] push_back       ***\n");
	printf("***      [2] push_front            [3] show_list       ***\n");
	printf("***      [4] pop_back              [5] pop_front       ***\n");
	printf("***      [6] insert_pos            [7] inset_val       ***\n");
	printf("***      [8] erase_pos             [9] erase_val       ***\n");
	printf("***      [10] find                 [11] length         ***\n");
	printf("***      [12] capacity             [13] sort           ***\n");
	printf("***      [14] reverse              [15] clear          ***\n");
	printf("***      [16] front                [17] back           ***\n");
	printf("***      [18] binary_find          [19] erase_all      ***\n");
	printf("**********************************************************\n");
	printf("做出你的选择：>");
}
void menuSlist()
{
	printf("**********************************************************\n");
	printf("***      [0] quit_system           [1] push_back        ***\n");
	printf("***      [2] push_front            [3] show_list       ***\n");
	printf("***      [4] pop_back              [5] pop_front       ***\n");
	printf("*        [6] insert_val            [7] erase_val       ***\n");
	printf("***      [8] find                  [9] length         ***\n");
	printf("***      [10] sort                 [11] reverse        ***\n");
	printf("***      [12] clear                [13] front          ***\n");
	printf("***      [14] back                 [15] erase_all      ***\n");
	printf("**********************************************************\n");
	printf("做出你的选择：>");
}


//ABD##E#H##CF##G##
//ABC##DE##F##G#H##

#if 0
int main()
{
	const char *s = "ABD##E#H##CF##G##";
	const char *vlr = "ABDEHCFG";
	const char *lvr = "DBEHAFCG";
	const char *lrv = "DHEBFGCA";
	int i = 0;
	BinTree bt;
	BinTreeInit(&bt);
	int j = strlen(vlr);
	bt = BinTreeCreate_4(lvr, lrv, &j, strlen(vlr));

	//bt = BinTreeCreate_2(s, &i);
	//BinTreeCreate(&bt);
	//bt = BinTreeCreate_1();
	//BinTreeVLR_Nor(bt);
	//BinTreeLVR_Nor(bt);
	//BinTreeL_Nor(bt);
	//BinTreeNode *p = BinTreeFind(bt, 'E');
	//BinTreeNode *s = BinTreeParent(bt, p);
	//BinTree bt1=BinTreeClone(bt);
	//bool flag = Equal(bt, bt1);


	//printf("VLR：");
	//BinTreeVLR(bt);
	//printf("\n");
	//printf("LVR：");
	//BinTreeLVR(bt);
	//printf("\n");
	//printf("LRV：");
	//BinTreeLRV(bt);
	//printf("\n");
	//printf("Level：");
	//BinTreeLevel(bt);
	//printf("\n");
	//printf("BinTreeSize：%d\n",BinTreeSize(bt));
	//printf("BinTreeHeight：%d\n", BinTreeHeight(bt));
}
#endif  //bintree

#if 0
int main()
{

	//CycleQueue Q;
	//CycleQueueInit(&Q);
	//CycleQueueEn(&Q, 1);
	//CycleQueueEn(&Q, 2);
	//CycleQueueEn(&Q, 3);
	//CycleQueueEn(&Q, 4);
	//CycleQueueEn(&Q, 5);
	//CycleQueueEn(&Q, 6);
	//CycleQueueEn(&Q, 7);
	//CycleQueueEn(&Q, 8);
	//CycleQueueEn(&Q, 9);
	//CycleQueueShow(&Q);
	//printf("%d  出队了\n", CycleQueueFront(&Q));
	//CycleQueueDe(&Q);
	//CycleQueueEn(&Q, 9);
	//CycleQueueShow(&Q);
	//printf("%d \n", CycleQueueSize(&Q));
	//CycleQueueDestroy(&Q);


	LinkQueue Q;
	LinkQueueInit(&Q);
	LinkQueueEn(&Q, 1);
	LinkQueueEn(&Q, 2);
	LinkQueueEn(&Q, 3);
	LinkQueueEn(&Q, 4);
	LinkQueueEn(&Q, 5);
	LinkQueueEn(&Q, 6);
	LinkQueueEn(&Q, 7);
	LinkQueueEn(&Q, 8);
	LinkQueueEn(&Q, 9);
	LinkQueueShow(&Q);
	printf("%d  出队了！\n", LinkQueueFront(&Q));
	LinkQueueDe(&Q);
	printf("%d  出队了！\n", LinkQueueFront(&Q));
	LinkQueueDe(&Q);
	printf("%d  出队了！\n", LinkQueueFront(&Q));
	LinkQueueDe(&Q);
	printf("%d  出队了！\n", LinkQueueFront(&Q));
	LinkQueueDe(&Q);
	printf("%d  出队了！\n", LinkQueueFront(&Q));
	LinkQueueDe(&Q);
	printf("%d  出队了！\n", LinkQueueFront(&Q));
	LinkQueueDe(&Q);
	LinkQueueShow(&Q);
	printf("%d  尾巴！\n", LinkQueueBack(&Q));
	printf("%d ！\n", LinkQueueSize(&Q));
	
	LinkQueueDestroy(&Q);


	//SeqQueue Q;
	//SeqQueueInit(&Q);
	//SeqQueueEn(&Q, 1);
	//SeqQueueEn(&Q, 2);
	//SeqQueueEn(&Q, 3);
	//SeqQueueEn(&Q, 4);
	//SeqQueueEn(&Q, 5);
	//SeqQueueEn(&Q, 6);
	//SeqQueueEn(&Q, 7);
	//SeqQueueEn(&Q, 8);
	//SeqQueueEn(&Q, 9);
	//SeqQueueShow(&Q);
	//printf("%d 出队了\n", SeqQueueFront(&Q));
	//SeqQueueDe(&Q);
	//printf("%d 出队了\n", SeqQueueFront(&Q));
	//SeqQueueDe(&Q);
	//printf("%d 出队了\n", SeqQueueFront(&Q));
	//SeqQueueDe(&Q);
	//printf("%d 出队了\n", SeqQueueFront(&Q));
	//SeqQueueDe(&Q);
	//SeqQueueShow(&Q);
	//printf("  %d \n", SeqQueueSize(&Q));
	//
	//
	//SeqQueueDestroy(&Q);

}

#endif  //seqqueue and linkqueue and cyclequeue


#if 0
int main()
{
	/*LinkStack st;
	LinkStackInit(&st);
	
	LinkStackPush(&st, 1);
	LinkStackPush(&st, 2);
	LinkStackPush(&st, 3);
	LinkStackPush(&st, 4);
	LinkStackPush(&st, 5);

	LinkStackShow(&st);
	printf("%d   出栈了\n", LinkStackTop(&st));
	LinkStackPop(&st);
	printf("%d   出栈了\n", LinkStackTop(&st));
	LinkStackPop(&st);
	printf("%d   出栈了\n", LinkStackTop(&st));
	LinkStackPop(&st);
	printf("%d   出栈了\n", LinkStackTop(&st));
	LinkStackPop(&st);
	printf("%d   出栈了\n", LinkStackTop(&st));
	LinkStackPop(&st);
	LinkStackPush(&st, 9);
	LinkStackPush(&st, 10);
	LinkStackShow(&st);

	printf("%d\n", LinkStackSize(&st));
	LinkStackDestroy(&st);*/

	SeqStack st;
	SeqStackInit(&st);
	SeqStackPush(&st, 1);
	SeqStackPush(&st, 2);
	SeqStackPush(&st, 3);
	SeqStackPush(&st, 4);
	SeqStackPush(&st, 5);
	SeqStackShow(&st);
	SeqStackPush(&st, 6);
	SeqStackPush(&st, 7);
	SeqStackPush(&st, 8);
	SeqStackPush(&st, 9);
	SeqStackShow(&st);
	printf("%d 出栈了\n", SeqStackTop(&st));
	SeqStackPop(&st);
	printf("%d 出栈了\n", SeqStackTop(&st));
	SeqStackPop(&st);
	printf("%d 出栈了\n", SeqStackTop(&st));
	SeqStackPop(&st);
	printf("%d 出栈了\n", SeqStackTop(&st));
	SeqStackPop(&st);
	SeqStackPush(&st, 9);
	SeqStackShow(&st);
	printf("%d\n",SeqStackSize(&st));
	
	SeqStackDestroy(&st);

	return 0;
}

#endif  //seqstack and linkstack


#if 0

int main() //双循环链表
{
	int select = 1;
	ElementType item = 0;
	int pos = 0;
	DCList mylist;
	DCListIni(&mylist);
	while (select)
	{
		menuSlist();
		scanf("%d", &select);
		switch (select)
		{
		case 1:
			printf("\n请输入尾插的值( - 结束)：>");
			while (scanf("%d", &item) && item != '-')
			{
				DCListPushBack(&mylist, item);
			}
			break;
		case 2:
			printf("\n请输入头插的值( - 结束)：>");
			while (scanf("%d", &item) && item != '-')
			{
				DCListPushFront(&mylist, item);
			}
			break;
		case 3:
			DCListShow(&mylist);
			break;
		case 4:
			DCListPopBack(&mylist);
			break;
		case 5:
			DCListPopFront(&mylist);
			break;
		case 6:
			//SlistSort(&mylist);
			printf("\n请输入要插的值( - 结束)：>");
			while (scanf("%d", &item) && item != '-')
			{
				DCListInsertVal(&mylist, item);
			}
			break;
		case 7:
			printf("\n请输入删除的值( - 结束)：>");
			while (scanf("%d", &item) && item != '-')
			{
				DCListEraseVal(&mylist, item);
			}
			break;
		case 8:
			printf("请输入要查找的值:>");
			scanf("%d", &item);
			if (DCListFind(&mylist, item) != NULL)
			{
				printf("数据查找成功！\n");
			}
			else
			{
				printf("数据不存在！\n");
			}
			break;
		case 9:
			printf("链表长度为：%u\n", DCListLength(&mylist));
			break;
		case 10:
			DCListSort(&mylist);
			break;
		case 11:
			DCListReverse(&mylist);
			break;
		case 12:
			DCListClear(&mylist);
			break;
		case 13:
			DCListFront(&mylist);
			break;
		case 14:
			DCListBack(&mylist);
			break;
		case 15:
			printf("请输入要清除的值：>");
			scanf("%d", &item);
			DCListEraseAll(&mylist, item);
		default:
			break;
		}
	}
	DCListDestroy(&mylist);
	return 0;
}

#endif //dclist


#if 1

int main() //头节点双循环链表
{
	int select = 1;
	ElementType item = 0;
	int pos = 0;
	DCList mylist;
	DCListHeadIni(&mylist);
	while (select)
	{
		menuSlist();
		scanf("%d", &select);
		switch (select)
		{
		case 1:
			printf("\n请输入尾插的值( - 结束)：>");
			while (scanf("%d", &item) && item != '-')
			{
				DCListHeadPushBack(&mylist, item);
			}
			break;
		case 2:
			printf("\n请输入头插的值( - 结束)：>");
			while (scanf("%d", &item) && item != '-')
			{
				DCListHeadPushFront(&mylist, item);
			}
			break;
		case 3:
			DCListHeadShow(&mylist);
			break;
		case 4:
			DCListHeadPopBack(&mylist);
			break;
		case 5:
			DCListHeadPopFront(&mylist);
			break;
		case 6:
			//SlistSort(&mylist);
			printf("\n请输入要插的值( - 结束)：>");
			while (scanf("%d", &item) && item != '-')
			{
				DCListHeadInsertVal(&mylist, item);
			}
			break;
		case 7:
			printf("\n请输入删除的值( - 结束)：>");
			while (scanf("%d", &item) && item != '-')
			{
				DCListHeadEraseVal(&mylist, item);
			}
			break;
		case 8:
			printf("请输入要查找的值:>");
			scanf("%d", &item);
			if (DCListHeadFind(&mylist, item) != NULL)
			{
				printf("数据查找成功！\n");
			}
			else
			{
				printf("数据不存在！\n");
			}
			break;
		case 9:
			printf("链表长度为：%u\n", DCListHeadLength(&mylist));
			break;
		case 10:
			DCListHeadSort(&mylist);
			break;
		case 11:
			DCListHeadReverse(&mylist);
			break;
		case 12:
			DCListHeadClear(&mylist);
			break;
		case 13:
			DCListHeadFront(&mylist);
			break;
		case 14:
			DCListHeadBack(&mylist);
			break;
		case 15:
			printf("请输入要清除的值：>");
			scanf("%d", &item);
			DCListHeadEraseAll(&mylist, item);
		default:
			break;
		}
	}
	DCListHeadDestroy(&mylist);
	return 0;
}

#endif //head_dclist



#if 0

int main() //头节点单循环链表
{
	int select = 1;
	ElementType item = 0;
	int pos = 0;
	SCList mylist;
	SCListHeadIni(&mylist);
	while (select)
	{
		menuSlist();
		scanf("%d", &select);
		switch (select)
		{
		case 1:
			printf("\n请输入尾插的值( - 结束)：>");
			while (scanf("%d", &item) && item != '-')
			{
				SCListHeadPushBack(&mylist, item);
			}
			break;
		case 2:
			printf("\n请输入头插的值( - 结束)：>");
			while (scanf("%d", &item) && item != '-')
			{
				SCListHeadPushFront(&mylist, item);
			}
			break;
		case 3:
			SCListHeadShow(&mylist);
			break;
		case 4:
			SCListHeadPopBack(&mylist);
			break;
		case 5:
			SCListHeadPopFront(&mylist);
			break;
		case 6:
			//SlistSort(&mylist);
			printf("\n请输入要插的值( - 结束)：>");
			while (scanf("%d", &item) && item != '-')
			{
				SCListHeadInsertVal(&mylist, item);
			}
			break;
		case 7:
			printf("\n请输入删除的值( - 结束)：>");
			while (scanf("%d", &item) && item != '-')
			{
				SCListHeadEraseVal(&mylist, item);
			}
			break;
		case 8:
			printf("请输入要查找的值:>");
			scanf("%d", &item);
			if (SCListHeadFind(&mylist, item) != NULL)
			{
				printf("数据查找成功！\n");
			}
			else
			{
				printf("数据不存在！\n");
			}
			break;
		case 9:
			printf("链表长度为：%u\n", SCListHeadLength(&mylist));
			break;
		case 10:
			SCListHeadSort(&mylist);
			break;
		case 11:
			SCListHeadReverse(&mylist);
			break;
		case 12:
			SCListHeadClear(&mylist);
			break;
		case 13:
			SCListHeadFront(&mylist);
			break;
		case 14:
			SCListHeadBack(&mylist);
			break;
		case 15:
			printf("请输入要清除的值：>");
			scanf("%d", &item);
			SCListHeadEraseAll(&mylist, item);
		default:
			break;
		}
	}
	SCListHeadDestroy(&mylist);
	return 0;
}

#endif //head_sclist


#if 0

int main() //无头节点单链表
{
	int select = 1;
	ElementType item = 0;
	int pos = 0;
	SCList mylist;
	SCListIni(&mylist);//无头节点初始化方法
	while (select)
	{
		menuSlist();
		scanf("%d", &select);
		switch (select)
		{
		case 1:
			printf("\n请输入尾插的值( - 结束)：>");
			while (scanf("%d", &item) && item != '-')
			{
				SCListPushBack(&mylist, item);
			}
			break;
		case 2:
			printf("\n请输入头插的值( - 结束)：>");
			while (scanf("%d", &item) && item != '-')
			{
				SCListPushFront(&mylist, item);
			}
			break;
		case 3:
			SCListShow(&mylist);
			break;
		case 4:
			SCListPopBack(&mylist);
			break;
		case 5:
			SCListPopFront(&mylist);
			break;
		case 6:
			//SlistSort(&mylist);
			printf("\n请输入要插的值( - 结束)：>");
			while (scanf("%d", &item) && item != '-')
			{
				SCListInsertVal(&mylist, item);
			}
			break;
		case 7:
			printf("\n请输入删除的值( - 结束)：>");
			while (scanf("%d", &item) && item != '-')
			{
				SCListEraseVal(&mylist, item);
			}
			break;
		case 8:
			printf("请输入要查找的值:>");
			scanf("%d", &item);
			if (SCListFind(&mylist, item) != NULL)
			{
				printf("数据查找成功！\n");
			}
			else
			{
				printf("数据不存在！\n");
			}
			break;
		case 9:
			printf("链表长度为：%u\n", SCListLength(&mylist));
			break;
		case 10:
			SCListSort(&mylist);
			break;
		case 11:
			SCListReverse(&mylist);
			break;
		case 12:
			SCListClear(&mylist);
			break;
		case 13:
			SCListFront(&mylist);
			break;
		case 14:
			SCListBack(&mylist);
			break;
		case 15:
			printf("请输入要清除的值：>");
			scanf("%d", &item);
			SCListEraseAll(&mylist, item);
		default:
			break;
		}
	}
	SCListDestroy(&mylist);
	return 0;
}

#endif //sclist


#if 0

int main()//有头节点单链表
{
	int select = 1;
	ElementType item = 0;
	int pos = 0;
	SList mylist;
	SlistIniHead(&mylist);//有头节点初始化方法
	while (select)
	{
		menuSlist();
		scanf("%d", &select);
		switch (select)
		{
		case 1:
			printf("\n请输入尾插的值( - 结束)：>");
			while (scanf("%d", &item) && item != '-')
			{
				SlistHeadPushBack(&mylist, item);
			}
			break;
		case 2:
			printf("\n请输入头插的值( - 结束)：>");
			while (scanf("%d", &item) && item != '-')
			{
				SlistHeadPushFront(&mylist, item);
			}
			break;
		case 3:
			SlistHeadShow(&mylist);
			break;
		case 4:
			SlistHeadPopBack(&mylist);
			break;
		case 5:
			SlistHeadPopFront(&mylist);
			break;
		case 6:
			SlistHeadSort(&mylist);
			printf("\n请输入要插的值( - 结束)：>");
			while (scanf("%d", &item) && item != '-')
			{
				SlistHeadInsertVal(&mylist, item);
			}
			break;
		case 7:
			printf("\n请输入删除的值( - 结束)：>");
			while (scanf("%d", &item) && item != '-')
			{
				SlistHeadEraseVal(&mylist, item);
			}
			break;
		case 8:
			printf("请输入要查找的值:>");
			scanf("%d", &item);
			if (SlistHeadFind(&mylist, item) != NULL)
			{
				printf("数据查找成功！\n");
			}
			else
			{
				printf("数据不存在！\n");
			}
			break;
		case 9:
			printf("链表长度为：%u\n", SlistHeadLength(&mylist));
			break;
		case 10:
			SlistHeadSort(&mylist);
			break;
		case 11:
			SlistHeadReverse(&mylist);
			break;
		case 12:
			SlistHeadClear(&mylist);
			break;
		case 13:
			SlistHeadFront(&mylist);
			break;
		case 14:
			SlistHeadBack(&mylist);
			break;
		case 15:
			printf("请输入要清除的值：>");
			scanf("%d", &item);
			SlistHeadEraseAll(&mylist, item);
		default:
			break;
		}
	}
	SlistHeadDestroy(&mylist);
	return 0;
}

#endif  // head_slist


#if 0

int main() //无头节点单链表
{
	int select = 1;
	ElementType item = 0;
	int pos = 0;
	SList mylist;
	SlistIni(&mylist);//无头节点初始化方法
	while (select)
	{
		menuSlist();
		scanf("%d", &select);
		switch (select)
		{
		case 1:
			printf("\n请输入尾插的值( - 结束)：>");
			while (scanf("%d", &item) && item != '-')
			{
				SlistPushBack(&mylist,item);
			}
			break;
		case 2:
			printf("\n请输入头插的值( - 结束)：>");
			while (scanf("%d", &item) && item != '-')
			{
				SlistPushFront(&mylist, item);
			}
			break;
		case 3:
			SlistShow(&mylist);
			break;
		case 4:
			SlistPopBack(&mylist);
			break;
		case 5:
			SlistPopFront(&mylist);
			break;
		case 6:
			SlistSort(&mylist);
			printf("\n请输入要插的值( - 结束)：>");
			while (scanf("%d", &item) && item != '-')
			{
				SlistInsertVal(&mylist,item);
			}
			break;
		case 7:
			printf("\n请输入删除的值( - 结束)：>");
			while (scanf("%d", &item) && item != '-')
			{
				SlistEraseVal(&mylist, item);
			}
			break;
		case 8:
			printf("请输入要查找的值:>");
			scanf("%d", &item);
			if (SlistFind(&mylist, item) != NULL)
			{
				printf("数据查找成功！\n");
			}
			else
			{
				printf("数据不存在！\n");
			}
			break;
		case 9:
			printf("链表长度为：%u\n",SlistLength(&mylist));
			break;
		case 10:
			SlistSort(&mylist);
			break;
		case 11:
			SlistReverse(&mylist);
			break;
		case 12:
			SlistClear(&mylist);
			break;
		case 13:
			SlistFront(&mylist);
			break;
		case 14:
			SlistBack(&mylist);
			break;
		case 15:
			printf("请输入要清除的值：>");
			scanf("%d", &item);
			SlistEraseAll(&mylist, item);
		default:
			break;
		}
	}
	SlistDestroy(&mylist);
	return 0;
}

#endif //slist


#if 0 //seqlist
int main()
{
	int select = 1;
	int item = 0;
	int pos = 0;
	Seqlist list;
	SeqlistInit(&list);
	while (select)
	{
		menuSeqlist();
		scanf("%d", &select);
		switch (select) 
		{
		case 1:
			printf("\n请输入你要尾插的数据( - 结束)：>");
			while (scanf("%d", &item) && item != '-')
			{
				SeqlistPushBack(&list, item);
			}
			//printf("尾部插入成功！\n");
			break;
		case 2:
			printf("\n请输入你要头插的数据( - 结束)：>");
			while (scanf("%d", &item) && item != '-')
			{
				SeqlistPushFront(&list, item);
			}
			break;
		case 3:
			SeqlistShow(&list);
			break;
		case 4:
			SeqlistPopBack(&list);
			SeqlistShow(&list);
			break;
		case 5:
			SeqlistPopFront(&list);
			SeqlistShow(&list);
			break;
		case 6:
			printf("\n请输入要插入的位置和值:>");
			scanf("%d %d", &pos, &item);
			SeqlistInsertPos(&list, pos, item);
			break;
		case 7:
			printf("\n请输入你要值插入的数据：>");
			scanf("%d", &item);
			SeqlistInsertVal(&list, item);
			break;
		case 8:
			printf("\n请输入要删除的位置:>");
			scanf("%d", &pos);
			SeqlistEraseBack(&list, pos + 1);
			break;
		case 9:
			printf("\n请输入你要删除的数据：>");
			scanf("%d", &item);
			SeqlistEraseVal(&list, item);
			break;
		case 10:
			printf("\n请输入你要查找的数据：>");
			scanf("%d", &item);
			int flag = SeqlistFind(&list, item);
			if (flag != -1)
			{
				printf("该数据位置为：%d\n", flag);
			}
			else
			{
				printf("该数据不存在\n");
			}
			break;
		case 11:
			SeqlistLength(&list);
			break;
		case 12:
			SeqlistCapacity(&list);
			break;
		case 13:
			SeqlistSort(&list);
			break;
		case 14:
			SeqlistReverse(&list);
			break;
		case 15:
			SeqlistClear(&list);
			break;
		case 16:
			SeqlistFront(&list);
			break;
		case 17:
			SeqlistBack(&list);
			break;
		case 18:
			printf("\n请输入你要二分查找的数据：>");
			scanf("%d", &item);
			SeqlistBinaryFind(&list, item);
			break;
		case 19:
			printf("\n请输入你要删除的数据：>");
			scanf("%d", &item);
			SeqlistEraseAll(&list,item);
			break;
		default:
			//printf("输出有误，重新输出！\n");
			break;
		}
	}
	SeqlistDestroy(&list);
	return 0;
}

#endif //seqlist