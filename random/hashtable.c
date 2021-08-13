#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BUCKET_NUM 100

typedef struct node node_t;

struct node {
    char *key;
    char *value;

    struct node *next;
};

uint32_t hash(char *key)
{
    int key_len = strlen(key);
    int hash = 0;
    for (int i = 0; i < key_len; i++)
    {
        hash ^= key[i];
    }
    return hash % BUCKET_NUM;
}

node_t *get_node_from_table(char *key, node_t *list[])
{
    node_t *node_found;
    uint32_t key_hash = hash(key);

    if (!strcmp(list[key_hash]->key, key))
    {
        node_found = list[key_hash];
        return node_found;
    }
    else
    {
        node_t* prev_node = list[key_hash];
        while (prev_node->next != NULL)
        {
            prev_node = prev_node->next;
            if (!strcmp(prev_node->key, key))
            {
                node_found = prev_node;
                return node_found;
            }
        }
    }
    return NULL;
}

int delete_node_from_table(char *key, node_t *list[])
{
    uint32_t key_hash = hash(key);
    if (!strcmp(list[key_hash]->key, key))
    {
            list[key_hash] = NULL;
            return 1;
    }
    else
    {
        node_t *current_node = list[key_hash];
        node_t *prev_node;
        while (current_node->next != NULL)
        {   
            prev_node = current_node;
            current_node = current_node->next;
            if (!strcmp(current_node->key, key))
            {
                prev_node->next = current_node->next;
                return 1;
            }
        }
    }
    return 0;
}

int add_node_to_table(node_t *old_node, node_t *list[])
{
    uint32_t key_hash = hash(old_node->key);

    if (list[key_hash] == NULL)
        list[key_hash] = old_node;
    else
    {
        node_t *prev_node = list[key_hash];
        while (prev_node->next != NULL)
        {
            prev_node = prev_node->next;
        }
        prev_node->next = old_node;
    }
    return 1;
}

node_t *create_node(char *key, char *value)
{
    node_t *new_node = malloc(sizeof(node_t));
    new_node->key = key;
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}


int main(int argc, char *argv[])
{
    node_t *list[BUCKET_NUM] = {NULL};

    node_t *new_node = create_node("KEY", "VALUE");

    add_node_to_table(new_node, list);

    node_t *res = get_node_from_table("KEY", list);

    printf("%s, %s\n", res->key, res->value);

    return 0;

}