#include <iostream>
#include <vector>
#include <Windows.h>
#include <conio.h>
#include <fstream>
#include <iomanip>
using namespace std;

// gotoxy 함수
void gotoxy(int x, int y) {
	COORD Pos;
	Pos.X = x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

class Grade {
public:
	int student_num;
	string name;
	int scores[10];
public:
	void create_student();
};
void Grade::create_student() {

	system("cls");
	int i, j;
	int x = 9;
	int y = 4;
	char flag;

	int studentMenuSelect = 0;

	gotoxy(x, y);
	printf("┌");
	for (i = 0; i < 98; i++) {
		printf("─");
	}
	printf("┐");

	for (i = 0; i < 30; i++) {
		y++;
		gotoxy(x, y);
		printf("│");

		x += 99;
		gotoxy(x, y);
		printf("│");
		x = 9;
	}
	gotoxy(x, y);
	printf("└");
	for (i = 0; i < 98; i++) {
		printf("─");
	}
	printf("┘\n\n\n");

	for (j = 0; j < 30; j++) {
		if (j == 8) {
			gotoxy(50, j);
			printf("학생 성적 입력하기");
		}
		if (j == 12) {
			gotoxy(48, j);
			printf("학번 : ");
			cin >> student_num;
		}
		if (j == 14) {
			gotoxy(48, j);
			printf("이름 : ");
			cin >> name;
		}
		if (j == 16) {
			gotoxy(40, j);
			printf("국어 : ");
			cin >> scores[0];
		}
		if (j == 18) {
			gotoxy(40, j);
			printf("수학 : ");
			cin >> scores[1];
		}
		if (j == 20) {
			gotoxy(40, j);
			printf("사회 : ");
			cin >> scores[2];
		}
		if (j == 22) {
			gotoxy(40, j);
			printf("과학 : ");
			cin >> scores[3];
		}
		if (j == 24) {
			gotoxy(40, j);
			printf("영어 : ");
			cin >> scores[4];
		}
		if (j == 16) {
			gotoxy(60, j);
			printf("JAVA : ");
			cin >> scores[5];
		}
		if (j == 18) {
			gotoxy(60, j);
			printf("C++ : ");
			cin >> scores[6];
		}
		if (j == 20) {
			gotoxy(60, j);
			printf("Python : ");
			cin >> scores[7];
		}
		if (j == 22) {
			gotoxy(60, j);
			printf("웹서버 : ");
			cin >> scores[8];
		}
		if (j == 24) {
			gotoxy(60, j);
			printf("자료구조 : ");
			cin >> scores[9];
		}
		if (j == 27) {
			gotoxy(33, j);
			cout << student_num << " " << name << " 학생의 점수를 다시 확인해주세요 (Y/N) : ";
			cin >> flag;
			if (flag == 'Y' || flag == 'y') {

			}
			else {

			}
		}
	}
}

void keyInput(char key) {
	if (key == 224 || key == 0) {
		switch (key) {
		case 72:
			printf("위");
		case 75:
			printf("왼쪽");
		case 77 : 
			printf("오른쪽");
		case 80:
			printf("아래");
		}
	}
}

// 함수 정의
void MainPage();
void StudentPage();
void TeacherPage();
void writeGrade();

// 학생 메인 페이지 함수
void StudentPage() {
	system("cls");
	int i;
	int x = 9;
	int y = 4;

	int studentMenuSelect = 0;

	gotoxy(x, y);
	printf("┌");
	for (i = 0; i < 98; i++) {
		printf("─");
	}
	printf("┐");

	for (i = 0; i < 30; i++) {
		y++;
		gotoxy(x, y);
		printf("│");

		if (i == 14) {
			gotoxy(48, i);
			printf("학생 메뉴");
		}
		if (i == 18) {
			gotoxy(53, i);
			printf("01. 성적보기");
		}
		if (i == 20) {
			gotoxy(53, i);
			printf("02. 의의신청하기");
		}
		if (i == 22) {
			gotoxy(53, i);
			printf("03. 뒤로가기");
		}

		x += 99;
		gotoxy(x, y);
		printf("│");
		x = 9;
	}
	gotoxy(x, y);
	printf("└");
	for (i = 0; i < 98; i++) {
		printf("─");
	}
	printf("┘\n\n\n");

	gotoxy(53, 25);
	printf("번호 입력 : ");
	scanf_s("%d", &studentMenuSelect);
	while (true) {
		switch (studentMenuSelect) {
		case 1:break;
		case 2:break;
		case 3: MainPage(); break;
		default:
			gotoxy(47, 27);
			printf("존재하지 않는 메뉴입니다");
			gotoxy(53, 25);
			printf("번호 입력 : ");
			scanf_s("%d", &studentMenuSelect);
		}
	}
	
}

// 교사 메인 페이지 함수
void TeacherPage() {
	system("cls");
	int i;
	int x = 9;
	int y = 4;

	int teacherMenuSelect = 0;

	gotoxy(x, y);
	printf("┌");
	for (i = 0; i < 98; i++) {
		printf("─");
	}
	printf("┐");

	for (i = 0; i < 30; i++) {
		y++;
		gotoxy(x, y);
		printf("│");

		if (i == 10) {
			gotoxy(54, i);
			printf("교사메뉴");
		}
		if (i == 14) {
			gotoxy(46, i);
			printf("01. 전체 학생 성적 보기");
		}
		if (i == 16) {
			gotoxy(46, i);
			printf("02. 학생 검색하기");
		}
		if (i == 18) {
			gotoxy(46, i);
			printf("03. 학생 성적 입력하기");
		}
		if (i == 20) {
			gotoxy(46, i);
			printf("04. 학생 성적 수정하기");
		}
		if (i == 22) {
			gotoxy(46, i);
			printf("05. 의의신청 목록 보기");
		}
		if (i == 24) {
			gotoxy(46, i);
			printf("06. 뒤로가기");
		}

		x += 99;
		gotoxy(x, y);
		printf("│");
		x = 9;
	}

	gotoxy(x, y);
	printf("└");
	for (i = 0; i < 98; i++) {
		printf("─");
	}
	printf("┘\n\n\n");

	gotoxy(53, 27);
	printf("번호 입력 : ");
	scanf_s("%d", &teacherMenuSelect);
	switch (teacherMenuSelect) {
	case 1:break;
	case 2:break;
	case 3:writeGrade(); break;
	case 4:break;
	case 5:break;
	case 6: MainPage(); break;
	default:
		gotoxy(47, 29);
		printf("존재하지 않는 메뉴입니다");
		gotoxy(53, 27);
		printf("번호 입력 : ");
		scanf_s("%d", &teacherMenuSelect);
	}
}

// 메인화면 (첫화면) 함수
void MainPage() {
	system("mode con:cols=120 lines=40");

	int i;
	int x = 9;
	int y = 4;

	int menuSelect = 0;

	gotoxy(x, y);
	printf("┌");
	for (i = 0; i < 98; i++) {
		printf("─");
	}
	printf("┐");

	for (i = 0; i < 30; i++) {
		y++;
		gotoxy(x, y);
		printf("│");

		if (i == 14) {
			gotoxy(48, i);
			printf("학생 성적 관리 프로그램");
		}
		if (i == 18) {
			gotoxy(53, i);
			printf("01. 학생메뉴");
		}
		if (i == 20) {
			gotoxy(53, i);
			printf("02. 교사메뉴");
		}

		x += 99;
		gotoxy(x, y);
		printf("│");
		x = 9;
	}
	gotoxy(x, y);
	printf("└");
	for (i = 0; i < 98; i++) {
		printf("─");
	}
	printf("┘\n\n\n");

	gotoxy(53, 23);
	printf("번호 입력 : ");
	scanf_s("%d", &menuSelect);
	if (menuSelect == 1) {
		StudentPage();
	}
	else if (menuSelect == 2) {
		TeacherPage();
	}
	else if (typeid(menuSelect).name() == "int") {
		gotoxy(47, 18);
		printf("존재하지 않는 메뉴입니다");
	}
	else {
		gotoxy(47, 18);
		printf("숫자를 입력해주세요");
	}
}
void writeGrade() {
	Grade g;
	g.create_student();
	ofstream fout("first_grade.txt", std::ios::app);
	fout << g.name << setw(10) << g.student_num << setw(10) <<
		g.scores[0] << setw(10) << g.scores[1] << setw(10) << g.scores[2] << setw(10) <<
		g.scores[3] << setw(10) << g.scores[4] << setw(10) << g.scores[5] << setw(10) <<
		g.scores[6] << setw(10) << g.scores[7] << setw(10) << g.scores[8] << setw(10) << g.scores[9] << setw(10) << endl;

	//fout.write(reinterpret_cast<char*> (&g), sizeof(Grade));
	fout.close();
}
int main() {
	MainPage();
	return 0;
}