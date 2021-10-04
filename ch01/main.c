//单链表的使用
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int date;
    struct node *next;
};
typedef struct node LNode,*LinkList;

void CreatList(LinkList head);
void PrintList(LinkList head);
void ListDelete(LinkList head,int i,int *e);
void ListInsert(LinkList head,int i,int e);

int main(void)
{
    LinkList head;
    int i,e,select,n;

    head = (LinkList)malloc(sizeof(LNode));
    head->next  = NULL;

    while (1)
    {
        printf("1:创建链表\n");
        printf("2:插入元素\n");
        printf("3:删除元素\n");
        printf("4:输出链表中的元素\n");
        printf("0:退出系统\n");
        scanf("%d",&select);

        switch(select){
            case 1:
                CreatList(head);break;
            case 2:
                printf("请输入待插入位置和元素:");
                scanf("%d%d",&i,&e);
                ListInsert(head,i,e);break;
            case 3:
                printf("请输入待删除元素位置:");
                scanf("%d",&i);
                ListDelete(head,i,&e);break;
            case 4:
                PrintList(head);
                printf("\n");break;
            case 0:
                exit(0);
        }
    }
    return 0;
}
void CreatList(LinkList head)
{
    LinkList p, rear = head;
    int num;

    printf("输入若干整数，输入-1表示输入结束\n");
    while (scanf("%d",&num),num != -1)
    {
        p = (LinkList)malloc(sizeof(LNode));
        p->date = num;
        rear->next = p;
        rear = p;
    }
    rear->next = NULL;
}
void PrintList(LinkList head)
{
    LinkList p = head->next;

    while(p)
    {
        printf("%d ",p->date);
        p = p->next;
    }
}
void ListDelete(LinkList head,int i,int *e)
{
    LinkList p,pre = head;
    int j = 0;
    while (pre && j<i-1)
    {
        pre = pre->next;
        ++j;
    }
    if(!pre || i<1)
    {
        printf("i值错误\n");
        return;
    }

    p = pre->next;
    pre->next = p->next;
    *e = p->date;
    free(p);
}
void ListInsert(LinkList head,int i,int e)
{
    LinkList p,pre = head;
    int j = 0;

    while (pre && j<i-1)
    {
        pre = pre->next;
        j++;
    }

    if(!pre || i<1)
    {
        printf("i值错误\n");
        return;
    }

    p = (LinkList)malloc(sizeof(LNode));
    p->date = e;
    p->next = pre->next;
    pre->next = p;
    
}
