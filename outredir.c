
//**********************************************************************************************
//*										outredir.c												*
//*																								*
//*				Copyright (C) 2015 www.myopensrc.in - All Rights Reserved						*
//*																								*
//*					AUTHOR: Dash			EMAIL: dash@myopensrc.in							*
//**********************************************************************************************
#include"header.h"

void outredir(char *ch)
{
	int p[2];
	pipe(p);
	int fd;
	int i=0,j,k;
	char cmd[50],*fname;
	char *arg[20];

	while(ch[i]!='>')
	{
		cmd[i]=ch[i];
		i++;
	}
	cmd[i]='\0';
	fname=&ch[i+1];

	i=j=k=0;
	while(cmd[i]!='\0')
	{
		if(cmd[i]==' '||cmd[i]=='\t')
			i++;
		else
		{
			arg[j]=malloc(15);
			k=0;
			while(cmd[i]!=' '&&cmd[i]!='\t'&& cmd[i]!='\0')
			{
				arg[j][k]=cmd[i];
				k++;
				i++;
			}
			arg[j][k]='\0';
			j++;
		}
	}
	arg[j]=NULL;
	fd=open(fname,O_WRONLY|O_CREAT,0644);
	if(fork()==0)
	{
		close(1);
		dup(fd);
		execvp(arg[0],arg);
	}
	else
	{
		wait();
		i=0;
		while(arg[i])
		{
			free(arg[i]);
			i++;
		}
	}
	i++;
}
