//gcc -o ej60 ej60.c
void main()
{
	//ejecuta una lista de cadenas en la consola
	execl( "/bin/ls", "ls", "-c", 0 );
}
