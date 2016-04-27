/*					 Exsto Tecnologia							*/
/* 				Biblioteca de LCD alfanum�rico 					*/
// Bibliotecas
#include<delays.h>

// Defini��es
#define CMD	0
#define DAT 1

// Prot�tipos das fun��es
void Delay5ms(void);
void Delay100us(void);
void OpenLCD(void);
void ClearLCD(void);
void GotoXYLCD(unsigned char x,unsigned char y);
void WriteLCD(unsigned char data, unsigned char CD);

// Bibliotecas
#include "LCD8.c"