//
//  String.c
//  HW1
//
//  Created by Roicxy Alonso Gonzalez on 6/27/17.
//  Copyright © 2017 AlonsoRoicxy. All rights reserved.
//

#include <stdio.h>
#include <stdLib.h>
#include "String.h"


int String_New(String * strObj,char * str)
{
    if(str == NULL || strObj == NULL)
        return 0;
    
    size_t len = String_ChrLen(str);
    strObj->size = len;
    strObj->str = (char *) malloc(sizeof(char) * len + 1);
    
    if(!strObj->str)
        return 0;
    
    int i;
    
    for(i = 0; i < len; i++)
        strObj->str[i] = str[i];
    
    strObj->str[++i] = '\0';
    strObj->hashcode = String_CreateHash(strObj->str);
    
    
    return 1;
}


char * String_Get(String * strObj)
{
    if(strObj == NULL)
        return 0;
    
    return strObj->str;
}
char String_GetChar(const String *strObj,const size_t index)
{
    if(strObj == NULL && index >= strObj->size)
        return '\0';
    
    return strObj->str[index];
    
}

int String_Append(String * strObj, char * strAppend)
{
    if(strObj && strObj->str)
    {
        size_t nlen = String_ChrLen(strAppend);
        
        char * tmp = (char *)realloc(strObj->str, sizeof(char) *(strObj->size + nlen + 1));
        
        if(!tmp)
        {
            size_t lastLen = strObj->size;
            strObj->str = tmp;
            strObj->size = strObj->size + nlen;
            
            size_t size = strObj->size;
            
            for(size_t i = lastLen, j = 0; i < size && j < nlen; i++, j++)
                strObj->str[i] = strAppend[j];
            
            strObj->hashcode = String_CreateHash(strObj->str);
            
            return 1;
        }

    }
    
    return -3;
    
}

int String_EqualLen(String *lhs, String *rhs)
{
    if(lhs == NULL || rhs == NULL)
        return 0;
    
    if(lhs->size == rhs->size)
        return 1;
    else
        return 0;
    
}

size_t String_ChrLen(char * str)
{
    size_t len = 0;
    
    for(char * ptr = str; *ptr != '\0'; ptr++ )
        len++;
    
    return len;
}

int String_Equal(String * lhs, String * rhs)
{
    if(lhs == NULL || rhs == NULL || lhs->size != rhs->size)
        return 0;
    
    for(int i = 0; i < lhs->size && lhs->str[i] != '\0'; i++)
        if(lhs->str[i] != rhs->str[i])
            return 0;
    
    return 1;
}

void String_Free(String * strObj)
{
    if(strObj != NULL && strObj->str != NULL)
    {
        free(strObj->str);
        strObj->str = NULL;
        strObj->size = 0;
        
    }
}

void String_Delete(String * strObj)
{
    if(strObj != NULL && strObj->str != NULL)
    {
        free(strObj->str);
        strObj->str = NULL;
        strObj->size = 0;
        
    }
}
//define get and set for a given char. only if is within bounds
void String_SetChar(const String *strObj,const size_t index, const char c)
{
    if(strObj->size > index)
        strObj->str[index] = c;
    
}
///Haven't finished
String * String_Cpy ( String * destination, const String * source )
{
    if(!destination || !source)
        return NULL;
    
    char * temp = (char *) realloc(destination->str, sizeof(char) * (source->size + 1));
    
    if(!temp)
        return NULL;
   
    if(temp)
    {
        int i;
        for(i = 0; i < source->size; i++)
            temp[i] = source->str[i];
        
        destination->str = temp;
        destination->size = source->size;
        destination->hashcode = String_CreateHash(destination->str);
        
        return destination;
        
    }
    
    return NULL;
        
}

String * String_nCpy ( String * destination, const String * source, size_t num )
{
    if(!source || !source->str || !destination || !destination->str || num >= source->size)
        return NULL;
    
    
    char * temp = (char * ) realloc(destination->str, sizeof(char) * (num + 1) );
    
    if(!temp)
        return NULL;
    
    int i;
    for(i = 0; i < num; i++)
        temp[i] = source->str[i];
    destination->str = temp;
    destination->size = num;
    destination->hashcode = String_CreateHash(destination->str);
    
    return destination;
    
}
//Ask about this function
String * String_Cat ( String * destination, const String * source )
{
    if(!source || !source->str || !destination || !destination->str )
        return NULL;
    
    char * temp = (char *) realloc(destination->str, sizeof(char) *
                                   (destination->size + source->size + 1));
    
    if(!temp)
        return NULL;
    
    size_t initial = destination->size;
    
    size_t i,j;
    size_t scSize = source->size;
    for(i = 0; i < initial; i++)
        temp[i] = destination->str[i];
    
    for(i = initial, j = 0; j < scSize; i++, j++)
        temp[i] = source->str[j];
    
    destination->str = temp;
    destination->size += scSize;
    destination->hashcode = String_CreateHash(destination->str);
    
    return destination;
}

String * String_nCat ( String * destination, const String * source, size_t num )
{
   if(!source || !source->str || !destination || !destination->str ||
      num >= (source->size + destination->size))
       return NULL;
    
    char * temp = (char * ) realloc(destination->str, sizeof(char) * (num + 1));
    
    if(temp)
    {
        size_t i, j, k;
        
        for(i = 0; i < destination->size && i < num; i++)
            temp[i] = destination->str[i];
        
        for(j = i, k = 0; j < num && k < source->size; j++, k++)
            temp[j] = source->str[k];
        
        destination->str = temp;
        destination->size = num;
        destination->hashcode = String_CreateHash(destination->str);
        
        return destination;
    }
    
    return NULL;
    
}

