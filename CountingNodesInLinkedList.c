//Write a program in C to create a singly linked list of n nodes and count the number of nodes
//Time complexity is O(n) and Space complexity is O(n)
#include <stdio.h>
#include <stdlib.h>
//Linked List Node
struct node
{
    int data;
    struct node *next;
};
int NoOfNodes(struct node *ptr)//function to calculate no of nodes in a linked list
{
    int count=0;//initializing a count variable
    while (ptr != NULL) //traversing the list
    {
        count++; //Increasing the nodes by 1 in each iteration of loop
        ptr = ptr->next;
    }
    return count;
}
int main()
{
    struct node *linkedList=NULL,*head=NULL,*ptr=NULL;
    int count=0,node,data;
    printf("Enter the number of nodes you want to insert ");
    scanf("%d", &node); //Taking number of nodes form user
    for(int i=0;i<node;i++)
    {
        printf("Enter the data of %dth node ",i+1);
        scanf("%d",&data);
        linkedList=(struct node*)malloc(sizeof(struct node));//creating the linked list in heap memory
        linkedList->data=data;
        linkedList->next=NULL;
        if(head==NULL)
        {
            head = linkedList; //assigning head to starting of linked List
            ptr=head;
        }
        else
        {
            ptr->next=linkedList;
            ptr=linkedList;
        }
    }
    count=NoOfNodes(head);
    printf("\nYou have inserted %d nodes\n",count);
    while (head != NULL) //traversing the list and printing the data
    {
        printf("%d ",head->data);
        head=head->next;
    }
}