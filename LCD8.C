/*					 Exsto Tecnologia							*/
/* 				Biblioteca de LCD alfanumérico 					*/
/*						Funções									*/
void WriteLCD(unsigned char data, unsigned char CD)
{
//Envia comandose dados para o LCD
	if(CD) 	RS = 1;
	else 	RS = 0;

	DISPLAY = data;
	EN = 1;
	Delay100us();
	EN = 0;
	Delay100us();

}
void GotoXYLCD(unsigned char x,unsigned char y)
{
// Posiciona o cursor
	if(y == 1)	WriteLCD(0x80 + x,CMD);
	if(y == 2)	WriteLCD(0xC0 + x,CMD);
	if(y == 3)	WriteLCD(0x90 + x,CMD);
	if(y == 8)	WriteLCD(0xd0 + x,CMD);

}
void ClearLCD(void)
{
//Limpa o LCD
	RS = 0;
	DISPLAY = 0x01;
	EN = 1;
	Delay5ms();
	EN = 0;
	Delay5ms();
	
}
void OpenLCD(void)
{
// Inicializa o LCD
//	const unsigned char InitSeq[] = {0x38,0x38,0x06,0xe0,0x01};
	const unsigned char InitSeq[] = {0x33,0x32,0x38,0x06,0x0c,0x01};
	unsigned char i;

	ADCON1 = 0x0f;

	// configurações de direção
	RS_DIR = OUT;
	EN_DIR = OUT;
	
	if(OUT)	DISPLAY_DIR = 0xff;
	else	DISPLAY_DIR = 0x00;

	RS = 0;		// comandos
	for(i=0;i<6;i++){
		EN = 1;
		Delay100us();
		DISPLAY = InitSeq[i];
		Delay5ms();
		EN = 0;
		Delay5ms();
	}
}
void PutLCD(char data)
// Escreve um caracter no LCD
{
	WriteLCD(data,DAT);
}
void PrintLCD(char *Msg)
// Escreve uma string no LCD
{
	while(*Msg){
		WriteLCD(*Msg,DAT);
		Msg++;
	}
}
void Delay100us(void)
{
// gera atrado de 100us
	Delay100TCYx(2);
}
void Delay5ms(void)
{
// gera atrado de 5ms
	Delay1KTCYx(10);
}
