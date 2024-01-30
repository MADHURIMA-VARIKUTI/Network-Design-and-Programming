#include<string.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<fcntl.h>
#include<sys/stat.h>
int main()
{
	int s,r,recb,sntb,x;
	struct sockaddr_in server;
	char buff[200];
	printf("Input the Port Number");
	scanf("%d",&x);
	s=socket(AF_INET,SOCK_STREAM,0);
	if(s==-1)
	{
		printf("\nSocket creation error.");
		exit(0);
	}
	printf("\nSocket created.");

	server.sin_family=AF_INET;
	server.sin_port=htons(x);
	server.sin_addr.s_addr=inet_addr("127.0.0.1");

	r=connect(s,(struct sockaddr*)&server,sizeof(server));
	if(r==-1)
	{
		printf("\nConnection error.");
		exit(0);
	}
	printf("\nSocket connected.");
	while(1)
	{
	int i;
	char temp[50];
	printf("\n\n");
	printf("Enter your choice: \n1 for Registration number\n2 for Name of student\n3 for Subject code\n4 to Exit\n");
	int n;
	int len;
	scanf("%d", &n);
	switch(n)
	{
		case 1: printf("\nEnter Registration number: ");
		scanf("%s",temp);
		buff[0]=1;
		len=strlen(temp);
		buff[1]=len;
		for(i=0;i<len;i++)
		{
			buff[i+2]=temp[i];
		}
		sntb=send(s,buff,sizeof(buff),0);
		if(sntb==-1)
		{
			close(s);
			printf("\nMessage Sending Failed");
			exit(0);
		}
		recb=recv(s,buff,sizeof(buff),0);
		if(recb==-1)
		{
			printf("\nMessage Recieving Failed");	
			close(s);
			exit(0);
		}
		printf("\n%s\n", buff);
		break;

		case 2:printf("\nEnter name of student: ");
		scanf("%s",temp);
		buff[0]=2;
		len=strlen(temp);
		buff[1]=len;
		for(i=0;i<len;i++)
		{
			buff[i+2]=temp[i];
		}
		sntb=send(s,buff,sizeof(buff),0);
		if(sntb==-1)
		{
			close(s);
			printf("\nMessage Sending Failed");
			exit(0);
		}
		recb=recv(s,buff,sizeof(buff),0);
		if(recb==-1)
		{
			printf("\nMessage Recieving Failed");	
			close(s);
			exit(0);
		}
		printf("\n%s\n", buff);
		break;

		case 3:printf("\nEnter subject code: ");
		scanf("%s",temp);
		buff[0]=3;
		len=strlen(temp);
		buff[1]=len;
		for(i=0;i<len;i++)
		{
			buff[i+2]=temp[i];
		}
		sntb=send(s,buff,sizeof(buff),0);
		if(sntb==-1)
		{
			close(s);
			printf("\nMessage Sending Failed");
			exit(0);
		}
		recb=recv(s,buff,sizeof(buff),0);
		if(recb==-1)
		{
			printf("\nMessage Recieving Failed");	
			close(s);
			exit(0);
		}
		printf("\n%s\n", buff);
		break;

		case 4:buff[0]=4;
		sntb=send(s,buff,sizeof(buff),0);
		if(sntb==-1)
		{
			close(s);
			printf("\nMessage Sending Failed");
			exit(0);
		}
		break;
		default: printf("\nTry again!\n");
	}
	if(n==4)
		break;
}
	close(s);

}
/*Input the Port Number1245

Socket created.
Socket connected.

Enter your choice: 
1 for Registration number
2 for Name of student
3 for Subject code
4 to Exit
1

Enter Registration number: 210953314

Name of student is: MADHU RIMA 
Adress is: MANIPAL 
PID is: 5945


Enter your choice: 
1 for Registration number
2 for Name of student
3 for Subject code
4 to Exit

2

Enter name of student: MAHA

Dept sem section courses: 
CCE  3  AICT123 ICT234 HUM198 
PID is: 5949


Enter your choice: 
1 for Registration number
2 for Name of student
3 for Subject code
4 to Exit
3

Enter subject code: ICT234

Marks are: 
MADHU: 75
MAHA: 84 
PID is: 5953


Enter your choice: 
1 for Registration number
2 for Name of student
3 for Subject code
4 to Exit
4


*/	

