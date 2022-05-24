#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>
#include<error.h>


int main(){
	int fd;
	char buff[100]="hi this is practice on copy to user and copy from user";
	char buff1[100];
	int len=strlen(buff);
	fd=open("/dev/Example_Device",O_RDWR);
	if(fd < 0){
		perror(" ");
	}
	else{
		write(fd,buff,len);
		printf("data from user %s\n",buff);

		read(fd,buff1,len);
		printf("data from kernel %s\n",buff1);
	}
	close(fd);
	return 0;
}
