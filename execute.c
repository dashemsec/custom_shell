
//**********************************************************************************************
//*										execute.c												*
//*																								*
//*				Copyright (C) 2015 www.myopensrc.in - All Rights Reserved						*
//*																								*
//*					AUTHOR: Dash			EMAIL: dash@myopensrc.in							*
//**********************************************************************************************

#include"header.h"

void execute(char *c)
{	
	char cmd[100],*arg[20];
	strcpy(cmd,c);
	int i=0,j=0,k=0;

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
	if(fork()==0)
	{
		execvp(arg[0],arg);
		perror(arg[0]);
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

}
