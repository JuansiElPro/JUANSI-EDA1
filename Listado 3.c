#include <stdio.h>
#include <stdlib.h>
#include <math.h>
double* Crear()
{
	double* p = (float*) malloc( sizeof( double ) );
	return p;
}
void Destruir( double* p )
{
	free( p );
}
int main()
{
	double* p = Crear();
	if( NULL == p )
	{
		printf( "Error asignando memoria\n" );
		exit( 1 );
	}
	double* q = Crear();
	double* r = Crear();
	printf( "Ingrese el ángulo en radianes:\n$ ");
	scanf( "%lf", p );
	*q = sin( *p );
	*r = cos( *p );
	printf( "Ángulo\tSeno\tCoseno\n" );
	printf( "%.4lf\t%.4lf\t%.4lf\n", *p, *q, *r );
	Destruir( p );
	Destruir( q );
	Destruir( r );
}

