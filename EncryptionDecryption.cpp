#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void EncryptFile(char *ptr)
{
	FILE *fp1=NULL;
	FILE *fp2=NULL;
	char ch;

	fp1=fopen(ptr,"r");
	fp2=fopen("check.txt","w");

	if(fp1==NULL || fp2 == NULL)
	{
		printf("\n cannot open file.");
		exit(1);
	}

	while((ch=fgetc(fp1))!=EOF)
	{
		ch=ch+7;
		fputc(ch,fp2);
	}
	
	printf("\n File created successfully.");
	printf("\n");
	fcloseall();
}
////////////////////////////////////////////////////////
//decryption
void DisplayOriginalFile()
{
	FILE *fp=NULL;
	char ch;

	fp=fopen("check.txt","r");
	if(fp == NULL)
	{
		printf("\n Unable to open file.");
		exit(1);
	}
	printf("\n Before decryption file contents are => ");
	while((ch=fgetc(fp))!=EOF)
	{
		printf("%c",ch);
	}
	rewind(fp);
	printf("\n After decryption file contents are => ");
	while((ch=fgetc(fp))!=EOF)
	{
		ch=ch-7;
		printf("%c",ch);
	}

	printf("\n");
	fclose(fp);
}
	
int main()
{
	char fname[50]={'\0'};
	printf("\n Enter file name with extension => ");
	scanf("%s",fname);

	EncryptFile(fname);
	DisplayOriginalFile();

	return 0;
}
