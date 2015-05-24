#include <stdio.h>
#include <stdlib.h>
#include "titulo.h"

struct datosUsuario{
	char usuario[50];
	char password[50];
	};
	
int verificarPassword(char passUsuario[], char passGuardada[]);
int verificarUsuario(void);
int validacion(void);
int imprimirRegistro(void);

int verificarPassword(char passUsuario[], char passGuardada[]){
    int i=0,j=0,k=0;
    i = strlen(passUsuario);
    j = strlen(passGuardada);
    if(i==j){
        for(k=0; k<i; k++){
            if(passUsuario[k] != passGuardada[k]){
                return 0;
            }
        }
        return 1;    
    }
    else{
        return 0;
    }
    
}

int verificarUsuario(){
	struct datosUsuario mUsuario;
	printf("Por favor introduce tu nombre de usuario: ");
	scanf("%s",mUsuario.usuario);
	printf("Introduce tu contrasenia: ");
	scanf("%s",mUsuario.password);

	FILE *mArchivo;
    	char pass[50];
	mArchivo = fopen(mUsuario.usuario,"r");
	if(mArchivo != NULL){
		fscanf(mArchivo,"%s",pass);
        	if(verificarPassword(mUsuario.password,pass)){
            		printf("Autenticacion correcta.\n");
            		fclose(mArchivo);
    
            		imprimirRegistro();
            		return 1;
        	}
        	else{
            		printf("Contrasenia incorrecta\n");
            		return 0;
       		 }
        
	}
	else{
		printf("El usuario no existe\n");
        return 0;
	}//Fin if/else
			
}

int validacion(){
	if(verificarUsuario()){
                   		 return 1;
                	}
return 0;
}

char usuario[50];
int imprimirRegistro(){
	printf("\n\n\tIngrese el numero de usuario a consultar:");
	scanf("%s",&usuario);
	
	FILE *archivo;
	char caracteres[50];
	archivo=fopen(usuario,"r");
	if (archivo!=NULL) {
		printf("Registro: \n");
		while(feof(archivo)==0){
			fgets(caracteres,50, archivo);
			printf("%s",caracteres);
		}
		fclose(archivo);
		return 1;
	}
	else
	{
		printf("No se encontro el usuario o el registro esta vacio!!");
		return 0;
	}
}

int main(){
	char res,rep;
	do{
	titulo();
	validacion();
	printf("\n\nDeseas ver otro registro? Presiona (S/N):  ");
	fflush(stdin);
	scanf("%c",&res);
	}while (res=='s'||res=='S');
	
	printf("Regresar al Menu Principal Presione(S/N): ");
	fflush(stdin);
	scanf("%c",&rep);
	if (rep == 'S' || rep == 's'){
		system("start menu.exe");
		return 0;
	}else{
		printf("\n\n\t***** Programa finalizado *****");
	}
return 0;
}
