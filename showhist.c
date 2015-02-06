
//**********************************************************************************************
//*										showhist.c												*
//*																								*
//*				Copyright (C) 2015 www.myopensrc.in - All Rights Reserved						*
//*																								*
//*					AUTHOR: Dash			EMAIL: dash@myopensrc.in							*
//**********************************************************************************************

#include"header.h"

void showhist(HIST *ptr)
{
	while(ptr)
	{
		printf("%d %s\n",ptr->line,ptr->cmd);
		ptr=ptr->next;
	}
}
