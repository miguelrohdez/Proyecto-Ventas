#include <stdio.h>
#include <stdlib.h>
#include "titulo.h"



void registroDatos(void);
void registroUsuario(void);

void registroDatos(){
	struct datosEmpleado{
		char nombre1[20];
		char nombre2[20];
		char AMaterno[20];      
		char APaterno[20];      
		int edad;
		char sexo[10];
		char escolaridad[30];
		int NoEmpleado;
		double salarioHora;
		char password[20];
		};

	char res;

		struct datosEmpleado empleado;


		fflush(stdin);
		printf("Ingresa tu primer nombre: \n");
		scanf("%s",&empleado.nombre1);
		printf("Tienes otro nombre? Presiona (S/N)\n");
		fflush(stdin);	
		scanf("%c",&res);
		if(res == 'S' || res == 's'){		
		printf("Ingresa tu segundo nombre: \n");
		scanf("%s",&empleado.nombre2);
		}
		printf("Ingresa tu Apellido Paterno: \n");
		scanf("%s",&empleado.APaterno);
		printf("Ingresa tu Apellido Materno: \n");
		scanf("%s",&empleado.AMaterno);
		printf("Ingresa la edad: \n");
		scanf("%i",&empleado.edad);
		printf("Ingrese tu sexo:[Masculino/Femenino] \n");
		scanf("%s",&empleado.sexo);
		printf("Ingresa tu escolaridad: [Secundaria/Preparatoria/Universidad]\n");
		scanf("%s",&empleado.escolaridad);
		printf("Ingrese el numero de empleado que se le asigno: \n");
		scanf("%i",&empleado.NoEmpleado);

		

	FILE *registro;
	registro = fopen("datosEmpleado", "a+");
	
	if (registro != NULL)
	{
		fprintf(registro, "Nombre:\t\t\t\t %s ",empleado.APaterno);
		fprintf(registro, "%s ",empleado.AMaterno);	
		fprintf(registro, "%s ",empleado.nombre1);
		fprintf(registro, "%s\n",empleado.nombre2);
		fprintf(registro, "Edad:\t\t\t\t %i\n",empleado.edad);
		fprintf(registro, "Escolaridad:\t\t\t %s\n",empleado.escolaridad);
		fprintf(registro, "Numero de empleado:\t\t %i\n",empleado.NoEmpleado);
		fprintf(registro, "\n*********************************************************************************\n" );
		printf("\a\n\tSe registraron tus datos correctamente\n");
		fclose(registro);
	}else{
		printf("Error, no se pudo realizar el registro!!\a\n");
	}
	
	return;
}


void registroUsuario(){
	struct registroUsuario{
	char usuario[50];
	char password[50];
	};//Fin estructura
	
	struct registroUsuario mUsuario;
	printf("Confirma tu  numero de usuario: ");
	scanf("%s",mUsuario.usuario);
	printf("Introduce tu nueva contrasenia: ");
	scanf("%s",mUsuario.password);

	FILE *archivoUsuario;
	int condicion = 0;
	archivoUsuario = fopen(mUsuario.usuario,"r");
	if(archivoUsuario!=NULL){
		printf("Ese nombre de Usuario ya existe, por favor intente con otro.\n");
	}else{
		archivoUsuario = fopen(mUsuario.usuario,"a+");
		if(archivoUsuario!=NULL){
			fprintf(archivoUsuario,"%s",mUsuario.password);
			printf("Usuario registrado correctamente\n");
			fclose(archivoUsuario);
		}	
		else{
			printf("EL usuario no pudo ser registrado nuestros Ingenieros se encuentran reparando el fallo. Gracias por su comprension.");
		}
	}
}


int main(){
	char rep, salir;
	do{
	titulo();
	printf("\tRegistra tus datos personales:\n\n");
	registroDatos();
	printf("\n\n\t Corfirma tu usuario y registra tu contraseña:\n");
	registroUsuario();
	printf("\n\n\tDeseas registrar otro usuario? Presiona (S/N): ");
	fflush(stdin);
	scanf("%c",&rep);
	}while(rep == 's'|| rep =='S');
	
	printf("\n\n\t\tRegresar al menu principal? Presione (S/N): ");
	fflush(stdin);
	scanf("%c",&salir);
	if (salir == 'S' || salir == 's'){
		system("start menu.exe");
		return 0;
	}else{
		printf("\n\n\t***** Programa finalizado *****");
	}

return 0;
	
}
