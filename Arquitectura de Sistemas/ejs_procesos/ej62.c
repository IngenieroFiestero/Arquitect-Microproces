#include <error.h>
#include <fcntl.h>
void main()
{
	execlp("ls", "ls", "-c", 0);
	syserr("execlp");
}
