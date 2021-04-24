#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void create_account();
void olduser_login();
void main_menu_after_logging();
void buy_books();

struct id_password
{
	char user_name[20];
	char password[20];	
};

struct books_personal_details
{
	char name[60];
	char email_id[50];
	char state[20];
	char city[20];
	char phone_no;
	char book_name[40];
	char book_edition[10];	
	char type_of_book[20];
	char author[40];
	char description[500];
};

main()
{	
	system("cls");// clearing the console screen's previous output. clrscr is not running here.
	int option;
	
	
	printf("			WELCOME TO THE OLD BOOKS MANAGEMENT SYSTEM\n				");
	printf("\n This programms deals with buying and selling of old books\n");
	
	
	printf("**********************************************************************");
	printf("\n Choose any one option from the following\n 1. NEW USER? CREATE ACCOUNT.\n 2. OLD USER? LOGIN.\n ");
	printf("\nYou have entered :  ");
	scanf("%d",&option);
	fflush(stdin);
	printf("*********************************************************************");

	if(option==1)
	{
		create_account();
	}
	
	else if(option==2)
	{
		olduser_login();
	}
	
	else
	{
		printf("\n wrong option selected");
	}
	
	getch();
}// end of main


void create_account()	// user wants to make account by giving password and username
{
	FILE *ptr;	
	struct id_password b1,b2;
	int i,j;
	int lag,fla;

	printf("\n Welcome\n");
	printf("\nEnter a vaild user name!!!  Max of 20 characters. It should not contain any space\n");
	gets(b1.user_name);
	fflush(stdin);
	
	// checking whether it contain space or not
	i=strlen(b1.user_name);
	for(j=0;j<i;j++)
	{
		if(b1.user_name[j]==' ')
		{
			lag=1;
			break;
		}
		else
		lag=2;
		
	} 
	// checking whether the id is already present or not
	
	if(lag==1)//checking for space
	   {	
			printf("Wrong attempt!!! It should not contain any spaces");
			//break;
		exit(0);

       } 
       
    else if(lag==2)
    {
	ptr=fopen("id_password.txt","r");
	
	while(fread(&b2,sizeof(b2),1,ptr)==1)//// reading record in file
		if(strcmp(b1.user_name,b2.user_name)==0)
		{
			fla=3;
			fclose(ptr);
			//break;
		}
	
		else
		{
			fla=4;
		}
		
    {	//starting of fla statement
		while(fla==3)
		{
			printf("Already existing id....\n");
				printf("***************************************************************************");
			break;
			exit(0);
		}
		
		if(fla==4)
		{	
			printf("Enter your password\n");
			gets(b1.password);
			fflush(stdin);
		
			ptr=fopen("id_password.txt","a");
			if(ptr==NULL)
			
			 {
				printf("Error occured!!!");
				exit(0);
		     }	 
	
		// writing record in file
		fwrite(&b1,sizeof(b1),1,ptr);
	
			fclose(ptr);
			printf("\n You have been successfully registered!!\n");
			printf("  THANKYOU\n");
			printf("*****************************************************************************");
		}//closing else if statement of fla=4
}//closing of fla statement

		}//closing of else if statement
	}// closing the function new user


void olduser_login()
{
	struct id_password b2,b3;
	FILE *ptr;
	int fla;
	
	printf("\n Enter your login id:	");
	gets(b2.user_name);
	fflush(stdin);
	
	printf("\nEnter your password: 	");	
	gets(b2.password);
	fflush(stdin);
	
	ptr=fopen("id_password.txt","r");
	if(ptr==NULL)
	{
		printf("Error occured!!!");
		exit(0);
	}
	
	// reading record in file
	ptr=fopen("id_password.txt","r");
	

	while(fread(&b3,sizeof(b3),1,ptr)==1)
	{	
		if(strcmp(b2.user_name,b3.user_name)==0)
		{
			if(strcmp(b2.password,b3.password)==0)
		
		{
			fla=1;
			fclose(ptr);	
		}
	}
	
		else
		{
			fla=2;
			
		}
	}
			
	if(fla==1)
	{
		printf("\n Welcome, login successful\n");
		printf("***************************************************************");
		main_menu_after_logging();
	}
	else
	{
			printf("login unsuccessful\n");
		 	printf("***************************************************************");
	}
	
}

