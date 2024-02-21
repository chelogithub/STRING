/*******************************************************************************
*	Codigo de las funciones
*
*	Funciones para trabajo con tipo de datos Str
*
*	Autor: Marcelo Garcia
*
*******************************************************************************/
#include "string.h"
#include "stdio.h"
#include "STR_Chelo.h"

int FT_String( unsigned char * a, unsigned char * b, unsigned char * c,int *ubicacion, int of, int tf)
{
	int n=0,n2=0,n3=0,n4=0, lnga=0, lngb=0,lngd=0,lnge=0,h=0,estado=0;
	
	lnga=strlen(a);
	lngb=strlen(b);
			if (lnga>=lngb) //Solo buscao si la cadena a buscar es menor a la que la contiene
			{
				//Debo prguntar por el primer caracter, recorro hasta encontrar el primero, si no lo encuentro me voy
				do{	
						n2=0;
							while(a[n]!= b[n2])
							{
								n++;
								if(n+lngb>(lnga+1)) 
								{
									estado=0;
									break;
								}//return(0); //No esta el string
							}
							
							do
							{   //Ac� el primero ya es igual
							 n++;
							 n2++;
							 if(n2==lngb)				//Si son iguales quiere decir que todos sus componentes son iguales
									{
									*ubicacion=n-lngb; 
									estado=1;
									break;
									//if (tf==0) return(1);	//Si solo pido buscar salgo ahora
									}		//Esta el string if(n2>=lngb-1) return(1);
						
								if((a[n]=='\0')||(n2>lngb))	//Si finaliz� el vector o bien ya reviso mas caracteres que los que contiene el vector
									 {
									 estado=0;
									 break;
									 //return(0);//if(n+lngb>=lnga) return(0);//No esta el string
									 }
							}while(a[n]== b[n2]);
						
					}	while((n+(lngb-1)<=(lnga-1))&&(estado!=1));	//while(n+lngb<=lnga);
				
					if (tf==0) 
					{return(estado);			//Agregado para no dejar valor si solo quiero buscar
					}
					else
					{								//Si quiero eliminar lo encontrado
						if((tf==1)&&(estado==1))//------------------------------Si la voy a eliminar tiene que estar
						{

							while (a[*ubicacion+n2+n3]!='\0')
									{
										a[*ubicacion+n3]=a[*ubicacion+lngb+n3];
										n3++;
									}			
							a[*ubicacion+n3]='\0';	//Identifico finalizacion del vector
							estado=3;
							return(estado);
						}
						//---DECODIFICACION DE IPD, EXTRACCI�N DE CADENA PRINCIPAL Y COPIA A CADENA SECUNDARIA
						if((tf==2)&&(estado==1))
						{	
							while(a[n-lngb+n4]!='\0')//---------------Copio a partir del IPD al vector tok.
							{
								c[n4]=a[n-lngb+n4];
								n4++;
							}
							strtok(c,",:");
							lngd= atoi(strtok(NULL,",: "));
							if(lngd>=of-1)
							{
								lngd=of-1;
							}
							c[6]=',';//------------------------------Reconstruyo vector 
									if (lngd < 10) 
											{
												c[8]=':';
												c[8+lngd+1]='\0';
												lnge=9+lngd;
											}
											else{
														if (lngd< 100) 
														{
															c[9]=':';
															c[9+lngd+1]='\0';
															lnge=10+lngd;
														}
														else
														{
														if (lngd < 1000) 
														{
															c[10]=':';
															c[10+lngd+1]='\0';
															lnge=11+lngd;
														}
														}
													}
												//------------------------------Vector reconstruido
							  //------------------------------Extraccion del vector en el original
							n4=0;
							while(a[n-lngb+lnge+n4]!='\0')//---------------Copio a partir del IPD al vector tok.
							{
								a[n-lngb+n4]=a[n-lngb+lnge+n4];
								n4++;
							}
							a[n-lngb+lnge+n4]='\0';
							a[n-lngb+n4]='\0';
							if((n-lngb)==(lnge+n4)) a[0]='\0';
							estado=3;
							
						}
						//---EXTRACCI�N DE CADENA PRINCIPAL Y COPIA A CADENA SECUNDARIA
						if((tf==3)&&(estado==1))
						{
						n3=0;
						while (n3<lngb)//---------------Copio la info a extraer
									{
										c[n3]=a[*ubicacion+n3];
										n3++;
									}
									c[n3]='\0';//---------------Finalizo el vector extra�do
						n3=0;
						while (a[*ubicacion+lngb+n3]!='\0')
									{
										a[*ubicacion+n3]=a[*ubicacion+lngb+n3];
										n3++;
									}			
							a[*ubicacion+n3]='\0';	//Identifico finalizacion del vector									
									
									
							estado=3;
						}

						return(estado);
					}
			}
			else
			{
				return(2);
			}
}

