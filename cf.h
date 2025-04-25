#include "./dynamic_string/dynamic_string.h"

#ifndef CF
#define CF

#define CF_ALPHABET "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define CF_CONSONANTS "BCDFGHJKLMNPQRSTVWXYZ"
#define CF_VOWELS "AEIOU"

#define CF_SURNAME_LEN 3
#define CF_NAME_LEN 3
#define CF_LEN 16

void cf_surname(const char* surname, String* p_cf);
void cf_name(const char* name, String* p_cf);
void cf_birth_year(const char* year, String* p_cf);
void cf_birth_month(int month, String* p_cf);
void cf_birth_day_and_sex(int day, char sex, String* p_cf);
void cf_birth_place(const char* birth_place, const char* birth_place_province, String* p_cf);
void cf_control_char(String* p_incomplete_cf);

#endif
