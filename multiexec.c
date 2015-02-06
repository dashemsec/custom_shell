
//**********************************************************************************************
//*										multiexec.c												*
//*																								*
//*				Copyright (C) 2015 www.myopensrc.in - All Rights Reserved						*
//*																								*
//*					AUTHOR: Dash			EMAIL: dash@myopensrc.in							*
//**********************************************************************************************

#include"header.h"

void multiexec(char *ch)
{
	char cmd[20], *cp;
	int i=0,j;
	//strcpy(cmd,ch);
	//printf("%s\n",ch);
abc:
	j=0;
	while(ch[i]!=';'&& ch[i]!='\0')
	{
		cmd[j]=ch[i];
		j++;
		i++;
	}
	cmd[j]='\0';
	i++;

	execute(cmd);

	if(ch[i-1]!='\0')
		goto abc;

}
