#include <stdio.h>
#include<string.h>
#include <stdbool.h>
#define TAM_MAX 32
typedef struct 
{
	int barcode;
	char name[TAM_MAX];
	float price;
} Product;

void Product_Ctor( Product* this, int barcode, char* name, float price )
{
	this->barcode = barcode;
	strncpy(this->name, name, TAM_MAX);
	this->price = price;
}
void Product_SetBarcode( Product* this, int barcode )
{
	this->barcode = barcode;
}
void Product_SetName( Product* this, char* name )
{
	strncpy(this->name, name, TAM_MAX);
}
void Product_SetPrice( Product* this, float price )
{
	this->price = price;
}
const int Product_GetBarcode( const Product* this )
{
	return( this->barcode );
}
const char* Product_GetName( const Product* this )
{
	return( this->name );
}
const float Product_GetPrice(const Product* this )
{
	return( this->price );
}
void Product_Print( const Product* this )
{
	printf( "Código de barras: %d, Nombre: %s, Precio: %0.2f\n", this->barcode, this->name, this->price );
}
void Product_Assign( Product* this, const Product* other )
{
	this->barcode = other->barcode;
	strncpy(this->name, other->name, TAM_MAX);
	this->price = other->price;
}
bool Product_IsEqual( const Product* this, const Product* other )
{
	return( (this->barcode == other->barcode) && (strcmp(this->name, other->name)) == 0 && (this->price == other->price) );
}
bool Product_IsEqual_ByBarcode( const Product* this, const Product* other )
{
	return( (this->barcode == other->barcode));
}
int main()
{
	int n=3;
	Product products[n];
	Product_Ctor( &products[0], 100, "Gansito", 10 );
	Product_Ctor( &products[1], 100, "Gansito", 10 );
	Product_Ctor( &products[2], 101, "Pepsi", 12 );
	
	float price;
	printf("Ingrese el precio de un producto: ");
	scanf("%f", &price );
	Product_SetPrice( &products[0], price );
	Product_SetPrice( &products[1], price );
	for( int i = 0; i < n; ++i)
	{
		printf("\nProducto %d Código: %d, Nombre: %s, Precio: %f\n", i+1, Product_GetBarcode( &products[i] ), Product_GetName( &products[i] ), Product_GetPrice( &products[i] ));
	}
	if(Product_IsEqual( &products[0], &products[1] ))
	{
		printf("\nEl producto 1 es igual al producto 2\n");
	}
	else
	{
		printf("\nEl producto 1 no es igual al producto 2\n");
	}
	if(Product_IsEqual_ByBarcode( &products[0], &products[2] ))
	{
		printf("\nEl código de barras del producto 1 es igual al producto 2\n");
	}
	else
	{
		printf("\nEl código de barras del producto 1 no es igual al producto 2\n");
	}
	
}


