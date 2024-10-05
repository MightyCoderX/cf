#include <stdio.h>
#include <stdlib.h>

#include "./cf.h"

#define input(prompt, input_format, ...)                                                           \
    printf("%s", prompt);                                                                          \
    scanf(input_format, __VA_ARGS__);

int main() {
    /*char *name;*/
    /*cf_name("Mattia", &name);*/
    /**/
    /*printf("Name: %s\n", name);*/

    char* surname;
    input("Surname: ", "%ms", &surname);
    string_to_upper(surname, surname);

    // char* name;
    // input("Name: ", "%ms", &name);
    // string_to_upper(name, name);
    //
    // char* birth_year;
    // input("Birth Year: ", "%ms", &birth_year);
    //
    // int birth_month = 0;
    // input("Birth Month: ", "%d", &birth_month);
    //
    // int birth_day = 0;
    // input("Birth Day: ", "%d", &birth_day);
    //
    // char sex = '\0';
    // input("Sex (m/f): ", "\n%c", &sex);
    //
    // char* birth_place;
    // input("Birth Place: ", "%ms", &birth_place);
    //
    // char* birth_place_province;
    // input("Birth Province: ", "%ms", &birth_place_province);
    //
    // puts("");
    // printf("surname: %s\nname: %s\nbirth date: %s-%02d-%d\nsex: %c\nbirth_place: %s (%s)\n",
    //     surname, name, birth_year, birth_month, birth_day, sex, birth_place, birth_place_province);

    char* cf = malloc(17);

    cf_surname(surname, cf);
    printf("CF: '%s'\n", cf);
}
