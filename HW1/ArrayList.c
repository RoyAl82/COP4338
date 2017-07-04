//
//  ArrayList.c
//  HW1
//
//  Created by Roicxy Alonso Gonzalez on 6/27/17.
//  Copyright © 2017 AlonsoRoicxy. All rights reserved.
//

#include <stdio.h>
#include "ArrayList.h"

boolean ArrayList_New(ArrayList * list)
{
    if(list)
    {
        ArrayListPtr * t = (ArrayListPtr *) malloc(sizeof(ArrayList));
        list->arr = malloc(sizeof(void));
//        list->arr[list->size] = malloc(sizeof(void) * INITIAL_SIZE_STRING_LIST);
        
        if(t)
        {
            *t = (ArrayList*)malloc(sizeof(ArrayList));
            
            *t = list;
            list->reserved = INITIAL_SIZE_STRING_LIST;
            
            return TRUE;
        }
        
    }
    
    
    return FALSE;
}

boolean ArrayList_Expand(ArrayList * list)
{
    if(list)
    {
        ArrayList * temp = (ArrayList *)realloc(list, sizeof(ArrayList) * list->reserved + INITIAL_SIZE_STRING_LIST);
        
        if(temp)
        {
            temp->reserved += INITIAL_SIZE_STRING_LIST;
            *list = *temp;
            
            return TRUE;
        }
    }
    
    return FALSE;

}
boolean ArrayList_Add(ArrayList * list, void * item)
{
    if(list && item && list->size < list->reserved)
    {
//        list->arr = malloc(sizeof(void));
//        list->arr[list->size] = malloc(sizeof(item) * INITIAL_SIZE_STRING_LIST);
        list->arr[list->size] = malloc(sizeof(void) * INITIAL_SIZE_STRING_LIST);
        
        list->arr[list->size++] = item;
        return TRUE;
    }
    else if(list && list->size == list->reserved && ArrayList_Expand(list))
    {
        return ArrayList_Add(list, item);
    }
    
    return FALSE;
}

void * ArrayList_GetList(ArrayList * list)
{
    
    
    return NULL;
}
inline size_t ArrayList_GetSize(ArrayList * list)
{
    if(list)
        return list->size;
    
    
    return FALSE;
}

//also need to define


boolean ArrayList_Free(ArrayList * list)
{
    
    
    
    return FALSE;
}
boolean ArrayList_Remove(ArrayList * list, size_t index)
{
    
    
    
    return FALSE;
}
boolean ArrayList_RemoveLast(ArrayList *list) //remove last item and updates
{
    if(list)
    {
        void * temp = list->arr[list->arr + list->size - list->arr];
        free(temp);
        return TRUE;
    }
    
    
    return FALSE;
}
boolean ArrayList_Set(ArrayList *list, size_t index, void * item) //it will expand if needed  D
{
    
    
    
    return FALSE;
}
void * ArrayList_Get(ArrayList *list, size_t index)
{
    if(list && index <= list->size)
    {
        return list->arr[index];
    }
    
    
    return NULL;
}
boolean ArrayList_Clear(ArrayList * list) //must do compact
{
    
    
    
    return FALSE;
}
boolean ArrayList_Copy(ArrayList * destination, const ArrayList * source)
{
    
    
    
    return FALSE;
}
boolean ArrayList_ExpandReserved(ArrayList * list, size_t reserved)
{
    
    
    
    return FALSE;
}
boolean ArrayList_Compact(ArrayList * list) //it compacts to size + 100 if possible.
{
    
    
    
    
    return FALSE;
}
