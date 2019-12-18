#define _CRT_SECURE_NO_WARNINGS

#include <fstream>

#include <stdio.h>

#include <iostream>

#include <conio.h>

#include <stdlib.h>


using namespace std;

void Add()

{

	char n, l, m;

	FILE* f;

	f = fopen("Users.txt", "a+");

	if (f)
	{
		printf("Enter name:");
		scanf("%s", &n);
		fprintf(f, "%s ", &n);
		printf("Enter Last Name:");

		scanf(" %s", &l);

		fprintf(f, "%s ", &l);

		printf("Enter Number:");

		scanf(" %s", &m);

		fprintf(f, "%s ", &m);

		fputs("\n", f);

		fclose(f);
	}
	else
	{
		printf("Can't open file");
	}
}

void Show()
{
	FILE* f;

	char c;
	f = fopen("Users.txt", "r");

	c = getc(f);

	while (c != EOF)

	{

		printf("%c", c);

		c = getc(f);

	}
	getchar();
}
void Del()

{

	FILE* f, *fp2;

	char c;

	int del_line, cnt = 0, temp = 1;

	f = fopen("Users.txt", "r");

	c = getc(f);

	while (c != EOF)

	{

		printf("%c", c);

		c = getc(f);

	}

	rewind(f);



	printf(" \n Enter line number of the line to be deleted:");

	scanf("%d", &del_line);

	while (!feof(f)) {

		fscanf(f, "%*[^\n]%*c");

		cnt++;

	}

	if (del_line >= cnt)

		printf("No User with such number");

	else

	{

		fp2 = fopen("temp.txt", "w");

		rewind(f);

		c = getc(f);

		while (c != EOF) {

			if (c == '\n')

				temp++;

			if (temp != del_line)

			{

				putc(c, fp2);

			}

			c = getc(f);

		}

		fclose(f);

		fclose(fp2);

		remove("Users.txt");

		rename("temp.txt", "Users.txt");

		f = fopen("Users.txt", "r");

		c = getc(f);

		while (c != EOF) {

			printf("%c", c);

			c = getc(f);

		}

	}
	fclose(f);

}

void Find()

{

	FILE* f;
	int i = 0;



	if (!(f = fopen("Users.txt", "rt")))

	{

		printf("Could Not Open File");

	}

	char word[20];

	printf("Enter abonent:");

	scanf("%s", &word);

	ifstream input("Users.txt");

	char buffer[1024];

	while (input.getline(buffer, 1024)) {

		if (strstr(buffer, word))
		{
			printf("%s\n", buffer);
			i++;
		}
	}if (i == 0) printf("No such User\n");

	fclose(f);
	getchar();
}

int main()

{
	bool done = false;
	int com;
	
			do 
			{
				printf("Type Command:\n1)Add User\n2)Delete User\n3)Find User\n4)Show list\n5)Exit the programm\n");

			scanf("%d", &com);

			switch (com)

			{

			case 1:

				Add();
				getchar();
				system("cls");
				break;

			case 2:

				Del();
				getchar();
				system("cls");
				break;

			case 3:
				Find();
				getchar();
				system("cls");
				break;
			case 4:
				Show();
				getchar();
				system("cls");
				break;
			case 5:
				done = true;
				exit(0);
			default:
				printf("Incorrect command\n");
				getchar();
				system("cls");
				break;
			
			}

			} while (!done);
	return 0;

}
