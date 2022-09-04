/**
 * this file is part of liveakra (http://github.com/niftproj/liveakra)
*/

#ifndef LIVEAKRA_LISTVIEW_H
#define LIVEAKRA_LISTVIEW_H

struct la_list
{
    void* data;
    struct la_list* next;
};
typedef struct la_list la_list_t;

#endif