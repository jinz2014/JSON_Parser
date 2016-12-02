#include <stdio.h>
#include <string.h>
#include "json.h"

// This parses all the key/values pairs in the krz.json file
int main()
{
    FILE *fp = fopen( "krz.json", "r" );
    jvalue *krz = jupdate(jparse( fp ));                    
    fclose( fp );

    for( jvalue **j = krz->u.v; *j; ++j )
    {
        if( !strcmp( (*j)->n, "email" ))           
            printf( "email address: %s\n", (*j)->u.s );

        if( !strcmp( (*j)->n, "lucky" ))           
            printf( "lucky number: %ld\n", (*j)->u.i );

        if( !strcmp( (*j)->n, "quarter" ))           
            printf( "quarter number: %Lf\n", (*j)->u.r );

        if( !strcmp( (*j)->n, "empty" ))           
            printf( "empty: %d\n", (*j)->d );

        if( !strcmp( (*j)->n, "nerd" ))           
            printf( "nerd ?: %d\n", (*j)->d );

        if( !strcmp( (*j)->n, "lotto" ))           
        {
            jvalue **a = (*j)->u.v;
            for (int i = 0; a[i] != NULL; i++)
                printf( "lotto : %d\n", a[i]->u.i);
        }
    }

    return 0;
}
