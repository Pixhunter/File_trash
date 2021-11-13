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
	fd=open(argv[1],O_RDONLY,0666);
	if (fd==-1)
	{
		perror(argv[1]);
		exit(1);
	}
	while (0!=read(fd, &num, sizeof(num)))
	{
		printf("%d  ", num);
	}
	printf("\n");
	close(fd);
	return 0;
}

