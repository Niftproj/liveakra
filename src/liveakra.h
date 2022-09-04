/**
 * @file liveakra.h
 * @author Ashu Sharma (ashusharma.sigmadev@gmail.com) (github.com/ashusharmasigdev)
 * @brief single c header for liveakra - a runtime live database, with simplicity of queries
 * @version 0.1
 * @date 2022-09-02
 * 
 * @copyright Copyright (c) 2022 Nift* Developers.
 * 
 */

#include "vec.h"

#ifndef LIVEAKRA_H
#define LIVEAKRA_H

#define LIVEAKRA_VERSION    "0.1"

/**
 * @brief field data type
 */
enum la_field_types
{
    LA_TYPE_STRING,
    LA_TYPE_NUMBER
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
 * @brief functions
 */


la_field_t* la_create_field(char** label, void* value, la_field_types_t type);
void la_delete_field(la_field_t* field);

char* la_return_str_value(la_field_t* field);
int la_return_num_value(la_field_t* field);

#endif