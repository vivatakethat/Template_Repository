/*
 * This program loops, reading a login name from standard
 * input and checking to see if it is a valid name. If it 
 * is not valid, the entire contents of the name in the 
 * password database are printed.
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <pwd.h>

int main( void )
  {
    struct passwd* pw;
    char    buf[80];

    setpwent( );
    while( gets( buf ) != NULL ) {
      if( ( pw = getpwnam( buf ) ) != ( struct passwd * )0 ) {
        printf( "Valid login name is: %s\n", pw->pw_name );
      } else {
        setpwent( );
        while( ( pw=getpwent( ) ) != ( struct passwd * )0 )
          printf( "%s\n", pw->pw_name );
      }
    }
    endpwent();
    return( EXIT_SUCCESS );
  }
