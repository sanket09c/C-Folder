//Structure, Union, Enum concepts
/*
Case 1: Int x,y;		//Single variable manageable.

Case 2: Int x1,x2,x3,….x100; unmanageable, therefore Derived datatype
        “array”(homogenous) is used.

Case 3: Heterogenous data as-int,char cannot be stored together in array.  Therefore UserDefined datatype(Contents dependent on user of pgm lang.
)needed. 

		 
Structure: All elements have their separate memory
				VS
Union: All elements share same memory(uses memory which is allocated to 	 max-sized datatype)
*/
# include<stdio.h>
# include<stdlib.h>

int main()
{

// Structure is collection of primitive, user defined and derived data //types

// Primitive data types(int/char/float/double/void)

//structure declaration-list cannot contain void type(as it will //not be //possible to calculate the size of obj thus making it //incomplete. For //further details check self-referential structure)

	struct primitive
	{
		int i;
		char c;
		float f;
		double d;
	};	
	struct primitive obj;

//Structure reading:- obj is a variable of type primitive which is //userdefined datatype i.e structure which contains 4 elements as:-
//1st int,2ns char,3rd float and 4th double.

	// Derived data types(Array/ptr/Functn)
	struct derived 
	{
		int arr[10];
		char brr[10];
	};

	// User defined data types(struct/union/enum)
	struct userDefined 
	{
		struct demo1
		{
			int i;
		};
	};
/////////////////////////////////////////////////////////
//name of members should be different to avoid ambiguity
struct unique
{
int i;
//char i;
};	//compile time error
//////////////////////////////////////////////////////
// newly created type is incomplete until the closing braces of structure declaration is encountered.

/*
struct incomplete
{
	struct incomplete a;
	struct incomplete b;
	//Type struct incomplete is incomplete until closing braces is 	//encountered.Hence, a member of type struct incomplete cannot be 	//created

};	//type struct incomplete is complete this point onwards.
*/
//////////////////////////////////////////////////////////////
// Self-referential structure
//Structure definition cannot contain an instance of itself. However, it //may contain ptr to instance of itself. i.e  It is a structure which //contains pointer which stores address of itself
// This concept is allowed because in any case pointer requires 4 bytes

	struct outer4
	{
		int i;
		struct outer4 *ptr;
	};
// Ex:- Used in Linked list.
//Structure: Node1:data,ptr		Node2: data,ptr
//ptr1 of Node1 points to Node2.


//////////// Structure without tag/name ////////////////////////////////
struct				
{
	int a;
	char b[10];
};	
	//As tag name is not present, you have to compulsory make an object //here itself. B’coz it won’t be possible to make object ahead as there //is no name of this struct whose obj can be made later.


/////////////////////// array of structure variables //////////////////
	struct temp
	{
		int i;
		int j;
	};
struct temp Arrobj[3];
//initializing
//	struct temp Arrobj[3]={{10,10},{11,12},{14,5}};
//	OR
//Arrobj[0]={10,10};
//	OR
//Arrobj[1].i=11;
//Arrobj[1].j=12;

	// In this case Arrobj is array of 3 element and each member is 
	// of type struct temp

/////////////////// Accessing structure members////////

			
	// Direct accessing
	struct DirAccess
	{
		int i;
	};

	struct DirAccess objDirAccess;
	// objDirAccess is a variable of type struct DirAccess
	// Assigning value of i
	// ‘.’ operator used for direct accessing
	
	objDirAccess.i = 4;
	printf("Value of i through direct accessing is %d\n", 	objDirAccess.i);

////////////////////////////////////////////////////////////////////////

	// Indirect accessing
struct Indirect 
	{
		int i;
	};
	struct Indirect objIndirect;
	struct Indirect *ptrIndirect;

	// ptrIndirect is a pointer which stores address of struct Indirect 

	ptrIndirect = &objIndirect;
	// ‘->’ operator used for indirect accessing
	ptrIndirect -> i = 10;

	printf("Value of i through indirect accessing is %d\n", ptrIndirect ->i);

////////// Scope //////////////////////////////

//visible only in scope in which it is defined. i.e not possible to //declare objects of below structure outside its visible scope(here //outside main() it won’t be available)

struct scope
{
	int x,y;
};
struct scope scopeObj1,scopeObj2;		//Also static memory allocation

//(check scopefunc() below main())
//////////////////////////////////////////////////////

// dynamical memory allocation  using malloc or calloc

	struct hello
	{
		int i,j;
	};

	struct hello *p = (struct hello*)malloc(sizeof(struct hello));
	if(p == NULL)
	{
		printf("Unable to allocate memory\n");
	}
////////////////////////////////////////////////////////////////////////
//Definition does not reserve any memory space for structure members, it //is not possible to initialize structure members during structure defnin //data segment 

	struct structDecl
	{
		//	int i = 12;				//Error
		//	char Author[10]=”Sanket”;	//Error
	};
//(but as defn it is part of pgm code, some memory allocated in code seg)
//(A new entry in Symbol table is made by compiler)
//(It contains name of struct, no. of bytes reqd.)
//But, see below..
////////////////////////////////////////////////////////////////////////
//Member by member initializing
struct Demo
{
int i;
int j;
};
struct Demo objNew;
objNew.i=10;
objNew.j=20;
////////////////////////////////////////////////////
// Member initialisation list
// Initializing the structure at the time of defining variable by using
	
	struct MemInit
	{
		int i;
		char c;
		float f;
	};

	// This is called as member initialisation list
	struct MemInit objMemInit = {10,'A',3.12f};
////////////////////////////////////////////////////////
//We can initialize at time of decln also,
struct A
{
int I;
char cha;
}objNow={10,'a'};
////////////////////////////////////////////////////////////
// Nested structure: defining structure inside another structure

	// inner1 is a inner structure inside outer1 structure
	struct outer1
	{
		int i;	
		struct inner1
		{
			int j;
		}iobj1;
	}oobj1;
	
	// To access member j we can use statement as

	oobj1.iobj1.j = 10;

////////////////////////////////////////////////////////////////////////

	// Nested structure

	// If the inner structure defined inside the outer structure then
	// we have to create object of that structure at the time of definition
	// because after that we cannot create object outside

	struct outer5
	{
		int i;	
		struct inner5
		{
			int j;
		};
	}oobj5;	//size 4bytes and not 8bytes.
	
	// In this case there is no error but memory for inner5 structure is
	// not allocated

////////////////////////////////////////////////////////////////////////
	// Nested structure

	// In this case inner structure is defined outside the outer structure
	struct inner2
	{
		int j;
	};

	struct outer2
	{
		int i;
		struct inner2 iobj2;
	};

	struct outer2 oobj2;
	
	// We can access member j in same manner as above
	oobj2.iobj2.j = 10;

///////////////////////////////////////////////////////////////////////
// We can use typedef for creating our (synonym/alias)new data type //for the structure (reason: Syntactical convenience...)
//Eg: long structure name to short structure name for saving typing //efforts. 
 	typedef struct demo
	{
		int i;
	}newtype;

	// newtype is not an object for struct demo but, it is typedef for struct demo i.e We can create variable of structure as,
	 newtype objm;
//////////////////////////////////////////////////////////////////////	

// If structure contians N members and we initialise M members (N > M)
	// Then remaining members contains garbage.

	struct demo9
	{
		int i;
		int j;
		int k;
	}obj9;

	obj9.i = 10;
	obj9.j = 20;
	// obj9.k contains some garbage values

////////////////////////////////////////////////////////////////////////	// We can check size of the structure by using sizeof operator

	struct StructSize 
	{
		int i;
		int j;
	};

	printf("Size of struct StructSize is %d\n",sizeof(StructSize));	//size = 8
///////////////////////////////////////////////////////////////////	
	// We can use assignment operator for structure variable
	// which performs shallow copy of one structure variable
	// to another structure variable

	struct copy
	{
		int i;
	};
struct copy obj1,obj2;

	obj1.i = 11;
	obj2.i = obj1.i;	
	printf("\n\n Value of variable is %d \n",obj2.i);	// 11

////////////////////////////////////////////////////////////////////////

// We cannot use (comparison,reln,equality) operators on structure //variables(comparison,reln,equality)
	/*
	if(obj2 > obj1)	// Error
	{
		printf("obj1 is less than obj2");
	}
	*/

////////////////////////////////////////////////////////////////////////
	// To get desired effect we have to compare it member wise

	struct demon
	{
		int i;
		int j;
	}var1={10,20},var2={10,20};

	/*
	if(var1 == var2)		// Error
	{
		printf("Both the variables are equal\n");
	}
	*/

	// This is the proper way of comparison
	if((var1.i == var2.i)&&(var1.j == var2.j))
	{
		printf("Both the variables are equal\n");
	}
	else
	{
		printf("Both the variables are not equal\n");	
	}


/////////////////////////////////////////////////////
	// We can use enum as a member of structure

	enum hello3 {e, r, t};

	struct demo10
	{
		int i;
		enum hello3 obj;
	}obj10;

	// We can initialise this enum variable as
	obj10.obj = e;
///////////////////////////////////////////////////////////////////	

	// If structure only contains characters then memory is allocated
	// in one byte at a time

	struct demo14
	{
		char c;
		char d;
		char e;
	}obj14;

	printf("\n\nSize of structure is %d\n",sizeof(demo14)); //3byte

///////////////////////////////////////////////////////////////////////// //In 32 bit processor memory is allocated in 1 WORD (4 bytes)size //alignment
// If size of data member is less than 4 bytes then remaining bytes are\
// considered as a padding.

	struct demo12
	{
		int id1;
		int id2;
		char name;
		char c;
		float percentage;
	};
	 
	struct demo13 
	{
		int id1;
		char name;
		int id2;
		char c;
		float percentage;                      
	};

    struct demo12 a1;
    struct demo13 b1;
 
    printf("\n\nsize of demo12 in bytes : %d\n",sizeof(a1));
    printf ( "\n   Address of id1        = %u", &a1.id1 );
    printf ( "\n   Address of id2        = %u", &a1.id2 );
    printf ( "\n   Address of name       = %u", &a1.name );
    printf ( "\n   Address of c          = %u", &a1.c );
    printf ( "\n   Address of percentage = %u",&a1.percentage );
 
    printf("   \n\nsize of demo13 in bytes : %d\n",sizeof(b1));
    printf ( "\n   Address of id1        = %u", &b1.id1 );
    printf ( "\n   Address of name       = %u", &b1.name );
    printf ( "\n   Address of id2        = %u", &b1.id2 );
    printf ( "\n   Address of c          = %u", &b1.c );
    printf ( "\n   Address of percentage = %u",&b1.percentage );

////////////////////////////////////////////////////////////////////////
//padding creates memory wastage. We have to use custom packing request //technique
	// We therefore use pre-processor directive ” # pragma pack()”

	#pragma pack(1)
	struct demo15 
	{
		int id1;
		int id2;
		char name;
		char c;
		float percentage;
	};
/*
#pragma pack(1):syntax Before structure declaration(As how much amt of memory should be allocated will be calculated while declaration itsellf) and not while structure variable creation.
(1): The request of 1byte packing is applicable to every structure which is declared after that prototype
(Any para: 1,2,4,8,16,… allowed)
(Also applicable to union)
*/
	#pragma pack(1)
	struct demo16 
	{
		int id1;
		char name;
		int id2;
		char c;
		float percentage;                      
	};
#pragma pack()
//#pragma pack(): To stop that packing request,write at end of //declaration
 
    struct demo15 a2;
    struct demo16 b2;
 
    printf("\n\nsize of demo15 in bytes : %d\n",sizeof(a2));
    printf ( "\n   Address of id1        = %u", &a2.id1 );
    printf ( "\n   Address of id2        = %u", &a2.id2 );
    printf ( "\n   Address of name       = %u", &a2.name );
    printf ( "\n   Address of c          = %u", &a2.c );
    printf ( "\n   Address of percentage = %u", &a2.percentage );
 
    printf("   \n\nsize of demo16 in bytes : %d\n", sizeof(b2));
    printf ( "\n   Address of id1        = %u", &b2.id1 );
    printf ( "\n   Address of name       = %u", &b2.name );
    printf ( "\n   Address of id2        = %u", &b2.id2 );
    printf ( "\n   Address of c          = %u", &b2.c );
    printf ( "\n   Address of percentage = %u", &b2.percentage );

////////////////////////////////////////////////////////////////////////
/* Further for more minute details to avoid memory wastage we can use the concept of bit field in Structure/Union.

Above concept also wastes memory (eg: memory reqd for date saving).
Date: 1 to 31	(6 bits are enough)
Month: 1 to 12	(5 bits)
Year: say 2000 to 2040	(13 bits)
i.e total of 3bytes is enough. Thuus saving 9bytes by bit field method.
*/
	struct demo17
	{
		int i:1;
		int c:4;
		int f:5;
		int k:3;
	};

	printf("\n\nSize of structure in case of bitfield is %d\n",sizeof(demo17));

////////////////////////////////////////////////////////////////////////

// If the structure contains the bifield then we cannot create a pointer
	// which points to its members
	// Means we cannot use & operator on bitfield

	struct demo18
	{
		int i:1;
		int c:4;
	}obj18;

	int *p18;
	//p18 = &obj18.i;	// Error

////////////////////////////////////////////////////////////////////////
//Not allowed in bitfield
	struct demoW
	{
	//	int c:35;	// Error cannot set value of the bitfield greater 				than size of the particular data type
	//	int arr[10]:4;	// Error cannot use bitfield for the array 
	//	float f:10;		// Error cannot use  float,double 
	// 	int i:0;		//0 not allowed
	//	int k; -3;		// -ve not allowed
};

////////////////////////////////////////////////////////////////////////

// union is similar as structure but memory allocated for the union
// is same as size of the largest member of that union

// In this case size of union is 8 because sizeof largest data member //in this union is 8 (and not like struct(sum of elements + padding)
	union demoCh
	{
		int i;
		char c;
		double d;
	};

	printf("\n\nSizeof union is %d\n",sizeof(demoCh));

////////////////////////////////////////////////////////////////////////

	// In case of union we can access single member at a time because
	// memory is shared between all the members
//
	union demoS
	{
		int i;
		char ch;
	}obj11;

	obj11.i = 97;
    obj11.ch = 'b';
	printf("Value of character is %d \n",obj11.i);
	printf("\n Value of character is %c \n",obj11.ch);
	//char ‘b’ is last value in our union due to which previous value i.e 97 is overwritten with ascii value of ‘b’.
////////////////////////////////////////////////////////////////////////

	// We can create nested union in same way like structure

	union outer24
	{
		int i;
		char c;
		union inner24
		{
			int k;
		};
	};

	// We can create a structure inside union as

	union outer25
	{
		int i;
		struct inner25
		{
			int k;
			double l;
		}obj;
	};

	printf("\n\nSizeof union is %d\n",sizeof(outer25));

////////////////////////////////////////////////////////////////////////

	// We can use bit field in union in same way as structure
	union demoX
	{
		int m:6;
	};

////////////////////////////////////////////////////////////////////////
//Enum 
/*
Theory:-
1.Enum is called enumeration const as the values get stored inside enum             are always const.
2.No separate memory.
3.Enum gets its memory in text section(therefore sizeOf() not valid here).
4.To inc readability enum is used.

*/
enum E1demo{f,g,h};	//f=0,g=1,h=2….auto inc by 1,starting with 0,when no //explicitly initializatn stated

enum E2demo{w=5,x,y};	//a=5(+ve,-ve allowed) given, therefore b=6,c=7.(auto inc by 		//1 from stated value and not not again from 0)

enum E3demo
{
//a=2,b,c,a
};	// a declared twice.Ambiguity Error

enum E4demo
{
A,b,c
}objM;
//ObjM=1;	//error
objM=b;		//allowed
//ObjM variable can be initialized with values of enum variable only.


enum e5{
d,en
};
//d=15;		//error
//en++;		//error….as in both trying to change enum values


enum en6{
q,o
}v;
//int *p=&v;		//error
//As we cannot fetch address of enum var (text section)
///////////////////////////////////////////////////
	return 0;
}
/*
void scopefunc()
{
	scope scopeObj1;		//Not visible here. Error
}

*/





