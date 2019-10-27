#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    int data;
    struct node *next;
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
    temp = head;
    temp -> next = head; //for creating and printing one node only

    for(i=2; i<=n; i++)
    {
        struct node *NewNode = (struct node*)malloc(sizeof(struct node));
        if(NewNode == NULL)
          {
              printf("Unable to allocate memory");
              return;
          }
        else
          {
              printf("Enter Node[%d]: ",i);
              scanf("%d", &data);

              NewNode -> data = data;
              NewNode -> next = NULL;

              temp -> next = NewNode;
              temp = temp -> next;
          }
        temp -> next = head; //linking rear to front
    }
}

void InsertAtBeginning()
{
    int data;
    struct node *temp, *NewNode = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter the data: ");
    scanf("%d", &data);

    NewNode -> data = data;
    NewNode -> next = NULL;
    if(head == NULL)
    {
        head = NewNode;
        head -> next = head; //head must point towards itself
    }
    else
    {
        temp = head;
        while(temp -> next!=head)
        {
            temp = temp -> next;
        }

        NewNode -> next = temp -> next;
        temp -> next = NewNode;
        head = NewNode;
    }
    Print();
}

void InsertAtN()
{
    int data, position, i;
    struct node *temp, *NewNode = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter the data: ");
    scanf("%d", &data);
    printf("\nEnter the position: ");
    scanf("%d", &position);

    NewNode -> data = data;
    NewNode -> next = NULL;

    if(position == 1)
    {
        temp = head;
        while(temp -> next!=head)
        {
            temp = temp -> next;
        }
        NewNode -> next = temp -> next;
        temp -> next = NewNode;
        head = NewNode;
    }
    else
    {
        temp = head;
        for(i=2; i<=position-1; i++)
        {
            temp = temp -> next;
        }
        NewNode -> next = temp -> next;
        temp -> next = NewNode;
    }
    Print();
}

void InsertAtEnd()
{
    int data;
    struct node *temp, *NewNode = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter the data: ");
    scanf("%d", &data);

    NewNode -> data = data;
    NewNode -> next = NULL;

    if(head == NULL)
    {
        head = NewNode;
        head -> next = head;
    }
    else
    {
        temp = head;
        while(temp -> next!=head)
        {
            temp = temp -> next;
        }
        temp -> next = NewNode;
        NewNode -> next = head;
    }
    Print();
}

void DeleteFromBeginning()
{
    struct node *temp, *LastNode;
    if(head == NULL)
    {
        printf("\nList Underflow\n");
        return;
    }
    if(head -> next == head)
    {
        head = NULL;
        free(head);
    }
    else
    {
        temp = head;
        LastNode = head;

        while(LastNode -> next!=head)
        {
            LastNode = LastNode -> next;
        }

        head = head -> next;
        LastNode -> next = head;
        free(temp);
    }
    Print();
}

void DeleteFromN()
{
    int position,i;
    struct node *temp, *PrevNode, *LastNode;
    if(head == NULL)
    {
        printf("\nList Underflow\n");
        return;
    }

    printf("\nEnter the position: ");
    scanf("%d", &position);

    PrevNode = head;

    if(position ==1 && head -> next == head) //only one element
    {
        head = NULL;
        free(head);
    }
    else if(position == 1)
    {
        temp = head;
        LastNode = head;

        while(LastNode -> next!=head)
        {
            LastNode = LastNode -> next;
        }

        head = head -> next;
        LastNode -> next = head;
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

        while(PrevNode -> next!=head) //TO ASSIGN THE LAST NODE POINT TO HEAD
        {
            PrevNode = PrevNode -> next;
        }
        PrevNode -> next = head;
    }
    Print();
}

void DeleteFromEnd()
{
    struct node *PrevNode, *LastNode;
    if(head == NULL)
    {
        printf("\nList Underflow\n");
        return;
    }
    else if(head -> next == head) //only one element
    {
        head = NULL;
        free(head);
    }
    else
    {
        LastNode = head;
        while(LastNode -> next!=head)
        {
            PrevNode = LastNode;
            LastNode = LastNode -> next; //Automatically gets NULL
        }

        PrevNode -> next = head; //ASSIGNING THE NEW LAST NODE TO HEAD
        free(LastNode);
    }
    Print();
}

bool IsCircular(struct node *head)
{
    // An empty linked list is circular
    if (head == NULL)
       return true;

    // Next of head
    struct node *node = head->next;

    // This loop would stop in both cases (1) If
    // Circular (2) Not circular
    while (node != NULL && node != head)
       node = node->next;

    // If loop stopped because of circular
    // condition
    return (node == head);
}

void Reverse()
{
    struct node *prev,*current,*last;
    if(head == NULL)
    {
        printf("\nList is empty\n");
        return;
    }
    last = head;
    prev = head;
    current = head -> next;
    head = head -> next;
    while(head != last)
    {
        head = head -> next;
        current -> next = prev;
        prev = current;
        current = head;
    }
    current -> next = prev;
    head = prev;
    Print();
}

void Print()
{
    struct node *temp;
    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    else
        temp = head;
        printf("\nList is: ");
        while(temp -> next!=head)
        {
            printf("%d ",temp -> data);
            temp = temp ->next;
        }
        printf("%d ",temp -> data);
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
    printf("7. Circular Linked List Check\n");
    printf("8. Reverse\n");
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
                if(IsCircular(head)==true)
                {
                    printf("\nCircular\n");
                }
                else
                {
                    printf("\nNot Circular\n");
                }
            }
            break;
        case 8 :
            {
                Reverse();
            }
            break;
        case 0 :
            break;
    }
    }while(x > 0);
}
