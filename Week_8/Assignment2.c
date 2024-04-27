#include <stdio.h>

#include <stdlib.h>

struct node
{
    int id;
    int priority;
    struct node *next;
};

/*
   create_node : Create a new struct node e, with given id and priority as val.
   Return a pointer to e.
*/
struct node *create_node(int id, int val)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));

    new_node->id = id;
    new_node->priority = val;
    new_node->next = NULL;
    return new_node;
}

/*
   append : Append the given node e, to the start of the list.
   Return the head of the list, which is now e.
*/
struct node *append(struct node *list, struct node *e)
{
    if (!list || e->priority > list->priority)
    {
        e->next = list;
        return e;
    }

    struct node *current = list;
    while (current->next && current->next->priority >= e->priority)
    {
        current = current->next;
    }

    e->next = current->next;
    current->next = e;

    return list;
}

/*
   search : Search for a node e in list, with given id.
   Return Return a pointer to e, if found. Return NULL otherwise.
*/
struct node *search(struct node *list, int id)
{
    struct node *current = list;
    while (current != NULL) {
        if (current->id == id) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

/*
   change_priority : Change priority of element with given id (if found) to val.
*/
void change_priority(struct node *list, int id, int val)
{
    struct node *current = list;
    while (current != NULL)
    {
        if (current->id == id)
        {
            current->priority = val;
            return;
        }
        current = current->next;
    }
}

/*
   delete_node : Remove element e from list;
   Return pointer to new head of list;
*/
struct node *delete_node(struct node *list, struct node *e)
{
    struct node *a = list;

    if (e == NULL)
        return list;

    if (e == list)
    {
        a = e->next;
        free(e);
        return a;
    }

    while (a->next != NULL)
    {
        if (a->next == e)
        {
            a->next = e->next;
            break;
        }
        a = a->next;
    }

    free(e);
    return list;
}

/*
   extract_max : Find the element e in list with maximum priority. Remove the element from the list.
       Return the start of new list.
*/
struct node *extract_max(struct node *list)
{
    struct node *e = list;
    struct node *maxe = NULL;
    struct node *prev = NULL, *max_prev = NULL;

    // Find the element with maximum priority in the list
    while (e != NULL) {
        if (maxe == NULL || e->priority > maxe->priority) {
            maxe = e;
            max_prev = prev;
        }
        prev = e;
        e = e->next;
    }

    // If maxe is not NULL, print its id
    if (maxe != NULL) {
        printf("Max: %d\n", maxe->id);
    } else {
        printf("Max: -1\n");
        return list;
    }

    // If maxe is the first node in the list
    if (maxe == list) {
        list = list->next;
    } else {
        max_prev->next = maxe->next;
    }

    free(maxe);

    return list;
}
/*
   find_priority : Searches for an element with given id.
   Returns its priority if found, -1 otherwise.
*/
int find_priority(struct node *list, int id)
{
    struct node *e = search(list, id);
    if (e != NULL)
        return e->priority;
    return -1;
}

int main()
{
    char op;
    int id, val;
    struct node *list = NULL;

    int flag = 1;
    do
    {
        scanf("%c ", &op);
        switch (op)
        {
        case 'A':
            scanf("%d %d", &id, &val);
            list = append(list, create_node(id, val));
            break;
        case 'S':
            scanf("%d", &id);
            printf("%d %d\n", id, find_priority(list, id));
            break;
        case 'C':
            scanf("%d %d", &id, &val);
            change_priority(list, id, val);
            break;
        case 'M':
            list = extract_max(list);
            break;
        case 'E':
            flag = 0;
        }
    } while (flag == 1);
    return 0;
}