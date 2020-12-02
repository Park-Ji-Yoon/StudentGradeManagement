#include <iostream>
#include <vector>
#include <Windows.h>
#include <conio.h>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

// 함수 정의
void MainPage(); // 메인 화면
void StudentPage(); // 학생 메인 화면
void TeacherPage(); // 교사 메인 화면
//void WriteGrade();
int ChoiceGrade(); // 학년 선택 화면
//void ShowAllGrades();
//void ShowGrade();

void GradeSuccess(); // 성적 입력 완료 화면
void ShowGrades(); // 성적 보는 화면

void ShowObjections(); // 의의신청 보는 화면
void ObjectionSuccess(); // 의의신청 완료 화면

void IsTeacher(); // 교사 비밀번호 입력 화면

void modityGrade(); // 학생 성적 수정

string searchGrade(int isStudent); // 학생 성적 검색해주는 함수

void showGrade(); // 학생 메뉴 => 학생 성적 보여주는 함수

void showGradeT(); // 교사 메뉴 => 학생 성적 보여주는 함수

void changeTeacherPW(); // 선생님 비밀번호 바꿔주는 함수 - 할 지 안 할지 고민 후 결정하기===================================================================================

// 교사 비밀번호
const string TEACHER_PASSWORD = "teacher";

// gotoxy 함수
void gotoxy(int x, int y) {
	COORD Pos;
	Pos.X = x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

// 성적 클래스
class Grade {
public:
	int student_num;
	string student_name;
	int score1; int score2; int score3; int score4; int score5;
	int score6; int score7; int score8; int score9; int score10;
	Grade(int student_num, string student_name, int score1, int score2, int score3, int score4, int score5, int score6, int score7, int score8, int score9, int score10) {
		this->student_num = student_num;
		this->student_name = student_name;
		this->score1 = score1;
		this->score2 = score2;
		this->score3 = score3;
		this->score4 = score4;
		this->score5 = score5;
		this->score6 = score6;
		this->score7 = score7;
		this->score8 = score8;
		this->score9 = score9;
		this->score10 = score10;
	}
	boolean makeGrade();
	Grade writeGrade(int flag);
	//void modityGrade();
};

// writeGrade에서 입력받은 성적을 파일에 출력
boolean Grade::makeGrade() {
	int flag = ChoiceGrade();
	if (flag == 1) {
		Grade g = writeGrade(1);
		ofstream fout("first_grade.txt", ios::app);
		fout << g.student_num << setw(10) << g.student_name << setw(7) << g.score1 << setw(7) << g.score2 << setw(7) 
			<< g.score3 << setw(7) << g.score4 << setw(7) << g.score7 << setw(7) << g.score6 << setw(7) << g.score7 
			<< setw(7) << g.score8 << setw(7) << endl;
		GradeSuccess();
	}
	else if (flag == 2) {
		Grade g = writeGrade(2);
		ofstream fout("second_grade.txt", ios::app);
		fout << g.student_num << setw(10) << g.student_name << setw(7) << g.score1 << setw(7) << g.score2 << setw(7)
			<< g.score3 << setw(7) << g.score4 << setw(7) << g.score5 << setw(7) << g.score6 << setw(8) << g.score7
			<< setw(8) << g.score8 << setw(8) << g.score9 << setw(7) << endl;
		GradeSuccess();
	}
	else {
		Grade g = writeGrade(3);
		ofstream fout("third_grade.txt", ios::app);
		fout << g.student_num << setw(10) << g.student_name << setw(7) << g.score1 << setw(7) << g.score2 << setw(7)
			<< g.score3 << setw(7) << g.score4 << setw(7) << g.score5 << setw(8) << g.score6 << setw(7) << g.score7
			<< setw(7) << g.score8 << setw(7) << setw(7) << endl;
		GradeSuccess();
	}
	return false;
}

// 성적 입력
Grade Grade::writeGrade(int flag) {
	if (flag == 1) {
		int student_num;
		string student_name;
		int score1 = 0; int score2 = 0; int score3 = 0; int score4 = 0; int score5 = 0;
		int score6 = 0; int score7 = 0; int score8 = 0; int score9 = 0; int score10 = 0;
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
				gotoxy(35, j);
				cout << "학번을 입력해주세요 : ";
				cin >> student_num;
				string remainder;
				getline(cin, remainder);
			}
			if (j == 10) {
				gotoxy(35, j);
				cout << "이름을 입력해주세요 : ";
				getline(cin, student_name, '\n'); // 띄워쓰기 해도 입력 가능
			}
			if (j == 12) {
				gotoxy(35, j);
				cout << "국어 : ";
				cin >> score1;
				string remainder;
				getline(cin, remainder);
			}
			if (j == 14) {
				gotoxy(35, j);
				cout << "수학 : ";
				cin >> score2;
				string remainder;
				getline(cin, remainder);
			}
			if (j == 16) {
				gotoxy(35, j);
				cout << "영어 : ";
				cin >> score3;
				string remainder;
				getline(cin, remainder);
			}
			if (j == 18) {
				gotoxy(35, j);
				cout << "사회 : ";
				cin >> score4;
				string remainder;
				getline(cin, remainder);
			}
			if (j == 20) {
				gotoxy(35, j);
				cout << "한국사 : ";
				cin >> score5;
				string remainder;
				getline(cin, remainder);
			}
			if (j == 22) {
				gotoxy(35, j);
				cout << "JAVA : ";
				cin >> score6;
				string remainder;
				getline(cin, remainder);
			}
			if (j == 24) {
				gotoxy(35, j);
				cout << "C언어 : ";
				cin >> score7;
				string remainder;
				getline(cin, remainder);
			}
			if (j == 26) {
				gotoxy(35, j);
				cout << "컴퓨터 구조 : ";
				cin >> score8;
				string remainder;
				getline(cin, remainder);
			}
		}
		Grade g(student_num, student_name, score1, score2, score3, score4, score5, score6, score7, score8, score9, score10);
		return g;
	}else if (flag == 2) {
		int student_num;
		string student_name;
		int score1 = 0; int score2 = 0; int score3 = 0; int score4 = 0; int score5 = 0;
		int score6 = 0; int score7 = 0; int score8 = 0; int score9 = 0; int score10 = 0;
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
				gotoxy(35, j);
				cout << "학번을 입력해주세요 : ";
				cin >> student_num;
				string remainder;
				getline(cin, remainder);
			}
			if (j == 10) {
				gotoxy(35, j);
				cout << "이름을 입력해주세요 : ";
				getline(cin, student_name, '\n'); // 띄워쓰기 해도 입력 가능
			}
			if (j == 12) {
				gotoxy(35, j);
				cout << "국어 : ";
				cin >> score1;
				string remainder;
				getline(cin, remainder);
			}
			if (j == 14) {
				gotoxy(35, j);
				cout << "수학 : ";
				cin >> score2;
				string remainder;
				getline(cin, remainder);
			}
			if (j == 16) {
				gotoxy(35, j);
				cout << "영어 : ";
				cin >> score3;
				string remainder;
				getline(cin, remainder);
			}
			if (j == 18) {
				gotoxy(35, j);
				cout << "과학 : ";
				cin >> score4;
				string remainder;
				getline(cin, remainder);
			}
			if (j == 20) {
				gotoxy(35, j);
				cout << "JSP : ";
				cin >> score5;
				string remainder;
				getline(cin, remainder);
			}
			if (j == 22) {
				gotoxy(35, j);
				cout << "JAVA : ";
				cin >> score6;
				string remainder;
				getline(cin, remainder);
			}
			if (j == 24) {
				gotoxy(35, j);
				cout << "C++ : ";
				cin >> score7;
				string remainder;
				getline(cin, remainder);
			}
			if (j == 26) {
				gotoxy(35, j);
				cout << "Python : ";
				cin >> score8;
				string remainder;
				getline(cin, remainder);
			}
			if (j == 28) {
				gotoxy(35, j);
				cout << "자료 구조 : ";
				cin >> score9;
				string remainder;
				getline(cin, remainder);
			}
		}
		Grade g(student_num, student_name, score1, score2, score3, score4, score5, score6, score7, score8, score9, score10);
		return g;
	}else {
		int student_num;
		string student_name;
		int score1 = 0; int score2 = 0; int score3 = 0; int score4 = 0; int score5 = 0;
		int score6 = 0; int score7 = 0; int score8 = 0; int score9 = 0; int score10 = 0;
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
				gotoxy(35, j);
				cout << "학번을 입력해주세요 : ";
				cin >> student_num;
				string remainder;
				getline(cin, remainder);
			}
			if (j == 10) {
				gotoxy(35, j);
				cout << "이름을 입력해주세요 : ";
				getline(cin, student_name, '\n'); // 띄워쓰기 해도 입력 가능
			}
			if (j == 12) {
				gotoxy(35, j);
				cout << "선택1 : ";
				cin >> score1;
				string remainder;
				getline(cin, remainder);
			}
			if (j == 14) {
				gotoxy(35, j);
				cout << "선택2 : ";
				cin >> score2;
				string remainder;
				getline(cin, remainder);
			}
			if (j == 16) {
				gotoxy(35, j);
				cout << "선택3 : ";
				cin >> score3;
				string remainder;
				getline(cin, remainder);
			}
			if (j == 18) {
				gotoxy(35, j);
				cout << "영어 : ";
				cin >> score4;
				string remainder;
				getline(cin, remainder);
			}
			if (j == 20) {
				gotoxy(35, j);
				cout << "사무관리 : ";
				cin >> score5;
				string remainder;
				getline(cin, remainder);
			}
			if (j == 22) {
				gotoxy(35, j);
				cout << "DB : ";
				cin >> score6;
				string remainder;
				getline(cin, remainder);
			}
			if (j == 24) {
				gotoxy(35, j);
				cout << "server : ";
				cin >> score7;
				string remainder;
				getline(cin, remainder);
			}
			if (j == 26) {
				gotoxy(35, j);
				cout << "Programming : ";
				cin >> score8;
				string remainder;
				getline(cin, remainder);
			}
		}
		Grade g(student_num, student_name, score1, score2, score3, score4, score5, score6, score7, score8, score9, score10);
		return g;
	}
}

