#include<stdio.h>
#include <stdlib.h>
#include "./cf.h"

int main() {
    /*char *name;*/
    /*cf_name("Mattia", &name);*/
    /**/
    /*printf("Name: %s\n", name);*/
    
    char* s1 = "Mattia";
    char* s2 = CF_CONSONANTS;

    char* intersection = malloc(strings_min_len(s1, s2) + 1);

    strings_intersect_chars(s1, CF_CONSONANTS, &intersection);
    printf("Intersection between '%s' and '%s' is '%s'\n", s1, s2, intersection);
}
