#include <stdlib.h>
#include "liveakra.h"

la_field_t* la_create_field(char** label, void* value, la_field_types_t type)
{
    la_field_t* field = (la_field_t*)malloc(sizeof(la_field_t));
    field->label = label;
    field->value = value;
    field->type = type;
    return field;
}

la_record_t* la_create_record()
{
    la_record_t* record = (la_record_t*)malloc(sizeof(la_record_t));
    record->fields = la_create_list();
    return record;
}

int la_record_add_field(la_record_t* record, la_field_t* field)
{
    /* filter if field label is same */
    return la_list_add_node(record->fields, (void*)field);
}

la_field_t* la_record_get_field(la_record_t* record, int at)
{
    return (la_field_t*)la_list_get_node(record->fields, at)->data;
}

bool la_record_delete_field(la_record_t* record, int at)
{
    return la_list_remove_node(record->fields, at);
}

void la_delete_field(la_field_t* field)
{
    free(field);
}

void la_delete_record(la_record_t* record)
{
    free(record);
}

char* la_return_str_value(la_field_t* field)
{
    return (char*)field->value;
}

int la_return_num_value(la_field_t* field)
{
    return (int)field->value;
}