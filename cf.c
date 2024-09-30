#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int strings_min_len(char* s1, char* s2) {
    int s1_len = strlen(s1);
    int s2_len = strlen(s2);

    return s1_len < s2_len ? s1_len : s2_len;
}

void strings_to_upper(char* str, char** uppercase_str) {

}

void strings_intersect_chars(char* s1, char* s2, char** intersection) {
    int intersection_index = 0;
    
    int i = 0;
    char c;
    do {
        c = s1[i];
        if(strchr(s2, c) != NULL) {
            *intersection[intersection_index] = c;
            intersection_index++;
        }

        i++;
    } while(c != '\0');
}

void cf_surname(char* surname, char** output) {
    
}

void cf_name(char* name, char** output){}

void cf_birth_year(char* year, char** output){}

void cf_birth_month(int month, char* ouput){}

void cf_birth_day_and_sex(int day, int* output){}

void cf_birth_place(char *brithplace, char *birthplace_province, char** output){}

void cf_control_letter(char* incomplete_cf, char *output){}
