#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct book { // ����ü ����, å�̸�, ���ڸ�, ����⵵, ȸ���, �帣
	char book_name[30];
	char authr_name[30];
	char year[10];
	char comp_name[20];
	char genre[20];
} book;

int add_book(book *book_list, int *nth); // �����߰�
int search_book(book* book_list, int num_total); // �˻� �Լ�
int print_book_list(book* book_list, int num_total); // å ����Ʈ �����ֱ�
int book_revise(book* book_list, int num_total);

int main() {
	int book_save_num = 100;
	int book_num_total = 0;
	int user_choice;
	book* book_list;

	book_list = (book *)malloc(sizeof(book) * book_save_num);
	
	FILE* fp;
	fp = fopen("input.txt", "r");
	for (int i = 0; i < 6; i++)
	{
		fscanf(fp, "%s %s %s %s %s", book_list[i].book_name, book_list[i].authr_name, book_list[i].year, book_list[i].comp_name, book_list[i].genre);
		book_num_total++;
	}
	

	while (1)
	{
		
		
		printf("\n�������� ���α׷�\n");
		printf("�޴��� �����ϼ���.\n");
		printf("1. �����߰�\n");
		printf("2. �����˻�\n");
		printf("3. ��������\n");
		printf("4. ��������\n");
		printf("5. �� ���� ��� ���\n");
		printf("6. ����\n");
		printf("7. ���α׷� ����(�ڵ�����)\n");

		printf("�޴� ���� : ");
		scanf("%d", &user_choice);

		if (user_choice == 1)
		{
			add_book(book_list, &book_num_total);
		}
		else if (user_choice == 2)
		{
			search_book(book_list, book_num_total);
		}
		else if (user_choice == 3)
		{
			book_revise(book_list, &book_num_total);
		}
		else if (user_choice == 4)
		{
			//remove_book(book_list, &book_num_total);
			int num;
			printf("������ å�� ��ȣ�� �Է��ϼ��� : ");
			scanf("%d", &num);
			for (int i = num; i < book_num_total; i++)
			{
				book_list[i] = book_list[i + 1];
			}
			--book_num_total;
			printf("å�� �����Ͽ����ϴ�\n");
		}
		else if (user_choice == 5)
		{
			for (int i = 0; i < book_num_total; i++)
			{
				printf("å��ȣ %d : %s %s %s %s %s\n",i, book_list[i].book_name, book_list[i].authr_name, book_list[i].year, book_list[i].comp_name, book_list[i].genre);
			}
		}
		else if (user_choice == 6)
		{
			FILE* fp1 = fopen("input.txt", "r+");
			for (int i = 0; i < book_num_total; i++)
			{
				fscanf(fp1, "%s %s %s %s %s", book_list[i].book_name, book_list[i].authr_name, book_list[i].year, book_list[i].comp_name, book_list[i].genre);
				fprintf(fp1, "%s %s %s %s %s", book_list[i].book_name, book_list[i].authr_name, book_list[i].year, book_list[i].comp_name, book_list[i].genre);
				book_num_total++;
			}
		}
		else if (user_choice == 7)
		{
			printf("���α׷� ����\n");
			FILE* fp1 = fopen("input.txt", "r+");
			for (int i = 0; i < book_num_total; i++)
			{
				fscanf(fp1, "%s %s %s %s %s", book_list[i].book_name, book_list[i].authr_name, book_list[i].year, book_list[i].comp_name, book_list[i].genre);
				fprintf(fp1, "%s %s %s %s %s", book_list[i].book_name, book_list[i].authr_name, book_list[i].year, book_list[i].comp_name, book_list[i].genre);
				book_num_total++;
			}

			fclose(fp);
			fclose(fp1);
			break;
		}
		else
		{
			printf("�߸� �Է��ϼ̽��ϴ�.\n");
		}
	}
		
}

int add_book(book* book_list, int* nth) { // ����ü �ϰ� å�� ���ڸ� ��Ÿ���� ����
	printf("å�� �̸� : ");
	scanf("%s", book_list[*nth].book_name);
	printf("������ �̸� : ");
	scanf("%s", book_list[*nth].authr_name);
	printf("���ǳ⵵ : ");
	scanf("%s", book_list[*nth].year);
	printf("���ǻ� �̸� : ");
	scanf("%s", book_list[*nth].comp_name);
	printf("å�� �帣 : ");
	scanf("%s", book_list[*nth].genre);

	(*nth)++;
}

