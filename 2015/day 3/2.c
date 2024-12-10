#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1
#define STR_SIZE 8192

#define isDigit(c) (c >= '0' && c <= '9')

typedef long unsigned int luint;
typedef char bool;
#define true 1
#define false 0


typedef struct{
    int x;
    int y;
} coord;

bool coordcmp(const coord *coord1, const coord *coord2){
    return (bool)!(coord1->x == coord2->x && coord1->y == coord2->y);
}

void coordcopy(coord *copy, const coord *coord0){
    copy->x = coord0->x;
    copy->y = coord0->y;
}


#define HT_CAPACITY 1000

#define FNV_OFFSET 14695981039346656037UL
#define FNV_PRIME 1099511628211UL

static luint hash_key(const coord* key){
    luint hash;
    const coord* p;

    hash = FNV_OFFSET;
    p = key;

    hash ^= (luint)(p->x);
    hash *= FNV_PRIME;
    hash ^= (luint)(p->y);
    hash *= FNV_PRIME;

    return hash;
}

/* Hash table entry */
typedef struct{
    coord* key;    /* key is NULL if this slot is empty */
    luint value;
} ht_entry;

/* Hash table structure */
typedef struct ht{
    ht_entry* entries;  /* hash slots */
    luint capacity;    /* size of _entries array */
    luint length;      /* number of items in hash table */
} ht;

ht* ht_create(void){
    ht* table = malloc(sizeof(ht));
    if (table == NULL)
        return NULL;

    table->length = 0;
    table->capacity = HT_CAPACITY;

    table->entries = calloc(table->capacity, sizeof(ht_entry));
    if (table->entries == NULL){
        free(table);
        return NULL;
    }

    return table;
}

void ht_destroy(ht* table){
    luint i;
    
    for (i = 0; i < table->capacity; i++){
        free((void*)table->entries[i].key);
    }

    free(table->entries);
    free(table);
}

luint ht_get(ht* table, const coord* key){
    luint hash = hash_key(key);
    luint index = (luint)(hash & (luint)(table->capacity - 1));

    while (table->entries[index].key != NULL){
        if (coordcmp(key, table->entries[index].key) == 0)
            return table->entries[index].value;
        index++;
        if (index >= table->capacity)
            index = 0;
    }

    return 0;
}

static const coord* ht_set_entry(ht_entry* entries, luint capacity, const coord* key, luint value, luint* plength) {
    luint hash;
    luint index;

    if (key == NULL)
        return NULL;

    hash = hash_key(key);
    index = (luint)(hash & (luint)(capacity - 1));

    while (entries[index].key != NULL) {
        if (coordcmp(key, entries[index].key) == 0) {
            entries[index].value = value;
            return entries[index].key;
        }
        index++;
        if (index >= capacity)
            index = 0;
    }

    if (plength != NULL)
        (*plength)++;
    entries[index].key = (coord*)malloc(sizeof(coord));
    coordcopy(entries[index].key, key);
    entries[index].value = value;
    
    return key;
}

static bool ht_expand(ht* table) {
    luint i, new_capacity;

    new_capacity = table->capacity * 2;
    if (new_capacity < table->capacity)
        return false;  /* overflow */

    ht_entry* new_entries = calloc(new_capacity, sizeof(ht_entry));
    if (new_entries == NULL)
        return false;

    for (i = 0; i < table->capacity; i++) {
        ht_entry entry = table->entries[i];
        if (entry.key != NULL) {
            ht_set_entry(new_entries, new_capacity, entry.key, entry.value, NULL);
        }
    }

    free(table->entries);
    table->entries = new_entries;
    table->capacity = new_capacity;
    
    return true;
}

const coord* ht_set(ht* table, const coord* key, luint value){
    if (table->length >= table->capacity / 2)
        if (!ht_expand(table))
            return NULL;

    return ht_set_entry(table->entries, table->capacity, key, value, &table->length);
}


int main(){
    char c, cInput[MAX_LINES][STR_SIZE + 1];
    int i, j, k;
    luint res, aux;
    coord positions[2];
    ht *table;

    memset(cInput, '\0', MAX_LINES * (STR_SIZE + 1));
    for(i = 0; i < MAX_LINES; i++){
        scanf("%c", &c);
        for(j = 0; c != '\n' && c != '\r' && c != '\0' && j < STR_SIZE; j++){
            cInput[i][j] = c;
            scanf("%c", &c);
        }
        cInput[i][j] = '\0';
    }

    /*--------------------------------*/

    table = ht_create();
    res = 0;
    positions[0].x = positions[0].y = 0;
    positions[1].x = positions[1].y = 0;
    for(k = 0; k < STR_SIZE; k++){
        aux = ht_get(table, &positions[k%2]);
        if(!aux) res++;
        ht_set(table, &positions[k%2], aux + 1);
        switch(cInput[0][k]){
            case '^':
                positions[k%2].y++;
                break;
            
            case 'v':
                positions[k%2].y--;
                break;

            case '>':
                positions[k%2].x++;
                break;

            case '<':
                positions[k%2].x--;
                break;
        }
    }
    k--;
    aux = ht_get(table, &positions[k%2]);
    if(!aux) res++;
    ht_set(table, &positions[k%2], aux + 1);
    
    ht_destroy(table);

    /*--------------------------------*/

    printf("%ld", res);
    
    return 0;
}
