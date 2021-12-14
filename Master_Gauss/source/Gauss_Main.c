#include <stdio.h>
#include <stdlib.h>
#include "Matric_Read.h"
#include "Matrix_Print.h"
#include "Matrix_Solve.h"



int main( int argc, char **argv ) {

	ukladr_t ukr = Matrix_Read( argv[1], ukr );

//	Matrix_Test(ukr);
	
	Matrix_Print1(ukr);

//	double *x = Matrix_Solve( ukr );

//	Matrix_Print2(ukr,x);

	free( ukr->wskaznik ); // wskaznik na poczatek tablicy wskaznikow z liniamii, 
		// pomaga w wyczyszczeniu pamieci, zabepiecza od ominiecia pewnego sektoru z liniamii.
	
	free( ukr->a );
	free( ukr->b );
	free( ukr );

	return EXIT_SUCCESS;
}


	
