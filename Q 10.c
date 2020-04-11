#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>

int main()
{
	int array[] = {143, 86, 1470, 913, 1774, 948, 1509, 1022, 1750, 130};
	int size = sizeof(array)/sizeof(array[0]);
	
	int total = 0;
	int i;
	total = array[1] - array[0];
    if(total<0)
    {
        total = total*-1;
    }
    for(i=2;i<10;i++)
    {
        total=total+abs(array[i]-array[i-1]);
    }
	
	char str[50];
	snprintf(str, 50, "%d\n", total);
	
	int fd;
	fd = open("File.txt",O_CREAT|O_RDWR,0777);
	write(fd, str, strlen(str));
	
	lseek(fd,0,SEEK_SET);
	char buffer[50];
	int a;
	a = read(fd,buffer,50);
	write(1,"Total Distance moved by Disk Arm: ",40);
	write(1,buffer,a);
}
