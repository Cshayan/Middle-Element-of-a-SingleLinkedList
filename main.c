//Programme to find the middle element of a linked list
#include <stdio.h>
#include <stdlib.h>
//structure declaration
struct node
{
    int data;
    struct node *next;
};
//create function to create the linked list
void create(struct node **start,int num)
{
    struct node *temp,*curr;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=num;
    temp->next=NULL;
    if((*start)==NULL)
    {
        (*start)=temp;
    }
    else
    {
        curr=(*start);
        while(curr->next!=NULL)
        {
            curr=curr->next;
        }
        curr->next=temp;
    }
}
//display function to print the list
void display(struct node *start)
{
    printf("\nThe list is:-\n");
    struct node *curr=start;
    while(curr!=NULL)
    {
        printf("%d\t",curr->data);
        curr=curr->next;
    }
    printf("\n\n");
}
//function to find the middle elements
void findMiddle(struct node *start,int n)
{
    struct node *slow=start, *fast=start,*prev;
    while(fast!=NULL&&fast->next!=NULL)
    {
        prev=slow;
        slow=slow->next;
        fast=fast->next->next;
    }
    if(n%2==1)
    printf("Middle element is %d\n\n\n\n\n",slow->data);
    else
        printf("Middle elements are %d and %d\n\n\n\n\n",prev->data,slow->data);
}
int main()
{
    struct node *start=NULL;
    int n,num;
    printf("Enter the no of nodes to be created:- ");
    scanf("%d",&n);
    int i;
    printf("\nEnter the elements:- ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&num);
        create(&start,num);    //calling create function
    }
    display(start);       //calling display function
    findMiddle(start,n);  //calling findMiddle function
    return 0;
}
