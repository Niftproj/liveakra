/**
 * this file is part of liveakra (http://github.com/niftproj/liveakra)
*/

#ifndef LIVEAKRA_LISTVIEW_H
#define LIVEAKRA_LISTVIEW_H

struct la_list_node
{
    void* data;
    struct la_list_node* prev;
    struct la_list_node* next;
};
typedef struct la_list_node la_list_node_t;

struct la_list
{
    la_list_node_t* head;
    int count;
};
typedef struct la_list la_list_t;

la_list_t* la_create_list();
la_list_node_t* la_create_list_node(void* data);
int la_list_add_node(la_list_t* list, void* data);
void la_list_delete(la_list_t* list);
la_list_node_t* la_list_get_node(la_list_t* list, int at);

#endif