// 성적 수정
void modityGrade() {
	int hakbun;
	string hakbun2;
	string line;
	int offset;

	// 학번 입력받기
	int flag = ChoiceGrade();

	// 해당 학번이 있는 줄에 엑세스하기
	if (flag == 1) {
		ifstream first_grade("first_grade.txt");
		cout << "자신의 학번을 입력하세요 : ";
		cin >> hakbun;
		hakbun2 = to_string(hakbun);

		while (!first_grade.eof()) {
			getline(first_grade, line);
			if ((offset = line.find(hakbun2, 0)) != string::npos) {
				cout << line << endl;
			}
		}
		first_grade.close();
	}
	
	// 무슨과목 바꿀 건지 물어보기
	// 점수 입력하기
	// 수정 완료
	FILE* p_file = NULL;
	char temp[256], * p;
	int find_pos;

	if (0 == fopen_s(&p_file, "first_grade.txt", "r+t")) {
		while (fgets(temp, 256, p_file) != NULL) {
			p = strstr(temp, "박지윤");
			if (p != NULL) {
				find_pos = strlen(temp) - (p - temp) + 1;
				fseek(p_file, (-1) * find_pos, SEEK_CUR);
				fwrite("일지윤", 4, 1, p_file);
				fseek(p_file, find_pos - 4, SEEK_CUR);
			}
		}
		fclose(p_file);
		//fout.seekp(-1, ios::end);
	}
}

