//***********************************************************************************************
//*										main.c													*
//*																								*
//*				Copyright (C) 2015 www.myopensrc.in - All Rights Reserved						*
//*																								*
//*					AUTHOR: Dash			EMAIL: dash@myopensrc.in							*
//***********************************************************************************************

#include"header.h"

main(int argc, char **argv)
{
	char ch[100];
	HIST *headptr=0;
	int count=1;

	if((argc>1)&&(strcmp(argv[1],"-c")==0))		//single command execution "./my_sh -c file"
	{
		int i;
		char *arg[20];
		if(argc<3)
		{
			printf("./my_sh -c: requires an argument\n");
			return;
		}
		for(i=2;i<argc;i++)
			arg[i-2]=argv[i];

		arg[i-2]=NULL;

		execvp(arg[0],arg);
		perror(arg[0]);
	}
	else
		while(1)								//--------------------------command terminal
		{	int flag=0,j=0;						//-----------------for avoiding white spaces
			printf("<%d %s> ",count,PROMPT_NAME);
		gets(ch);

			while(ch[j])
			{
				if(ch[j]!=' '&& ch[j]!='\t')
					flag=1;
				j++;
			}

			if(flag)
			{
				addhist(count, ch, &headptr);
				if(strcmp("quit",ch)==0)		//---------------------------exit the terminal
					return;
				else if(strcmp("pid",ch)==0)	//--------------------------Dislpay Process ID
					printf("%d\n",getpid());
				else if(strcmp("ppid",ch)==0)	//-------------------Display Parent Process ID
					printf("%d\n",getppid());
				else if(strcmp("hist",ch)==0)	//-----------------------------Display history
					showhist(headptr);
				else if(!strncmp(ch,"cd ",3))
				{
					if(my_cd(ch))
					{
						printf("my_sh: cd: %s :no such file or directory\n",&ch[3]);
						//	system("pwd");
					}
				}
				//else if(!strcmp(ch,"cd"))

				else if(strchr(ch,';')!=NULL)
					multiexec(ch);					//------------sequential execution of commands
				else if(strchr(ch,'|')!=NULL)	//----------------------------------------PIPE
					mypipe(ch);
				else if(strchr(ch,'>')!=NULL)
					outredir(ch);					//--------------------------output redirection
				else if(strchr(ch,'<')!=NULL)	//---------------------------input redirection
					inredir(ch);
				else							//-------------------------execute the command
				{
					execute(ch);
				}
			}
			count++;

		}


}

