/*******************************************************************************
*	Declaraciones de la Librer�a
*
*	Funciones para trabajo con tipo de datos Str
*
*	Autor: Marcelo Garcia
*
*******************************************************************************/
#include "main.h"

int INTOA( int , unsigned char *); //Colocar en otro .h y.c
 /*----------------------------------------------
int					Nro a convertir
unsigned char*		cadena de caracteres resultante
-----------------------------------------------*/
int FTOA( int a,  unsigned char *v1, int comma);
/*----------------------------------------------
int					Nro a convertir
unsigned char*		cadena de caracteres resultante
comma				lugar del nro donde se quiere poner la coma
-----------------------------------------------*/

int FT_String( unsigned char * , unsigned char *, unsigned char *,int *, int, int);
/*-------------------------------------------------------------------------------------------
ADVERTENCIA, esta funció utiliza y funciona solamente con caracter delimitador "\0"

BUSCAR UNA CADENA DENTRO DE OTRA

String 1="LA CASA ROJA"
String 2="CASA"
String 3={};
int ubic=0;

valor=FT_String( String 1, String 2, String 3,&ubic, 0);

En este caso valor será 1

String 1="LA CASA ROJA"
String 2="TOSTADA"
String 3={};
int ubic=0;

valor=FT_String( String 1, String 2, String 3,&ubic, 0);

En este caso valor será 0

String 1="LA CASA ROJA"
String 2="TOSTADA DE MANTECA"
String 3={};
int ubic=0;

valor=FT_String( String 1, String 2, String 3,&ubic, 0);

En este caso valor será 2

String 1="LA CASA ROJA"
String 2="CASA"
String 3={};
int ubic=0;

valor=FT_String( String 1, String 2, String 3,&ubic, 1);

En este caso valor será 3

String 1="LA CASA +IPD:3,ABCROJA"
String 2="CASA"
String 3={};
int ubic=4;

valor=FT_String( String 1, String 2, String 3,&ubic, 2);

En este caso String1 será "LA CASA ROJA"

String 1="LA CASA +IPD:3,ABCROJA"
String 2="CASA"
String 3={};
int ubic=11

valor=FT_String( String 1, String 2, String 3,&ubic, 2);

En este caso String1 será "LA CASA +IPD:3,ABCROJA" pues no lo encontrará luego de la posicion 11

String 1="LA CASA ROJA"
String 2="CASA"
String 3={};
int ubic=0;

valor=FT_String( String 1, String 2, String 3,&ubic, 3);

En este caso String 1="LA CASA ROJA"
			 String 2="CASA"
			 String 3="LA  ROJA"

----------------------------------------------
int					resultado de la busqueda

					0 :	Cadena no contenida en cadena original
					1 :	Cadena contenida en cadena original
					2 : Cadena de caracteres no compatibles
					3 : Cadena eliminada del vector original
					
unsigned char*		cadena de caracteres a analizar
unsigned char*		cadena de caracteres a encontrar
unsigned char*		cadena de caracteres extra�da
int * 				ubicacion en donde comienza la cadena buscada
int								Instrucci�n para la tarea que realiza la funci�n
									0: Busca en la cadena lo qu se detalla en el segundo unsigned char *
									1: Elimina en la cadena lo qu se detalla en el segundo unsigned char *
									2: Elimina de maneRa autom�tica el +IPD y activa lectura
									3: Elimina de maneRa autom�tica la cadena tok y la copia al vector especificado
									
-----------------------------------------------*/
int FT_String_ND( unsigned char * ,int *, unsigned char *, int *, unsigned char *,int *, int *, int *,int,int);
/*-------------------------------------------------------------------------------------------
ADVERTENCIA, esta funció utiliza y funciona solamente con caracter delimitador "\0"

BUSCAR UNA CADENA DENTRO DE OTRA

String 1="LA CASA ROJA"
String 2="CASA"
String 3={};
int ubic=0;

valor=FT_String( String 1, String 2, String 3,&ubic, 0);

En este caso valor será 1

String 1="LA CASA ROJA"
String 2="TOSTADA"
String 3={};
int ubic=0;

valor=FT_String( String 1, String 2, String 3,&ubic, 0);

En este caso valor será 0

String 1="LA CASA ROJA"
String 2="TOSTADA DE MANTECA"
String 3={};
int ubic=0;

valor=FT_String( String 1, String 2, String 3,&ubic, 0);

En este caso valor será 2

String 1="LA CASA ROJA"
String 2="CASA"
String 3={};
int ubic=0;

valor=FT_String( String 1, String 2, String 3,&ubic, 1);

En este caso valor será 3

String 1="LA CASA +IPD:3,ABCROJA"
String 2="CASA"
String 3={};
int ubic=4;

valor=FT_String( String 1, String 2, String 3,&ubic, 2);

En este caso String1 será "LA CASA ROJA"

String 1="LA CASA +IPD:3,ABCROJA"
String 2="CASA"
String 3={};
int ubic=11

valor=FT_String( String 1, String 2, String 3,&ubic, 2);

En este caso String1 será "LA CASA +IPD:3,ABCROJA" pues no lo encontrará luego de la posicion 11

String 1="LA CASA ROJA"
String 2="CASA"
String 3={};
int ubic=0;

valor=FT_String( String 1, String 2, String 3,&ubic, 3);

En este caso String 1="LA CASA ROJA"
			 String 2="CASA"
			 String 3="LA  ROJA"

----------------------------------------------
OUT:int				resultado de la busqueda

					0 :	Cadena no contenida en cadena original
					1 :	Cadena contenida en cadena original
					2 : Cadena de caracteres no compatibles
					3 : Cadena eliminada del vector original
					4 : Cadena eliminada del original, datos correctos
					5 : Cadena eliminada del original, datos incorrectos

IN :unsigned char*	cadena de caracteres a analizar
IN :int				cdad de elementos del vector
IN :unsigned char*	cadena de caracteres a encontrar
IN :int				cdad de elementos del vector
OUT:unsigned char*	cadena de caracteres extra�da
OUT:int				cdad de elementos del vector
OUT:int * 			ubicacion en donde comienza la cadena buscada
OUT:int				ID de conexion
IN :int				longitud del vector en función 4 maximo tamaño para evitar escritura fuera del area de memoria
IN :int								Instrucci�n para la tarea que realiza la funci�n
									0: Busca en la cadena lo qu se detalla en el segundo unsigned char *
									1: Elimina en la cadena lo qu se detalla en el segundo unsigned char *
									2: Elimina de maneRa autom�tica el +IPD y lo copia al tok
									3: Elimina de maneRa autom�tica la cadena tok y la copia al vector especificado
									4: Elimina de manera automatica el +IPD copia al tok solo los datos e infomra se estan ok
									5: Elimina de manera automatica el +IPD copia al tok solo los datos infomra se estan ok y copia el id de conexion

-----------------------------------------------*/