// 학생 => 성적 보기
string searchGrade(int isStudent) {
	int flag = ChoiceGrade();
	string line;
	int hakbun;
	int offset;
	string hakbun2;

	int i, j;
	int x = 9;
	int y = 4;

	int where;

	boolean visible = false;

	system("cls");
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
	for (i = 0; i < 30; i++) {
		if (i == 13) {
			if (flag == 1) {
				ifstream first_grade("first_grade.txt");
				if (isStudent == 1) {
					gotoxy(45, i);
					cout << "자신의 학번을 입력하세요 : ";
				}
				else {
					gotoxy(40, i);
					cout << "검색을 원하는 학생의 학번을 입력하세요 : ";
				}
				cin >> hakbun;
				hakbun2 = to_string(hakbun);

				while (!first_grade.eof()) {
					getline(first_grade, line);
					if ((offset = line.find(hakbun2, 0)) != string::npos) {
						gotoxy(20, i + 3);
						cout << "학번     이름      국어   수학   영어   사회   국사   JAVA   C     컴퓨터 구조" << endl;
						gotoxy(20, i + 4);
						cout << line << endl;
						visible = true;
					}
				}
				if (visible == false) {
					gotoxy(40, i + 3);
					cout << "해당 학번에 입력된 성적이 없습니다" << endl;
				}
				first_grade.close();
				visible = false;
				return line;
			}
			else if (flag == 2) {
				gotoxy(45, i);
				ifstream second_grade("second_grade.txt");
				cout << "자신의 학번을 입력하세요 : ";
				cin >> hakbun;
				hakbun2 = to_string(hakbun);

				while (!second_grade.eof()) {
					getline(second_grade, line);
					if ((offset = line.find(hakbun2, 0)) != string::npos) {
						gotoxy(18, i + 3);
						cout << "학번     이름      국어   수학   영어   과학   JSP   JAVA     C++     Python  DS  " << endl;
						gotoxy(18, i + 4);
						cout << line << endl;
						visible = true;
					}
				}
				if (visible == false) {
					gotoxy(40, i + 3);
					cout << "해당 학번에 입력된 성적이 없습니다" << endl;
				}
				second_grade.close();
				visible = false;
				return line;
			}
			else {
				gotoxy(45, i);
				ifstream third_grade("third_grade.txt");
				cout << "자신의 학번을 입력하세요 : ";
				cin >> hakbun;
				hakbun2 = to_string(hakbun);

				while (!third_grade.eof()) {
					getline(third_grade, line);
					if ((offset = line.find(hakbun2, 0)) != string::npos) {
						gotoxy(20, i + 3);
						cout << "학번     이름     선택1  선택2  선택3  영어  사무관리  DB  server   Programming" << endl;
						gotoxy(20, i + 4);
						cout << line << endl;
						visible = true;
					}
				}
				if (visible == false) {
					gotoxy(40, i + 3);
					cout << "해당 학번에 입력된 성적이 없습니다" << endl;
				}
				third_grade.close();
				visible = false;
				return line;
			}
		}
	}
}

