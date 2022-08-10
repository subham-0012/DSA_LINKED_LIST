/*Given a singly linked list consisting of N nodes.The task is to remove duplicates(nodes with duplicate values) from the given list(if exists) .Note : Try not to use extra space.Expected time complexity is O(N)*/
//Time complexity is O(n) and if Linked List is already given then space complexity is O(1)
#include <stdio.h>
#include <stdlib.h>
            //Linked List Node
            struct node
{
    int data;
    struct node *next;
};
//void function that take head pointer of a singly linked List and remove duplicate nodes
void removeDuplicates(struct node * Head)
{
    //newHead pointing same as head of Linked List
    struct node *newHead=Head;
    struct node *nextToNext=NULL;
    //checking if Linked List is empty
    if(newHead==NULL)
    {
        return ;
    }
    //else condition
    else
    {
        //Traverse the list till last node
        while(newHead->next!=NULL)
        {
            //checking if current node data is equal to next node data
            if(newHead->data==newHead->next->data)
            {
                nextToNext=newHead->next->next;
                free(newHead->next);
                newHead->next=nextToNext;
            }
            else
            {
                //moving to next node
                newHead=newHead->next;
            }
        }
    }
}
int main()
{
    struct node *LinkedList=NULL,*Head=NULL,*ptr=NULL;
    int node, data;
    printf("Enter the number of nodes you want to insert ");
    scanf("%d", &node);//Taking number of nodes form user
    for (int i = 0; i < node; i++)
    {
        printf("Enter the data of %dth node ", i + 1);
        scanf("%d", &data);//Taking each node data from user
        LinkedList = (struct node *)malloc(sizeof(struct node)); //creating the linked list in heap memory
        LinkedList->data = data;
        LinkedList->next = NULL;
        if (Head == NULL)
        {
            Head = LinkedList;//assigning head to starting of linked List
            ptr = Head;
        }
        else
        {
            ptr->next = LinkedList;
            ptr = LinkedList;
        }
    }
    removeDuplicates(Head);//sending head to removeDuplicates function to remove duplicate elements
    printf("Linked List after removing duplicate elements is ");
    while(Head!=NULL)//traversing the list after removing duplicate elements and printing the data
    {
        printf("%d ",Head->data);
        Head=Head->next;
    }
}