int FT_String_ND( unsigned char * a, int *an, unsigned char * b, int *bn, unsigned char * c,int *cn, int *ubicacion, int *idcom, int of, int tf)
{
	int n=0,n2=0,n3=0,n4=0,n5=0, lnga=0, lngb=0,lngd=0,lnge=0,h=0,estado=0,cliente=0;

	lnga=*an;
	lngb=*bn;
			if (lnga>=lngb) //Solo buscao si la cadena a buscar es menor a la que la contiene
			{
				//Debo preguntar por el primer caracter, recorro hasta encontrar el primero, si no lo encuentro me voy
				do{
						n2=0;
							while(a[n]!= b[n2])
							{
								n++;
								if(n+lngb>(lnga+1))
								{
									estado=0;
									break;
								}//return(0); //No esta el string
							}

							do
							{   //Aca el primero ya es igual
							 n++;

							 n2++;
							 if(n2==lngb)				//Si pasé poracá recorriendo todo el vector ya se que lo contiene
									{
									*ubicacion=n-lngb+1;
									estado=1;
									break;
									//if (tf==0) return(1);	//Si solo pido buscar salgo ahora
									}		//Esta el string if(n2>=lngb-1) return(1);

							 if(n2>lngb)//if((a[n]=='\0')||(n2>lngb))	//Si finaliz� el vector o bien ya reviso mas caracteres que los que contiene el vector
									 {
									 estado=0;
									 break;
									 //return(0);//if(n+lngb>=lnga) return(0);//No esta el string
									 }
							}while(a[n]== b[n2]);

					}	while((n+(lngb-1)<=(lnga-1))&&(estado!=1));	//while(n+lngb<=lnga);

					if (tf==0) 					//Si solo pido buscar
					{return(estado);			//Agregado para no dejar valor si solo quiero buscar
					}
					else
					{								//Si quiero eliminar lo encontrado
						if((tf==1)&&(estado==1))//------------------------------Si la voy a eliminar tiene que estar
						{

							/*while (a[*ubicacion+n2+n3]!='\0')
									{
										a[*ubicacion+n3]=a[*ubicacion+lngb+n3];
										n3++;
									}*/
							while ((*ubicacion+n2+n3)<=lnga)
									{
										a[*ubicacion+n3-1]=a[*ubicacion+lngb+n3-1];
										n3++;
									}

							//a[*ubicacion+n3-1]='\0';	//Identifico finalizacion del vector
							*an=*ubicacion+n3-1;		//Largo del vector
							estado=3;
							return(estado);
						}
						//------------------------------------------------------------------------------------
						//---DECODIFICACION DE IPD, EXTRACCI�N DE CADENA PRINCIPAL Y COPIA A CADENA SECUNDARIA
						//------------------------------------------------------------------------------------
						if((tf==2)&&(estado==1))
						{
							while((n-lngb+n4)<=lnga)//---------------Copio a partir del IPD al vector tok que es el c.
							{						 // n quedó en la ultima posicion del vector b
								c[n4]=a[n-lngb+n4];
								n4++;
								*cn=n4;
							}
							strtok(c,",:");
							lngd= atoi(strtok(NULL,",: "));
							if(lngd>=of-1)
							{
								lngd=of-1;
							}
							c[6]=',';//------------------------------Reconstruyo vector
									if (lngd < 10)
											{
												c[8]=':';
												c[8+lngd+1]='\0';
												lnge=9+lngd;
											}
											else{
														if (lngd< 100)
														{
															c[9]=':';
															c[9+lngd+1]='\0';
															lnge=10+lngd;
														}
														else
														{
														if (lngd < 1000)
														{
															c[10]=':';
															c[10+lngd+1]='\0';
															lnge=11+lngd;
														}
														}
													}
												//------------------------------Vector reconstruido
							  //------------------------------Extraccion del vector en el original
							*cn=lnge;
							n4=0;
							while((n-lngb+lnge+n4)<=lnga)//while(a[n-lngb+lnge+n4]!='\0')//---------------Copio a partir del IPD al vector tok.
							{
								a[n-lngb+n4]=a[n-lngb+lnge+n4];
								n4++;
							}
							*an=n+n4-lngb-1;
							a[n-lngb+lnge+n4]='\0';
							a[n-lngb+n4]='\0';
							if((n-lngb)==(lnge+n4)) a[0]='\0';
							estado=3;

						}
						//------------------------------------------------------------------------------------
						//---EXTRACCI�N DE CADENA PRINCIPAL Y COPIA A CADENA SECUNDARIA-----------------------
						//------------------------------------------------------------------------------------
						if((tf==3)&&(estado==1))
						{
						n3=0;
						while (n3<lngb)//---------------Copio la info a extraer
									{
										c[n3]=a[*ubicacion+n3-1];
										n3++;
									}
									//c[n3]='\0';//---------------Finalizo el vector extra�do
						n5=0;
						while ((*ubicacion+lngb+n5)<=*an)
									{
										a[*ubicacion+n5-1]=a[*ubicacion+lngb+n5-1];
										n5++;
									}
							//a[*ubicacion+n3]='\0';	//Identifico finalizacion del vector
						    *an=*ubicacion+n5-1;
							*cn=n3;
							estado=3;
						}
						//------------------------------------------------------------------------------------
						//---DECODIFICACION DE IPD, EXTRACCI�N DE CADENA PRINCIPAL COPIA A CADENA SECUNDARIA DE
						//--- LOS DATOS CON EVALUACION DE INTEGRIDAD DE LOS MISMOS 4 DATOS OK 5 DATOS NO OK
						//------------------------------------------------------------------------------------
						if((tf==4)&&(estado==1))
						{
							while((n-lngb+n4)<=lnga)//---------------Copio a partir del IPD al vector tok que es el c.
							{						 // n quedó en la ultima posicion del vector b
								c[n4]=a[n-lngb+n4];
								n4++;
								*cn=n4;  //lonitud del vector tok + el /r/n+IPD,XX:
							}
							strtok(c,",:"); //En teoria no afecta el vector
							lngd= atoi(strtok(NULL,",: ")); //Datos informados de +IPD,XX: no deberia afectar el vector

							if(lngd>=of-1)//if(lngd>=of-1)
							{
								lngd=of-1;
							}
							c[6]=',';//------------------------------Reconstruyo vector
									if (lngd < 10)
											{
												c[8]=':';
												//c[8+lngd+1]='\0';
												lnge=9+lngd;
											}
											else{
														if (lngd< 100)
														{
															c[9]=':';
															//c[9+lngd+1]='\0';
															lnge=10+lngd;
														}
														else
														{
														if (lngd < 1000)
														{
															c[10]=':';
															//c[10+lngd+1]='\0';
															lnge=11+lngd;
														}
														}
													}
												//------------------------------Vector reconstruido
							  //------------------------------Extraccion del vector en el original
							*cn=lnge; //Longitud del vecto TOK completo
							n4=0;
							while((n-lngb+lnge+n4)<=lnga)//while(a[n-lngb+lnge+n4]!='\0')//---------------Copio a partir del IPD al vector tok.
							{
								a[n-lngb+n4]=a[n-lngb+lnge+n4];
								n4++;
							}
							*an=n+n4-lngb-1; //longitud del vector A
							n5=0;
							while((lnge-lngd+n5)<*cn)
							{
								c[n5]=c[(lnge-lngd+n5)];
								n5++;
							}
							*cn=n5; //Nueva longitud del vector con datos extaidos

							if((*cn+lnge-lngd+*an)==lnga)
							{
								estado=4;

							}
							else
							{
								estado=5;
							}

							//a[n-lngb+lnge+n4]='\0';
							//a[n-lngb+n4]='\0';
							//if((n-lngb)==(lnge+n4)) a[0]='\0';
							//estado=3;

						}
						//--------------------------------    MODO SERVIDOR    -------------------------------
						//---DECODIFICACION DE IPD, EXTRACCI�N DE CADENA PRINCIPAL COPIA A CADENA SECUNDARIA DE
						//--- LOS DATOS CON EVALUACION DE INTEGRIDAD DE LOS MISMOS 4 DATOS OK 5 DATOS NO OK
						//------------------- SOLO VALIDO PARA CLIENTES DE 0 A 9     -------------------------
						//------------------------------------------------------------------------------------
						if((tf==5)&&(estado==1))
						{
							while((n-lngb+n4)<=lnga)//---------------Copio a partir del IPD al vector tok que es el c.
							{						 // n quedó en la ultima posicion del vector b
								c[n4]=a[n-lngb+n4];
								n4++;
								*cn=n4;  //lonitud del vector tok + el /r/n+IPD,XXX:
							}
							strtok(c,",:"); //En teoria no afecta el vector
							cliente= atoi(strtok(NULL,",: ")); //Clieng del cual se reciben los datos
							lngd= atoi(strtok(NULL,",: ")); //Datos informados de +IPD,XX: no deberia afectar el vector
							if(lngd>=of-1)
							{
								lngd=of-1;
							}
							c[6]=',';//------------------------------Reconstruyo vector
									if (lngd < 10)
											{
												c[10]=':';
												//c[8+lngd+1]='\0';
												lnge=11+lngd;
											}
											else{
														if (lngd< 100)
														{
															c[11]=':';
															//c[9+lngd+1]='\0';
															lnge=12+lngd;
														}
														else
														{
														if (lngd < 1000)
														{
															c[12]=':';
															//c[10+lngd+1]='\0';
															lnge=13+lngd;
														}
														}
													}
												//------------------------------Vector reconstruido
							  //------------------------------Extraccion del vector en el original
							*cn=lnge; //Longitud del vecto TOK completo
							n4=0;
							while((n-lngb+lnge+n4)<=lnga)//while(a[n-lngb+lnge+n4]!='\0')//---------------Copio a partir del IPD al vector tok.
							{
								a[n-lngb+n4]=a[n-lngb+lnge+n4];
								n4++;
							}
							*an=n+n4-lngb-1; //longitud del vector A
							n5=0;
							while((lnge-lngd+n5)<*cn)
							{
								c[n5]=c[(lnge-lngd+n5)];
								n5++;
							}
							*cn=n5; //Nueva longitud del vector con datos extaidos

							if((*cn+lnge-lngd+*an)==lnga)
							{
								estado=4;
								*idcom=cliente;
							}
							else
							{
								estado=5;
							}

							//a[n-lngb+lnge+n4]='\0';
							//a[n-lngb+n4]='\0';
							//if((n-lngb)==(lnge+n4)) a[0]='\0';
							//estado=3;

						}
						return(estado);
					}
			}
			else
			{
				return(2);
			}
}


