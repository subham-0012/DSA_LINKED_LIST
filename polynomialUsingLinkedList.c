#include <stdio.h>
#include <stdlib.h>
struct polynomial
{
    int coefficient;
    int exponant;
    struct polynomial *next;
};
int main()
{
    struct polynomial *linkedlist1 = NULL, *head1 = NULL, *ptr1 = NULL, *linkedlist2 = NULL, *head2 = NULL, *ptr2 = NULL, *linkedlist3 = NULL, *head3 = NULL, *ptr3 = NULL;
    int numberofelements,coffn,exp;
    printf("enter the number of elements you want in first polynomial ");
    scanf("%d",&numberofelements);
    for(int i=0;i<numberofelements;i++)
    {
        scanf("%d %d",&coffn,&exp);
        linkedlist1=(struct polynomial*)malloc(sizeof(struct polynomial));
        linkedlist1->coefficient=coffn;
        linkedlist1->exponant=exp;
        linkedlist1->next=NULL;
        if(head1==NULL)
        {
            head1=linkedlist1;
            ptr1=head1;
        }
        else
        {
            ptr1->next=linkedlist1;
            ptr1=ptr1->next;
        }
    }
    printf("enter the number of elements you want in second polynomial ");
    scanf("%d", &numberofelements);
    for (int i = 0; i < numberofelements; i++)
    {
        scanf("%d %d", &coffn, &exp);
        linkedlist2 = (struct polynomial *)malloc(sizeof(struct polynomial));
        linkedlist2->coefficient = coffn;
        linkedlist2->exponant = exp;
        linkedlist2->next = NULL;
        if (head2 == NULL)
        {
            head2 = linkedlist2;
            ptr2 = head2;
        }
        else
        {
            ptr2->next = linkedlist2;
            ptr2 = ptr2->next;
        }
    }
    while(head1!=NULL&&head2!=NULL)
    {
        linkedlist3 = (struct polynomial *)malloc(sizeof(struct polynomial));
        if(head1->exponant>head2->exponant)
        {
            linkedlist3->coefficient=head1->coefficient;
            linkedlist3->exponant = head1->exponant;
            linkedlist3->next=NULL;
            head1=head1->next;
        }
        else if (head1->exponant < head2->exponant)
        {
            linkedlist3->coefficient = head2->coefficient;
            linkedlist3->exponant = head2->exponant;
            linkedlist2->next = NULL;
            head2 = head2->next;
        }
        else
        {
            linkedlist3->coefficient = head1->coefficient+head2->coefficient;
            linkedlist3->exponant = head1->exponant;
            linkedlist3->next = NULL;
            head1 = head1->next;
            head2 = head2->next;
        }
        if (head3 == NULL)
        {
            head3 = linkedlist3;
            ptr3 = head3;
        }
        else
        {
            ptr3->next = linkedlist3;
            ptr3 = ptr3->next;
        }
    }
    while (head1 != NULL)
    {
        linkedlist3 = (struct polynomial *)malloc(sizeof(struct polynomial));
            linkedlist3->coefficient = head1->coefficient;
            linkedlist3->exponant = head1->exponant;
            linkedlist3->next = NULL;
            head1 = head1->next;
        if (head3 == NULL)
        {
            head3 = linkedlist3;
            ptr3 = head3;
        }
        else
        {
            ptr3->next = linkedlist3;
            ptr3 = ptr3->next;
        }
    }
    while (head2 != NULL)
    {
        linkedlist3 = (struct polynomial *)malloc(sizeof(struct polynomial));
        linkedlist3->coefficient = head2->coefficient;
        linkedlist3->exponant = head2->exponant;
        linkedlist3->next = NULL;
        head2 = head2->next;
        if (head3 == NULL)
        {
            head3 = linkedlist3;
            ptr3 = head3;
        }
        else
        {
            ptr3->next = linkedlist3;
            ptr3 = ptr3->next;
        }
    }
    printf("\n");
    while (head3 != NULL)
    {
        printf("%dx^%d ", head3->coefficient, head3->exponant);
        head3 = head3->next;
    }
}