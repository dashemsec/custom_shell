//***********************************************************************************************
//*										sigign.c												*									
//*																								*
//*				AUTHOR: Sourabh Das		EMAIL: sourabhdas143@gmail.com							*
//***********************************************************************************************

#include"header.h"

void sigign(void)
{
//signal(SIGINT,SIG_IGN);		//Ignores Ctrl + C
signal(SIGQUIT,SIG_IGN);	//Ignores Ctrl + \

}
