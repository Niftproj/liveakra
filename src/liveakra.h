/**
 * this file is part of liveakra (http://github.com/niftproj/liveakra)
*/

#include "listview.h"

#ifndef LIVEAKRA_H
#define LIVEAKRA_H

#define LIVEAKRA_VERSION    "0.1"

/**
 * @brief field data type
 */
enum la_field_types
{
    LA_TYPE_STRING,
    LA_TYPE_NUMBER,
};
typedef enum la_field_types la_field_types_t;

/**
 * @brief field
 */
struct la_field
{
    char* label;
    void* value;
    la_field_types_t type;
};
typedef struct la_field la_field_t;


/**
 * @brief record
 */
struct la_record
{
    la_list_t* fields;
    int field_count;
};
typedef struct la_record la_record_t;


/**
 * @brief functions
 */

la_field_t* la_create_field(char** label, void* value, la_field_types_t type);
la_record_t* la_create_record_with_data(la_list_t* fields, int field_counts);
la_record_t* la_create_record();

void la_delete_field(la_field_t* field);

char* la_return_str_value(la_field_t* field);
int la_return_num_value(la_field_t* field);

#endif