 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
    char info[100];
    struct node *ptr;
}*front,*temp1,*temp,*front1;
 
struct node1
{
    char info1[100];
    struct node1 *ptr1;
}*top,*top1,*temp2;


void enq(char data[100]);
void deq();
void display_queue();
void create();
void queuesize();
void push(char data[100]);
void display_stack();
void stack_count();
void create1();
 
int count = 0;
int count1 = 0;
 
void main()
{
    int no, ch, e;
    int state=1;
    char name[100];
    create();
    create1();
    while(state==1)
    {
    printf("1 - For entry of customer");
    printf("\n 2 - For exit of customer");
    printf("\n 3 - The names of customers who left the restaurant");
    printf("\n 4 - No. of customers who left");
    printf("\n 5 - Display the names of customers in restaurant");
    printf("\n 6 - No. of customers in restaurant");
    
    printf("\n Enter choice : ");
    scanf("%d", &ch);
	
        switch (ch)
        {
        case 1:
            printf("Enter name: \n");
            scanf("%s", name);
            enq(name);
            break;
        case 2:
            deq();
            break;
	case 3:
	    display_stack();
	    break;
	case 4:
	    stack_count();
	    break;
	
        case 5:
            display_queue();
            break;
        case 6:
            queuesize();
            break;
	
        default:
            printf("Wrong choice, Please enter correct choice  ");
            break;
        }
	printf("\nDo you want to continue?\n");
	printf("Enter 1 for YES, 0 for NO\n");
	scanf("%d",&state);
    }
}
 
/* Create an empty queue */
void create()
{
    front =  NULL;
}

/* Create an empty stack */
void create1()
{
    top = NULL;
}
 
/* Returns stack size */
void stack_count()
{
    printf("\n No. of customers who left the restaurant : %d\n", count1);
}

/* Returns queue size */
void queuesize()
{
    printf("\n No. of customers in restaurant : %d\n", count);
}
 
/* Enqueing the queue */
void enq(char data[100])
{
    if (front == NULL)
    {
        temp1 = (struct node *)malloc(1*sizeof(struct node));
        temp1->ptr = NULL;
        strcpy(temp1->info,data);

        front = temp1;
    }
    else
    {
        temp=(struct node *)malloc(1*sizeof(struct node));
        temp1->ptr = temp;
        strcpy(temp->info,data);

        temp->ptr = NULL;
 
        temp1 = temp;
    }
    count++;
}

/*pushing into stack*/
void push(char data[100])
{
    if (top == NULL)
    {
        top =(struct node1 *)malloc(1*sizeof(struct node1));
        top->ptr1 = NULL;
        strcpy(top->info1,data);
    }
    else
    {
        temp2 =(struct node1 *)malloc(1*sizeof(struct node1));
        temp2->ptr1 = top;
        strcpy(temp2->info1,data);
        top = temp2;
    }
    count1++;
}
 
 
/* Displaying the queue elements */
void display_queue()
{
    front1 = front;
 
    if (front1 == NULL)
    {
        printf("Restaurant is empty\n");
        return;
    }
    while (front1 != temp2)
    {
        printf("%s ", front1->info);
        front1 = front1->ptr;
    }
    /*if (front1 == temp2)
        printf("%s", front1->info);*/
}

/* Display stack elements */
void display_stack()
{
    top1 = top;
 
    if (top1 == NULL)
    {
        printf("Stack is empty\n");
        return;
    }
 
    while (top1 != NULL)
    {
        printf("%s ", top1->info1);
        top1 = top1->ptr1;
    }
 }
 
/* Dequeing the queue */
void deq()
{
    front1 = front;
 
    if (front1 == NULL)
    {
        printf("\nRestaurant is empty\n");
        return;
    }
    else{
        if (front1->ptr != NULL)
        {
            front1 = front1->ptr;
            printf("\n %s left\n", front->info);
            push(front->info);
            free(front);
            front = front1;
        }
        else
        {
            printf("\n%s left\n", front->info);
	    push(front->info);
            free(front);
            front = NULL;
            temp1 = NULL;
        }
}
	
        count--;
}
 

 