void showGrade() {
	string line = searchGrade(1);

	int i, j;
	int x = 9;
	int y = 4;
	char flag;

	int studentMenuSelect = 0;

	int where;

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
		if (j == 16) {
			gotoxy(35, j + 5);
			cout << "(0 : 메인화면, 1 : 학생화면, 2 : 다시 검색) : ";
			cin >> where;
		}
	}
	if (where == 0) {
		system("cls");
		MainPage();
	}
	else if (where == 1) {
		system("cls");
		StudentPage();
	}
	else if (where == 2) {
		system("cls");
		showGrade();
	}
	else {
		for (j = 0; j < 30; j++) {
			if (j == 16) {
				gotoxy(35, j + 5);
				cout << "존재하지 않는 메뉴입니다";
				gotoxy(35, j + 3);
				cout << "(0 : 메인화면, 1 : 학생화면, 2 : 다시 검색) : ";
				cin >> where;
			}
		}
	}
}

void showGradeT() {
	string line = searchGrade(0);

	int i, j;
	int x = 9;
	int y = 4;
	char flag;

	int studentMenuSelect = 0;

	int where;

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
		if (j == 16) {
			gotoxy(35, j + 5);
			cout << "(0 : 메인화면, 1 : 교사화면, 2 : 다시 검색) : ";
			cin >> where;
		}
	}
	if (where == 0) {
		system("cls");
		MainPage();
	}
	else if (where == 1) {
		system("cls");
		TeacherPage();
	}
	else if (where == 2) {
		system("cls");
		showGradeT();
	}
	else {
		for (j = 0; j < 30; j++) {
			if (j == 16) {
				gotoxy(35, j + 5);
				cout << "존재하지 않는 메뉴입니다";
				gotoxy(35, j + 3);
				cout << "(0 : 메인화면, 1 : 교사화면, 2 : 다시 검색) : ";
				cin >> where;
			}
		}
	}
}

