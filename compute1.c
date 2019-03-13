#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"NFA1.h"

int flag=0;
void NFA_Test(int,int);
bool isFinal(int);
char str[50];

int main()
{
	char ch;
	int i=0;
	FILE *fr, *fp;
	fr=fopen("input.txt","r");
	fp=fopen("Output_DFA1.txt","w");
	fscanf(fr,"%s",str);
	while(!feof(fr))
	{
		i=0;
		
		NFA_Test(in_st,0);
		if(flag==1)
		{
			fprintf(fp,"%s\tAccepted\n",str);

		}
		else
			fprintf(fp,"%s\tReject\n",str);
		flag=0;


		fscanf(fr,"%s",str);
	}

}

void NFA_Test(int cur_st,int i)
{
	int k;
	int Nxt_st;
	if(str[i]=='\0')
	{
		if(isFinal(cur_st))
		{
			flag=1;
			return;
		}
	}
	else
	{
		for(k=0;k<N_st;k++)
		{
			Nxt_st=rules[cur_st][str[i]-'0'][k];
			
			if(Nxt_st != -1)
			{
				NFA_Test(Nxt_st,i+1);
			}
		}
	}
}
bool isFinal(int f)
{
	int i;
	for(i=0;i<N_Fst;i++)
	{
		if(f==fin[i])
		{
			return true;

		}

	}
	return false;
}
	

