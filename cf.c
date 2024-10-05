#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cf.h"

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

void cf_name(const char* name, char* output) { }

void cf_birth_year(const char* year, char* output) { output = string_last_n(year, 2); }

void cf_birth_month(int month, char* ouput) { }

int cf_birth_day_and_sex(int day, char sex) { return sex == 'm' ? day : day + 40; }

void cf_birth_place(const char* birth_place, const char* birth_place_province, char* output) { }

void cf_control_letter(const char* incomplete_cf, char* output) { }
