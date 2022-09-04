#include <stdio.h>
#include <stdlib.h>
#include "liveakra.h"

/* test */
#define test_section(desc)\
  do {\
    printf("--- %s\n", desc);\
  } while (0)

#define test_assert(cond)\
  do {\
    int pass__ = cond;\
    printf("[%s] %s:%d: ", pass__ ? "PASS" : "FAIL", __FILE__, __LINE__);\
    printf((strlen(#cond) > 50 ? "%.47s...\n" : "%s\n"), #cond);\
    if (pass__) { pass_count++; } else { fail_count++; }\
  } while (0)

#define test_print_res()\
  do {\
    printf("------------------------------------------------------------\n");\
    printf("-- Results:   %3d Total    %3d Passed    %3d Failed       --\n",\
           pass_count + fail_count, pass_count, fail_count);\
    printf("------------------------------------------------------------\n");\
  } while (0)

int pass_count = 0;
int fail_count = 0;

int main(void) {

    printf("\n");

    {
        test_section("la_field: [str]");
        la_field_t* name_field = la_create_field("name", (void*)"lalu", LA_TYPE_STRING);
        test_assert(name_field->label == "name");
        test_assert(la_return_str_value(name_field) == "lalu");
        la_delete_field(name_field);
    }

    {
        test_section("la_field: [num]");
        la_field_t* num_field = la_create_field("rank", (void*)9, LA_TYPE_NUMBER);
        test_assert(num_field->label == "rank");
        test_assert(la_return_num_value(num_field) == 9);
        la_delete_field(num_field);
    }
    

    return 0;

}