void main_menu_after_logging()
{
	int option;
	char y_no,x;
	struct books_personal_details b1;
	FILE *ptr;
	
	printf("\nWelcome.");
	printf("\n1. Do you want to sell books?\n2. Do you want to buy books?\nEnter 1 or 2:     ");
	scanf("%d",&option);
	fflush(stdin);
	printf("\n**********************************************************************");
	
	if(option==1)
	{
		printf("\nYou need to fill some of the deatils about you and your books\n");
		printf("Are you ready for entering the details? Type yes for Y and no for N:     ");
		scanf("%c",&y_no);
		fflush(stdin);
		printf("\n******************************************************");
		
		if(y_no=='Y'||y_no=='y')
		{
			
			printf("\nWhatever are you typing will be visible to people who will be looking for books.");
			printf("\nEnter your name:     ");
			gets(b1.name);
			fflush(stdin);
			
			printf("\nEnter your state name:		");
			scanf("%s",&b1.state);
			fflush(stdin);
			
			printf("\nEnter your city name:		");
			scanf("%s",&b1.city);
			fflush(stdin);
			
			printf("\nEnter your e-mail id:		");
			scanf("%s",&b1.email_id);
			fflush(stdin);
			
			printf("\nEnter your phone number[Note: This will be visible to the all person. So if you don't want to enter anything type xxxxxx]:	");
			scanf("%s",&b1.phone_no);
			fflush(stdin);
	
			{
			printf("\nEnter your book details");
			
			printf("\nEnter the name of your book:		");
			gets(b1.book_name);
			fflush(stdin);
			
			printf("\nEnter the author of your book:		");
			gets(b1.author);
			fflush(stdin);
			
			printf("\nEnter the edition of your book:		");
			gets(b1.book_edition);
			fflush(stdin);
			
			printf("\nEnter the type of book like story book,NCERT etc:		");
			gets(b1.type_of_book);
			fflush(stdin);
			
			printf("\nEnter other details of the books:		");
			gets(b1.description);
			fflush(stdin);
			
			ptr=fopen("details.txt","a");
			fwrite(&b1,sizeof(b1),1,ptr);
			fclose(ptr);
	
		}
		
			printf("\nThankyou for giving your details. The person will contact you directly through the e-mail. ");
			printf("\n We are just responsible for showing you details of the books.");
			printf("\n******************************************************************");
		
		}
		
		else if(y_no=='N'||y_no=='n')
		{
			printf("Thankyou. Hope to meet you soon");
		}
		
		else
		{
			printf("\nWrong choice");
		}
	}
	
	else if(option==2)
	{
		buy_books();
	}
	
	else
	{
		printf("\n Wrong option selected\n");
	}
	
} 

void buy_books()
{
	struct books_personal_details b1;
	FILE *ptr;
	char ch,book_name[20],person_name[30];
	int flag;
	
		ptr=fopen("details.txt","r");
		printf("\nBook name\tAuthor\tBook edition\tType of book\tdescription\tName of the person holding book\t\n");
		while(fread(&b1,sizeof(b1),1,ptr)==1)
		{
			printf("%s\t%s\t%s\t%s\t%s\t%s\n",b1.book_name,b1.author,b1.book_edition,b1.type_of_book,b1.description,b1.name);
		//	printf("%s",b1.name);
		//	printf("%s",b1.phone_no);
		//	printf("%s",b1.city);
		//	printf("%s",b1.state);
		//	printf("%s",b1.email_id);
		}
		fclose(ptr);
		
		printf("\nDo you want to know more about the person holding the book.type y for yes and n for no");
		scanf("%c",&ch);
		
		if(ch=='Y'||ch=='y')
		{
			printf("\nType the book name:	");
			fflush(stdin);
			gets(book_name);
			fflush(stdin);
			printf("\nEnter name of the person:	");
			gets(person_name);
			fflush(stdin);
			
			ptr=fopen("details.txt","r");
			while(fread(&b1,sizeof(b1),1,ptr)==1)
			{
				if(strcmp(book_name,b1.book_name)==0&&(strcmp(person_name,b1.name)==0))
				{
					
					printf("Email id: %s\nCity in which person name: %s\nState: %s\n",b1.email_id,b1.city,b1.state);
					printf("%s",b1.phone_no);
					flag=1;
						fclose(ptr);
						break;
				}
				else
				flag=2;
			}
			if(flag==2)
			puts("Error");
	
		}
		else
		{
			printf("Thankyou");
		}
}