uint16_t ByteToInt( uint8_t, uint8_t);

int CopiaVector(char *, char *, int, int, char *);
/* ------------------------------------------------------------
Esta funcion copia un vector en otro, la idea es usarla cuando no

se puede utilizar la función strcpy la que utiliza como caracter
delimitador el "\0"
Esta funciòn permite indicar la cantidad de elementos a copiar

!CUIDADO! COMO NO USA UN CARACTER DELIMITADOR SE PUDEN ESCRIBIR
ACCIDENTALMENTE DIRECCIONES DE MEMORIA DE OTROS VECTORES.
Esto es posible si se elije copiar una cadad de elementos superior
a la capacidad del vector

----------------------------------------------
int					resultado de la operación
					0	:	ok
					1	:	Excedida la cantidad de elementos
char*				Vector al que se desea copiar la informacion
char*   			Vector de origne de informacion
int 				0 =  calculado por comando strlen, finalización por /0
					n =  cantidad de elementos a copiar sin importar terminacion /0
int                 0 = No completar restante con /0
					1 = Completar restante con/0
char*				Vector al caracter con el que se desea completar la info
					No habilitado de momento
----------------------------------------------*/

int STRNACT_ADV(unsigned char*, int ,unsigned char*, int);
/*----------------------------------------------
int					Cantidad de elementos del string concatenado

unsigned char*		cadena de caracteres con la dirección
int					cdad de caracteres de dirección
unsigned char*		cadena de caracteres con la info a adjuntar
int 				cantidad de caracteres de datos


-----------------------------------------------*/
