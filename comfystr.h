
#ifndef COMFY_STRING_HEADER
#define COMFY_STRING_HEADER

#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void  cfstrFree( char* );
char* cfstrCreate( const char* );
char* cfstrCopy( char* );
char* cfstrSubString( char*, unsigned, unsigned );

unsigned cfstrSize( const char* );
_Bool cfstrNullOrEmpty( const char* );

unsigned cfstrFind( char*, char* );

_Bool cfstrCompare( char*, char* );
_Bool cfstrContains( char*, char* );
_Bool cfstrStartsWith( char*, char* );
_Bool cfstrEndsWith( char*, char* );

void cfstrToLower( char* );
void cfstrToUpper( char* );

unsigned cfstrCountChr( const char*, char );
void cfstrSplitChr( char**, char*, char );

#endif
