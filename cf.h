#ifndef CF
#define CF

#define CF_CONSONANTS "BCDFGHJKLMNPQRSTVWXYZ"
#define CF_VOWELS "AEIOU"

int strings_min_len(char* s1, char* s2);
void strings_intersect_chars(char* s1, char* s2, char** intersection);

void cf_surname(char* surname, char** output);
void cf_name(char* name, char** output);
void cf_birth_year(char* year, char** output);
void cf_birth_month(int month, char* ouput);
void cf_birth_day_and_sex(int day, int* output);
void cf_birth_place(char *brithplace, char *birthplace_province, char** output);
void cf_control_letter(char* incomplete_cf, char *output);

#endif