// 성적 입력 완료 화면
void GradeSuccess() {
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
				cout << "성적입력이 완료되었습니다!!" << endl;
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
					int score1 = 0; int score2 = 0; int score3 = 0; int score4 = 0; int score5 = 0;
					int score6 = 0; int score7 = 0; int score8 = 0; int score9 = 0; int score10 = 0;
					Grade g(0, "", score1, score2, score3, score4, score5, score6, score7, score8, score9, score10);
					g.makeGrade();
				}
				else {
					gotoxy(45, 18);
					cout << "0이나 1을 입력해주세요" << endl;
				}
			}
		}
	}
} // end of GradeSuccess

// 의의신청 클래스
class Objection {
public:
	int student_num;
	string subject;
	string reason;
	Objection(int student_num, string subject, string reason) {
		this->subject = subject;
		this->student_num = student_num;
		this->reason = reason;
	}
	boolean makeObjection();
	Objection writeObjection();
}; // end of Objection (class)

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
} // end of Objection::makeObjection

// 의의신청 화면
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
} // end of Objection::writeObjection

// 의의신청 완료 화면
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
} // end of ObjectionSuccess

// 선생님인지 확인하는 창 (비밀번호 사용)
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
					cout << "(뒤로가려면 0 입력)" << endl;
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
} // end of IsTeacher

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
			//case 1:ShowGrade(); break;
		case 1: showGrade(); break;
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
	case 1:ShowGrades();  break;
	case 2:showGradeT();
	case 3: {
		int score1 = 0; int score2 = 0; int score3 = 0; int score4 = 0; int score5 = 0;
		int score6 = 0; int score7 = 0; int score8 = 0; int score9 = 0; int score10 = 0;
		Grade g(0, "", score1, score2, score3, score4, score5, score6, score7, score8, score9, score10);
		g.makeGrade();
		break;
	}
	case 4:modityGrade();  break;
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
//void WriteGrade() {
//	int flag = ChoiceGrade();
//	if (flag == 1) {
//		First_Grade g;
//		g.create_student();
//		ofstream fout("first_grade.txt", std::ios::app);
//		fout << g.name << setw(7) << g.student_num << setw(7) <<
//			g.first_scores[0] << setw(7) << g.first_scores[1] << setw(7) << g.first_scores[2] << setw(7) <<
//			g.first_scores[3] << setw(7) << g.first_scores[7] << setw(7) << g.first_scores[5] << setw(7) <<
//			g.first_scores[6] << setw(7) << g.first_scores[7] << endl;
//		fout.close();
//	}
//	else if (flag == 2) {
//		Second_Grade g;
//		g.create_student();
//		ofstream fout("second_grade.txt", std::ios::app);
//		fout << g.name << setw(7) << g.student_num << setw(7) <<
//			g.second_scores[0] << setw(10) << g.second_scores[1] << setw(10) << g.second_scores[2] << setw(7) <<
//			g.second_scores[3] << setw(7) << g.second_scores[4] << setw(7) << g.second_scores[5] << setw(7) <<
//			g.second_scores[6] << setw(7) << g.second_scores[7] << setw(7) << g.second_scores[8] << setw(7) << g.second_scores[9] << setw(5) << endl;
//		fout.close();
//	}
//	else {
//		Third_Grade g;
//		g.create_student();
//		ofstream fout("third_grade.txt", std::ios::app);
//		fout << g.name << setw(7) << g.student_num << setw(7) <<
//			g.third_scores[0] << setw(10) << g.third_scores[1] << setw(10) << g.third_scores[2] << setw(7) <<
//			g.third_scores[3] << setw(7) << g.third_scores[4] << setw(7) << g.third_scores[5] << setw(7) <<
//			g.third_scores[6] << setw(7) << g.third_scores[7] << setw(7) << g.third_scores[8] << setw(7) << endl;
//		fout.close();
//	}
//}
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
//void ShowAllGrades() {
//	int flag = ChoiceGrade();
//	if (flag == 1) {
//		system("cls");
//
//		int i;
//		int x = 9;
//		int y = 4;
//
//		int gradeSelect = 0;
//
//		gotoxy(x, y);
//		printf("┌");
//		for (i = 0; i < 98; i++) {
//			printf("─");
//		}
//		printf("┐");
//
//		for (i = 0; i < 30; i++) {
//			y++;
//			gotoxy(x, y);
//			printf("│");
//
//			if (i == 5) {
//				int j = 5;
//				gotoxy(25, i);
//				char inputString[1000];
//
//				First_Grade fg;
//				ifstream fin;
//				fin.open("first_grade.txt");
//				while (!fin.eof()) {
//					j++;
//					fin.getline(inputString, 100);
//					gotoxy(25, j);
//					cout << inputString << endl;
//				}
//				fin.close();
//			}
//
//			x += 99;
//			gotoxy(x, y);
//			printf("│");
//			x = 9;
//		}
//		gotoxy(x, y);
//		printf("└");
//		for (i = 0; i < 98; i++) {
//			printf("─");
//		}
//		printf("┘\n\n\n");
//	}
//	else if (flag == 2) {
//		system("cls");
//
//		int i;
//		int x = 9;
//		int y = 4;
//
//		int gradeSelect = 0;
//
//		gotoxy(x, y);
//		printf("┌");
//		for (i = 0; i < 98; i++) {
//			printf("─");
//		}
//		printf("┐");
//
//		for (i = 0; i < 30; i++) {
//			y++;
//			gotoxy(x, y);
//			printf("│");
//
//			if (i == 5) {
//				int j = 5;
//				gotoxy(25, i);
//				char inputString[1000];
//
//				First_Grade fg;
//				ifstream fin;
//				fin.open("second_grade.txt");
//				while (!fin.eof()) {
//					j++;
//					fin.getline(inputString, 100);
//					gotoxy(25, j);
//					cout << inputString << endl;
//				}
//				fin.close();
//			}
//
//			x += 99;
//			gotoxy(x, y);
//			printf("│");
//			x = 9;
//		}
//		gotoxy(x, y);
//		printf("└");
//		for (i = 0; i < 98; i++) {
//			printf("─");
//		}
//		printf("┘\n\n\n");
//	}
//	else {
//		system("cls");
//
//		int i;
//		int x = 9;
//		int y = 4;
//
//		int gradeSelect = 0;
//
//		gotoxy(x, y);
//		printf("┌");
//		for (i = 0; i < 98; i++) {
//			printf("─");
//		}
//		printf("┐");
//
//		for (i = 0; i < 30; i++) {
//			y++;
//			gotoxy(x, y);
//			printf("│");
//
//			if (i == 5) {
//				int j = 5;
//				gotoxy(25, i);
//				char inputString[1000];
//
//				First_Grade fg;
//				ifstream fin;
//				fin.open("third_grade.txt");
//				while (!fin.eof()) {
//					j++;
//					fin.getline(inputString, 100);
//					gotoxy(25, j);
//					cout << inputString << endl;
//				}
//				fin.close();
//			}
//
//			x += 99;
//			gotoxy(x, y);
//			printf("│");
//			x = 9;
//		}
//		gotoxy(x, y);
//		printf("└");
//		for (i = 0; i < 98; i++) {
//			printf("─");
//		}
//		printf("┘\n\n\n");
//	}
//}
//void ShowGrade() {
//	int flag = ChoiceGrade();
//	int studnet_num;
//
//	if (flag == 1) {
//		system("cls");
//
//		int i;
//		int x = 9;
//		int y = 4;
//
//		int gradeSelect = 0;
//
//		gotoxy(x, y);
//		printf("┌");
//		for (i = 0; i < 98; i++) {
//			printf("─");
//		}
//		printf("┐");
//
//		for (i = 0; i < 30; i++) {
//			y++;
//			gotoxy(x, y);
//			printf("│");
//
//			x += 99;
//			gotoxy(x, y);
//			printf("│");
//			x = 9;
//		}
//		gotoxy(x, y);
//		printf("└");
//		for (i = 0; i < 98; i++) {
//			printf("─");
//		}
//		printf("┘\n\n\n");
//		gotoxy(45, 17);
//		cout << "학번을 입력하세요 : ";
//		cin >> studnet_num;
//		// 파일에서 해당 학번에 대한 성적읽기=======================================================================
//	}
//	else if (flag == 2) {
//
//	}
//	else {
//
//	}
//}

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
} // end of ShowObjections

