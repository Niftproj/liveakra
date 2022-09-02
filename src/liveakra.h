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

/* memset */
#include <string.h>

#include "vec.h"

#ifndef LIVEAKRA_H
#define LIVEAKRA_H

#define LIVEAKRA_VERSION    "0.1"

enum FieldTypes {
    FIELD_TYPE_NUMBER,
    FIELD_TYPE_STRING,
};

typedef enum FieldTypes FieldTypes_t;

#define LA_NEW_FIELD(NAME, NAME_t)\
    struct NAME {\
        char** label;\
        void* value;\
        FieldTypes_t type;\
    };\
    typedef struct NAME NAME_t;

#define LA_INIT_FIELD(FIELD_NAME, LABEL, TYPE, VALUE)\
    memset((FIELD_NAME), 0, sizeof(*(FIELD_NAME)));\
    *FIELD_NAME.label = LABEL;\
    *FIELD_NAME.value = VALUE;\
    *FIELD_NAME.type = TYPE;

#define LA_GET_FIELD_VALUE(FIELD_NAME)\
    *FIELD_NAME.type == FIELD_TYPE_STRING ? LA_RETURN_STRING_VALUE(FIELD_NAME) : (void)

LA_NEW_FIELD(la_field, la_field_t);

char* LA_RETURN_STRING_VALUE(la_field_t* field);
int LA_RETURN_NUM_VALUE(la_field_t* field);

// struct la_record {
//     vec_t(la_str_field_t) str_fields;
//     vec_t(la_num_field_t) num_fields;
// };

#endif