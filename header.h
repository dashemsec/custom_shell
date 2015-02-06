
//***********************************************************************************************
//*										header.h												*
//*																								*
//*				Copyright (C) 2015 www.myopensrc.in - All Rights Reserved						*
//*																								*
//*					AUTHOR: Dash			EMAIL: dash@myopensrc.in							*
//***********************************************************************************************
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<signal.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

# define PROMPT_NAME "my_sh"
typedef struct hist
{
	int line;
	char cmd[100];
	struct hist *next;
}HIST;

void addhist(int, char*, HIST**);
void showhist(HIST*);
void execute(char *);
void multiexec(char *);
void mypipe(char *);
void outredir(char *);
void inredir(char *);
int my_cd(char *);
