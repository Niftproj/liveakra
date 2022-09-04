#include <stdlib.h>
#include "listview.h"

la_list_t* la_create_list()
{
    la_list_t* list = (la_list_t*)malloc(sizeof(la_list_t));
    list->count = 0;
    list->head = NULL;
    return list;
}

la_list_node_t* la_create_list_node(void* data)
{
    la_list_node_t* node = (la_list_node_t*)malloc(sizeof(la_list_node_t));
    node->data = data;
}

int la_list_add_node(la_list_t* list, void* data)
{
    if(list->head == NULL)
    {
        list->head = la_create_list_node(data);
        list->head->next = NULL;
        list->head->prev = NULL;
        list->count += 1;
    }
    else
    {
        /* go on end and add node to next */
        la_list_node_t* node = list->head;
        while (node->next != NULL)
        {
            node = node->next;
        }

        // we got on end as (while end)
        if(node->next == NULL)
        {
            la_list_node_t* n = la_create_list_node(data);
            n->next = NULL;
            n->prev = node;
            node->next = n;
            list->count += 1;
        }
        
    }
    return list->count;
}

la_list_node_t* la_list_get_node(la_list_t* list, int at)
{
    if(at > list->count || list->count == 0)
        return NULL;
    
    if(at == 0)
        return list->head;

    int index = at;
    la_list_node_t* node = list->head;
    while (node->next != NULL && index > 0)
    {
        index -= 1;
        node = node->next;
    }
    
    return node;
}

void la_list_delete(la_list_t* list)
{
    free(list);
}