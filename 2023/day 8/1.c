#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 768
#define STR_SIZE 283
/*
#define MAX_LINES 5
*/
/*
#define MAX_LINES 9
#define STR_SIZE 16
*/

#define isDigit(c) (c >= '0' && c <= '9')

typedef long unsigned int luint;
typedef char bool;
#define true 1
#define false 0


#define HT_CAPACITY 2 * (MAX_LINES - 2)

#define FNV_OFFSET 14695981039346656037UL
#define FNV_PRIME 1099511628211UL

static luint hash_key(const char* key){
    luint hash;
    const char* p;

    hash = FNV_OFFSET;
    p = key;

    for (p = key; *p; p++){
        hash ^= (luint)(unsigned char)(*p);
        hash *= FNV_PRIME;
    }

    return hash;
}

/* Hash table entry */
typedef struct{
    const char* key;    /* key is NULL if this slot is empty */
    void* value;
} ht_entry;

/* Hash table structure */
typedef struct ht{
    ht_entry* entries;  /* hash slots */
    luint capacity;    /* size of _entries array */
    luint length;      /* number of items in hash table */
} ht;

/* Hash table iterator */
typedef struct{
    const char* key;  /* current key */
    void* value;      /* current value */

    ht* _table;       /* reference to hash table being iterated */
    luint _index;    /* current index into ht._entries */
} hti;

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

void* ht_get(ht* table, const char* key){
    luint hash = hash_key(key);
    luint index = (luint)(hash & (luint)(table->capacity - 1));

    while (table->entries[index].key != NULL){
        if (strcmp(key, table->entries[index].key) == 0)
            return table->entries[index].value;
        index++;
        if (index >= table->capacity)
            index = 0;
    }

    return NULL;
}

static const char* ht_set_entry(ht_entry* entries, luint capacity, const char* key, void* value, luint* plength) {
    luint hash;
    luint index;

    if (key == NULL)
        return NULL;

    hash = hash_key(key);
    index = (luint)(hash & (luint)(capacity - 1));

    while (entries[index].key != NULL) {
        if (strcmp(key, entries[index].key) == 0) {
            entries[index].value = value;
            return entries[index].key;
        }
        index++;
        if (index >= capacity)
            index = 0;
    }

    if (plength != NULL)
        (*plength)++;
    entries[index].key = (char*)key;
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

const char* ht_set(ht* table, const char* key, void* value){
    if (value == NULL)
        return NULL;

    if (table->length >= table->capacity / 2)
        if (!ht_expand(table))
            return NULL;

    return ht_set_entry(table->entries, table->capacity, key, value, &table->length);
}

luint ht_length(ht* table) {
    return table->length;
}

hti* ht_iterator(ht* table) {
    hti* it = malloc(sizeof(hti));
    if(it == NULL )
        return NULL;

    it->_table = table;
    it->_index = 0;

    return it;
}

bool ht_next(hti* it) {
    ht* table = it->_table;

    while (it->_index < table->capacity) {
        luint i = it->_index;
        it->_index++;
        if (table->entries[i].key != NULL) {
            ht_entry entry = table->entries[i];
            it->key = entry.key;
            it->value = entry.value;

            return true;
        }
    }

    return false;
}


typedef struct{
    char key[4];
    char L[4];
    char R[4];
} node;

void copyStrInRange(char *s, const char *s0, int i0, int size){
    int i;
    for(i = 0; i < size && s0[i + i0] != '\0'; i++){
        s[i] = s0[i + i0];
    }
    s[i] = '\0';
}


int main(){
    char c, cInput[MAX_LINES][STR_SIZE + 1];
    int i, j, res;
    char instructions[STR_SIZE + 1];
    node *pAuxNode, *currentNode, *destination;
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

    for(i = 0; cInput[0][i] != '\0'; i++) instructions[i] = cInput[0][i];
    instructions[i] = '\0';

    table = ht_create();
    for(i = 2; i < MAX_LINES; i++){
        pAuxNode = (node*)malloc(sizeof(node));
        copyStrInRange((char*)pAuxNode->key, cInput[i], 0, 3);
        copyStrInRange((char*)pAuxNode->L, cInput[i], 7, 3);
        copyStrInRange((char*)pAuxNode->R, cInput[i], 12, 3);
        ht_set(table, pAuxNode->key, pAuxNode);
    }

    currentNode = ht_get(table, "AAA");
    destination = ht_get(table, "ZZZ");
    for(i = res = 0; currentNode != destination; i++, res++){
        if(instructions[i] == '\0') i = 0;
        if(instructions[i] == 'L')
            currentNode = ht_get(table, (char*)currentNode->L);
        else currentNode = ht_get(table, (char*)currentNode->R);
    }

    ht_destroy(table);

    /*--------------------------------*/

    printf("%d", res);
    
    return 0;
}
