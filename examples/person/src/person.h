#ifndef __PERSON_PERSON_H
#define __PERSON_PERSON_H

#ifdef __cplusplus
extern "C" {
#endif

struct person;

struct person *person_create(const char *name, int age);

void person_free(struct person *p);

const char *person_get_name(struct person *p);
void person_set_name(struct person *p, const char *name);

int person_get_age(struct person *p);
void person_set_age(struct person *p, int age);

#ifdef __cplusplus
}
#endif

#endif /* __PERSON_PERSON_H */
