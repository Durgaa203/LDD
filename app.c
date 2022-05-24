#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
#include<error.h>

int main()
{
	int fd,len;
	char buff[1024];
	char *s ="hello world";
	len =strlen(s);
	fd=open("/dev/Example_Device",O_RDWR);
	int ret=write(fd,s,len);
	read(fd,buff,len);
	printf("%d\n%d\n",ret,len);
	close(fd);
	return 0;
}
