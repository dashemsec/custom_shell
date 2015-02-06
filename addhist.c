
//**********************************************************************************************
//*										addhist.c												*
//*																								*
//*				Copyright (C) 2015 www.myopensrc.in - All Rights Reserved						*
//*																								*
//*					AUTHOR: Dash			EMAIL: dash@myopensrc.in							*
//**********************************************************************************************
#include"header.h"

void addhist(int line, char *cmd, HIST **ptr)
{
	HIST *temp, *temp1;
	temp = malloc(sizeof(HIST));
	strcpy(temp->cmd,cmd);
	temp->line=line;
	static int count1=1;
	if(count1>10)
	{
		temp1= *ptr;
		*ptr= temp1->next;
		free(temp1);
	}
	if(*ptr==0)
	{
		temp->next=*ptr;
		*ptr=temp;
	}
	else
	{
		temp1=*ptr;
		while(temp1->next)
			temp1=temp1->next;

		temp->next=temp1->next;
		temp1->next=temp;
	}
	count1++;
}
