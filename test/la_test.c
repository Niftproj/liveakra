#include <stdio.h>
#include <stdlib.h>
#include "liveakra.h"
#include "listview.h"

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

    {
        test_section("la_listview: create_list");
        la_list_t* list = la_create_list();
        test_assert(list->head == NULL);
        test_assert(list->count == 0);
        test_assert(la_list_add_node(list, "sample") == 1);
        test_assert(list->count == 1);
        test_assert(list->head->data == "sample");
        test_assert(la_list_add_node(list, "sample2") == 2);
        test_assert(list->count == 2);
        test_assert(list->head->next->data == "sample2");
        test_assert(list->head->next->prev->data == "sample");
        test_assert(list->head->next->prev->next->data == "sample2");
        test_assert(la_list_get_node(list, 0)->data == "sample");
        test_assert(la_list_get_node(list, 1)->data == "sample2");
        test_assert(la_list_remove_node(list, 0) == true);
        test_assert(la_list_get_node(list, 0)->data == "sample2");
        test_assert(list->count == 1);
        test_assert(la_list_remove_node(list, 1) == true);
        test_assert(list->count == 0);
        la_list_delete(list);
    }

    {
        test_section("la_record:");
        la_record_t* record1 = la_create_record();
        test_assert(record1->fields->count == 0);
        la_field_t* name_field = la_create_field("name", (void*)"lalu", LA_TYPE_STRING);
        test_assert(la_record_add_field(record1, name_field) == 1);
        la_field_t* num_field = la_create_field("rank", (void*)9, LA_TYPE_NUMBER);
        test_assert(la_record_add_field(record1, num_field) == 2);
        test_assert(la_record_get_field(record1, 0) == name_field);
        test_assert(la_record_get_field(record1, 1) == num_field);
        test_assert(la_record_get_field(record1, 0)->label == "name");
        test_assert(la_return_num_value(la_record_get_field(record1, 1)) == 9);
        test_assert(la_record_delete_field(record1, 0) == true);
        test_assert(la_record_get_field(record1, 0) == num_field);
        la_delete_record(record1);
    }

    test_print_res();

    return 0;

}