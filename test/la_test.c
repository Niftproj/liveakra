#include <stdio.h>
#include "liveakra.h"

int main(void) {

    printf("\nrunning...\n");

    int i;

    /* test default dataspace */
    la_str_field_t name_field;
    la_str_field_t planet_field;
    LA_INIT_FIELD(&name_field, "name", "lalu");
    LA_INIT_FIELD(&planet_field, "planet", "earth");

    printf("name_field- name: %s, val: %s", name_field.label, name_field.value);
    printf("planet_field- name: %s, val: %s", planet_field.label, planet_field.value);

    return 0;

}