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
    size_t size;
    size_t tableSize;
    
} HashTable;


typedef struct List
{
    void * item;
    struct List * next;
    
} item;


boolean Hash_Remove(void * item);

boolean Hash_Rehash();

boolean Hash_Find(void * item);

boolean Hash_Get_HashCode(void * item);

size_t Hash_HashCode(void * item);



boolean Hash_Add(void * item);




#endif /* HashMap_h */