void ShowGrades() {
	int flag = ChoiceGrade();
	int student_num;
	char student_name[20];
	int scores[10];

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
		fin.open("first_grade.txt");

		char inputString[1000];
		while (!fin.eof()) {
			count++;
			fin.getline(inputString, 100);
			gotoxy(20, count);
			cout << inputString << endl;
		}
		//while (fin >> student_num >> student_name >> scores[0] >> scores[1] >> scores[2] >> scores[3] >> scores[4] >> scores[5] >> scores[6] >> scores[7] >> scores[8] >> scores[9]) {
		//	gotoxy(15, count);
		//	/*printf("%8d%10s", student_num, subject);
		//	cout << reason << endl;*/
		//	cout << student_num << setw(20) << student_name << setw(30) << scores[0]  << setw(10) <<  scores[1] << setw(10) << scores[2] << setw(10) << scores[3] << setw(10) << scores[4] << setw(10) << scores[5] << setw(10) << scores[6] << setw(10) << scores[7] << setw(10) << scores[8] << setw(10) << scores[9] << endl;
		//	count++;
		//}
		//while (fin >> student_num >> student_name >> scores[0] >> scores[1] >> scores[2] >> scores[3] >> scores[4] >> scores[5] >> scores[6] >> scores[7] >> scores[8] >> scores[9]) {
		//	gotoxy(15, count);
		//	/*printf("%8d%10s", student_num, subject);
		//	cout << reason << endl;*/
		//	cout << student_num << setw(20) << student_name << setw(30) << scores[0]  << setw(10) <<  scores[1] << setw(10) << scores[2] << setw(10) << scores[3] << setw(10) << scores[4] << setw(10) << scores[5] << setw(10) << scores[6] << setw(10) << scores[7] << setw(10) << scores[8] << setw(10) << scores[9] << endl;
		//	count++;
		//}
		//while (fin >> student_num >> student_name >> scores[0] >> scores[1] >> scores[2] >> scores[3] >> scores[4] >> scores[5] >> scores[6] >> scores[7] >> scores[8] >> scores[9]) {
		//	gotoxy(15, count);
		//	/*printf("%8d%10s", student_num, subject);
		//	cout << reason << endl;*/
		//	cout << student_num << setw(20) << student_name << setw(30) << scores[0]  << setw(10) <<  scores[1] << setw(10) << scores[2] << setw(10) << scores[3] << setw(10) << scores[4] << setw(10) << scores[5] << setw(10) << scores[6] << setw(10) << scores[7] << setw(10) << scores[8] << setw(10) << scores[9] << endl;
		//	count++;
		//}
		fin.close();
	}
	else if (flag == 2) {
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
		fin.open("second_grade.txt");

		char inputString[1000];
		while (!fin.eof()) {
			count++;
			fin.getline(inputString, 100);
			gotoxy(20, count);
			cout << inputString << endl;
		}
		fin.close();
	}
	else {
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
		fin.open("third_grade.txt");

		char inputString[1000];
		while (!fin.eof()) {
			count++;
			fin.getline(inputString, 100);
			gotoxy(20, count);
			cout << inputString << endl;
		}
		fin.close();
	}
} // end of ShowGrades

// 메인함수
int main() {
	MainPage();
	return 0;
} // end of main