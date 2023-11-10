#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int d;   
    int p; 
    struct Node  *next; 
}node;

node *create(int d,int p)
{
    node *newnode = (node*)malloc(sizeof(node));
    
    newnode -> d = d;
    newnode -> p = p;
    newnode -> next = NULL;
    
    return newnode;
}

void enqueue(node **top,int d,int p) 
    node *newnode = create(d,p);
    
    if(*top == NULL || p < (*top) -> p)
    {
        newnode -> next = *top;
        *top = newnode;
    }
    else
    {
        node* temp = *top;
        while(temp -> next != NULL && temp -> next -> p <= p)
        {
            temp = temp -> next;
        }
        newnode -> next = temp -> next;
        temp -> next = newnode;
    }
}

void dequeue(node **top) 
{
    if(*top == NULL)
    {
        printf("Queue is empty\n");
        return;
    }
    
    node *temp = *top;
    int d = temp -> d;
    int p = temp -> p;
    *top = temp -> next;
    
    free(temp);
    
    printf("\nDequeued element (data:priority): | %d : %d | \n", d, p);
        
}

void dispaly(node *top) 
{
    if(top == NULL)
    {
        printf("Queue is empty\n");
        return;
    }
    
    printf("Priority Queue (data:priority):\n");
     node *temp = top;
    while(temp != NULL)
    {
        printf("| %d : %d | -> ", temp -> d, temp -> p);
        temp = temp -> next;
    }
    printf("NULL\n");
}


int main()
{
    node *top = NULL;
    int d,p,c;
   
    
    while(1) 
    {
        printf("\nPriority Queue Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &c);
        switch(c)
        {
            case 1:
                printf("Enter the number:");
                scanf("%d",&d);
                printf("Enter the priority:");
                scanf("%d",&p);
                enqueue(&top,d,p); 
                break;
            case 2:
                dequeue(&top); 
                break;
            case 3:
                dispaly(top); 
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}
