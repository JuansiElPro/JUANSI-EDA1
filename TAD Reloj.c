#include <stdio.h>
#include <stdbool.h>
typedef struct 
{
	int horas;
	int minutos;
	int segundos;
} Reloj;
void Reloj_Imprime( const Reloj* this ) 
{
	printf( "%02d:%02d:%02d\n", this->horas, this->minutos, this->segundos );
}
void Reloj_Poner( Reloj* this, int horas, int minutos, int segundos )
{
	this->horas = horas;
	this->minutos = minutos;
	this->segundos = segundos;
}
void Reloj_Incremento( Reloj* this )
{
	++this->segundos;
	if( this->segundos > 59 )
	{
		this->segundos = 0;
		++this->minutos;
		if( this->minutos > 59 )
		{
			this->minutos = 0;
			++this->horas;
			if( this->horas > 23 )
			{
				this->horas = 0;
			}
		}
	}
}
void Reloj_SetHoras( Reloj* this, int horas )
{
	this->horas = horas;
}
void Reloj_SetMinutos( Reloj* this, int minutos )
{
	this->minutos = minutos;
}
void Reloj_SetSegundos( Reloj* this, int segundos )
{
	this->segundos = segundos;
}
const int Reloj_GetHoras( const Reloj* this )
{
	return( this->horas );
}
const int Reloj_GetMinutos( const Reloj* this )
{
	return( this->minutos );
}
const int Reloj_GetSegundos( const Reloj* this )
{
	return( this->segundos );
}
bool Reloj_Cmp_IsEqual( const Reloj* this, const Reloj* other )
{
	return( (this->segundos == other->segundos) && (this->minutos == other->minutos) && (this->horas == other->horas) );
}
int main()
{
	Reloj casio;
	Reloj swatch;
	Reloj alarma_1;
	Reloj alarma_2;
	Reloj_Poner( &casio, 12, 0, 0 );
	printf( "Reloj 'casio' antes: " );
	Reloj_Imprime( &casio );
	Reloj_Poner( &swatch, 19, 30, 0 );
	printf( "Reloj 'swatch' antes: " );
	Reloj_Imprime( &swatch );
	Reloj_SetHoras( &alarma_1, 13 );
	Reloj_SetMinutos( &alarma_1, 10 );
	Reloj_SetSegundos( &alarma_1, 0 );
	printf( "Alarma 1 puesta a las: %02d:%02d:%02d\n", Reloj_GetHoras( &alarma_1 ), Reloj_GetMinutos( &alarma_1 ), Reloj_GetSegundos( &alarma_1 ) );
	Reloj_SetHoras( &alarma_2, 20 );
	Reloj_SetMinutos( &alarma_2, 35 );
	Reloj_SetSegundos( &alarma_2, 30 );
	printf( "Alarma 2 puesta a las: %02d:%02d:%02d\n", Reloj_GetHoras( &alarma_2 ), Reloj_GetMinutos( &alarma_2 ), Reloj_GetSegundos( &alarma_2 ) );
	printf( "...\n" );
	int n = 4925;
	for( size_t i = 0; i < n; ++i )
	{
		Reloj_Incremento( &casio );
		Reloj_Incremento( &swatch );
		if( Reloj_Cmp_IsEqual( &alarma_1, &casio ) || Reloj_Cmp_IsEqual( &alarma_1, &swatch ) )
		{
			printf("\nHORA DE LEVANTARSE\n\n");
			printf( "Hora del Reloj 'casio' cuando suena la alarma 1: " );
			Reloj_Imprime( &casio );
			printf( "Hora del Reloj 'swatch' cuando suena la alarma 1: " );
			Reloj_Imprime( &swatch );
		}
		else if ( Reloj_Cmp_IsEqual( &alarma_2, &casio ) || Reloj_Cmp_IsEqual( &alarma_2, &swatch ) )
		{
			printf("\nHORA DE LEVANTARSE\n\n");
			printf( "Hora del Reloj 'casio' cuando suena la alarma 2: " );
			Reloj_Imprime( &casio );
			printf( "Hora del Reloj 'swatch' cuando suena la alarma 2: " );
			Reloj_Imprime( &swatch );
		}
		
	}
	printf( "...\n" );
	printf( "Reloj 'casio' después: " );
	Reloj_Imprime( &casio );
	printf( "Reloj 'swatch' después: " );
	Reloj_Imprime( &swatch );
}