int search_book(book* book_list, int num_total) {
	int user_input;
	int i;
	char user_search[30];
	printf("� ������� �˻��Ͻðڽ��ϱ� : \n");
	printf("1. å���� �˻� \n");
	printf("2. ���ڸ� �˻� \n");
	printf("3. ���ǳ⵵ �˻� \n");
	printf("4. ���ǻ�� �˻� \n");
	printf("5. �帣 �˻� \n");
	scanf("%d", & user_input);

	printf("�˻�� �Է����ּ��� : ");
	scanf("%s" , user_search);
	printf("�˻� ��� \n");

	if (user_input == 1)
	{
		for (i = 0; i < num_total; i++) {
			if (strcmp(book_list[i].book_name, user_search) == 0)
			{
				printf("��ȣ : %d \n ���� : %s \n ���� : %s \n ���ǳ⵵ : %s \n ���ǻ� : %s \n �帣 : %s \n",i+1, book_list[i].book_name, book_list[i].authr_name, book_list[i].year, book_list[i].comp_name, book_list[i].genre);
			}
			else{printf("�˻��Ͻ� å�� �����ϴ�.\n");}
		}
	}
	else if (user_input == 2)
	{
		for (i = 0; i < num_total; i++) {
			if (strcmp(book_list[i].authr_name, user_search) == 0)
			{
				printf("��ȣ : %d \n ���� : %s \n ���� : %s \n ���ǳ⵵ : %s \n ���ǻ� : %s \n �帣 : %s \n", i + 1, book_list[i].book_name, book_list[i].authr_name, book_list[i].year, book_list[i].comp_name, book_list[i].genre);
			}
			else { printf("�˻��Ͻ� å�� �����ϴ�.\n"); }
		}
	}
	else if (user_input == 3)
	{
		for (i = 0; i < num_total; i++) {
			if (strcmp(book_list[i].year, user_search) == 0)
			{
				printf("��ȣ : %d \n ���� : %s \n ���� : %s \n ���ǳ⵵ : %s \n ���ǻ� : %s \n �帣 : %s \n", i + 1, book_list[i].book_name, book_list[i].authr_name, book_list[i].year, book_list[i].comp_name, book_list[i].genre);
			}
			else { printf("�˻��Ͻ� å�� �����ϴ�.\n"); }
		}
	}
	else if (user_input == 4)
	{
		for (i = 0; i < num_total; i++) {
			if (strcmp(book_list[i].comp_name, user_search) == 0)
			{
				printf("��ȣ : %d \n ���� : %s \n ���� : %s \n ���ǳ⵵ : %s \n ���ǻ� : %s \n �帣 : %s \n", i + 1, book_list[i].book_name, book_list[i].authr_name, book_list[i].year, book_list[i].comp_name, book_list[i].genre);
			}
			else { printf("�˻��Ͻ� å�� �����ϴ�.\n"); }
		}
	}
	else if (user_input == 5)
	{
		for (i = 0; i < num_total; i++) {
			if (strcmp(book_list[i].genre, user_search) == 0)
			{
				printf("��ȣ : %d \n ���� : %s \n ���� : %s \n ���ǳ⵵ : %s \n ���ǻ� : %s \n �帣 : %s \n", i + 1, book_list[i].book_name, book_list[i].authr_name, book_list[i].year, book_list[i].comp_name, book_list[i].genre);
			}
			else { printf("�˻��Ͻ� å�� �����ϴ�.\n"); }
		}
	}
	return 0;
}

int book_revise(book* book_list, int num_total) {
	char *revise[30];
	int i;
	printf("�����ϰ� ���� å�� ��ȣ�� �����ϼ��� : ");
	scanf("%d", &i);
	printf("�� Ȯ�ο� : %s\n", book_list[i].book_name);
	
	printf("å�� �̸� : ");
	scanf("%s", revise);
	strcpy(book_list[i].book_name, revise);
	printf("������ �̸� : ");
	scanf("%s", revise);
	strcpy(book_list[i].authr_name, revise);
	printf("���ǳ⵵ : ");
	scanf("%s", revise);
	strcpy(book_list[i].year, revise);
	printf("���ǻ� �̸� : ");
	scanf("%s", revise);
	strcpy(book_list[i].comp_name, revise);
	printf("å�� �帣 : ");
	scanf("%s", revise);
	strcpy(book_list[i].genre, revise);
}

int print_book_list(book* book_list, int num_total) {
	FILE* fp;
	errno_t err = fopen_s(&fp, "input.txt", "w");
	if (err == 0)
	{
		printf("����\n");
	}
	else
	{
		printf("error\n");
		return	0;
	}

	fprintf(fp, "%d\n", num_total);
	for (int i = 0; i < num_total; i++)
	{
		fprintf(fp, "s \n %s \n %s \n %s \n %s \n", book_list[i].book_name, book_list[i].authr_name, book_list[i].year, book_list[i].comp_name, book_list[i].genre);
	}
	fclose(fp);
	
}