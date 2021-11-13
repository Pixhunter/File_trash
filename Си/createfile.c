#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char* argv[])
{
	int fd;
	int num;
	if (argc!=2)
	{
		fprintf(stderr, "Usage %s name file\n", argv[0]);
		exit(1);
	}
	fd=open(argv[1],O_WRONLY|O_CREAT|O_TRUNC,0666);
	if (fd==-1)
	{
		perror(argv[1]);
		exit(1);
	}
	printf("Enter integers, in the end put ctrl+d\n");
	while (1==scanf("%d", &num))
	{
		write(fd, &num, sizeof(num));
	}
	close(fd);
	return 0;
}



