
//**********************************************************************************************
//*										mypipe.c												*
//*																								*
//*				Copyright (C) 2015 www.myopensrc.in - All Rights Reserved						*
//*																								*
//*					AUTHOR: Dash			EMAIL: dash@myopensrc.in							*
//**********************************************************************************************
#include"header.h"

void mypipe(char *c)
{
	int p[2];
	pipe(p);
	char cmd[100],*arg1[10], *arg2[10];
	strcpy(cmd,c);
	int i=0,j=0,k=0;

	while(cmd[i]!='|')
	{
		if(cmd[i]==' '||cmd[i]=='\t')
			i++;
		else
		{
			arg1[j]=malloc(15);
			k=0;
			while(cmd[i]!=' '&&cmd[i]!='\t'&& cmd[i]!='|')
			{
				arg1[j][k]=cmd[i];
				k++;
				i++;
			}
			arg1[j][k]='\0';
			j++;
		}
	}
	arg1[j]=NULL;
	i++;
	j=0;
	while(cmd[i]!='\0')
	{
		if(cmd[i]==' '||cmd[i]=='\t')
			i++;
		else
		{
			arg2[j]=malloc(15);
			k=0;
			while(cmd[i]!=' '&&cmd[i]!='\t'&& cmd[i]!='\0')
			{
				arg2[j][k]=cmd[i];
				k++;
				i++;
			}
			arg2[j][k]='\0';
			j++;
		}
	}
	arg2[j]=NULL;

	if(fork()==0)
	{
		close(1);
		dup(p[1]);
		execvp(arg1[0],arg1);
	}	
	else
	{
		if(fork()==0)
		{	close(0);
			dup(p[0]);
			execvp(arg2[0],arg2);	
		}
		else
		{	wait(0);
			i=0;
			while(arg1[i])
			{
				free(arg1[i]);
				i++;
			}
			i=0;
			while(arg2[i])
			{
				free(arg2[i]);
				i++;
			}
		}
	}
}
