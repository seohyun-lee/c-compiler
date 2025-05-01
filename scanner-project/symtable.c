#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define SYM_TABLE_SIZE	100
#define HASH_TABLE_SIZE 100
#define STR_POOL_SIZE   1000
char separators[] = " ,;\t\n\r\n";
char str_pool[STR_POOL_SIZE];
int sym_table[SYM_TABLE_SIZE][2];

#define isLetter(x) ( ((x) >= 'a' && (x) <='z') || ((x) >= 'A' && (x) <= 'Z') || ((x) == '_')) 
#define isDigit(x) ( (x) >= '0' && (x) <= '9' )

typedef struct HTentry* HTpointer;
typedef struct HTentry {
    int index;  
    HTpointer next;  
}HTentry;

HTpointer HT[HASH_TABLE_SIZE];

int divisionMethod(char* key, int tableSize) {
    unsigned int hash_key = 0;
    int c;

    while ((c = *key++)) {
        hash_key += c;
    }
    return hash_key % tableSize;
}

int midsquareMethod(char* key, int tableSize) {
    int squared;
    int midPart;
    unsigned int hash_key = 0;
    int c;

    while ((c = *key++)) {
        hash_key += c;
    }

    squared = hash_key * hash_key;
    midPart = squared / 100 % 1000; // ¡¶∞ˆ∞™¿« ¡ﬂ∞£ ∫Œ∫– √ﬂ√‚
    return midPart % tableSize;
}

int foldingMethod(char* key, int tableSize) {
    int fold = 0;
    unsigned int hash_key = 0;
    int c;

    while ((c = *key++)) {
        hash_key += c;
    }

    while (hash_key > 0) {
        fold += hash_key % 10000; // 4¿⁄∏Ææø ≥™¥©æÓ ¥ı«‘
        hash_key /= 10000;
    }
    return fold % tableSize;
}
void init_sym_table() {
    int i;
    for (i = 0; i < SYM_TABLE_SIZE; i++) {
        sym_table[i][0] = -1;
        sym_table[i][1] = -1;
    }
}

void print_sym_table() {
    int i;
    printf("\nSymbol Table\n");
    printf("ID\tIndex\tLength\tSymbol\n");
    for (i = 0; i < SYM_TABLE_SIZE; i++) {
        if (sym_table[i][0] != -1) {
            printf("%d\t%d\t%d\t%s\n", i+1, sym_table[i][0], sym_table[i][1], str_pool+sym_table[i][0]);
        }
    }
}

HTpointer lookup_hash_table(int id_index, int hscode) {
    HTpointer entry = HT[hscode];

    // √º¿Ã¥◊µ» ∏ÆΩ∫∆Æ∏¶ ≈Ωªˆ
    while (entry != NULL) {
        if (strcmp(str_pool+ sym_table[entry->index-1][0], str_pool+id_index) == 0) {
            return entry; // √£¿∫ «◊∏Ò π›»Ø
        }
        entry = entry->next;
    }
    return NULL; // «◊∏Ò¿ª √£¡ˆ ∏¯«— ∞ÊøÏ
}

int add_hash_table(int id_index, int hscode) {
    // ªı «◊∏Ò ª˝º∫ π◊ √ ±‚»≠
    HTpointer newEntry = (HTpointer)malloc(sizeof(HTentry));
    if (newEntry == NULL) {
        printf("∏ﬁ∏∏Æ «“¥Á Ω«∆–\n");
        return -1; 
    }
    newEntry->index = id_index;
    newEntry->next = NULL;

    if (HT[hscode] == NULL) {
        // √π π¯¬∞ «◊∏Ò¿∏∑Œ √ﬂ∞°
        HT[hscode] = newEntry;
    }
    else {
        // ¿ÃπÃ «◊∏Ò¿Ã ¿÷¿∏∏È, ∏ÆΩ∫∆Æ¿« ∏« æ’ø° √ﬂ∞°
        newEntry->next = HT[hscode];
        HT[hscode] = newEntry;
    }
    return 0;
}

void print_hash_table() {
    printf("\nHash Table:\n");
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        HTpointer entry = HT[i];
        if (entry != NULL) {
            printf("[%d]: ", i);
            while (entry != NULL) {
                printf("%d -> ", entry->index);
                entry = entry->next;
            }
            printf("NULL\n");
        }
    }
}

int index_start = 0;
int sym_table_index = 0;

int process_sym_table(char* identifier) {
    int hash_value = 0;
    strcpy(str_pool + index_start, identifier);

    hash_value = divisionMethod(str_pool + index_start, HASH_TABLE_SIZE);
    
    HTpointer htp = lookup_hash_table(index_start, hash_value);
    if (htp == NULL) {
        sym_table[sym_table_index][0] = index_start;
        sym_table[sym_table_index++][1] = (int)strlen(str_pool + index_start);

        if (add_hash_table(sym_table_index, hash_value) < 0) {
            return -1;
        }
        printf("%d\t%s\n", hash_value, str_pool + index_start); // πˆ∆€¿« ≥ªøÎ¿ª »≠∏Èø° √‚∑¬

        index_start += strlen(identifier);
        str_pool[index_start++] = '\0';
        return 0;
    }
    else {
        printf("%d\t%s (already exists)\n", hash_value, str_pool + index_start); // πˆ∆€¿« ≥ªøÎ¿ª »≠∏Èø° √‚∑¬
        return 0;
    }
}
