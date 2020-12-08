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
int ChoiceGrade(); // 학년 선택 화면

void GradeSuccess(); // 성적 입력 완료 화면
void ShowGrades(); // 성적 보는 화면

void ShowObjections(); // 의의신청 보는 화면
void ObjectionSuccess(); // 의의신청 완료 화면

void IsTeacher(); // 교사 비밀번호 입력 화면
void modifyGrade(); // 학생 성적 수정
string searchGrade(int isStudent); // 학생 성적 검색해주는 함수
void showGrade(); // 학생 메뉴 => 학생 성적 보여주는 함수
void showGradeT(); // 교사 메뉴 => 학생 성적 보여주는 함수

void changePw();

// 교사 비밀번호
string TEACHER_PASSWORD = "teacher";

// gotoxy 함수 (콘솔창 내에서 위치 지정 해줌)
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
	Grade() {

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

// ModifyGrade클래스
class ModifyGrade : public Grade {
public:
	string student_num;
	string student_name;
	string score1; string score2; string score3; string score4; string score5;
	string score6; string score7; string score8; string score9; string score10;

	ModifyGrade(string student_num, string student_name, string score1, string score2, string score3, string score4, string score5, string score6, string score7, string score8, string score9, string score10) {
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
};

// 성적 수정
void modifyGrade() {
	int hakbun;
	string hakbun2;
	string line;
	int offset;

	string subject;
	string new_score;

	// 학번 입력받기
	int flag = ChoiceGrade();

	// 해당 학번이 있는 줄에 엑세스하기
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

		for (int k = 0; k < 30; k++) {
			if (k == 11) {
				gotoxy(40, k);
				ifstream first_grade("first_grade.txt");
				cout << "자신의 학번을 입력하세요 : ";
				cin >> hakbun;
				hakbun2 = to_string(hakbun);

				string student_name;
				string student_num;
				string score1; string score2; string score3; string score4; string score5;
				string score6; string score7; string score8;

				ModifyGrade mg("0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0");

				while (first_grade >> student_num >> student_name >> score1 >> score2 >> score3 >> score4 >> score5 >> score6 >> score7 >> score8) {
					mg.student_num = student_num;
					mg.student_name = student_name;
					mg.score1 = score1;
					mg.score2 = score2;
					mg.score3 = score3;
					mg.score4 = score4;
					mg.score5 = score5;
					mg.score6 = score6;
					mg.score7 = score7;
					mg.score8 = score8;
					if (mg.student_num == hakbun2) {
						gotoxy(25, k + 3);
						cout << "학번    이름     국어   수학   영어   사회   국사   JAVA   C   컴퓨터구조" << endl;
						gotoxy(25, k + 4);
						cout << mg.student_num << setw(10) << student_name <<
							setw(5) << score1 << setw(7) << score2 << setw(7) << score3 << setw(7) << score4 << setw(7)
							<< score5 << setw(7) << score6 << setw(7) << score7 << setw(7) << score8 << '\n';
						break;
					}
				}
				first_grade.close();

				// 무슨과목 바꿀 건지 물어보기
				gotoxy(40, k + 7);
				cout << "성적을 수정할 과목을 입력하세요 : ";
				cin >> subject;
				gotoxy(40, k + 9);
				cout << "수정된 성적을 입력하세요 : ";
				cin >> new_score;
				if (subject == "국어") {
					mg.score1 = new_score;
				}
				else if (subject == "수학") {
					mg.score2 = new_score;
				}
				else if (subject == "영어") {
					mg.score3 = new_score;
				}
				else if (subject == "사회") {
					mg.score4 = new_score;
				}
				else if (subject == "국사") {
					mg.score5 = new_score;
				}
				else if (subject == "자바") {
					mg.score6 = new_score;
				}
				else if (subject == "C") {
					mg.score7 = new_score;
				}
				else if (subject == "컴퓨터구조") {
					mg.score8 = new_score;
				}
				else {
					subject = "";
					new_score = "";
					gotoxy(40, k + 7);
					cout << "성적을 수정할 과목을 입력하세요 : ";
					cin >> subject;
					gotoxy(40, k + 9);
					cout << "수정된 성적을 입력하세요 : ";
					cin >> new_score;
				}

				// 이전 점수 삭제
				FILE* fd, * fd1;
				char name[80];
				char line[80];
				string name2;
				char temp[2048];

				fd = fopen("first_grade.txt", "rb");
				const char* c = hakbun2.c_str();
				strcpy(name, c);
				fflush(stdin);

				temp[0] = 0;
				while (!feof(fd)) {
					memset(&line[0], 0, sizeof(0));
					fgets(line, 80, fd);
					if (strstr(line, name) == NULL) {
						strcat(temp, line);
					}
				}
				fclose(fd);

				fd = fopen("first_grade.txt", "wb");
				fprintf(fd, "%s", temp);
				fclose(fd);

				// 수정된 성적 입력
				ofstream fout("first_grade.txt", ios::app);
				fout << mg.student_num << setw(10) << mg.student_name << setw(7) << mg.score1 << setw(7) << mg.score2 << setw(7)
					<< mg.score3 << setw(7) << mg.score4 << setw(7) << mg.score7 << setw(7) << mg.score6 << setw(7) << mg.score7
					<< setw(7) << mg.score8 << setw(7) << endl;
			}
		}

		gotoxy(45, 23);
		cout << "성적이 수정되었습니다" << endl;

		gotoxy(23, 26);
		int select = -1;
		cout << "(0 입력 : 메인화면, 1 입력 : 교사메뉴, 2 입력 : 성적 수정하기) : ";
		cin >> select;
		while (true) {
			switch (select) {
				//case 1:ShowGrade(); break;
			case 0: MainPage(); break;
			case 1: TeacherPage(); break;
			case 2: modifyGrade(); break;
			default:
				gotoxy(47, 27);
				printf("존재하지 않는 메뉴입니다");
				gotoxy(15, 26);
				printf("(0 입력 : 메인화면, 1 입력 : 교사메뉴, 2 입력 : 성적 수정하기) : ");
				scanf_s("%d", &select);
			}
		}
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

		for (int k = 0; k < 30; k++) {
			if (k == 11) {
				gotoxy(40, k);
				ifstream second_grade("second_grade.txt");
				cout << "자신의 학번을 입력하세요 : ";
				cin >> hakbun;
				hakbun2 = to_string(hakbun);

				string student_name;
				string student_num;
				string score1; string score2; string score3; string score4; string score5;
				string score6; string score7; string score8; string score9;

				ModifyGrade mg("0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0");

				while (second_grade >> student_num >> student_name >> score1 >> score2 >> score3 >> score4 >> score5 >> score6 >> score7 >> score8 >> score9) {
					mg.student_num = student_num;
					mg.student_name = student_name;
					mg.score1 = score1;
					mg.score2 = score2;
					mg.score3 = score3;
					mg.score4 = score4;
					mg.score5 = score5;
					mg.score6 = score6;
					mg.score7 = score7;
					mg.score8 = score8;
					mg.score9 = score9;
					if (mg.student_num == hakbun2) {
						gotoxy(23, k + 3);
						cout << "학번    이름     국어   수학   영어   과학   JSP   JAVA   C++  Python  DS" << endl;
						gotoxy(23, k + 4);
						cout << mg.student_num << setw(10) << student_name <<
							setw(5) << score1 << setw(7) << score2 << setw(7) << score3 << setw(7) << score4 << setw(7)
							<< score5 << setw(6) << score6 << setw(7) << score7 << setw(6) << score8 << setw(7) << score9 << '\n';
						break;
					}
				}
				second_grade.close();

				// 무슨과목 바꿀 건지 물어보기
				gotoxy(40, k + 7);
				cout << "성적을 수정할 과목을 입력하세요 : ";
				cin >> subject;
				gotoxy(40, k + 9);
				cout << "수정된 성적을 입력하세요 : ";
				cin >> new_score;
				if (subject == "국어") {
					mg.score1 = new_score;
				}
				else if (subject == "수학") {
					mg.score2 = new_score;
				}
				else if (subject == "영어") {
					mg.score3 = new_score;
				}
				else if (subject == "과학") {
					mg.score4 = new_score;
				}
				else if (subject == "JSP") {
					mg.score5 = new_score;
				}
				else if (subject == "JAVA") {
					mg.score6 = new_score;
				}
				else if (subject == "C++") {
					mg.score7 = new_score;
				}
				else if (subject == "Python") {
					mg.score8 = new_score;
				}
				else if (subject == "DS") {
					mg.score9 = new_score;
				}
				else {
					subject = "";
					new_score = "";
					gotoxy(40, k + 7);
					cout << "성적을 수정할 과목을 입력하세요 : ";
					cin >> subject;
					gotoxy(40, k + 9);
					cout << "수정된 성적을 입력하세요 : ";
					cin >> new_score;
				}

				// 이전 점수 삭제
				FILE* fd, * fd1;
				char name[80];
				char line[80];
				string name2;
				char temp[2048];

				fd = fopen("second_grade.txt", "rb");
				const char* c = hakbun2.c_str();
				strcpy(name, c);
				fflush(stdin);

				temp[0] = 0;
				while (!feof(fd)) {
					memset(&line[0], 0, sizeof(0));
					fgets(line, 80, fd);
					if (strstr(line, name) == NULL) {
						strcat(temp, line);
					}
				}
				fclose(fd);

				fd = fopen("second_grade.txt", "wb");
				fprintf(fd, "%s", temp);
				fclose(fd);

				// 수정된 성적 입력
				ofstream fout("second_grade.txt", ios::app);
				fout << mg.student_num << setw(10) << mg.student_name << setw(7) << mg.score1 << setw(7) << mg.score2 << setw(7)
					<< mg.score3 << setw(7) << mg.score4 << setw(7) << mg.score7 << setw(7) << mg.score6 << setw(7) << mg.score7
					<< setw(7) << mg.score8 << setw(7) << endl;
			}
		}

		gotoxy(45, 23);
		cout << "성적이 수정되었습니다" << endl;

		gotoxy(23, 26);
		int select = -1;
		cout << "(0 입력 : 메인화면, 1 입력 : 교사메뉴, 2 입력 : 성적 수정하기) : ";
		cin >> select;
		while (true) {
			switch (select) {
				//case 1:ShowGrade(); break;
			case 0: MainPage(); break;
			case 1: TeacherPage(); break;
			case 2: modifyGrade(); break;
			default:
				gotoxy(47, 27);
				printf("존재하지 않는 메뉴입니다");
				gotoxy(15, 26);
				printf("(0 입력 : 메인화면, 1 입력 : 교사메뉴, 2 입력 : 성적 수정하기) : ");
				scanf_s("%d", &select);
			}
		}
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

		for (int k = 0; k < 30; k++) {
			if (k == 11) {
				gotoxy(40, k);
				ifstream third_grade("third_grade.txt");
				cout << "자신의 학번을 입력하세요 : ";
				cin >> hakbun;
				hakbun2 = to_string(hakbun);

				string student_name;
				string student_num;
				string score1; string score2; string score3; string score4; string score5;
				string score6; string score7; string score8;

				ModifyGrade mg("0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0");

				while (third_grade >> student_num >> student_name >> score1 >> score2 >> score3 >> score4 >> score5 >> score6 >> score7 >> score8) {
					mg.student_num = student_num;
					mg.student_name = student_name;
					mg.score1 = score1;
					mg.score2 = score2;
					mg.score3 = score3;
					mg.score4 = score4;
					mg.score5 = score5;
					mg.score6 = score6;
					mg.score7 = score7;
					mg.score8 = score8;
					if (mg.student_num == hakbun2) {
						gotoxy(17, k + 3);
						cout << "학번     이름     선택1   선택2   선택3   영어   사무관리   DB   server   Programming" << endl;
						gotoxy(17, k + 4);
						cout << mg.student_num << setw(10) << student_name <<
							setw(6) << score1 << setw(8) << score2 << setw(8) << score3 << setw(8) << score4 << setw(9)
							<< score5 << setw(9) << score6 << setw(7) << score7 << setw(11) << score8 << '\n';
						break;
					}
				}
				third_grade.close();

				// 무슨과목 바꿀 건지 물어보기
				gotoxy(40, k + 7);
				cout << "성적을 수정할 과목을 입력하세요 : ";
				cin >> subject;
				gotoxy(40, k + 9);
				cout << "수정된 성적을 입력하세요 : ";
				cin >> new_score;
				if (subject == "국어") {
					mg.score1 = new_score;
				}
				else if (subject == "수학") {
					mg.score2 = new_score;
				}
				else if (subject == "영어") {
					mg.score3 = new_score;
				}
				else if (subject == "과학") {
					mg.score4 = new_score;
				}
				else if (subject == "JSP") {
					mg.score5 = new_score;
				}
				else if (subject == "JAVA") {
					mg.score6 = new_score;
				}
				else if (subject == "C++") {
					mg.score7 = new_score;
				}
				else if (subject == "Python") {
					mg.score8 = new_score;
				}
				else if (subject == "DS") {
					mg.score9 = new_score;
				}
				else {
					subject = "";
					new_score = "";
					gotoxy(40, k + 7);
					cout << "성적을 수정할 과목을 입력하세요 : ";
					cin >> subject;
					gotoxy(40, k + 9);
					cout << "수정된 성적을 입력하세요 : ";
					cin >> new_score;
				}

				// 이전 점수 삭제
				FILE* fd, * fd1;
				char name[80];
				char line[80];
				string name2;
				char temp[2048];

				fd = fopen("third_grade.txt", "rb");
				const char* c = hakbun2.c_str();
				strcpy(name, c);
				fflush(stdin);

				temp[0] = 0;
				while (!feof(fd)) {
					memset(&line[0], 0, sizeof(0));
					fgets(line, 80, fd);
					if (strstr(line, name) == NULL) {
						strcat(temp, line);
					}
				}
				fclose(fd);

				fd = fopen("third_grade.txt", "wb");
				fprintf(fd, "%s", temp);
				fclose(fd);

				// 수정된 성적 입력
				ofstream fout("third_grade.txt", ios::app);
				fout << mg.student_num << setw(10) << mg.student_name << setw(7) << mg.score1 << setw(7) << mg.score2 << setw(7)
					<< mg.score3 << setw(7) << mg.score4 << setw(7) << mg.score7 << setw(7) << mg.score6 << setw(7) << mg.score7
					<< setw(7) << mg.score8 << setw(7) << endl;
			}
		}

		gotoxy(45, 23);
		cout << "성적이 수정되었습니다" << endl;

		gotoxy(23, 26);
		int select = -1;
		cout << "(0 입력 : 메인화면, 1 입력 : 교사메뉴, 2 입력 : 성적 수정하기) : ";
		cin >> select;
		while (true) {
			switch (select) {
				//case 1:ShowGrade(); break;
			case 0: MainPage(); break;
			case 1: TeacherPage(); break;
			case 2: modifyGrade(); break;
			default:
				gotoxy(47, 27);
				printf("존재하지 않는 메뉴입니다");
				gotoxy(15, 26);
				printf("(0 입력 : 메인화면, 1 입력 : 교사메뉴, 2 입력 : 성적 수정하기) : ");
				scanf_s("%d", &select);
			}
		}
	}
}

void changePw() {
	int i, j;
	int x = 9;
	int y = 4;

	string old_pw;
	string new_pw;
	string new_pw_identify;
	boolean collect = false;
	int select;

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
		if (i == 14) {
			gotoxy(45, i);
			cout << "현재 비밀번호 입력 : ";
			cin >> old_pw;
			if (old_pw != TEACHER_PASSWORD) {
				gotoxy(45, i + 2);
				cout << "현재 비밀번호 입력 : ";
				cin >> old_pw;
			}
			else {
				collect = true;
			}
		}
		if (i == 16 && collect == true) {
			gotoxy(45, i);
			cout << "새 비밀번호 입력 : ";
			cin >> new_pw;
			if (new_pw.length() < 6) {
				gotoxy(45, i + 2);
				cout << "비밀번호는 최소 6글자 이상이어야 합니다";
				gotoxy(45, i);
				cout << "새 비밀번호 입력 : ";
				cin >> new_pw;
			}
			if(new_pw.length() >= 6) {
				gotoxy(45, i + 2);
				cout << "새 비밀번호 확인 : ";
				cin >> new_pw_identify;
				if (new_pw == new_pw_identify) {
					TEACHER_PASSWORD = new_pw;
					gotoxy(45, i + 5);
					cout << "(0 : 메인화면, 1 : 교사화면) : ";
					cin >> select;
					if (select == 0) {
						MainPage();
					}
					else if (select == 1) {
						TeacherPage();
					}
					else {

					}
				}
			}
		}
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

// 학생 -> 성적 보기
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

// 교사 -> 학생 검색하기
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
				cout << "(0 입력 : 메인화면, 1 입력 : 교사메뉴, 2 입력 : 성적 입력하기) : ";
				cin >> studentMenuSelect;
				if (studentMenuSelect == 0) {
					success == false;
					MainPage();
				}
				else if (studentMenuSelect == 1) {
					success == false;
					TeacherPage();
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

// Objection클래스 (의의신청 클래스)
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
		fout << ob.student_num << setw(20) << ob.subject << setw(50) << ob.reason << endl;
		ObjectionSuccess();
	}
	else if (flag == 1) {
		Objection ob = writeObjection();
		ofstream fout("second_grade_objection.txt", ios::app);
		fout << ob.student_num << setw(20) << ob.subject << setw(50) << ob.reason << endl;
		ObjectionSuccess();
	}
	else {
		Objection ob = writeObjection();
		ofstream fout("third_grade_objection.txt", ios::app);
		fout << ob.student_num << setw(20) << ob.subject << setw(50) << ob.reason << endl;
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
		if (k == 12) {
			gotoxy(50, k);
			cout << "교사 보안 확인" << endl;
		}
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

		if (i == 8) {
			gotoxy(54, i);
			printf("교사메뉴");
		}
		if (i == 12) {
			gotoxy(46, i);
			printf("01. 전체 학생 성적 보기");
		}
		if (i == 14) {
			gotoxy(46, i);
			printf("02. 학생 검색하기");
		}
		if (i == 16) {
			gotoxy(46, i);
			printf("03. 학생 성적 입력하기");
		}
		if (i == 18) {
			gotoxy(46, i);
			printf("04. 학생 성적 수정하기");
		}
		if (i == 20) {
			gotoxy(46, i);
			printf("05. 의의신청 목록 보기");
		}
		if (i == 22) {
			gotoxy(46, i);
			printf("06. 비밀번호 변경");
		}if (i == 24) {
			gotoxy(46, i);
			printf("07. 뒤로가기");
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
	case 4:modifyGrade();  break;
	case 5: ShowObjections();  break;
	case 6: changePw(); break;
	case 7: MainPage(); break;
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
		IsTeacher();
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

// 학년을 선택하는 함수
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
		fin.open("second_grade_objection.txt");

		char inputString[1000];
		while (!fin.eof()) {
			count++;
			fin.getline(inputString, 100);
			gotoxy(25, count);
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
		fin.open("third_grade_objection.txt");

		char inputString[1000];
		while (!fin.eof()) {
			count++;
			fin.getline(inputString, 100);
			gotoxy(25, count);
			cout << inputString << endl;
		}
		fin.close();
	}
	int select;
	for (int k = 0; k < 30; k++) {
		if (k == 27) {
			gotoxy(21, k);
			cout << "(0 입력 : 메인화면, 1 입력 : 교사메뉴, 2 입력 : 의의신청 목록보기) : ";
			cin >> select;
			if (select == 0) {
				select == false;
				MainPage();
			}
			else if (select == 1) {
				select == false;
				TeacherPage();
			}
			else if (select == 2) {
				ShowObjections();
			}
			else {
				gotoxy(45, k + 2);
				cout << "0이나 1을 입력해주세요" << endl;
			}
		}
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
	int select;
	for (int k = 0; k < 30; k++) {
		if (k == 27) {
			gotoxy(20, k);
			cout << "(0 입력 : 메인화면, 1 입력 : 교사메뉴, 2 입력 : 전체 성적 보기) : ";
			cin >> select;
			if (select == 0) {
				select == false;
				MainPage();
			}
			else if (select == 1) {
				select == false;
				TeacherPage();
			}
			else if (select == 2) {
				ShowGrades();
			}
			else {
				gotoxy(45, k + 2);
				cout << "0이나 1을 입력해주세요" << endl;
			}
		}
	}
} // end of ShowGrades

// 메인함수
int main() {
	MainPage();
	return 0;
} // end of main