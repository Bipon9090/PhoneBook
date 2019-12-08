#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void clearInput(void);
void dataInsert(void);
void dataShow(void);
void dataDelet(void);
void dataEdit(void);
int dataSearch(void);
int editPermission(void);
int accountNumber(int);


struct list {
	int number;
	char name[20];
	char phone[15];
	char email[20];
	struct list *next;

};


typedef struct list node;

node *start, *tamp, *tamp1, *prev;

int count = 0;


int main()
{

	char ch;
	start = NULL;

	do
	{
		fflush(stdin);
		puts("\nWelcome To The Contact Database");
		puts("--------------------------------");
		puts("1 - Add a new contact");
		puts("2 - Delete contact");
		puts("3 - List all contacts");
		puts("4 - Modify contact");
		puts("5 - Find a contact by name");
		puts("--------------------------------");
		puts("Q - Save and quit\n");
		printf("\tYour choice:");
		ch = getchar();
		ch = toupper(ch);
		switch (ch)
		{
		case '1':
			puts("Add a new contact\n");
			fflush(stdin);
			dataInsert();
			break;
		case '2':
			puts("Delete a contact\n");
			dataDelet();
			break;
		case '3':
			puts("List all contacts\n");
			dataShow();
			break;
		case '4':
			puts("Modify a contact\n");
			dataEdit();
			break;
		case '5':
			puts("Find a contact by name\n");
			dataSearch();
			break;
		case 'Q':
			puts("Save and quit\n");
		default:
			break;
		}
	} while (ch != 'Q');


}

void dataInsert(void)
{

	if (start == NULL) {

		start = new node();


		count++;
		printf("%s: %i\n", "contact number", count);
		start->number = count;

		printf("%s: ", "Enter contact name");
		gets(start->name);
		printf("%s: ", "Enter contact Phone number");
		gets(start->phone);
		printf("%s: ", "Enter contact email");
		gets(start->email);
		printf("contact added!");


		start->next = NULL;

		prev = start;


	}

	else
	{
		tamp = new node();


		count++;
		printf("%s: %i\n", "contact number", count);
		tamp->number = count;

		printf("%s: ", "Enter contact name");
		gets(tamp->name);
		printf("%s: ", "Enter contact Phone number");
		gets(tamp->phone);
		printf("%s: ", "Enter contact email");
		gets(tamp->email);
		printf("contact added!");


		tamp->next = NULL;
		prev->next = tamp;
		prev = tamp;

	}


}

void dataShow(void)
{
	if (start == NULL)
		puts("There are no contacts to display!");

	else
	{
		printf("%s\t\t %s\t\t %s\t\t %s\n", "Acct#", "Name", "Phone", "Email");
		puts("------------------------------------------------------");

		tamp = start;

		do
		{

			printf("%d:\t\t %s\t\t %s\t\t %s\n", tamp->number, tamp->name, tamp->phone, tamp->email);

		}

		while ((tamp = tamp->next) != NULL);
	}
}

void dataDelet(void)
{
	int record;
	node *back;

	if (start == NULL)
	{
		puts("There are no contacts to delete!");
		return;
	}

	dataShow();
	printf("Enter contact account number to delete: ");
	scanf("%d", &record);
	tamp = start;

	while (tamp != NULL)
	{
		if (tamp->number == record)
		{
			if (tamp == start)
				start = tamp->next;
			else
				back->next = tamp->next;

			free(tamp);
			printf("contact %d deleted!\n", record);
			return;
		}

		else
		{
			back = tamp;
			tamp = tamp->next;
		}
	}
	printf("contact %d not found!\n", record);
}

void dataEdit(void)
{
	int record, result;
	if (start == NULL)
	{
		puts("There are no contacts to modify!");
		return;
	}

	dataShow();
	printf("Enter contact account number to modify or change: ");
	scanf("%d", &record);
	result = accountNumber(record);

	if (result > 0) {
		printf("Contact %d:\n", tamp->number);
		printf("Name: %s\n", tamp->name);
		if (editPermission())
			gets(tamp->name);
		printf("Phone: %s\n", tamp->phone);
		if (editPermission())
			gets(tamp->phone);
		printf("Email: %s\n", tamp->email);
		if (editPermission())
			gets(tamp->email);
		return;
	}
	printf("contact %d was not found!\n", record);
}



int dataSearch(void)
{
	char searchName[20];

	if (start == NULL)
	{
		puts("There are no contacts to find!");
		return 1;
	}

	printf("Enter contact name: ");
	fflush(stdin);
	gets(searchName);

	tamp = start;
	while (tamp != NULL)
	{
		if (strcmp(tamp->name, searchName) == 0)
		{
			printf("%s\t\t %s\t\t %s\t\t %s\n", "Acct#", "Name", "Phone", "Email");
			puts("------------------------------------------------------");

			printf("%d:\t\t %s\t\t %s\t\t %s\n", tamp->number, tamp->name, tamp->phone, tamp->email);


			return 0;
		}
		else
		{
			tamp = tamp->next;
		}
	}
	printf("contact %s was not found!\n", searchName);
	return 1;
}



int accountNumber(int recordnum)
{
	int record;
	record = recordnum;
	tamp = start;
	while (tamp != NULL)
	{

		if (tamp->number == record)
		{
			return 1;
		}

		else
		{
			tamp = tamp->next;
		}
	}
	return -1;
}


int editPermission(void)
{
	char ch;
	fflush(stdin);
	printf("Update? (Y to update any other key to not)");
	ch = getchar();
	ch = toupper(ch);
	fflush(stdin);
	if (ch == 'Y')
	{
		printf("Enter new value: ");
		return(1);
	}
	else
		return(0);
}