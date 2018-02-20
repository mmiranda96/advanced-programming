#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "qsort.h"

static int compareById(const void *this, const void *that)
{
    return ((Student*)this)->id - ((Student*)that)->id;
}

void sortById(Student *class, int numElements)
{
    qsort((void*)class, (size_t)numElements, sizeof(Student), compareById);
}

static int compareByName(const void *this, const void *that)
{
    return strcmp(((Student*)this)->name, ((Student*)that)->name);
}

void sortByName(Student *class, int numElements)
{
    qsort((void*)class, (size_t)numElements, sizeof(Student), compareByName);
}
