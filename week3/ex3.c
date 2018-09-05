#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *nextNode;
};

struct node * newNodeLists()
{
    struct node *l1 = malloc(sizeof(struct node));
    l1->nextNode=NULL;
    return l1;
}


void insert_(struct node *head, int v,int n)
{
    struct node *temp = head;

    for(int i=0; i<n; i++)
    {
        temp = temp->nextNode;
        if(temp==NULL)
        {
            printf("wrong error %d",n);
            exit(0);
        }

    }

    if(temp->nextNode==NULL)
    {
        temp->nextNode = malloc(sizeof(struct node));
        temp->nextNode->data = v;
        temp->nextNode->nextNode = NULL;
    }
    else
    {
        struct node *temp=temp->nextNode;
        temp->nextNode=malloc(sizeof(struct node));
        temp->nextNode->data = v;
        temp->nextNode->nextNode=temp;
    }


}

void delete_node(struct node *head, int n)
{
    struct node *temp = head;

    for(int i=0; i<n; i++)
    {
        temp = temp->nextNode;
        if(temp==NULL)
        {
            printf("wrong error",n);
            return;
        }

    }
    if(temp->nextNode->nextNode==NULL)
    {
        temp->nextNode = NULL;
    }
    else
    {
        temp->nextNode=temp->nextNode->nextNode;
    }


}

void print_list(struct node *head)
{
    struct node *temp = head->nextNode;

    while (temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->nextNode;
    }
}


int main()
{
    struct node *l1 = newNodeLists();

    insert_(l1,1,1);
    insert_(l1,234,0);
    delete_node(l1,1);

    print_list(l1);

    return 0;
};