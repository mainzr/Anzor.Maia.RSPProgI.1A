/*
 ============================================================================
 Name        : parcialProg_2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


typedef struct{
	int id;
	char marca[20];
	int tipo;
	float peso;
}eVehiculo;


eVehiculo* Vehiculonew();
int vehiculo_setId(eVehiculo* this,int id);
int vehiculo_setMarca(eVehiculo* this,char* marca);
int vehiculo_setTipo(eVehiculo* this,int tipo);
int vehiculo_setPeso(eVehiculo* this,float peso);
eVehiculo* vehiculo_newParametros(char* idStr,char* marcaeStr,char* tipoStr, char* pesoStr);



int main(void)
{
	eVehiculo* unVehiculo = NULL;

    unVehiculo = vehiculo_newParametros("1", "Fiat", "147", "12.500");


	if(unVehiculo==NULL)
	{
		printf("Hubo problema al crear un vahiculo\n");
		exit(1);
	}


	FILE* f = fopen ("archivo.bin", "wb");
	    if(f == NULL)
	    {
	        printf("No se pudo abrir el archivo");
	        exit(1);
	    }

	    if(fwrite(unVehiculo, sizeof(eVehiculo), 1, f)==1)
	    {
	        printf("vehiculo guardado con exito!\n");
	    }
	    fclose(f);
	    free(unVehiculo);


	return EXIT_SUCCESS;
}


int vehiculo_setId(eVehiculo* this,int id)
{
	int error = 1;

	if(this != NULL)
	{
		this->id = id;
		error = 0;
	}

	return error;
}


int vehiculo_setMarca(eVehiculo* this,char* marca)
{
	int error = 1;

	if(this != NULL && marca != NULL)
	{
		strcpy(this->marca, marca);

		error = 0;
	}


	return error;
}


int vehiculo_setTipo(eVehiculo* this,int tipo)
{
	int error = 1;

	if(this != NULL && tipo > 0)
	{
		this->tipo = tipo;

		error = 0;
	}

	return error;
}

int vehiculo_setPeso(eVehiculo* this,float peso)
{
	int error = 1;

	if(this != NULL && peso > 0)
	{
		this->peso = peso;

		error = 0;
	}

	return error;
}


eVehiculo* Vehiculonew()
{
   eVehiculo* newVehiculo;

   newVehiculo = (eVehiculo*) malloc(sizeof(eVehiculo));

   if(newVehiculo != NULL)
   {
   	newVehiculo->id = 0;
       strcpy(newVehiculo->marca, " ");
       newVehiculo->tipo = 0;
       newVehiculo->peso = 0;

   }

   return newVehiculo;
}


eVehiculo* vehiculo_newParametros(char* idStr,char* marcaeStr,char* tipoStr, char* pesoStr)
{
    eVehiculo* newVehiculo;

    newVehiculo = Vehiculonew();

    if(newVehiculo != NULL)
    {
        if((vehiculo_setId(newVehiculo, atoi(idStr))
           || vehiculo_setMarca(newVehiculo, marcaeStr)
		   || vehiculo_setTipo(newVehiculo, atoi(tipoStr))
           || vehiculo_setPeso(newVehiculo, atoi(pesoStr))))
           {
                free(newVehiculo);
                newVehiculo = NULL;
           }
    }
    return newVehiculo;
}
























/*
void calcular(float n1, float n2, int pFunc(float*, float, float))
{
	float resultado;

	if(pFunc(&resultado, n1, n2) == 0)
	{
		printf("\nResultado: %.2f", resultado);
	}
	else
	{
		printf("\nNo se puede dividir por 0.");
	}


}

int dividir(float* resultado, float num1, float num2)
{
	int error = 1;

	if(resultado != NULL)
	{
		if(num2 != 0)
		{
			*resultado = num1 / num2;
			error = 0;
		}

	}


	return error;
}
*/
