//
//  ArrayList.c
//  HW1
//
//  Created by Roicxy Alonso Gonzalez on 6/27/17.
//  Copyright © 2017 AlonsoRoicxy. All rights reserved.
//

#include <stdio.h>
#include "ArrayList.h"

//****************************************************************
boolean ArrayList_New(ArrayList * list)
{
    if(list)
    {
        list->arr = calloc(INITIAL_SIZE_STRING_LIST, sizeof(void*) * INITIAL_SIZE_STRING_LIST);
        
        if(list->arr)
        {
            list->reserved = INITIAL_SIZE_STRING_LIST;
            list->size = 0;
            return TRUE;
        }
    }
    return FALSE;
}
//*****************************************************************
boolean ArrayList_Expand(ArrayList * list)
{
    if(list->size < list->reserved)
        return TRUE;
    
    if(list && list->arr)
    {
        void * temp = realloc(list->arr, sizeof(void *) * list->reserved * 2);
        
        if(temp)
        {
            list->arr = temp;
            list->reserved += INITIAL_SIZE_STRING_LIST;
            
            return TRUE;
        }
    }
    
    return FALSE;
}
//***************************************************************
boolean ArrayList_Add(ArrayList * list, void * item)
{
    if(list && item && list->size < list->reserved)
    {
        list->arr[list->size++] = item;
        return TRUE;
    }
    else if(list && list->size == list->reserved && ArrayList_Expand(list))
    {
        return ArrayList_Add(list, item);
    }
    
    return FALSE;
}
//******************************************************************
void * ArrayList_GetList(ArrayList * list)
{
    if(list && list->arr)
        return list->arr;
    
    return NULL;
}
//******************************************************************
inline size_t ArrayList_GetSize(ArrayList * list)
{
    if(list)
        return list->size;
    
    return FALSE;
}
//*****************************************************************
boolean ArrayList_Free(ArrayList * list)
{
    if(list && list->arr)
    {
        free(list->arr);
        list->arr = NULL;
        list->size = list->reserved = 0;
        
        return TRUE;
    }
    return FALSE;
}
//*****************************************************************
boolean ArrayList_Remove(ArrayList * list, size_t index)
{
    if(list && list->arr && index < list->size)
    {
        if(list->arr[index] != NULL)
        {
            free(list->arr[index]);
            list->arr[index] = NULL;
            list->size--;
        }
        return TRUE;
    }
    return FALSE;
}
//******************************************************************
boolean ArrayList_RemoveLast(ArrayList *list) //remove last item and updates
{
    if(list && list->arr && list->size > 0)
    {
        if(ArrayList_Remove(list, list->size - 1))
           return ArrayList_Compact(list);
    }
    return FALSE;
}
//***********************************************************************
boolean ArrayList_Set(ArrayList *list, size_t index, void * item) //it will expand if needed  D
{
    if(list && list->arr && index < list->size)
    {
        list->arr[index] = item;
        
        return TRUE;
    }
    return FALSE;
}
//************************************************************************
void * ArrayList_Get(ArrayList *list, size_t index)
{
    if(list && list->arr && index < list->size && list->arr[index])
    {
        return list->arr[index];
    }
    
    return NULL;
}
//********************************************************************
boolean ArrayList_Clear(ArrayList * list) //must do compact
{
    if(list && list->arr)
    {
        for(int i = 0; i < list->reserved; i++)
        {
            if(list->arr[i])
            {
                free(list->arr[i]);
                list->arr[i] = NULL;
            }
        }
        
        list->size = 0;
        
        return ArrayList_Compact(list);
    }
    
    return FALSE;
}
//************************************************************************
boolean ArrayList_Copy(ArrayList * destination, const ArrayList * source)
{
    if(source && destination && source->arr && destination->arr)
    {       
        if(ArrayList_ExpandReserved(destination, source->reserved))
        {
            for(int i = 0; i < source->reserved; i++)
            {
                if(*(&destination->arr[i]) != NULL)
                    free(destination->arr[i]);
                
                destination->arr[i] = source->arr[i];
            }
            
            destination->size = source->size;
            destination->reserved = destination->reserved;
            
            return TRUE;
        }
        
        for(int i = 0; i < source->reserved; i++)
        {
            if(destination->arr[i] != NULL)
                free(destination->arr[i]);
            
            destination->arr[i] = source->arr[i];
        }
        
        destination->size = source->size;
        destination->reserved = destination->reserved;
        
        return TRUE;
    }
    
    return FALSE;
}
//*******************************************************************
boolean ArrayList_ExpandReserved(ArrayList * list, size_t reserved)
{
    if(list && list->arr && reserved > list->size)
    {
        void * temp = realloc(list->arr, sizeof(void *) * reserved);
        
        if(temp)
        {
            list->arr = temp;
            list->reserved = reserved;
            
            return TRUE;
        }
    }
    
    return FALSE;
}
//*****************************************************************************
boolean ArrayList_Compact(ArrayList * list) //it compacts to size + 100 if possible.
{
    if(list && list->arr && *list->arr && list->size < (list->reserved - INITIAL_SIZE_STRING_LIST))
    {
        int last = 0;
        for(int i = 0; list->size > 0 && i < list->reserved; i++)
            if(list->arr[i])
                last = i;
        
        void * temp = realloc(list->arr,sizeof(void *) * list->size + INITIAL_SIZE_STRING_LIST);
        
        if(temp && list->size > 0)
        {
            list->arr = temp;
            list->reserved = list->size + INITIAL_SIZE_STRING_LIST;
            
            return TRUE;
        }
    
        if(last <= (list->size + INITIAL_SIZE_STRING_LIST) &&
           ArrayList_ExpandReserved(list, list->size + INITIAL_SIZE_STRING_LIST))
            return TRUE;
    }
    else if(list && list->arr && !*list->arr)
    {
        list->arr = calloc(sizeof(void*), INITIAL_SIZE_STRING_LIST);
        list->reserved = INITIAL_SIZE_STRING_LIST;
        
        return TRUE;
    }
    
    return FALSE;
}
