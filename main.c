#include <ctype.h>
#include <stdio.h>
#include <string.h>

#include "./cf.h"

#define input(prompt, input_format, ...)                                                           \
    printf("%s", prompt);                                                                          \
    scanf(input_format, __VA_ARGS__);

void string_to_upper(char* str) {
    for(size_t i = 0; i < strlen(str); i++) {
        str[i] = toupper(str[i]);
    }
}

int main() {
    char* surname;
    input("Surname: ", "%ms", &surname);
    string_to_upper(surname);

    char* name;
    input("Name: ", "%ms", &name);
    string_to_upper(name);

    char* birth_year;
    input("Birth Year: ", "%ms", &birth_year);

    int birth_month = 0;
    input("Birth Month: ", "%d", &birth_month);

    int birth_day = 0;
    input("Birth Day: ", "%d", &birth_day);

    char sex = '\0';
    input("Sex (m/f): ", "\n%c", &sex);

    char* birth_place;
    input("Birth Place: ", "%ms", &birth_place);

    char* birth_place_province;
    input("Birth Province: ", "%ms", &birth_place_province);

    puts("");
    // printf("surname: %s\nname: %s\nbirth date: %s-%02d-%d\nsex: %c\nbirth_place: %s (%s)\n",
    //     surname, name, birth_year, birth_month, birth_day, sex, birth_place, birth_place_province);

    String cf = string_new_with_cap(16);

    cf_surname(surname, &cf);
    cf_name(name, &cf);
    cf_birth_year(birth_year, &cf);
    cf_birth_month(birth_month, &cf);
    cf_birth_day_and_sex(birth_day, sex, &cf);
    cf_birth_place(birth_place, birth_place_province, &cf);
    cf_control_char(&cf);
    printf("CF: '%s'\n", cf.value);
}
