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

void la_delete_field(la_field_t* field)
{
    free(field);
}

char* la_return_str_value(la_field_t* field)
{
    return (char*)field->value;
}

int la_return_num_value(la_field_t* field)
{
    return (int)field->value;
}