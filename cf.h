#ifndef CF
#define CF

#define CF_CONSONANTS "BCDFGHJKLMNPQRSTVWXYZ"
#define CF_VOWELS "AEIOU"

#define CF_SURNAME_LEN 3
#define CF_NAME_LEN 3

int strings_min_len(const char* s1, const char* s2);
void string_to_upper(const char* str, char* uppercase_str);
void strings_intersect_chars(const char* s1, const char* s2, int max, char* intersection);

void cf_surname(const char* surname, char* output);
void cf_name(const char* name, char* output);
void cf_birth_year(const char* year, char* output);
void cf_birth_month(int month, char* ouput);
int cf_birth_day_and_sex(int day, char sex);
void cf_birth_place(const char* birth_place, const char* birth_place_province, char* output);
void cf_control_letter(const char* incomplete_cf, char* output);

#endif
