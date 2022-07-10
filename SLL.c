#include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef struct node
{
    char player[20];
    char team[20];
    float bavg;
    struct node *next;

} NODE;

NODE *add(NODE *first)
{
    NODE *newnode, *temp;
    newnode = (NODE *)malloc(sizeof(NODE));
    newnode->next = NULL;
    printf("\nEnter the name of player");
    scanf("%s", newnode->player);
    printf("\nEnter the name of team");
    scanf("%s", newnode->team);
    printf("\nEnter the batting average");
    scanf("%f", &newnode->bavg);
    if (first == NULL)
        first = newnode;
    else
    {
        temp = first;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        printf("\n%s is inserted in list", newnode->player);
    }
    return first;
}
void display(NODE *first)
{

    if (first == NULL)
    {
        printf("\nEmpty list");
    }
    else
    {
        printf("\nNAME\tTEAM\tBAVG\n");
        while (first != NULL)
        {
            printf("%s\t%s\t%f\n", first->player, first->team, first->bavg);
            first = first->next;
        }
    }
}
NODE *search(NODE *first)
{
    char player[20];
    NODE *temp;
    if (first == NULL)
        printf("\nEmpty");
    else
    {
        printf("\nEnter the name of player to be searched:");
        scanf("%s", player);
        temp = first;
        while (temp != NULL && strcmp(player, temp->player) != 0)
        {
            temp = temp->next;
        }
        if (temp == NULL)
            printf("\nNOt found");
        else
        {
            printf("\nFound");
            printf("\nBatting average is %f", temp->bavg);
            printf("\nenter new batting average:");
            scanf("%f", &temp->bavg);
            printf("\nupdated");
        }
    }
    return (first);
}
int main()
{
    NODE *first=NULL;
    int choice;
    while(1)
    {
        printf("\n1:add\n2:search\n3:display\n4:exit");
        printf("\nenter your choice");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:first=add(first);
            break;
            case 2:first=search(first);
            break;
            case 3:display(first);
            break;
            case 4:exit(0);
            default:printf("\ninvalid");
        }
    }
    return 0;
}