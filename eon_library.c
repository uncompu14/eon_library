#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct book { // 구조체 선언, 책이름, 저자명, 발행년도, 회사명, 장르
	char book_name[30];
	char authr_name[30];
	char year[10];
	char comp_name[20];
	char genre[20];
} book;

int add_book(book *book_list, int *nth); // 내용추가
int search_book(book* book_list, int num_total); // 검색 함수
int print_book_list(book* book_list, int num_total); // 책 리스트 보여주기
int book_revise(book* book_list, int num_total); //책 내용 수정

int main() {
	int book_save_num = 100;
	int book_num_total = 0;
	int user_choice;
	book* book_list;

	book_list = (book*)malloc(sizeof(book) * book_save_num);

	FILE* fp;
	fp = fopen("input.txt", "rt");
		
	for(int i = 0; i < book_save_num; i ++) //최대 저장가능한 책의 갯수만큼 반복
	{
		if (feof(fp) == 0) // input.txt가 끝이 나지 않았다면 실행.
		{
			fscanf(fp, "%s %s %s %s %s\n", book_list[i].book_name, book_list[i].authr_name, book_list[i].year, book_list[i].comp_name, book_list[i].genre);
			++book_num_total;
		}		
	}
	
	

	while (1) 
	{
		printf("\n도서관리 프로그램\n");
		printf("메뉴를 선택하세요.\n");
		printf("1. 도서추가\n");
		printf("2. 도서검색\n");
		printf("3. 도서수정\n");
		printf("4. 도서삭제\n");
		printf("5. 총 도서 목록 출력\n");
		printf("6. 저장\n");
		printf("7. 프로그램 종료(자동저장)\n");

		printf("메뉴 선택 : ");
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
			book_revise(book_list, book_num_total);
		}
		else if (user_choice == 4)//삭제할 책번호 입력시 총 책의 갯수를 하나 줄여주고 삭제할 책의 뒷번호 책들을 앞으로 당겨와줌.
		{
			int num;
			printf("삭제할 책번호를 입력하세요(ex : 백년아이 책번호는 0) : ");
			scanf("%d", &num);
			for (int i = num; i < book_num_total; i++)
			{
				book_list[i] = book_list[i + 1];
			}
			--book_num_total;
			printf("책을 삭제하였습니다\n");
		}
		else if (user_choice == 5) // 총 책의 갯수만큼 printf 반복
		{
			for (int i = 0; i < book_num_total; i++)
			{
				printf("책번호 %d : %s %s %s %s %s\n",i, book_list[i].book_name, book_list[i].authr_name, book_list[i].year, book_list[i].comp_name, book_list[i].genre);
			}
		}
		else if (user_choice == 6) // wt모드를 사용하여 쓰기모드사용. 책의 갯수만큼 fprintf를 이용하여 메모장에 써줌.
		{
			FILE* fp1 = fopen("input.txt", "wt");
			for (int i = 0; i < book_num_total; i++)
			{
				fprintf(fp1, "%s %s %s %s %s\n", book_list[i].book_name, book_list[i].authr_name, book_list[i].year, book_list[i].comp_name, book_list[i].genre);
			}
			fclose(fp1);
		}
		else if (user_choice == 7) // 자동저장 후 종류
		{
			printf("프로그램 종료\n");
			FILE* fp1 = fopen("input.txt", "wt");
			for (int i = 0; i < book_num_total; i++)
			{
				fprintf(fp1, "%s %s %s %s %s\n", book_list[i].book_name, book_list[i].authr_name, book_list[i].year, book_list[i].comp_name, book_list[i].genre);
			}
			fclose(fp);
			fclose(fp1);
			break;
		}
		else
		{
			printf("잘못 입력하셨습니다.\n");
		}
	}
	
	return 0;
}

int add_book(book* book_list, int* nth) { // 구조체 북과 책의 숫자를 나타내는 변수
	printf("책의 이름 : ");
	scanf("%s", book_list[*nth].book_name);
	printf("저자의 이름 : ");
	scanf("%s", book_list[*nth].authr_name);
	printf("출판년도 : ");
	scanf("%s", book_list[*nth].year);
	printf("출판사 이름 : ");
	scanf("%s", book_list[*nth].comp_name);
	printf("책의 장르 : ");
	scanf("%s", book_list[*nth].genre);

	(*nth)++;
	return 0;
} //책의 내용을 추가

