#include "person.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    // Error handling omitted on purpose to make the example simpler.

    if (argc < 3 || argc > 4) {
        fprintf(stderr, "Usage: %s <name> <age> <>\n", argv[0]);
        return EXIT_FAILURE;
    }

    struct person *p = person_create("Kalle Johansson", 32);
    if (argc == 4) {
        /*
         * Setting p to NULL so that we get a segmentation fault if contract
         * checks are turned off.
         */
        person_free(p);
        p = NULL;
    }

    printf("name: %s, age: %d\n", person_get_name(p), person_get_age(p));

    /*
     * Using unvalidated input to trigger contract violations. This is an easy
     * way to demonstrate the different contract checking levels.
     *
     * NOTE: Contracts should never be used to validate untrusted input.
     */
    person_set_name(p, argv[1]);
    person_set_age(p, strtol(argv[2], NULL, 10));
    printf("name: %s, age: %d\n", person_get_name(p), person_get_age(p));

    person_free(p);
    return 0;
}