int String_Cmp ( const String * str1, const String * str2 )
{
    if(!str1 || !str1->str || !str2 || !str2->str)
        return -3;
    
    size_t size;
    
    if(str1->size >= str2->size)
        size = str2->size;
    else
        size = str1->size;
    
    for(int i = 0; i < size ; i++)
    {
        if(str1->str[i] > str2->str[i])
            return 1;
        else if(str1->str[i] < str2->str[i])
            return -1;
    }
            
    if(str1->size > str2->size)
        return 1;
    else if(str1->size < str2->size)
        return -1;
    else
        return 0;
    
}

int String_nCmp ( const String * str1, const String * str2, size_t num )
{
    if(!str1 || !str1->str || !str2 || !str2->str || num > str1->size || num > str2->size)
        return -3;
    
    for(int i = 0; i < num ; i++)
    {
        if(str1->str[i] > str2->str[i])
            return 1;
        else if(str1->str[i] < str2->str[i])
            return -1;
    }
    
    return 0;

}

String * String_Chr (String * str, int character )
{
    if(str && str->str)
    {
        char c = character;
        
        while(*str->str != c && *str->str != '\0')
            str->str++;
        return (*str->str == c) ? str : NULL;
    }
    
    return NULL;
}

size_t String_cSpn ( const String * str1, const String * str2 )
{
    if(str1 && str1->str && str2 && str2->str)
    {
        char * c;
        
        for(c = str1->str; *c != '\0'; c++)
        {
            for(int i = 0; i < str2->size ;i++)
                if(*c == str2->str[i])
                    return str2->size - i;
        }
    }
    
    return 0;
}

String * String_pBrk (const String * str1, const String * str2 )
{
    
    
    
    
    return NULL;
}

String * String_rChr (const String * str, int character )
{
    
    
    
    
    return NULL;
}

size_t String_spn ( const String * str1, const String * str2 )
{
    
    
    
    
    return 0;
}

String * String_Str (String * str1, const String * str2 )
{
    
    
    
    
    return NULL;
}

size_t String_Len ( const String * str )
{
    if(!str)
        return 0;
    
    size_t len;
    for(len = 0; str->str[len] != '\0'; len++);
    
    return len;
    
}

size_t String_GetHashCode(const String * str)
{
    if(!str || !str->str)
        return 0;
    
    return str->hashcode;
}

size_t String_CreateHash(const char * str)
{
    if(!str)
        return 0;
    
    size_t hashCode = 0;
    
    for(int i = 0; str[i] != '\0'; i++)
        hashCode += (str[i] * (2 + i));
    return hashCode;
    
}

String * String_Trim(String * str)
{
    
    
    
    
    
    return NULL;
    
}

String * String_LTrim(String * str)
{
    
    
    
    
    return NULL;
}

String * String_RTrim(String * str)
{
    
    
    
    return NULL;
}

size_t String_GetCharFromIndex(const String * str, int index)
{
    if(!str || !str->str || str->size <= index)
        return 0;
    return str->str[index];
}

size_t String_IndexOfChar(const String * str, char c)
{
    if(!str || !str->str || !c)
        return 0;
    int index = 0;
    while( index < str->size && str->str[index++] != c);
    
    return index;
        
}

String * String_Lower(String * str)
{
    
    if(!str || !str->str)
        return 0;
    
    String * newStr = (String* ) malloc(sizeof(String));
    if(newStr)
        newStr->str = (char*) malloc(sizeof(char) * str->size);
    
    if(!newStr || !newStr->str)
        return 0;
    
    newStr->size = str->size;
    
    
    for(int i = 0; i < str->size; i++)
    {
        char c = str->str[i];
        if(c > 'A' && c < 'Z')
            newStr->str[i] = c + ('a' - 'A');
        
        newStr->str[i] = c;
    }
    newStr->hashcode = String_CreateHash(newStr->str);
    
    return newStr;
    
}

String * String_Upper(String * str)
{
    if(!str || !str->str)
        return 0;
    
    String * newStr = (String* ) malloc(sizeof(String));
    if(newStr)
        newStr->str = (char*) malloc(sizeof(char) * str->size);
    
    if(!newStr || !newStr->str)
        return 0;
    
    newStr->size = str->size;
    
    
    for(int i = 0; i < str->size; i++)
    {
        char c = str->str[i];
        if(c > 'a' && c < 'z')
            newStr->str[i] = c - ('a' - 'A');
        
        newStr->str[i] = c;
    }
    
    newStr->hashcode = String_CreateHash(newStr->str);
    
    return newStr;
}

String * String_Reverse(String * str)
{
    if(!str || !str->str || !str->size)
        return NULL;
    
    String * newStr = (String *) malloc(sizeof(String));
    
    if(!newStr)
        return NULL;
    
    newStr->str = (char *) malloc(sizeof(char) * (str->size + 1));
    
    if(!newStr->str)
        return NULL;
    
    size_t initial = 0;
    size_t last = str->size;
    
    while((newStr->str[initial++] = str->str[last--]) != '\0');
    
    newStr->hashcode = String_CreateHash(newStr->str);
    
    return newStr;
    
}

size_t String_WordCount(const String * str)
{
    
    
    
    
    
    return 0;
}


String * String_StartsWith (const String * str, const String * startsWith)
{
    
    
    
    return NULL;
}//return new string

String * String_TrimChar(String * str, const char * c)
{
    
    
    
    return NULL;
}












