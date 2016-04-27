/* 						Exsto Tecnologia						*/
/*						Leitura de teclado						*/

void openKeyboard(void)
{
	C0_DIR = OUT;
	C1_DIR = OUT;
	C2_DIR = OUT;
	C3_DIR = OUT;
	L0_DIR = IN;
	L1_DIR = IN;
	L2_DIR = IN;
	L3_DIR = IN;
	EnablePullups();
}
unsigned char getKey(void)
{
	unsigned char key = '\0';
	// coluna 0
	C0 = 0;
	C1 = 1;
	C2 = 1;
	C3 = 1;

	if(!L0) key = 'A';
	else if(!L1) key = 'B';
	else if(!L2) key = 'C';
	else if(!L3) key = 'D';

	// coluna 1
	C0 = 1;
	C1 = 0;
	C2 = 1;
	C3 = 1;

	if(!L0) key = '3';
	else if(!L1) key = '6';
	else if(!L2) key = '9';
	else if(!L3) key = 'F';

	// coluna 2
	C0 = 1;
	C1 = 1;
	C2 = 0;
	C3 = 1;

	if(!L0) key = '2';
	else if(!L1) key = '5';
	else if(!L2) key = '8';
	else if(!L3) key = '0';

	// coluna 3
	C0 = 1;
	C1 = 1;
	C2 = 1;
	C3 = 0;

	if(!L0) key = '1';
	else if(!L1) key = '4';
	else if(!L2) key = '7';
	else if(!L3) key = 'E';

	return(key);
}




