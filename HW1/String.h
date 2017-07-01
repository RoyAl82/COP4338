//
//  String.h
//  lec2
//
//  Created by Francisco on 6/28/15.
//  Updated: 07/03/16
//  Copyright (c) 2015 Francisco. All rights reserved.
//

#ifndef lec2_String_h
#define lec2_String_h

typedef struct
{
    size_t size; //size without '\0'
    char * str;
    size_t hashcode;
} String;

//size_t String_CStr_Len(char * str);
size_t String_ChrLen(char *s);
int String_EqualLen(String *lhs, String *rhs);
int String_New(String * strObj,char * str);
int String_Equal(String * lhs, String * rhs);
void String_Delete(String * strObj);
char * String_Get(String * strObj);
int String_Append(String * strObj, char * strAppend);

void String_Free(String * strObj);
//define get and set for a given char. only if is within bounds
char String_GetChar(const String *strObj,const size_t index);
void String_SetChar(const String *strObj,const size_t index, const char c);

//The following are the signature you requried
String * String_Cpy ( String * destination, const String * source );
String * String_nCpy ( String * destination, const String * source, size_t num );
String * String_Cat ( String * destination, const String * source );
String * String_nCat ( String * destination, const String * source, size_t num );
int String_Cmp ( const String * str1, const String * str2 );
int String_nCmp ( const String * str1, const String * str2, size_t num );
String * String_Chr (String * str, int character );
size_t String_cSpn ( const String * str1, const String * str2 );
String * String_pBrk (const String * str1, const String * str2 );
String * String_rChr (const String * str, int character );
size_t String_spn ( const String * str1, const String * str2 );
String * String_Str (String * str1, const String * str2 );

size_t String_Len ( const String * str );

size_t String_GetHashCode(const String * str);
size_t String_CreateHash(const char *);
String * String_Trim(String * str);
String * String_LTrim(String * str);
String * String_RTrim(String * str);
size_t String_GetCharFromIndex(const String * str, int index);
size_t String_IndexOfChar(const String * str, char c);
String * String_Lower(String * str);
String * String_Upper(String * str);
String * String_Reverse(String * str);
size_t String_WordCount(const String * str);


String * String_StartsWith (const String * str, const String * startsWith); //return new string
String * String_TrimChar(String * str, const char * c);

//extra credit
///char * String_Tok ( String * str, const char * delimiters );

//optional
///void String_InitStruct(String ** strObj);
///void String_FreeStruct(String ** strObj);

#endif
