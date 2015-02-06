
//**********************************************************************************************
//*										my_cd.c													*
//*																								*
//*				Copyright (C) 2015 www.myopensrc.in - All Rights Reserved						*
//*																								*
//*					AUTHOR: Dash			EMAIL: dash@myopensrc.in							*
//**********************************************************************************************

#include "header.h"

int my_cd(char *ch)
{
	printf("==%s==\n",&ch[3]);
	if(chdir(&ch[3]))
		return 1;
	else
		return 0;
}
