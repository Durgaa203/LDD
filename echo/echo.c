#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>
#include<string.h>
int main(int argc,char *argv[]){
int fd,len;
if(argc == 3){
char *s=argv[1];
len=strlen(s);
char *s1=argv[2];
fd=open(s1,O_CREAT |O_WRONLY,00700);
write(fd,s,len);
close(fd);
}
else if(argc > 3){
printf("please enter string and filename\n");
}
else{
printf("please enter string and filename\n");
}
return 0;
}

