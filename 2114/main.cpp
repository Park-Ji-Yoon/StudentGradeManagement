#include <iostream>
#include <vector>
#include <Windows.h>
#include <conio.h>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

// 함수 정의
void MainPage();
void StudentPage();
void TeacherPage();
void WriteGrade();
int ChoiceGrade();
void ShowAllGrades();
void ShowGrade();
void ObjectionSuccess();
void ShowObjections();
void IsTeacher(); // 교사 비밀번호 입력 화면

// 교사 비밀번호
const string TEACHER_PASSWORD = "teacher";

// gotoxy 함수
void gotoxy(int x, int y) {
	COORD Pos;
	Pos.X = x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
class Objection {
public:
	string subject;
	int student_num;
	string reason;
	Objection(int student_num, string subject, string reason) {
		this->subject = subject;
		this->student_num = student_num;
		this->reason = reason;
	}
	boolean makeObjection();
	Objection writeObjection();
};
boolean Objection::makeObjection() {
	int flag = ChoiceGrade();
	if (flag == 1) {
		Objection ob = writeObjection();
		ofstream fout("first_grade_objection.txt", ios::app);
		fout << ob.student_num << setw(20) << ob.subject << setw(30) << ob.reason << endl;
		ObjectionSuccess();
	}
	else if (flag == 1) {
		Objection ob = writeObjection();
		ofstream fout("second_grade_objection.txt", ios::app);
		fout << ob.student_num << setw(20) << ob.subject << setw(30) << ob.reason << endl;
		ObjectionSuccess();
	}
	else {
		Objection ob = writeObjection();
		ofstream fout("third_grade_objection.txt", ios::app);
		fout << ob.student_num << setw(20) << ob.subject << setw(30) << ob.reason << endl;
		ObjectionSuccess();
	}
	return false;
}
Objection Objection::writeObjection() {
	int student_num;
	string subject;
	string reson;

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
		if (j == 14) {
			gotoxy(35, j);
			cout << "학번을 입력해주세요 : ";
			cin >> student_num;
			string remainder;
			getline(cin, remainder);
		}
		if (j == 16) {
			gotoxy(35, j);
			cout << "의의신청할 과목을 입력해주세요 : ";
			getline(cin, subject, '\n'); // 띄워쓰기 해도 입력 가능
		}
		if (j == 18) {
			gotoxy(35, j);
			cout << "이유를 적어주세요(최대 50자) : ";
			getline(cin, reason); // 띄워쓰기 해도 입력 가능
		}
	}
	Objection ob(student_num, subject, reason);
	return ob;
}
void ObjectionSuccess() {
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

	boolean success = true;

	for (j = 0; j < 30; j++) {
		if (j == 15) {
			while (success == true) {
				gotoxy(45, j);
				cout << "의의신청이 완료되었습니다!!" << endl;
				gotoxy(30, 17);
				cout << "(0 입력 : 메인화면, 1 입력 : 학생메뉴, 2 입력 : 의의신청하기) : ";
				cin >> studentMenuSelect;
				if (studentMenuSelect == 0) {
					success == false;
					MainPage();
				}
				else if (studentMenuSelect == 1) {
					success == false;
					StudentPage();
				}
				else if (studentMenuSelect == 2) {
					success = false;
					Objection ob(0, "", "");
					ob.makeObjection();
				}
				else {
					gotoxy(45, 18);
					cout << "0이나 1을 입력해주세요" << endl;
				}
			}
		}
	}
}
class Grade {
public:
	int student_num;
	string name;
	void create_student();
	void showGrade();
};
// 1학년 클래스
class First_Grade : Grade {
public:
	int student_num;
	string name;
	int first_scores[8];
	void create_student();
	void showGrade();
};
// 2학년 클래스
class Second_Grade : Grade {
public:
	int student_num;
	string name;
	int second_scores[10];
	void create_student();
	void showGrade();
};
class Third_Grade : Grade {
public:
	int student_num;
	string name;
	int third_scores[9];
	void create_student();
	void showGrade();
};
void First_Grade::create_student() {

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
			cin >> first_scores[0];
		}
		if (j == 18) {
			gotoxy(40, j);
			printf("영어 : ");
			cin >> first_scores[2];
		}
		if (j == 20) {
			gotoxy(40, j);
			printf("한국사 : ");
			cin >> first_scores[4];
		}
		if (j == 22) {
			gotoxy(40, j);
			printf("C언어 : ");
			cin >> first_scores[6];
		}
		if (j == 16) {
			gotoxy(60, j);
			printf("수학 : ");
			cin >> first_scores[1];
		}
		if (j == 18) {
			gotoxy(60, j);
			printf("사회 : ");
			cin >> first_scores[3];
		}
		if (j == 20) {
			gotoxy(60, j);
			printf("JAVA : ");
			cin >> first_scores[5];
		}
		if (j == 22) {
			gotoxy(60, j);
			printf("컴퓨터 구조 : ");
			cin >> first_scores[7];
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
void Second_Grade::create_student() {

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
			cin >> second_scores[0];
		}
		if (j == 18) {
			gotoxy(40, j);
			printf("수학 : ");
			cin >> second_scores[1];
		}
		if (j == 20) {
			gotoxy(40, j);
			printf("사회 : ");
			cin >> second_scores[2];
		}
		if (j == 22) {
			gotoxy(40, j);
			printf("과학 : ");
			cin >> second_scores[3];
		}
		if (j == 24) {
			gotoxy(40, j);
			printf("영어 : ");
			cin >> second_scores[4];
		}
		if (j == 16) {
			gotoxy(60, j);
			printf("JAVA : ");
			cin >> second_scores[5];
		}
		if (j == 18) {
			gotoxy(60, j);
			printf("C++ : ");
			cin >> second_scores[6];
		}
		if (j == 20) {
			gotoxy(60, j);
			printf("Python : ");
			cin >> second_scores[7];
		}
		if (j == 22) {
			gotoxy(60, j);
			printf("웹서버 : ");
			cin >> second_scores[8];
		}
		if (j == 24) {
			gotoxy(60, j);
			printf("자료구조 : ");
			cin >> second_scores[9];
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
void Third_Grade::create_student() {

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
			cin >> third_scores[0];
		}
		if (j == 18) {
			gotoxy(40, j);
			printf("수학 : ");
			cin >> third_scores[1];
		}
		if (j == 20) {
			gotoxy(40, j);
			printf("영어 : ");
			cin >> third_scores[2];
		}
		if (j == 22) {
			gotoxy(40, j);
			printf("Nodejs : ");
			cin >> third_scores[3];
		}
		if (j == 24) {
			gotoxy(40, j);
			printf("Spring : ");
			cin >> third_scores[4];
		}
		if (j == 16) {
			gotoxy(60, j);
			printf("JAVA : ");
			cin >> third_scores[5];
		}
		if (j == 18) {
			gotoxy(60, j);
			printf("C++ : ");
			cin >> third_scores[6];
		}
		if (j == 20) {
			gotoxy(60, j);
			printf("Python : ");
			cin >> third_scores[7];
		}
		if (j == 22) {
			gotoxy(60, j);
			printf("웹서버 : ");
			cin >> third_scores[8];
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

void IsTeacher() {
	system("cls");
	int i;
	int x = 9;
	int y = 4;

	string teacherPw;

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

	for (int k = 0; k < 30; k++) {
		if (k == 17) {
			while (teacherPw != TEACHER_PASSWORD) {
				gotoxy(47, k + 5);
				cout << "(뒤로가려면 0입력)" << endl;
				gotoxy(35, k);
				cout << "교사 비밀번호를 입력해주세요 : ";
				cin >> teacherPw;
				if (teacherPw == TEACHER_PASSWORD) {
					TeacherPage();
					break;
				}
				else if (teacherPw == "0") {
					MainPage();
					break;
				}
				else {
					gotoxy(45, k + 2);
					cout << "비밀번호가 틀렸습니다" << endl;
					gotoxy(35, k);
					cout << "교사 비밀번호를 입력해주세요 : ";
					cin >> teacherPw;
					gotoxy(47, k + 5);
					cout << "(뒤로가려면 0입력)" << endl;
					if (teacherPw == TEACHER_PASSWORD) {
						TeacherPage();
						break;
					}
					else if (teacherPw == "0") {
						MainPage();
						break;
					}
				}
			}
		}
	}
}
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
			gotoxy(56, i);
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
		case 1:ShowGrade(); break;
		case 2: {
			Objection ob(0, "", ""); 
			ob.makeObjection(); 
			break;
		}	
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
	case 1:ShowAllGrades();  break;
	case 2:break;
	case 3:WriteGrade(); break;
	case 4:break;
	case 5: ShowObjections();  break;
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
void WriteGrade() {
	int flag = ChoiceGrade();
	if (flag == 1) {
		First_Grade g;
		g.create_student();
		ofstream fout("first_grade.txt", std::ios::app);
		fout << g.name << setw(7) << g.student_num << setw(7) <<
			g.first_scores[0] << setw(7) << g.first_scores[1] << setw(7) << g.first_scores[2] << setw(7) <<
			g.first_scores[3] << setw(7) << g.first_scores[7] << setw(7) << g.first_scores[5] << setw(7) <<
			g.first_scores[6] << setw(7) << g.first_scores[7] << endl;
		fout.close();
	}
	else if (flag == 2) {
		Second_Grade g;
		g.create_student();
		ofstream fout("second_grade.txt", std::ios::app);
		fout << g.name << setw(7) << g.student_num << setw(7) <<
			g.second_scores[0] << setw(10) << g.second_scores[1] << setw(10) << g.second_scores[2] << setw(7) <<
			g.second_scores[3] << setw(7) << g.second_scores[4] << setw(7) << g.second_scores[5] << setw(7) <<
			g.second_scores[6] << setw(7) << g.second_scores[7] << setw(7) << g.second_scores[8] << setw(7) << g.second_scores[9] << setw(5) << endl;
		fout.close();
	}
	else {
		Third_Grade g;
		g.create_student();
		ofstream fout("third_grade.txt", std::ios::app);
		fout << g.name << setw(7) << g.student_num << setw(7) <<
			g.third_scores[0] << setw(10) << g.third_scores[1] << setw(10) << g.third_scores[2] << setw(7) <<
			g.third_scores[3] << setw(7) << g.third_scores[4] << setw(7) << g.third_scores[5] << setw(7) <<
			g.third_scores[6] << setw(7) << g.third_scores[7] << setw(7) << g.third_scores[8] << setw(7) << endl;
		fout.close();
	}
}
int ChoiceGrade() {
	system("cls");

	int i;
	int x = 9;
	int y = 4;

	int gradeSelect = 0;

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

		if (i == 13) {
			gotoxy(48, i);
			printf("학년을 선택해주세요");
		}
		if (i == 17) {
			gotoxy(53, i);
			printf("01. 1학년");
		}
		if (i == 19) {
			gotoxy(53, i);
			printf("02. 2학년");
		}
		if (i == 21) {
			gotoxy(53, i);
			printf("03. 3학년");
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

	gotoxy(50, 25);
	printf("번호 입력 : ");
	scanf_s("%d", &gradeSelect);
	if (gradeSelect == 1) {
		return 1;
	}
	else if (gradeSelect == 2) {
		return 2;
	}
	else if (gradeSelect == 3) {
		return 3;
	}
	else {
		// 1, 2, 3 학년 이 아닌 다른 것을 선택했을 때 처리
	}
}
void ShowAllGrades() {
	int flag = ChoiceGrade();
	if (flag == 1) {
		system("cls");

		int i;
		int x = 9;
		int y = 4;

		int gradeSelect = 0;

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

			if (i == 5) {
				int j = 5;
				gotoxy(25, i);
				char inputString[1000];

				First_Grade fg;
				ifstream fin;
				fin.open("first_grade.txt");
				while (!fin.eof()) {
					j++;
					fin.getline(inputString, 100);
					gotoxy(25, j);
					cout << inputString << endl;
				}
				fin.close();
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
	}
	else if (flag == 2) {
		system("cls");

		int i;
		int x = 9;
		int y = 4;

		int gradeSelect = 0;

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

			if (i == 5) {
				int j = 5;
				gotoxy(25, i);
				char inputString[1000];

				First_Grade fg;
				ifstream fin;
				fin.open("second_grade.txt");
				while (!fin.eof()) {
					j++;
					fin.getline(inputString, 100);
					gotoxy(25, j);
					cout << inputString << endl;
				}
				fin.close();
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
	}
	else {
	system("cls");

	int i;
	int x = 9;
	int y = 4;

	int gradeSelect = 0;

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

		if (i == 5) {
			int j = 5;
			gotoxy(25, i);
			char inputString[1000];

			First_Grade fg;
			ifstream fin;
			fin.open("third_grade.txt");
			while (!fin.eof()) {
				j++;
				fin.getline(inputString, 100);
				gotoxy(25, j);
				cout << inputString << endl;
			}
			fin.close();
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
	}
}
void ShowGrade() {
	int flag = ChoiceGrade();
	int studnet_num;

	if(flag == 1){
		system("cls");

		int i;
		int x = 9;
		int y = 4;

		int gradeSelect = 0;

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
		gotoxy(45, 17);
		cout << "학번을 입력하세요 : ";
		cin >> studnet_num;
		// 파일에서 해당 학번에 대한 성적읽기=======================================================================
	}
	else if (flag == 2) {

	}
	else {

	}
}
// 교사 -> 의의신청 목록 보기
void ShowObjections() {
	int flag = ChoiceGrade();
	int student_num;
	char subject[20];
	char reason[100];

	if (flag == 1) {
		system("cls");
		int i;
		int x = 9;
		int y = 4;

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

		int count = 5;
		ifstream fin;
		fin.open("first_grade_objection.txt");

		char inputString[1000];
		while (!fin.eof()) {
			count++;
			fin.getline(inputString, 100);
			gotoxy(25, count);
			cout << inputString << endl;
		}
		//while (fin >> student_num >> subject >> reason) {
		//	gotoxy(15, count);
		//	/*printf("%8d%10s", student_num, subject);
		//	cout << reason << endl;*/
		//	cout << student_num << setw(20) << subject << setw(30) << reason << endl;
		//	count++;
		//}
		fin.close();
	}
	else if (flag == 2) {

	}
	else {

	}
}
int main() {
	MainPage();
	return 0;
}