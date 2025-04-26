#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cf.h"

void cf_surname(const char* surname, String* p_cf) {
    String cf_sur = string_from_cstr_intersection(surname, CF_CONSONANTS, 3);

    int missing = 0;

    if(cf_sur.length < CF_SURNAME_LEN) {
        missing = CF_SURNAME_LEN - cf_sur.length;
        // printf("len: %d missing: %d\n", len, missing);
        String sur_vowels = string_from_cstr_intersection(surname, CF_VOWELS, missing);
        string_concat(&cf_sur, sur_vowels.value);
        string_free(&sur_vowels);
    }

    if(cf_sur.length < CF_SURNAME_LEN) {
        missing = CF_SURNAME_LEN - cf_sur.length;
        for(int i = 0; i < missing; i++) {
            string_append(&cf_sur, 'X');
        }
    }

    string_concat(p_cf, cf_sur.value);
    string_free(&cf_sur);
}

void cf_name(const char* name, String* p_cf) {
    String cf_n = string_from_cstr_intersection(name, CF_CONSONANTS, 4);

    if(cf_n.length == 3) {
        string_concat(p_cf, cf_n.value);
        string_free(&cf_n);
        return;
    }

    if(cf_n.length == 4) {
        sprintf(cf_n.value, "%c%c%c", cf_n.value[0], cf_n.value[2], cf_n.value[3]);
        string_concat(p_cf, cf_n.value);
        string_free(&cf_n);
        return;
    }

    size_t missing = CF_NAME_LEN - cf_n.length;

    if(missing > 0) {
        String vowels = string_from_cstr_intersection(name, CF_VOWELS, missing);
        string_concat(&cf_n, vowels.value);
    }

    missing = CF_NAME_LEN - cf_n.length;

    for(int i = cf_n.length; i < CF_NAME_LEN; i++) {
        string_append(&cf_n, 'X');
    }

    string_concat(p_cf, cf_n.value);
    string_free(&cf_n);
}

void cf_birth_year(const char* year, String* p_cf) {
    String last2digits = string_from_cstr_sub(year, -2, -1);
    string_concat(p_cf, last2digits.value);
    string_free(&last2digits);
}

void cf_birth_month(int month, String* p_cf) {
    char m;
    if(month > 12 && month < 1) {
        m = '\0';
    } else {
        m = "ABCDEHLMPRST"[month - 1];
    }

    string_append(p_cf, m);
}

void cf_birth_day_and_sex(int day, char sex, String* p_cf) {
    String cf_bday_sex = string_new_with_cap(2);

    int birth_day = sex == 'm' ? day : day + 40;
    sprintf(cf_bday_sex.value, "%d", birth_day);

    string_concat(p_cf, cf_bday_sex.value);
    string_free(&cf_bday_sex);
}

void cf_birth_place(const char* birth_place, const char* birth_place_province, String* p_cf) {
    String cf_bplace = string_new_with_cap(4);
    FILE* f = fopen("./codici_catastali_comuni_clean.csv", "r");

    // A001;ABANO TERME;PD
    char c;
    int field_num = 0;
    int line_number = 0;
    int column_number = 0;

    String buf = string_from_cstr("");
    String municipality_code = string_from_cstr("");
    String municipality_name = string_from_cstr("");

    while((c = fgetc(f)) != EOF) {
        if(c == ';') {
            // printf("%s\n", buf.value);
            if(field_num == 0) {
                string_set(&municipality_code, buf.value);
                // printf("code: %s\n", municipality_code.value);
            } else if(field_num == 1) {
                string_set(&municipality_name, buf.value);
                // printf("name: %s\n", municipality_name.value);
                String upper_birth_place = string_from_cstr(birth_place);
                string_upper(&upper_birth_place);
                // printf("haystack: %s, needle: %s\n", municipality_name.value, upper_birth_place.value);
                if(strstr(municipality_name.value, upper_birth_place.value)) {
                    string_free(&upper_birth_place);
                    printf("found municipality: %s %s\n", municipality_name.value,
                        municipality_code.value);
                    string_set(&cf_bplace, municipality_code.value);
                    break;
                }
            }
            field_num++;
            string_clear(&buf);
        } else if(c == '\n') {
            field_num = 0;
            line_number++;
            column_number = 0;
            string_clear(&buf);
        } else {
            string_append(&buf, c);
        }

        column_number++;
    }

    string_free(&buf);
    string_free(&municipality_code);
    string_free(&municipality_name);

    fclose(f);

    string_concat(p_cf, cf_bplace.value);
    string_free(&cf_bplace);
}

void cf_control_char(String* p_incomplete_cf) {
    int odd[] = { 1, 0, 5, 7, 9, 13, 15, 17, 19, 21, 2, 4, 18, 20, 11, 3, 6, 8, 12, 14, 16, 10, 22,
        25, 24, 23 };

    int sum = 0;
    for(size_t i = 0; i < p_incomplete_cf->length; i++) {
        char c = p_incomplete_cf->value[i];
        int index;
        if(isalpha(c)) {
            index = c - 'A';
        } else if(isalnum(c) && !isalpha(c)) {
            index = c - '0';
        }

        int val;
        if((i + 1) % 2 == 0) {
            val = index;
        } else {
            val = odd[index];
        }

        printf("c: %c, i: %lu, val: %d\n", c, i, val);
        sum += val;
    }

    printf("sum: %d\n", sum);
    char control = 'A' + (sum % 26);

    string_append(p_incomplete_cf, control);
}
