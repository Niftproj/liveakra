#include <stdio.h>
#include "liveakra.h"

int main(void) {

    printf("\nrunning...\n");
    
    la_field_t name_field;
    LA_INIT_FIELD(&name_field, "name", FIELD_TYPE_STRING, "lalu");
    la_field_t num_field;
    LA_INIT_FIELD(&num_field, "rank", FIELD_TYPE_NUMBER, 5);

    printf("label: %s, val: %s", name_field.label, LA_RETURN_STRING_VALUE(&name_field));
    printf("label: %s, val: %d", num_field.label, LA_RETURN_NUM_VALUE(&num_field));

    return 0;

}