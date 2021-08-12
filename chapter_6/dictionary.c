/* Write a function undef that will remove a name and definition
 * from the table maintained by lookup and install.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct nlist {              /* table entry: */
    struct nlist *next;     /* next entry in chain */
    char *name;             /* defined name */
    char *defn;             /* replacement text */
};


#define HASHSIZE 4

static struct nlist *hashtab[HASHSIZE]; /* pointer table */

/* hash: form hash value for string s */
unsigned hash(char *s)
{
    unsigned hashval;

    for(hashval = 0; *s != '\0'; s++)
        hashval = *s + 31 * hashval;

    return hashval % HASHSIZE;
}


/* lookup: look for s in hashtab */

struct nlist *lookup(char *s)
{
    struct nlist *np;

    for (np = hashtab[hash(s)]; np != NULL; np = np->next)
        if (strcmp(s, np->name) == 0)
            return np;  /* found */
    return NULL;        /* not found */
}

/* install: put (name, defn) in hashtab */
struct nlist *install(char *name, char *defn)
{
    struct nlist *np;
    unsigned hashval;

    if ((np = lookup(name)) == NULL)  { /* not found */
        np = (struct nlist *) malloc(sizeof(*np));

        if (np == NULL || (np->name = strdup(name)) == NULL)
            return NULL;
        hashval = hash(name);
        np->next = hashtab[hashval];
        hashtab[hashval] = np;
    } else  /* already there */
        free((void *) np->defn);    /* free the previous defn */

    if ((np->defn = strdup(defn)) == NULL)
        return NULL;

    return np;
}

struct nlist *undef(char *name)
{
    struct nlist *found = lookup(name);

    if (found == NULL)
        return NULL;
    else
    {
        if (found->next != NULL)
        {
            found = found->next;
        }
        else
        {
            if (found == hashtab[hash(name)])
            {
                hashtab[hash(name)] = NULL;
                free((void *) found);
            }
            else
            {
                struct nlist *previous;
                struct nlist *current;
                for (current = hashtab[hash(name)]; current != NULL; current = current->next)
                {
                    if (current == found)
                    {
                        previous->next = current->next;
                        free((void *) found);
                        return NULL;
                    }
                    previous = current;
                }
            }
        }
    }
    return found;
}


int main(int argc, char *argv[])
{
    struct nlist *table[6] = {
            (install("key", "value")),
            (install("key1", "value1")),
            (install("key2", "value2")),
            (install("key3", "value3")),
            (install("key4", "value4")),
            (install("key5", "value5"))
    };

    int i;

    struct nlist *start;
    for (i = 0; i < HASHSIZE; i++)
    {
        printf("Bucket %d: ", i);
        for (start = hashtab[i]; start != NULL; start = start->next)
        {
            printf("KEY: %s  Value: %s   ", start->name, start->defn);
        } 
        printf("\n");
    }

    undef("key1");
    undef("key3");

    for (i = 0; i < HASHSIZE; i++)
    {
        printf("Bucket %d: ", i);
        for (start = hashtab[i]; start != NULL; start = start->next)
        {
            printf("KEY: %s  Value: %s   ", start->name, start->defn);
        } 
        printf("\n");
    }

    struct nlist *result;

    char *keys[6] = {
            "key",
            "key1",
            "key2",
            "key3",
            "key4",
            "key5"
    };

    for (i = 0; i < 6; i++) {
        if ((result = lookup(keys[i])) == NULL) {
            printf("key not found\n");
        } else {
            printf("%s->%s\n", result->name, result->defn);
        }
    }

    return 0;
}