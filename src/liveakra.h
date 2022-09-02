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

#define LA_NEW_FIELD(T, NAME, NAME_t)\
    struct NAME {\
        char** label;\
        T* value;\
    };\
    typedef struct NAME NAME_t;

#define LA_INIT_FIELD(FIELD_NAME, LABEL, VALUE)\
    *FIELD_NAME.label = LABEL;\
    *FIELD_NAME.value = VALUE;

LA_NEW_FIELD(char*, la_str_field, la_str_field_t);

#endif