//
//  HashTable.h
//  HW1
//
//  Created by Roicxy Alonso Gonzalez on 7/7/17.
//  Copyright © 2017 AlonsoRoicxy. All rights reserved.
//

#ifndef HashMap_h
#define HashMap_h

#include <stdio.h>
#include "globalconst.h"


typedef struct
{
    void ** table;
    size_t currentSize;
    size_t tableSize;
    
} HashMap;


typedef struct List
{
    void * item;
    struct List * next;
    
} Item;


static const int DEFAULT_TABLE_SIZE = 101;

boolean Hash_Insert(HashMap * myHash,void * item);

boolean Hash_New(HashMap * myHash);

boolean Hash_Remove(HashMap * myHash, void * item);

boolean Hash_Rehash(HashMap * myHash);

boolean Hash_Contains(HashMap * myHash, void * item);

size_t Hash_Get_HashCode(void * item);

size_t Hash_HashingCode(HashMap * myHash, void * item);

boolean Hash_MakeEmpty(HashMap * myHash);

void * Hash_Get_Item(HashMap * myHash, void * item);

boolean Hash_Comparables(void * item1, void * item2);

void * Hash_Get_Item_With_Index(HashMap * myHash, size_t * index);

boolean Hash_Delete_HashMap(HashMap * myHash);

size_t Hash_nextPrime(size_t n);

boolean Hash_isPrime(size_t n);




#endif /* HashMap_h */
