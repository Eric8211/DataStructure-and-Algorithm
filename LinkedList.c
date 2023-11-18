#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}Node;

void add_node(Node **start, int value)
{
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->data = value;
    new_node->next = NULL;

    if (*start == NULL)   //First time to add
    {
        *start = new_node;
        return;
    }
    else  //After first time to add
    {
        Node *current;
        current = *start;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = new_node;
        return;
    }
}

void insert_node(Node **start, int insertAfterValue, int value)
{
    Node *current = *start;
    while (current->next != NULL)
    {
        if (insertAfterValue == current->data)
        {
            Node *new_node = (Node*)malloc(sizeof(Node));
            new_node->data = value;
            new_node->next = NULL;
            //Last node to insert
            if (current->next == NULL)
            {
                current->next = new_node;
                break;
            }
            else
            {
                //Insert node between 2 node
                new_node->next = current->next;
                current->next = new_node;
                break;
            }
        }
        current = current->next;
    }
    
}

void delete_node(Node **start, int value)
{
    Node *current = *start, *temp;
    int notExist;

    //If we want to delete first node
    if (current->data == value)
    {
        notExist = 0;
        *start = current->next;
        free(current);
    }
    //Delete the node which is not the first node
    while (current->next != NULL)
    {
        if (current->next->data == value)
        {
            notExist = 0;
            temp = current->next;
            current->next = current->next->next;
            free(temp);
            break;
        }
        else
        {
            notExist = 1;
            current = current->next;
        }
    }
    //Print exist or nnot
    if (notExist == 1)
    {
        printf("%d is not exist\n", value);
        return;
    }
    else
    {
        printf("delete %d successfully\n", value);
    }
    
}

void traversal_list(Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void delete_list(Node *node)
{
    Node *current, *temp;
    current = node;
    while (current != NULL)
    {
        temp = current;
        current = current->next;
        free(temp);
    }
}

int main()
{
    Node *number = NULL;
    add_node(&number, 1);
    add_node(&number, 40);
    add_node(&number, 90);
    delete_node(&number, 40);
    delete_node(&number, 10);
    insert_node(&number, 1, 50);

    traversal_list(number);
    delete_list(number);
    return 0;
}