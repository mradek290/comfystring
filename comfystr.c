
#ifndef COMFY_STRING_IMPL
#define COMFY_STRING_IMPL

#include "comfystr.h"

void cfstrFree( char* s ){
    free( ((unsigned*)s)-1 );
}

char* cfstrCreate( const char* s ){

    unsigned sz = strlen(s);
    unsigned* psz = (unsigned*) malloc( sz * sizeof(char*) + sizeof(sz) );
    char* q = (char*)(psz+1);
    *psz = sz-1;
    memcpy( q, s, sz * sizeof(char) );
    return q;
}

char* cfstrCopy( char* s ){

    unsigned ssz = 1 + cfstrSize(s);
    unsigned* psz = (unsigned*) malloc( ssz * sizeof(char) + sizeof(ssz) );
    char* q = (char*)(psz+1);
    *psz = ssz-1;
    memcpy( q, s, ssz * sizeof(char) );
    return q;
}

char* cfstrSubString( char* s, unsigned p0, unsigned p1 ){

    unsigned ssz = cfstrSize(s);
    if( p1 < p0 ){
        unsigned t = p0;
        p0 = p1;
        p1 = t;
    }

    if( ssz < p0 ){
        return 0;
    }

    if( p1 > ssz ) p1 = ssz+1;

    unsigned sz = p1-p0;
    unsigned* psz = (unsigned*) malloc( (sz+1) * sizeof(char) + sizeof(sz) );
    char* q = (char*)(psz+1);
    *psz = sz;
    memcpy( q, s + p0, sz );
    q[sz] = 0;
    return q;
}

unsigned cfstrSize( const char* s ){
    return *((unsigned*)s-1);
}

_Bool cfstrNullOrEmpty( const char* s ){
    return s == "" || !s || !*s;
}

unsigned cfstrFind( char* s, char* ss ){
    char* q = strstr( s, ss);
    return q ? q-s : ~0ul;
}

_Bool cfstrCompare( char* a, char* b ){
    unsigned sa = cfstrSize(a);
    unsigned sb = cfstrSize(b);
    return sa == sb ? !memcmp(a,b,sa) : 0;
}

_Bool cfstrContains( char* s, char* ss ){
    return strstr(s,ss);
}

_Bool cfstrStartsWith( char* s, char* ss ){
    return strstr(s,ss) == s;
}

_Bool cfstrEndsWith( char* s, char* ss ){
    //should maybe start comparing in reverse idk
    return cfstrFind(s,ss) == cfstrSize(s) - cfstrSize(ss);
}

void cfstrToLower( char* s ){
    char* e = s + cfstrSize(s);
    while( s < e ) *s = (char) tolower(*s++);
}

void cfstrToUpper( char* s ){
    char* e = s + cfstrSize(s);
    while( s < e ) *s = (char) toupper(*s++);
}

unsigned cfstrCountChr( const char* s, char c ){

    unsigned cnt = 0;
    const char* e = s + cfstrSize(s);
    while( s < e ) cnt += *s++ == c ? 1 : 0;
    return cnt;
}

//needs fix: doesnt find the last segment
void cfstrSplitChr( char** res, char* s, char c ){

    const char* e = s + cfstrSize(s);   
    const char* p0 = s;
    const char* p1;
    while( s < e ){

        if( *s == c ){

            p1 = s;
            unsigned sz = p1-p0;
            unsigned msz = sz+1;
            unsigned* psz = (unsigned*) malloc( msz * sizeof(char) );
            *psz = msz-1;
            char* q = (char*)(psz+1);
            memcpy( q, p0, sz );
            *res++ = q;
            p0 = p1+1;
        }

        ++s;
    }
}

#endif
