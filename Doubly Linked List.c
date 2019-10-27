#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head = NULL;
void Print();

void CreateList(int n)
{
    if(n < 1)
        return;

    int i,data;
    struct node *temp;
    head = (struct node*)malloc(sizeof(struct node));

    printf("Enter Node[1]: ");
    scanf("%d", &data);

    head -> data = data;
    head -> next = NULL;
    head -> prev = NULL;
    temp = head;

    for(i=2; i<=n; i++)
    {
        struct node *NewNode = (struct node*)malloc(sizeof(struct node));
        printf("Enter Node[%d]: ",i);
        scanf("%d", &data);

        NewNode -> data = data;
        NewNode -> next = NULL;
        NewNode -> prev = temp;

        temp -> next = NewNode;
        NewNode -> prev = temp -> next;
        temp = temp -> next;
    }
}

void InsertAtBeginning()
{
    int data;
    struct node *NewNode = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter the data: ");
    scanf("%d", &data);

    NewNode -> data = data;
    NewNode -> next = NULL;
    NewNode -> prev = NULL;

    if(head == NULL)
    {
        head = NewNode;
    }
    else
    {
        head -> prev = NewNode;
        NewNode -> next = head;
        head = NewNode;
    }
    Print();
}

void InsertAtN()
{
    int data, position, i;
    struct node *NewNode = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter the data: ");
    scanf("%d", &data);
    printf("\nEnter the position: ");
    scanf("%d", &position);

    NewNode -> data = data;
    NewNode -> next = NULL;
    NewNode -> prev = NULL;

    if(position == 1)
    {
        NewNode -> next = head;
        head -> prev = NewNode;
        head = NewNode;
    }
    else
    {
        struct node *temp;
        temp = head;
        for(i=2; i<=position-1; i++)
        {
            temp = temp -> next;
        }

        NewNode -> next = temp -> next;
        temp -> next = NewNode;
        NewNode -> prev = temp;
    }
    Print();
}

void InsertAtEnd()
{
    struct node *NewNode = (struct node*)malloc(sizeof(struct node));
    int data;
    printf("\nEnter the data: ");
    scanf("%d", &data);
    struct node *temp;

    NewNode -> data = data;
    NewNode -> next = NULL;
    NewNode -> prev = NULL;

    if(head == NULL)
    {
        head = NewNode;
    }
    else
    {
        temp = head;
        while(temp -> next!=NULL)
        {
            temp = temp -> next;
        }
        temp -> next = NewNode;
        NewNode -> prev = temp;
    }
    Print();
}

void DeleteFromBeginning()
{
    struct node *temp;
    if(head == NULL)
    {
        printf("\nList Underflow\n");
        return;
    }
    temp = head;
    head = head -> next;
    free(temp);

    Print();
}

void DeleteFromN()
{
    int position,i;
    struct node *temp, *PrevNode;
    if(head == NULL)
    {
        printf("\nList Underflow\n");
        return;
    }

    printf("\nEnter the position: ");
    scanf("%d", &position);

    PrevNode = head;

    if(position ==1)
    {
        temp = head;
        head = head -> next;
        free(temp);
    }
    else
    {
        for(i=2; i<=position-1; i++)
        {
            PrevNode = PrevNode -> next;
        }
        temp = PrevNode -> next;
        PrevNode -> next = temp -> next;
        free(temp);
    }
    Print();
}

void DeleteFromEnd()
{
    struct node *LastNode, *PrevNode;
    if(head == NULL)
    {
        printf("\nList Underflow\n");
        return;
    }
    else if(head -> next == NULL && head -> prev == NULL) //only one element
    {
        head = NULL;
        free(head);
    }
    else
    {
        LastNode = head;
        while(LastNode -> next!=NULL)
        {
            PrevNode = LastNode;
            LastNode = LastNode -> next; //Automatically gets NULL
        }
        PrevNode -> next = NULL;
        free(LastNode);
    }
    Print();
}

void Reverse()
{
    struct node *prev, *temp, *current;
    current = head;
    prev = NULL;
    while(current!=NULL)
    {
        temp = current -> next;
        current -> next = prev;
        prev = current;
        current = temp;
    }
    head = prev;

    Print();
}

void Print()
{
    struct node *temp;
    if(head == NULL)
    {
        printf("\nList is empty\n");
        return;
    }
    else
    {
        temp = head;
        printf("\nList is: ");
        while(temp!=NULL)
        {
            printf("%d ",temp -> data);
            temp = temp ->next;
        }
    }
    printf("\n");
}

int main()
{
    int n,x;
    printf("Enter the amount of nodes: ");
    scanf("%d", &n);
    CreateList(n);
    Print();
    do
    {
    printf("\nMenu\n");
    printf("1. Insertion At Beginning\n");
    printf("2. Insertion At N\n");
    printf("3. Insertion At End\n");
    printf("4. Deletion From Beginning\n");
    printf("5. Deletion From N\n");
    printf("6. Deletion From End\n");
    printf("7. Reverse\n");
    printf("0. Exit\n");
    printf("\nEnter the choice: ");
    scanf("%d", &x);
    switch(x)
    {
        case 1 :
            {
                InsertAtBeginning();
            }
            break;
        case 2 :
            {
                InsertAtN();
            }
            break;
        case 3 :
            {
                InsertAtEnd();
            }
            break;
        case 4 :
            {
                DeleteFromBeginning();
            }
            break;
        case 5 :
            {
                DeleteFromN();
            }
            break;
        case 6 :
            {
                DeleteFromEnd();
            }
            break;
        case 7 :
            {
                Reverse();
            }
            break;
        case 0 :
            break;
    }
    }while(x > 0);
}
