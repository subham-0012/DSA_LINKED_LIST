/*
//Inserting element at the starting of a linked list
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
int main()
{
    struct node *node1, *node2, *head, *node3;
    node1 = (struct node *)malloc(sizeof(struct node));
    node2 = (struct node *)malloc(sizeof(struct node));
    node3 = (struct node *)malloc(sizeof(struct node));
    node1->data = 10;
    node1->next = NULL;
    node2->data = 20;
    node2->next = NULL;
    node1->next = node2;
    head = node1;
    node3->data = 30;
    node3->next = head;
    head = node3;
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
}
*/
/*
//Inserting element at a particular node in a linked list
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
int main()
{
    struct node *node1, *node2, *head, *node3, *head1;
    node1 = (struct node *)malloc(sizeof(struct node));
    node2 = (struct node *)malloc(sizeof(struct node));
    node3 = (struct node *)malloc(sizeof(struct node));
    node1->data = 10;
    node1->next = NULL;
    node2->data = 20;
    node2->next = NULL;
    node1->next = node2;
    head = node1;
    head1 = node1;
    while (head1->data != 10)
    {
        head1 = head1->next;
    }
    node3->data = 30;
    node3->next = head1->next;
    head1->next = node3;
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
}
*/
/*
//Inserting element at the end of a linked list
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
int main()
{
    struct node *node1, *node2, *head, *node3, *head1;
    node1 = (struct node *)malloc(sizeof(struct node));
    node2 = (struct node *)malloc(sizeof(struct node));
    node3 = (struct node *)malloc(sizeof(struct node));
    node1->data = 10;
    node1->next = NULL;
    node2->data = 20;
    node2->next = NULL;
    node1->next = node2;
    head = node1;
    head1 = node1;
    while (head1->next != NULL)
    {
        head1 = head1->next;
    }
    node3->data = 30;
    node3->next = NULL;
    head1->next = node3;
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
}
*/
/*
//Merging 2 linked list
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void merge(struct node *p, struct node *q, struct node **s)
{
    struct node *z;
    z = NULL;
    if (p == NULL && q == NULL)
    {
        return;
    }
    while (p != NULL && q != NULL)
    {
        if (*s == NULL)
        {
            *s = malloc(sizeof(struct node));
            z = *s;
        }
        else
        {
            z->next = malloc(sizeof(struct node));
            z = z->next;
        }
        if (p->data < q->data)
        {
            z->data = p->data;
            p = p->next;
        }
        else
        {
            if (q->data < p->data)
            {
                z->data = q->data;
                q = q->next;
            }
            else
            {
                if (p->data == q->data)
                {
                    z->data = q->data;
                    p = p->next;
                    q = q->next;
                }
            }
        }
    }
    while (p != NULL)
    {
        z->next = malloc(sizeof(struct node));
        z = z->next;
        z->data = p->data;
        p = p->next;
    }
    while (q != NULL)
    {
        z->next = malloc(sizeof(struct node));
        z = z->next;
        z->data = q->data;
        q = q->next;
    }
    z->next = NULL;
}
int main()
{
    struct node *linkedlist1Node1, *linkedlist1Node2, *linkedlist1Node3, *linkedlist1Head;
    linkedlist1Node1 = (struct node *)malloc(sizeof(struct node));
    linkedlist1Node2 = (struct node *)malloc(sizeof(struct node));
    linkedlist1Node3 = (struct node *)malloc(sizeof(struct node));
    linkedlist1Node1->data = 10;
    linkedlist1Node1->next = NULL;
    linkedlist1Node2->data = 20;
    linkedlist1Node2->next = NULL;
    linkedlist1Node1->next = linkedlist1Node2;
    linkedlist1Node3->data = 30;
    linkedlist1Node3->next = NULL;
    linkedlist1Node2->next = linkedlist1Node3;
    linkedlist1Head = linkedlist1Node1;
    struct node *linkedlist2Node1, *linkedlist2Node2, *linkedlist2Node3, *linkedlist2Head;
    linkedlist2Node1 = (struct node *)malloc(sizeof(struct node));
    linkedlist2Node2 = (struct node *)malloc(sizeof(struct node));
    linkedlist2Node3 = (struct node *)malloc(sizeof(struct node));
    linkedlist2Node1->data = 5;
    linkedlist2Node1->next = NULL;
    linkedlist2Node2->data = 15;
    linkedlist2Node2->next = NULL;
    linkedlist2Node1->next = linkedlist2Node2;
    linkedlist2Node3->data = 25;
    linkedlist2Node3->next = NULL;
    linkedlist2Node2->next = linkedlist2Node3;
    linkedlist2Head = linkedlist2Node1;
    struct node **Linkedlist3Node1;
    merge(linkedlist1Head, linkedlist2Head, Linkedlist3Node1);
    return 0;
}*/
#include<stdio.h>
int main()
{
    int i,key,j,count,n;
    scanf("%d",&n);
    int arr[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(i=0;i<n;i++)
    {
        key=arr[i];
        j=i-1;
        while(j>=0&&key<arr[j])
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
    for(i=0;i<n;i++)
    {
        count=1;
        while(arr[i]==arr[i+1])
        {
            i++;
            count++;
        }
        printf("%d ",count);
    }
}