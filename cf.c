#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cf.h"
#include "dynamic_string/dynamic_string.h"

#define PRINT_DEBUG(msg, format) printf("%s: %" format "\n", __func__, msg);

int strings_min_len(const char* s1, const char* s2) {
    int s1_len = strlen(s1);
    int s2_len = strlen(s2);

    return s1_len < s2_len ? s1_len : s2_len;
}

void string_to_upper(const char* str, char* uppercase_str) {
    int len = strlen(str);
    for(int i = 0; i < len; i++) {
        uppercase_str[i] = toupper(str[i]);
    }
}

char* string_last_n(const char* s, size_t n) {
    size_t length = strlen(s);

    return (char*)(length < n ? s : s + length - n);
}

void strings_intersect_chars(const char* s1, const char* s2, int max, char* intersection) {
    int intersection_index = 0;

    int i = 0;
    char c;
    do {
        c = s1[i];
        if(strchr(s2, c) != NULL) {
            intersection[intersection_index] = c;
            intersection_index++;
        }

        i++;

        printf("s1: %s\n", s1);
        printf("s2: %s\n", s2);
        printf("c: %c\n", c);
        printf("intersection: %s\n", intersection);
        puts("");
    } while(c != '\0' && intersection_index < max);
}

void cf_surname(const char* surname, char* output) {
    strings_intersect_chars(surname, CF_CONSONANTS, CF_SURNAME_LEN, output);

    int len = strlen(output);
    int missing = 0;

    if(len < CF_SURNAME_LEN) {
        missing = CF_SURNAME_LEN - len;
        printf("len: %d missing: %d\n", len, missing);
        strings_intersect_chars(surname, CF_VOWELS, missing, output + len);
    }

    len = strlen(output);

    if(len < CF_SURNAME_LEN) {
        missing = CF_SURNAME_LEN - len;
        for(int i = len; i < len + missing; i++) {
            output[i] = 'X';
        }
    }
}

void cf_name(const char* name, char* output) {
    int len = strlen(output);
    strings_intersect_chars(name, CF_CONSONANTS, 4, output + len);

    int missing = 0;

    if(len == 3)
        return;

    if(len == 4) {
        sprintf(output + len, "%c%c%c", output[0], output[1], output[3]);
        return;
    }

    missing = CF_NAME_LEN - len;

    for(int i = len; i < len + missing; i++) {
        output[i] = 'X';
    }
}

void cf_birth_year(const char* year, char* output) {
    int len = strlen(output);
    char* year_2_digits = string_last_n(year, 2);
    sprintf(output, "%s", year_2_digits);
}

void cf_birth_month(int month, char* output) {
    if(month > 12 && month < 1) {
        return;
    }

    output[strlen(output)] = "ABCDEHLMPRST"[month - 1];
}

void cf_birth_day_and_sex(int day, char sex, char* output) {
    int birth_day = sex == 'm' ? day : day + 40;
    sprintf(output + strlen(output), "%d", birth_day);
}

void cf_birth_place(const char* birth_place, const char* birth_place_province, char* output) {
    FILE* f = fopen("./codici_catastali_comuni_clean.csv", "r");

    // A001;ABANO TERME;PD
    char c;
    int field_num = 0;
    int line_number = 0;
    int column_number = 0;

    String buf = string_init("");
    String municipality_code = string_init("");
    String municipality_name = string_init("");

    while((c = fgetc(f)) != EOF) {
        if(c == ';') {
            field_num++;
            printf("%s\n", buf.value);
            if(field_num == 0) {
                string_set(&municipality_code, buf.value);
            } else if(field_num == 1) {
                string_set(&municipality_name, buf.value);
            } else if(field_num == 2) {
                char* upper_birth_place = malloc(strlen(birth_place) + 1);
                string_to_upper(birth_place, upper_birth_place);
                if(strstr(municipality_name.value, upper_birth_place)) {
                    sprintf(output, "%s", municipality_code.value);
                    break;
                }
            }
            string_clear(&buf);
        } else if(c == '\n') {
            line_number++;
            column_number = 0;
            string_clear(&buf);
        } else {
            string_append(&buf, c);
        }

        column_number++;
    }

    string_free(buf);
    string_free(municipality_code);
    string_free(municipality_name);

    fclose(f);
}

void cf_control_letter(const char* incomplete_cf, char* output) { }
