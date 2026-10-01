#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char inf[256];
    struct node *next;
};

struct node *head = NULL, *last = NULL;

struct node *get_struct(void)
{
    struct node *p = NULL;
    char s[256];

    if ((p = (struct node*)malloc(sizeof(struct node))) == NULL)
    {
        printf("Memory error\n");
        exit(1);
    }

    printf("Enter unit name: \n");
    scanf("%s", s);
    if (*s == 0)
    {
        printf("No data was recorded\n");
        free(p);
        return NULL;
    }

    strcpy(p->inf, s);
    p->next = NULL;
    return p;
}

void enqueue(void)
{
    struct node *p = get_struct();
    if (p == NULL)
        return;

    if (head == NULL)
    {
        head = p;
        last = p;
    }
    else
    {
        last->next = p;
        last = p;
    }
}

void dequeue(void)
{
    struct node *tmp;

    if (head == NULL)
    {
        printf("Queue empty\n");
        return;
    }

    printf("Removed from queue: %s\n", head->inf);
    tmp = head;
    head = head->next;
    if (head == NULL)
        last = NULL;
    free(tmp);
}

void review(void)
{
    struct node *struc = head;
    if (head == NULL)
    {
        printf("Queue empty\n");
        return;
    }
    printf("Queue (front to back): \n");
    while (struc)
    {
        printf("Name - %s\n", struc->inf);
        struc = struc->next;
    }
}

int main(void)
{
    int choice;

    for (;;)
    {
        printf("\n1 - Add unit (enqueue)\n2 - Remove unit (dequeue)\n3 - Review queue\n0 - Exit\nYour choise: ");
        if (scanf("%d", &choice) != 1)
            break;

        switch (choice)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            review();
            break;
        case 0:
            return 0;
        default:
            printf("Incorrect menu\n");
        }
    }
    return 0;
}
