#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>
#include<error.h>
int main()
{
int fd1,fd2;
char buf;
fd1=open("file1",O_RDONLY);
fd2=open("copying_file",O_WRONLY | O_CREAT,00700);
if(fd1<0){
printf("file not opened\n");
perror(" ");
}
else{
printf("file opened with read only mode\n");
}
while(read(fd1,&buf,1))
{
write(fd2,&buf,1);
}
printf("copying success\n");
close(fd1);
close(fd2);
return 0;
}

