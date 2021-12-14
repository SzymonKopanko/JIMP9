#include "Matric_Read.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>



void Matrix_Print1(ukladr_t ur)
{

FILE *out = fopen("log.txt", "w"); // plik z wynikami dla marcierzy wiekszych niz 8x8; 

	if( ur->n <= 8 ) {
		printf( "Macierz:\n" );
		for( int i= 0; i < ur->n; i++ ) {
			for( int j= 0; j < ur->n; j++ )
				printf( "\t%g", ur->a[i][j] );
			printf( "\n" );
		}
		printf( "Wektor prawych stron:\n" );
		for( int i= 0; i < ur->n; i++ )
			printf( "%g\n", *(ur->b+i) );
	}
	else{
		fprintf(out, "Macierz:\n" );
		for( int i= 0; i < ur->n; i++ ) {
			for( int j= 0; j < ur->n; j++ )
				fprintf(out, "\t%g", ur->a[i][j] );
			fprintf(out, "\n" );
		}
		fprintf(out, "Wektor prawych stron:\n" );
		for( int i= 0; i < ur->n; i++ )
			fprintf(out, "%g\n", *(ur->b+i) );
	}
fclose(out);
}

void Matrix_Print2(ukladr_t ur, double *x)
{

FILE *out = fopen("log.txt", "a+"); // plik z wynikami dla marcierzy wiekszych niz 8x8; 
	if( x != NULL ) {
		if( ur->n <= 8 ) {
			printf( "Rozwiązanie:\n" );
			for( int i= 0; i < ur->n; i++ )
				printf( "%g\n", x[i] );
		} else {
			
			fprintf(out, "Rozwiązanie:\n" );
			for( int i= 0; i < ur->n; i++ )
				fprintf(out, "%g\n", x[i] );


			}

	} else {
		printf( "Wystapil blad, nie umiem tego rozwiazac!!\n" );
	}
free(x);
fclose(out);
}
