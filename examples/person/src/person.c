#include "person.h"

#include <contract/contract.h>
#include <string.h>

#define NAME_MAX_LEN 32

struct person {
    char name[NAME_MAX_LEN];
    int age;
};

struct person *person_create(const char *name, int age)
{
    EXPECT(name != NULL);
    EXPECT_AUDIT(strlen(name) < NAME_MAX_LEN);
    EXPECT(age >= 0);

    struct person *p = malloc(sizeof(struct person));
    if (!p)
        return NULL;

    strcpy(p->name, name);
    p->age = age;
    ENSURE_AUDIT(strcmp(p->name, name) == 0);
    return p;
}

void person_free(struct person *p)
{
    if (p) {
        free(p);
    }
}

const char *person_get_name(struct person *p)
{
    EXPECT(p != NULL);
    return p->name;
}

void person_set_name(struct person *p, const char *name)
{
    EXPECT(p != NULL);
    EXPECT(name != NULL);
    EXPECT_AUDIT(strlen(name) < NAME_MAX_LEN);
    strcpy(p->name, name);
    ENSURE_AUDIT(strcmp(p->name, name) == 0);
}

int person_get_age(struct person *p)
{
    EXPECT(p != NULL);
    return p->age;
}

void person_set_age(struct person *p, int age)
{
    EXPECT(p != NULL);
    EXPECT(age >= 0);
    p->age = age;
}