int search_book(book* book_list, int num_total) { //먼저 어떤 기능으로 찾을지 확인 후 문자열 비교 함수를 이용해서 검색
	int user_input;
	int i;
	char user_search[30];
	printf("어떤 기능으로 검색하시겠습니까 : \n");
	printf("1. 책제목 검색 \n");
	printf("2. 저자명 검색 \n");
	printf("3. 출판년도 검색 \n");
	printf("4. 출판사명 검색 \n");
	printf("5. 장르 검색 \n");
	scanf("%d", & user_input);

	printf("검색어를 입력해주세요 : ");
	scanf("%s" , user_search);
	printf("검색 결과 \n");

	if (user_input == 1)
	{
		for (i = 0; i < num_total; i++) {
			if (strcmp(book_list[i].book_name, user_search) == 0)
			{
				printf("번호 : %d \n 제목 : %s \n 저자 : %s \n 출판년도 : %s \n 출판사 : %s \n 장르 : %s \n",i+1, book_list[i].book_name, book_list[i].authr_name, book_list[i].year, book_list[i].comp_name, book_list[i].genre);
			}
			else{printf("검색하신 책이 없습니다.\n");}
		}
	}
	else if (user_input == 2)
	{
		for (i = 0; i < num_total; i++) {
			if (strcmp(book_list[i].authr_name, user_search) == 0)
			{
				printf("번호 : %d \n 제목 : %s \n 저자 : %s \n 출판년도 : %s \n 출판사 : %s \n 장르 : %s \n", i + 1, book_list[i].book_name, book_list[i].authr_name, book_list[i].year, book_list[i].comp_name, book_list[i].genre);
			}
			else { printf("검색하신 책이 없습니다.\n"); }
		}
	}
	else if (user_input == 3)
	{
		for (i = 0; i < num_total; i++) {
			if (strcmp(book_list[i].year, user_search) == 0)
			{
				printf("번호 : %d \n 제목 : %s \n 저자 : %s \n 출판년도 : %s \n 출판사 : %s \n 장르 : %s \n", i + 1, book_list[i].book_name, book_list[i].authr_name, book_list[i].year, book_list[i].comp_name, book_list[i].genre);
			}
			else { printf("검색하신 책이 없습니다.\n"); }
		}
	}
	else if (user_input == 4)
	{
		for (i = 0; i < num_total; i++) {
			if (strcmp(book_list[i].comp_name, user_search) == 0)
			{
				printf("번호 : %d \n 제목 : %s \n 저자 : %s \n 출판년도 : %s \n 출판사 : %s \n 장르 : %s \n", i + 1, book_list[i].book_name, book_list[i].authr_name, book_list[i].year, book_list[i].comp_name, book_list[i].genre);
			}
			else { printf("검색하신 책이 없습니다.\n"); }
		}
	}
	else if (user_input == 5)
	{
		for (i = 0; i < num_total; i++) {
			if (strcmp(book_list[i].genre, user_search) == 0)
			{
				printf("번호 : %d \n 제목 : %s \n 저자 : %s \n 출판년도 : %s \n 출판사 : %s \n 장르 : %s \n", i + 1, book_list[i].book_name, book_list[i].authr_name, book_list[i].year, book_list[i].comp_name, book_list[i].genre);
			}
			else { printf("검색하신 책이 없습니다.\n"); }
		}
	}
	return 0;
}

int book_revise(book* book_list, int num_total) { //수정할 책의 번호 선택후 수정할 내용 입력하면 복사하여 넣어주기.
	char revise[30];
	int i;
	printf("수정하고 싶은 책의 번호를 선택하세요 : ");
	scanf("%d", &i);
	
	printf("책의 이름 : ");
	scanf("%s", revise);
	strcpy(book_list[i].book_name, revise);
	printf("저자의 이름 : ");
	scanf("%s", revise);
	strcpy(book_list[i].authr_name, revise);
	printf("출판년도 : ");
	scanf("%s", revise);
	strcpy(book_list[i].year, revise);
	printf("출판사 이름 : ");
	scanf("%s", revise);
	strcpy(book_list[i].comp_name, revise);
	printf("책의 장르 : ");
	scanf("%s", revise);
	strcpy(book_list[i].genre, revise);

	return 0;
}

