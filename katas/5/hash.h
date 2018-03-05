#ifndef H_HASH
#define H_HASH
#define TRUE 1
#define FALSE 0
typedef struct e {
    void *key;
    void *value;
} Element;

typedef struct v {
    unsigned count;
    unsigned size;
    Element *elements;
} Vector;

typedef struct ht {
    unsigned size;
    Vector *data;
    unsigned (*hash)(void *, unsigned);
    void *(*copyKey)(void *);
    void *(*copyValue)(void *);
    int (*compareKeys)(void *, void *);
} Hash;

void initHash(Hash *, unsigned,
              unsigned (*)(void *, unsigned),
              void *(*)(void *), void *(*)(void *),
              int (*compareKeys)(void *, void *));
void insert(Hash *, void *, void *);
void * get(Hash *, void *);
void * set(Hash *, void *, void *);
int contains(Hash *, void *);
#endif