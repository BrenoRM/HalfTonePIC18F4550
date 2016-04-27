/*					 Exsto Tecnologia							*/
/* 				Biblioteca de LCD alfanumérico 					*/
// Bibliotecas
#include<delays.h>

// Definições
#define CMD	0
#define DAT 1

// Protótipos das funções
void Delay5ms(void);
void Delay100us(void);
void OpenLCD(void);
void ClearLCD(void);
void GotoXYLCD(unsigned char x,unsigned char y);
void WriteLCD(unsigned char data, unsigned char CD);

// Bibliotecas
#include "LCD8.c"
