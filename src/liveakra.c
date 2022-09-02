#include "liveakra.h"

char* LA_RETURN_STRING_VALUE(la_field_t* field)
{
    return (char*)field->value;
}

int LA_RETURN_NUM_VALUE(la_field_t* field)
{
    return (int)field->value;
}