#include <stdio.h>
#include <stdlib.h>


typedef struct Node
{
    int data;
    struct Node *next;
} Node;


Node *createNode(int data)
{
    Node *temp;
    temp = (Node *)malloc(sizeof(Node));

    temp->next = NULL;
    temp->data = data;
    return temp;
}


void appendNode(Node **head, int data)
{
    Node *temp = *head;
    if (NULL == *head)
    {
        *head = createNode(data);
        return;
    }
    while (NULL != temp->next)
    {
        temp = temp->next;
    }
    temp->next = createNode(data);
}

void printList(Node *head)
{
    Node *temp = head;
    while (NULL != temp)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL");
}

void freeList(Node *head)
{
    Node *temp;
    while (NULL != head)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}




int main()
{
    int choice, data;
    Node *head = NULL;

    while (1)
    {
        printf("\n1.添加1个节点\n2.输出链表\n3.退出\n");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("输入新增节点数据: ");
                scanf("%d", &data);
                appendNode(&head, data);
                break;
            case 2:
                printf("当前链表: \n\n");
                printList(head);
                break;
            case 3:
                freeList(head);
                return 0;
            default:
                printf("无效的指令，请重新输入\n");
        }
    }

    return 0;
}














