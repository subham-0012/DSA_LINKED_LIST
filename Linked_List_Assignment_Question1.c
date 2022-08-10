#include <stdio.h>
#include <stdlib.h>
struct Student
{
    char Name[100],grade;
    int RollNo,mark1,mark2,mark3,mark4,mark5;
    float average_marks;
};
struct Node
{
    struct Node* prev;
    struct Student stud;
    struct Node* Next;
};
char grade(float average_marks)
{
    char result;
    if(average_marks>89)
    {
        result='O';
    }
    else if(average_marks>79)
    {
        result='A';
    }
    else if(average_marks>69)
    {
        result = 'B';
    }
    else if(average_marks>59)
    {
        result = 'C';
    }
    else if(average_marks>49)
    {
        result = 'D';
    }
    return result;
}
struct Node* create(struct Node *newhead)
{
    struct Node * ptr=newhead,*t;
    if (newhead == NULL)
    {
        newhead=(struct Node*)malloc(sizeof(struct Node));
        newhead->Next=NULL;
        newhead->prev=NULL;
        printf("enter the Name of student ");
        scanf("%s",newhead->stud.Name);
        printf("enter the rollno of student ");
        scanf("%d",&newhead->stud.RollNo);
        printf("enter the marks 1 of student ");
        scanf("%d",&newhead->stud.mark1);
        printf("enter the marks 2 of student ");
        scanf("%d",&newhead->stud.mark2);
        printf("enter the marks 3 of student ");
        scanf("%d",&newhead->stud.mark3);
        printf("enter the marks 4 of student ");
        scanf("%d",&newhead->stud.mark4);
        printf("enter the marks 5 of student ");
        scanf("%d",&newhead->stud.mark5);
        newhead->stud.average_marks=(newhead->stud.mark1+newhead->stud.mark2+newhead->stud.mark3+newhead->stud.mark4+newhead->stud.mark5)/5.0;
        newhead->stud.grade=grade(newhead->stud.average_marks);
        ptr = newhead;
    }
    else
    {
        while(ptr->Next!=NULL)
        {
            ptr=ptr->Next;
        }
        t = (struct Node *)malloc(sizeof(struct Node));
        t->Next = NULL;
        t->prev = NULL;
        printf("enter the Name of student ");
        scanf("%s",t->stud.Name);
        printf("enter the rollno of student ");
        scanf("%d",&t->stud.RollNo);
        printf("enter the marks 1 of student ");
        scanf("%d",&t->stud.mark1);
        printf("enter the marks 2 of student ");
        scanf("%d",&t->stud.mark2);
        printf("enter the marks 3 of student ");
        scanf("%d",&t->stud.mark3);
        printf("enter the marks 4 of student ");
        scanf("%d",&t->stud.mark4);
        printf("enter the marks 5 of student ");
        scanf("%d",&t->stud.mark5);
        t->stud.average_marks=(t->stud.mark1+t->stud.mark2+t->stud.mark3+t->stud.mark4+t->stud.mark5)/5.0;
        t->stud.grade=grade(t->stud.average_marks);
        ptr->Next=t;
        t->Next=NULL;
        t->prev=ptr;
        ptr=t;
    }
    return newhead;
}
void display(struct Node *newNode)
{
    struct Node * ptr=newNode,*ptr1;
    while(ptr!=NULL)
    {
        printf("The student name is %s\n",ptr->stud.Name);
        printf("The student roll no is %d\n",ptr->stud.RollNo);
        printf("The marks of student is 1st subject is %d\n",ptr->stud.mark1);
        printf("The marks of student is 2nd subject is %d\n",ptr->stud.mark2);
        printf("The marks of student is 3rd subject is %d\n",ptr->stud.mark3);
        printf("The marks of student is 4th subject is %d\n",ptr->stud.mark4);
        printf("The marks of student is 5th subject is %d\n",ptr->stud.mark5);
        printf("The average marks of student are %f\n",ptr->stud.average_marks);
        printf("The grade of student is %c\n",ptr->stud.grade);
        if(ptr->Next==NULL)
        {
            ptr1=ptr;
        }
        ptr=ptr->Next;
    }
    while(ptr1!=NULL)
    {
        printf("The student name is %s\n",ptr1->stud.Name);
        printf("The student roll no is %d\n",ptr1->stud.RollNo);
        printf("The marks of student is 1st subject is %d\n",ptr1->stud.mark1);
        printf("The marks of student is 2nd subject is %d\n",ptr1->stud.mark2);
        printf("The marks of student is 3rd subject is %d\n",ptr1->stud.mark3);
        printf("The marks of student is 4th subject is %d\n",ptr1->stud.mark4);
        printf("The marks of student is 5th subject is %d\n",ptr1->stud.mark5);
        printf("The average marks of student are %f\n",ptr1->stud.average_marks);
        printf("The grade of student is %c\n",ptr1->stud.grade);
        ptr1 = ptr1->prev;
    }
}
int main()
{
    struct Node * Head=NULL;
    int number_of_students;
    printf("Enter the number of students ");
    scanf("%d",&number_of_students);
    while(number_of_students--)
    {
        Head=create(Head);
    }
    display(Head);
    return 0;
}