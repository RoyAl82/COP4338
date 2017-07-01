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
    return FALSE;
}

boolean ArrayList_Expand(ArrayList * list)
{
    return FALSE;

}
boolean ArrayList_Add(ArrayList * list, void * item)
{
    return FALSE;
}

void * ArrayList_GetList(ArrayList * list)
{
    return NULL;
}
inline size_t ArrayList_GetSize(ArrayList * list)
{
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
    return FALSE;
}
boolean ArrayList_Set(ArrayList *list, size_t index, void * item) //it will expand if needed  D
{
    return FALSE;
}
void * ArrayList_Get(ArrayList *list, size_t index)
{
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
