//String Functions only 

//string length
unsigned int strlenX(const char *str)
{
	unsigned int length = 0;
	if(str == NULL)
	{
		return 0;
	}

	while(*str != '\0')
	{
		length++;
		str++;
	}
	return length;
}

// convert string to uppercase
char* struprX(char *str)
{
	char *tp = str;
	if(tp == NULL)
	{
		return 0;
	}

	while(*tp != '\0')
	{
		if((*tp) >= 'a' && (*tp) <= 'z')
		{
			(*tp) = (*tp) - 32;
		}
		tp++;
	}
	return str;
}	


// convert string to lowercase
char* StrLwrX(char *cPtr1)
{
	char *cPtr2=cPtr1;
	if(cPtr2 == NULL)
	{
		return 0;
	}
	while(*cPtr2!='\0')
	{
		if(*cPtr2>=65 AND *cPtr2<=90)
		{
			*cPtr2=*cPtr2+32;
		}
		cPtr2++;
	}
	return cPtr2; 
}


// case(upp-lower) toggling
char* StrToggle(char *cPtr1)
{
	char *cPtr=cPtr1;
	while(*cPtr!='\0')
	{
		if(*cPtr >= 'a' AND *cPtr <= 'z')
		{
			*cPtr=*cPtr - 32;
		}
		else if(*cPtr >= 'A' AND *cPtr <= 'Z')
		{
			*cPtr = *cPtr + 32;
		}
		cPtr++;
	}
	return cPtr; 
}

//string copy
char* StrCpyX(char* cDest,char* cSrc)
{
	char *cDest1=cDest;
	while(*cSrc!='\0')
	{
			*cDest=*cSrc;
			cSrc++;
			cDest++;
	}
	cDest='\0';
	return cDest1;
}

//string concat
char* strcatX(char *source, const char *destn)
{
	if(source == NULL || destn == NULL)
	{
		return 0;
	}
	char *tp1 = source;
	char *tp2 = destn;

	while(*tp1 != '\0')
	{
		tp1++;
	}
	while(*tp2 != '\0')
	{
		*tp1 = *tp2;
		tp1++;
		tp2++;
	}
	*tp1 = '\0';
	return tp1;
}


//compare two string
int MyStrCmp(char* first,char* second)
{
	if(first == NULL || second == NULL)
	{
		return -1;
	}
	while((*first != '\0') && (*second != '\0'))
	{
		if(*first != *second)
		{
			break;
		}
		first++;
		second++;
	}
	if((*first==’\0’)&&(*second==’\0’))
	{
		return 0;
	}
	else{
		return -1;
	}
}

//reverse the given string
void strRevX(char* src)
{
	char *end=null;
	char temp;
	if(src==NULL)
	{
		return;
	}
	end=src+strlenX(src)-1;
	 
	while(src<end)
	{
		temp=*src;
		*src=*end;
		*end=temp;
		src++;
		end++;
	}
}
//Check whether 1st string is substring of other
BOOL strstrX(char *src, char*dest)
{
	char*temp=NULL;
	BOOL flag=FALSE;
	while(*dest!=’\0’)
	{
		temp=src;
		if(*temp==*dest)
		{
			while(*temp!=’\0’)
			{
				if(*temp!=*dest)
				break;
				temp++;
				dest++;
			}
			if(*temp==’\0’)
			{
				flag=TRUE;
				break;
			}
		}
		dest++;
	}
	return flag;
}

//check given string is palindrome or not(case-insensitive)
BOOL CheckPalindrome(char *src)
{
	char *start,*end;
	BOOL flag=TRUE;
	if(src == NULL)
	{
		return FALSE;
	}
	start=src;
	end=src+strlenX(src)-1;
	while(start <= end)
	{
		if((*start == *end)||( *start == (*end)-32)||( *start ==  (*end)+32))
		{
			Start++;
			End--;
		}
		else
		{
			flag=FALSE;
			break;	
		}
	}
	return flag;
}

