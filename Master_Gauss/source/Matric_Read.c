#include <stdio.h>
#include <stdlib.h>
#include "Matric_Read.h"



ukladr_t Matrix_Read( char *nazwa_pliku, ukladr_t u ) {
	


	FILE *in = fopen( nazwa_pliku, "r" );
	int n = 0;
	if( fscanf( in, "%d", &n ) != 1 || n <= 0 )
		return NULL;
	
	u = malloc( sizeof *u );

	if( u == NULL )
		return NULL;

	u->a = malloc( n * sizeof *(u->a) );
	u->a[0] = malloc( n*n * sizeof(double) ); 
        u->wskaznik = u->a[0];
	u->b = malloc( n * sizeof *(u->b) );
	if( u->a == NULL || u->b == NULL || u->a[0] == NULL ) {
		free( u->b );
		free( u->a[0] );
		free( u->a );
		free( u );
		return NULL;
	} else {
		for( int i= 1; i < n; i++ )
			u->a[i] = u->a[i-1] + n;
	}

	u->n = n;
  for( int i= 0; i < n; i++ ) {
		for( int j= 0; j < n; j++ ) 
			if( fscanf( in, "%lf", u->a[i]+j ) != 1 ) {
   			free( u->b );
			free( u->a[0] );
    			free( u->a );
    			free( u );
    			return NULL;
  			}
		}	
	for( int i= 0; i < n; i++ ) {
    if( fscanf( in, "%lf", u->b+i ) != 1 ) {
      free( u->b );
      free( u->a[0] );	
      free( u->a );
      free( u );
      return NULL;
    }
        }

fclose(in);

return u;
}
