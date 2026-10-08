#include<stdio.h>
#define MAX 5
int queue[MAX];
int front=-1,rear=-1;
void insert()
{
    int value;
    if(rear==MAX-1)
    {
        printf("queue overflow\n");
        return;
    }
    printf("enter the value to insert:");
    scanf("%d",&value);
    if(front ==-1)
        front=0;
    rear++;
    queue[rear]=value;
    printf("%d inserted into the queue \n",value);
}
void delet()
{
    if(front==-1||front>rear)
    {
        printf("queue empty");
        return;
    }
    printf("%d is successfully deleted\n",queue[front]);
    front++;
    if(front>rear)
    {
      front==-1;
      rear==-1;
    }
}
void display()
{
    int i;
    if(front==-1)
    {
        printf("queue empty\n");
        return;
    }
    printf("queue elements are:/n");
    for(i=front;i<=rear;i++)
    {
        printf("\n%d\n",queue[i]);
    }
    printf("\n");
}
int main()
{
   int choice;
   while(1)
   {
       printf("\n====QUEUE OPERATIONS====\n");
       printf("1.insert\n");
       printf("2.delete\n");
       printf("3.display\n");
       printf("4.exit\n");
       printf("enter your choice:");
       scanf("%d",&choice);
       switch(choice)
       {
           case 1:insert();
           break;
           case 2:delet();
           break;
           case 3:display();
           break;
           case 4:printf("exiting...");
           return 0;
           default:printf("invalid input\n");
       }
   }
   return 0;
}