int INTOA( int a,  unsigned char *v1)
{
char origbuff[20]="0";	
int i=0;	
	
		sprintf(origbuff,"%i",a);	
		while(i<=strlen(origbuff))
		{			
		*v1++=(unsigned char)origbuff[i];
		i++;
		}
		return(i);
}

int FTOA( int a,  unsigned char *v1, int comma)
{
char origbuff[20]="0";
int i=0;
int b=0;

		sprintf(origbuff,"%i",a); 	//Paso el entreo a cadena de caracteres
		b=strlen(origbuff);
		if(comma<b)					//Si la posición de la coma es menor a la posición de los caracteres ejemplo int= 2 comma=0 resultado = 0,02
		{

			while(i<=((b)+1))
			{
				if((i==(b-comma))&&(comma<(b)))
				{
					*v1++='.';
					//i++;
				}
				*v1++=(unsigned char)origbuff[i];
				i++;
			}
			return(i);
			/*while(i<=((b)+1))
			{
				if((i==comma)&&(comma<(b)))
				{
					*v1++='.';
					//i++;
				}
				*v1++=(unsigned char)origbuff[i];
				i++;
			}
			return(i);*/
		  }
		else
		{
			/*v1++='0';
			*v1++='.';
			*v1++='0';*/
		}
		return(0);
}

uint16_t ByteToInt( uint8_t a, uint8_t b)
{
	uint16_t c=0;
					 c=(a)<<8;
					 c|=(b);
	return (c);
}

int CopiaVector( char *a, char *b, int c, int d,char *e)
{
int x =0;
char j[]="\0";  //Vector
char *f=&j;		//Puntero tipo char que aloja las direcciones de memoria del vector j
if (c==0)
{
	x=strlen(b);
}
else
	{
		x=c;
		if (x>512)// OJO SOLO HTTP if (x>128)
			{
				return(1);
			}
		else
			{
				int p=0;
				while(p<x)
				{
					*a++=*b++;
					p++;
				}


			if (d==1)
			{
			  p=c;
			  while (p<c+1)//512)// OJO SOLO HTTP while (p<128)
			  {

				  *a++=*f;//*a++=*e; //Lo que está en la memoria de f vaya a la memoria de a
				  p++;
				  //&a[p]="/0";

			  }
			return (0);
			}

			}
	}
return (1);
}


int STRNACT_ADV(unsigned char * a, int b ,unsigned char * c, int d)
{
	int i=b;
	while(i<(d+b))
	{
		a[i]=c[i-b];
		i++;
	}

	a[i]=0x00;

	return(i+1);
}
