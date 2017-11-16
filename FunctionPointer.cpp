#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
>Like variable,a compiled code upon execution gets some space in main memory.Thus, a fn in pgm code is places at some memoryvlocatn in code segment.
>fn type is derived datatype.
>With function pointer’s, a function can be called at runtime.
>It stores address of functn(add of 1st functn) and not its content.
>When we create a fn ptr we can store the address of any fn whose prototype gets matched with prototype of that of fn ptr.
Eg:-	 	int Add(int,int)		//accepts two int, returns int
==>        Int(*P)(int  ,int);	//‘P’ is the ptr which may store address of such a functn which accepts 2 para: int, int and that fn returns int.
==> 
>At this point only a ptr gets created but it contains nothing. As we want to store the address of functn then there is no need to use address of operator b’coz name of functn is internally considered as its ‘base address’.
P=Add;
P(10,20);		//when we use this ‘p’ ptr by passing 10 and 20 the fn gets implicitly called whose add is stored in ptr p.
>This concept is generally used in libraries as dll where we have to receive the address of functn due to which acceptor should be fn ptr.
>like normal ptr, memory for fn ptr is 4bytes, but it stores add from text section of process.
*/

int add(int no1, int no2)			//1000
{
	printf(“Add”);
}
int sub(int no1, int no2)			//2000
{
	printf(“Sub”);
}
int mul(int no1, int no2)			//3000
{
	printf(“Mul”);
}
int main()
{
int(*P)(int,int);
P=add;
P(10,20);			//call 1000
P=sub;
P(20,30);			//call 2000
P=mul;
P(10,2);			//call 3000
return 0;
}


 
