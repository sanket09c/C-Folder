#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void DisplayFileContents( char *cPtr)
{
	FILE *fptr=NULL;
	char Buff[1024]={'\0'};

	fptr=fopen(cPtr,"r");
	
	if(fptr == NULL)
	{
		printf("\n Cannot open file.\n");
		exit(1);
	}

	printf("\n File contets are => \n ");
	
	while(fgets(Buff,1024,fptr) != NULL)	
{
		printf("%s",Buff);
	}
	printf("\n");
	fclose(fptr);
}
/////////////////////////////////////////////////////////////////////
int DisplayFileSize( char *cPtr )
{
	FILE *fptr=NULL;
	long int filesize=0;
	fptr=fopen(cPtr,"r");
	if(fptr == NULL)
	{
		printf("\n Can not open file.\n");
		exit(1);
	}

	if( fseek(fptr,0,SEEK_END) == -1 )
	{
		printf("\n Unable to perform action.");
		exit(1);
	}
filesize=ftell(fptr);
	fclose(fptr);

	return filesize;
}
////////////////////////////////////////////////////////////////////
void CopyFile( char *cPtr )
{
	//create FILE pointer
	FILE *fptr1=NULL;
	FILE *fptr2=NULL;

	char chr ='\0';
	fptr1=fopen(cPtr,"r");
	fptr2=fopen("Check.txt","w");
if(fptr1 == NULL || fptr2 == NULL)
	{
		printf("\n Problem in reading or writing a file.\n");
		exit(1);
	}
while( ( chr = fgetc(fptr1) ) != EOF )
	{
		fputc(chr,fptr2);
	}
	printf("\n File copied successfully.\n");

	fcloseall();	
}
///////////////////////////////////////////////////////////////////////
void CopyFileReverse( char *cPtr )
{
	FILE *fptr1=NULL;
	FILE *fptr2=NULL;

	fptr1=fopen(cPtr,"r+");
	fptr2=fopen("demo.txt","w");

if(fptr1 == NULL || fptr2 == NULL)
	{
		printf("\n Problem in reading or writing a file.\n");
		exit(1);
	}

	if(fseek(fptr1,-3,SEEK_END) == -1)
	{
 		printf("\n Unable to continue.");
		fcloseall();
		exit(2);
	}


	fpos_t pos;
	fgetpos(fptr1,&pos);
	
	while(pos >= 0)
	{
		fputc(fgetc(fptr1),fptr2);
		pos=pos-1;
		fsetpos(fptr1,&pos);
	}
	
	printf("\nFile copied successfully...\n");
	
	fcloseall();
}
///////////////////////////////////////////////////////////////
void Concat( char *cP1 , char *cP2 )
{
	FILE *fp1=NULL;
	FILE *fp2=NULL;

	char ch='\0';
fp1=fopen(cP1,"r");
	fp2=fopen(cP2,"a");

	if(fp1 == NULL || fp2 == NULL)
	{
		printf("\n Problem in reading or writing a file.\n");
		exit(1);
	}

	while( ( ch = fgetc(fp1) ) != EOF )
	{
		fputc(ch,fp2);
	}

	printf("\n File copied successfully.\n");

	fcloseall();
}
/////////////////////////////////////////////////////////////////
int CompareFiles( char *cPtr1 , char *cPtr2 )
{
	FILE *fp1=NULL;
	FILE *fp2=NULL;

	char cr1='\0';
	char cr2='\0';

	fp1=fopen(cPtr1,"r");
	
	fp2=fopen(cPtr2,"r");

	if(fp1 == NULL || fp2 == NULL)
	{
		printf("\n Problem in reading or writing a file.\n");
		exit(1);
	}

	while(1)
	{
		cr1 = fgetc(fp1);
		cr2 = fgetc(fp2);
		
		if(cr1 == EOF || cr2 == EOF)
		{
			break;
		}
		
		if( cr1 != cr2 )
		{
			return 0;
		}
	}
	if(cr1 != EOF || cr2 != EOF)
	{
		return 0;
	}

	return 1;
	fcloseall();
}


int main()
{
	char filename1[20]={'\0'};
	char filename2[20]={'\0'};

	printf("\n Enter file name1 with extension => ");
	scanf("%s",filename1);

	printf("\n Enter second file name with extension => ");
	scanf("%s",filename2);

//////////////////////////////////////
	DisplayFileContents(filename1);
//////////////////////////////////////
DisplayFileSize(filename1);
/////////////////////////////////////
CopyFile(filename1);
//////////////////////////////////////////
CopyFileReverse(filename1);
//////////////////////////////////////////
	Concat(filename1,filename2);
//////////////////////////////////////////

int result=CompareFiles(filename1,filename2);

	if(result == 1)
	{
		printf("\n Both files are same.\n");
	}
	else
	{
		printf("\n Files are not same.\n");
	}

	return 0;
}
