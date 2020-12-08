#include <iostream>
#include <vector>
#include <Windows.h>
#include <conio.h>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

// �Լ� ����
void MainPage(); // ���� ȭ��
void StudentPage(); // �л� ���� ȭ��
void TeacherPage(); // ���� ���� ȭ��
int ChoiceGrade(); // �г� ���� ȭ��

void GradeSuccess(); // ���� �Է� �Ϸ� ȭ��
void ShowGrades(); // ���� ���� ȭ��

void ShowObjections(); // ���ǽ�û ���� ȭ��
void ObjectionSuccess(); // ���ǽ�û �Ϸ� ȭ��

void IsTeacher(); // ���� ��й�ȣ �Է� ȭ��
void modifyGrade(); // �л� ���� ����
string searchGrade(int isStudent); // �л� ���� �˻����ִ� �Լ�
void showGrade(); // �л� �޴� => �л� ���� �����ִ� �Լ�
void showGradeT(); // ���� �޴� => �л� ���� �����ִ� �Լ�

void changePw();

// ���� ��й�ȣ
string TEACHER_PASSWORD = "teacher";

// gotoxy �Լ� (�ܼ�â ������ ��ġ ���� ����)
void gotoxy(int x, int y) {
	COORD Pos;
	Pos.X = x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

// ���� Ŭ����
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

// writeGrade���� �Է¹��� ������ ���Ͽ� ���
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

// ���� �Է�
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
		printf("��");
		for (i = 0; i < 98; i++) {
			printf("��");
		}
		printf("��");
		for (i = 0; i < 30; i++) {
			y++;
			gotoxy(x, y);
			printf("��");
			x += 99;
			gotoxy(x, y);
			printf("��");
			x = 9;
		}
		gotoxy(x, y);
		printf("��");
		for (i = 0; i < 98; i++) {
			printf("��");
		}
		printf("��\n\n\n");
		for (j = 0; j < 30; j++) {
			if (j == 8) {
				gotoxy(35, j);
				cout << "�й��� �Է����ּ��� : ";
				cin >> student_num;
				string remainder;
				getline(cin, remainder);
			}
			if (j == 10) {
				gotoxy(35, j);
				cout << "�̸��� �Է����ּ��� : ";
				getline(cin, student_name, '\n'); // ������� �ص� �Է� ����
			}
			if (j == 12) {
				gotoxy(35, j);
				cout << "���� : ";
				cin >> score1;
				string remainder;
				getline(cin, remainder);
			}
			if (j == 14) {
				gotoxy(35, j);
				cout << "���� : ";
				cin >> score2;
				string remainder;
				getline(cin, remainder);
			}
			if (j == 16) {
				gotoxy(35, j);
				cout << "���� : ";
				cin >> score3;
				string remainder;
				getline(cin, remainder);
			}
			if (j == 18) {
				gotoxy(35, j);
				cout << "��ȸ : ";
				cin >> score4;
				string remainder;
				getline(cin, remainder);
			}
			if (j == 20) {
				gotoxy(35, j);
				cout << "�ѱ��� : ";
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
				cout << "C��� : ";
				cin >> score7;
				string remainder;
				getline(cin, remainder);
			}
			if (j == 26) {
				gotoxy(35, j);
				cout << "��ǻ�� ���� : ";
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
		printf("��");
		for (i = 0; i < 98; i++) {
			printf("��");
		}
		printf("��");
		for (i = 0; i < 30; i++) {
			y++;
			gotoxy(x, y);
			printf("��");
			x += 99;
			gotoxy(x, y);
			printf("��");
			x = 9;
		}
		gotoxy(x, y);
		printf("��");
		for (i = 0; i < 98; i++) {
			printf("��");
		}
		printf("��\n\n\n");
		for (j = 0; j < 30; j++) {
			if (j == 8) {
				gotoxy(35, j);
				cout << "�й��� �Է����ּ��� : ";
				cin >> student_num;
				string remainder;
				getline(cin, remainder);
			}
			if (j == 10) {
				gotoxy(35, j);
				cout << "�̸��� �Է����ּ��� : ";
				getline(cin, student_name, '\n'); // ������� �ص� �Է� ����
			}
			if (j == 12) {
				gotoxy(35, j);
				cout << "���� : ";
				cin >> score1;
				string remainder;
				getline(cin, remainder);
			}
			if (j == 14) {
				gotoxy(35, j);
				cout << "���� : ";
				cin >> score2;
				string remainder;
				getline(cin, remainder);
			}
			if (j == 16) {
				gotoxy(35, j);
				cout << "���� : ";
				cin >> score3;
				string remainder;
				getline(cin, remainder);
			}
			if (j == 18) {
				gotoxy(35, j);
				cout << "���� : ";
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
				cout << "�ڷ� ���� : ";
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
		printf("��");
		for (i = 0; i < 98; i++) {
			printf("��");
		}
		printf("��");
		for (i = 0; i < 30; i++) {
			y++;
			gotoxy(x, y);
			printf("��");
			x += 99;
			gotoxy(x, y);
			printf("��");
			x = 9;
		}
		gotoxy(x, y);
		printf("��");
		for (i = 0; i < 98; i++) {
			printf("��");
		}
		printf("��\n\n\n");
		for (j = 0; j < 30; j++) {
			if (j == 8) {
				gotoxy(35, j);
				cout << "�й��� �Է����ּ��� : ";
				cin >> student_num;
				string remainder;
				getline(cin, remainder);
			}
			if (j == 10) {
				gotoxy(35, j);
				cout << "�̸��� �Է����ּ��� : ";
				getline(cin, student_name, '\n'); // ������� �ص� �Է� ����
			}
			if (j == 12) {
				gotoxy(35, j);
				cout << "����1 : ";
				cin >> score1;
				string remainder;
				getline(cin, remainder);
			}
			if (j == 14) {
				gotoxy(35, j);
				cout << "����2 : ";
				cin >> score2;
				string remainder;
				getline(cin, remainder);
			}
			if (j == 16) {
				gotoxy(35, j);
				cout << "����3 : ";
				cin >> score3;
				string remainder;
				getline(cin, remainder);
			}
			if (j == 18) {
				gotoxy(35, j);
				cout << "���� : ";
				cin >> score4;
				string remainder;
				getline(cin, remainder);
			}
			if (j == 20) {
				gotoxy(35, j);
				cout << "�繫���� : ";
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

// ModifyGradeŬ����
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

// ���� ����
void modifyGrade() {
	int hakbun;
	string hakbun2;
	string line;
	int offset;

	string subject;
	string new_score;

	// �й� �Է¹ޱ�
	int flag = ChoiceGrade();

	// �ش� �й��� �ִ� �ٿ� �������ϱ�
	if (flag == 1) {
		system("cls");
		int i;
		int x = 9;
		int y = 4;

		gotoxy(x, y);
		printf("��");
		for (i = 0; i < 98; i++) {
			printf("��");
		}
		printf("��");

		for (i = 0; i < 30; i++) {
			y++;
			gotoxy(x, y);
			printf("��");

			x += 99;
			gotoxy(x, y);
			printf("��");
			x = 9;
		}
		gotoxy(x, y);
		printf("��");
		for (i = 0; i < 98; i++) {
			printf("��");
		}
		printf("��\n\n\n");

		for (int k = 0; k < 30; k++) {
			if (k == 11) {
				gotoxy(40, k);
				ifstream first_grade("first_grade.txt");
				cout << "�ڽ��� �й��� �Է��ϼ��� : ";
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
						cout << "�й�    �̸�     ����   ����   ����   ��ȸ   ����   JAVA   C   ��ǻ�ͱ���" << endl;
						gotoxy(25, k + 4);
						cout << mg.student_num << setw(10) << student_name <<
							setw(5) << score1 << setw(7) << score2 << setw(7) << score3 << setw(7) << score4 << setw(7)
							<< score5 << setw(7) << score6 << setw(7) << score7 << setw(7) << score8 << '\n';
						break;
					}
				}
				first_grade.close();

				// �������� �ٲ� ���� �����
				gotoxy(40, k + 7);
				cout << "������ ������ ������ �Է��ϼ��� : ";
				cin >> subject;
				gotoxy(40, k + 9);
				cout << "������ ������ �Է��ϼ��� : ";
				cin >> new_score;
				if (subject == "����") {
					mg.score1 = new_score;
				}
				else if (subject == "����") {
					mg.score2 = new_score;
				}
				else if (subject == "����") {
					mg.score3 = new_score;
				}
				else if (subject == "��ȸ") {
					mg.score4 = new_score;
				}
				else if (subject == "����") {
					mg.score5 = new_score;
				}
				else if (subject == "�ڹ�") {
					mg.score6 = new_score;
				}
				else if (subject == "C") {
					mg.score7 = new_score;
				}
				else if (subject == "��ǻ�ͱ���") {
					mg.score8 = new_score;
				}
				else {
					subject = "";
					new_score = "";
					gotoxy(40, k + 7);
					cout << "������ ������ ������ �Է��ϼ��� : ";
					cin >> subject;
					gotoxy(40, k + 9);
					cout << "������ ������ �Է��ϼ��� : ";
					cin >> new_score;
				}

				// ���� ���� ����
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

				// ������ ���� �Է�
				ofstream fout("first_grade.txt", ios::app);
				fout << mg.student_num << setw(10) << mg.student_name << setw(7) << mg.score1 << setw(7) << mg.score2 << setw(7)
					<< mg.score3 << setw(7) << mg.score4 << setw(7) << mg.score7 << setw(7) << mg.score6 << setw(7) << mg.score7
					<< setw(7) << mg.score8 << setw(7) << endl;
			}
		}

		gotoxy(45, 23);
		cout << "������ �����Ǿ����ϴ�" << endl;

		gotoxy(23, 26);
		int select = -1;
		cout << "(0 �Է� : ����ȭ��, 1 �Է� : ����޴�, 2 �Է� : ���� �����ϱ�) : ";
		cin >> select;
		while (true) {
			switch (select) {
				//case 1:ShowGrade(); break;
			case 0: MainPage(); break;
			case 1: TeacherPage(); break;
			case 2: modifyGrade(); break;
			default:
				gotoxy(47, 27);
				printf("�������� �ʴ� �޴��Դϴ�");
				gotoxy(15, 26);
				printf("(0 �Է� : ����ȭ��, 1 �Է� : ����޴�, 2 �Է� : ���� �����ϱ�) : ");
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
		printf("��");
		for (i = 0; i < 98; i++) {
			printf("��");
		}
		printf("��");

		for (i = 0; i < 30; i++) {
			y++;
			gotoxy(x, y);
			printf("��");

			x += 99;
			gotoxy(x, y);
			printf("��");
			x = 9;
		}
		gotoxy(x, y);
		printf("��");
		for (i = 0; i < 98; i++) {
			printf("��");
		}
		printf("��\n\n\n");

		for (int k = 0; k < 30; k++) {
			if (k == 11) {
				gotoxy(40, k);
				ifstream second_grade("second_grade.txt");
				cout << "�ڽ��� �й��� �Է��ϼ��� : ";
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
						cout << "�й�    �̸�     ����   ����   ����   ����   JSP   JAVA   C++  Python  DS" << endl;
						gotoxy(23, k + 4);
						cout << mg.student_num << setw(10) << student_name <<
							setw(5) << score1 << setw(7) << score2 << setw(7) << score3 << setw(7) << score4 << setw(7)
							<< score5 << setw(6) << score6 << setw(7) << score7 << setw(6) << score8 << setw(7) << score9 << '\n';
						break;
					}
				}
				second_grade.close();

				// �������� �ٲ� ���� �����
				gotoxy(40, k + 7);
				cout << "������ ������ ������ �Է��ϼ��� : ";
				cin >> subject;
				gotoxy(40, k + 9);
				cout << "������ ������ �Է��ϼ��� : ";
				cin >> new_score;
				if (subject == "����") {
					mg.score1 = new_score;
				}
				else if (subject == "����") {
					mg.score2 = new_score;
				}
				else if (subject == "����") {
					mg.score3 = new_score;
				}
				else if (subject == "����") {
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
					cout << "������ ������ ������ �Է��ϼ��� : ";
					cin >> subject;
					gotoxy(40, k + 9);
					cout << "������ ������ �Է��ϼ��� : ";
					cin >> new_score;
				}

				// ���� ���� ����
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

				// ������ ���� �Է�
				ofstream fout("second_grade.txt", ios::app);
				fout << mg.student_num << setw(10) << mg.student_name << setw(7) << mg.score1 << setw(7) << mg.score2 << setw(7)
					<< mg.score3 << setw(7) << mg.score4 << setw(7) << mg.score7 << setw(7) << mg.score6 << setw(7) << mg.score7
					<< setw(7) << mg.score8 << setw(7) << endl;
			}
		}

		gotoxy(45, 23);
		cout << "������ �����Ǿ����ϴ�" << endl;

		gotoxy(23, 26);
		int select = -1;
		cout << "(0 �Է� : ����ȭ��, 1 �Է� : ����޴�, 2 �Է� : ���� �����ϱ�) : ";
		cin >> select;
		while (true) {
			switch (select) {
				//case 1:ShowGrade(); break;
			case 0: MainPage(); break;
			case 1: TeacherPage(); break;
			case 2: modifyGrade(); break;
			default:
				gotoxy(47, 27);
				printf("�������� �ʴ� �޴��Դϴ�");
				gotoxy(15, 26);
				printf("(0 �Է� : ����ȭ��, 1 �Է� : ����޴�, 2 �Է� : ���� �����ϱ�) : ");
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
		printf("��");
		for (i = 0; i < 98; i++) {
			printf("��");
		}
		printf("��");

		for (i = 0; i < 30; i++) {
			y++;
			gotoxy(x, y);
			printf("��");

			x += 99;
			gotoxy(x, y);
			printf("��");
			x = 9;
		}
		gotoxy(x, y);
		printf("��");
		for (i = 0; i < 98; i++) {
			printf("��");
		}
		printf("��\n\n\n");

		for (int k = 0; k < 30; k++) {
			if (k == 11) {
				gotoxy(40, k);
				ifstream third_grade("third_grade.txt");
				cout << "�ڽ��� �й��� �Է��ϼ��� : ";
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
						cout << "�й�     �̸�     ����1   ����2   ����3   ����   �繫����   DB   server   Programming" << endl;
						gotoxy(17, k + 4);
						cout << mg.student_num << setw(10) << student_name <<
							setw(6) << score1 << setw(8) << score2 << setw(8) << score3 << setw(8) << score4 << setw(9)
							<< score5 << setw(9) << score6 << setw(7) << score7 << setw(11) << score8 << '\n';
						break;
					}
				}
				third_grade.close();

				// �������� �ٲ� ���� �����
				gotoxy(40, k + 7);
				cout << "������ ������ ������ �Է��ϼ��� : ";
				cin >> subject;
				gotoxy(40, k + 9);
				cout << "������ ������ �Է��ϼ��� : ";
				cin >> new_score;
				if (subject == "����") {
					mg.score1 = new_score;
				}
				else if (subject == "����") {
					mg.score2 = new_score;
				}
				else if (subject == "����") {
					mg.score3 = new_score;
				}
				else if (subject == "����") {
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
					cout << "������ ������ ������ �Է��ϼ��� : ";
					cin >> subject;
					gotoxy(40, k + 9);
					cout << "������ ������ �Է��ϼ��� : ";
					cin >> new_score;
				}

				// ���� ���� ����
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

				// ������ ���� �Է�
				ofstream fout("third_grade.txt", ios::app);
				fout << mg.student_num << setw(10) << mg.student_name << setw(7) << mg.score1 << setw(7) << mg.score2 << setw(7)
					<< mg.score3 << setw(7) << mg.score4 << setw(7) << mg.score7 << setw(7) << mg.score6 << setw(7) << mg.score7
					<< setw(7) << mg.score8 << setw(7) << endl;
			}
		}

		gotoxy(45, 23);
		cout << "������ �����Ǿ����ϴ�" << endl;

		gotoxy(23, 26);
		int select = -1;
		cout << "(0 �Է� : ����ȭ��, 1 �Է� : ����޴�, 2 �Է� : ���� �����ϱ�) : ";
		cin >> select;
		while (true) {
			switch (select) {
				//case 1:ShowGrade(); break;
			case 0: MainPage(); break;
			case 1: TeacherPage(); break;
			case 2: modifyGrade(); break;
			default:
				gotoxy(47, 27);
				printf("�������� �ʴ� �޴��Դϴ�");
				gotoxy(15, 26);
				printf("(0 �Է� : ����ȭ��, 1 �Է� : ����޴�, 2 �Է� : ���� �����ϱ�) : ");
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
	printf("��");
	for (i = 0; i < 98; i++) {
		printf("��");
	}
	printf("��");
	for (i = 0; i < 30; i++) {
		y++;
		gotoxy(x, y);
		printf("��");
		x += 99;
		gotoxy(x, y);
		printf("��");
		x = 9;
	}
	gotoxy(x, y);
	printf("��");
	for (i = 0; i < 98; i++) {
		printf("��");
	}
	printf("��\n\n\n");
	for (i = 0; i < 30; i++) {
		if (i == 14) {
			gotoxy(45, i);
			cout << "���� ��й�ȣ �Է� : ";
			cin >> old_pw;
			if (old_pw != TEACHER_PASSWORD) {
				gotoxy(45, i + 2);
				cout << "���� ��й�ȣ �Է� : ";
				cin >> old_pw;
			}
			else {
				collect = true;
			}
		}
		if (i == 16 && collect == true) {
			gotoxy(45, i);
			cout << "�� ��й�ȣ �Է� : ";
			cin >> new_pw;
			if (new_pw.length() < 6) {
				gotoxy(45, i + 2);
				cout << "��й�ȣ�� �ּ� 6���� �̻��̾�� �մϴ�";
				gotoxy(45, i);
				cout << "�� ��й�ȣ �Է� : ";
				cin >> new_pw;
			}
			if(new_pw.length() >= 6) {
				gotoxy(45, i + 2);
				cout << "�� ��й�ȣ Ȯ�� : ";
				cin >> new_pw_identify;
				if (new_pw == new_pw_identify) {
					TEACHER_PASSWORD = new_pw;
					gotoxy(45, i + 5);
					cout << "(0 : ����ȭ��, 1 : ����ȭ��) : ";
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

// �л� => ���� ����
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
	printf("��");
	for (i = 0; i < 98; i++) {
		printf("��");
	}
	printf("��");
	for (i = 0; i < 30; i++) {
		y++;
		gotoxy(x, y);
		printf("��");
		x += 99;
		gotoxy(x, y);
		printf("��");
		x = 9;
	}
	gotoxy(x, y);
	printf("��");
	for (i = 0; i < 98; i++) {
		printf("��");
	}
	printf("��\n\n\n");
	for (i = 0; i < 30; i++) {
		if (i == 13) {
			if (flag == 1) {
				ifstream first_grade("first_grade.txt");
				if (isStudent == 1) {
					gotoxy(45, i);
					cout << "�ڽ��� �й��� �Է��ϼ��� : ";
				}
				else {
					gotoxy(40, i);
					cout << "�˻��� ���ϴ� �л��� �й��� �Է��ϼ��� : ";
				}
				cin >> hakbun;
				hakbun2 = to_string(hakbun);

				while (!first_grade.eof()) {
					getline(first_grade, line);
					if ((offset = line.find(hakbun2, 0)) != string::npos) {
						gotoxy(20, i + 3);
						cout << "�й�     �̸�      ����   ����   ����   ��ȸ   ����   JAVA   C     ��ǻ�� ����" << endl;
						gotoxy(20, i + 4);
						cout << line << endl;
						visible = true;
					}
				}
				if (visible == false) {
					gotoxy(40, i + 3);
					cout << "�ش� �й��� �Էµ� ������ �����ϴ�" << endl;
				}
				first_grade.close();
				visible = false;
				return line;
			}
			else if (flag == 2) {
				gotoxy(45, i);
				ifstream second_grade("second_grade.txt");
				cout << "�ڽ��� �й��� �Է��ϼ��� : ";
				cin >> hakbun;
				hakbun2 = to_string(hakbun);

				while (!second_grade.eof()) {
					getline(second_grade, line);
					if ((offset = line.find(hakbun2, 0)) != string::npos) {
						gotoxy(18, i + 3);
						cout << "�й�     �̸�      ����   ����   ����   ����   JSP   JAVA     C++     Python  DS  " << endl;
						gotoxy(18, i + 4);
						cout << line << endl;
						visible = true;
					}
				}
				if (visible == false) {
					gotoxy(40, i + 3);
					cout << "�ش� �й��� �Էµ� ������ �����ϴ�" << endl;
				}
				second_grade.close();
				visible = false;
				return line;
			}
			else {
				gotoxy(45, i);
				ifstream third_grade("third_grade.txt");
				cout << "�ڽ��� �й��� �Է��ϼ��� : ";
				cin >> hakbun;
				hakbun2 = to_string(hakbun);

				while (!third_grade.eof()) {
					getline(third_grade, line);
					if ((offset = line.find(hakbun2, 0)) != string::npos) {
						gotoxy(20, i + 3);
						cout << "�й�     �̸�     ����1  ����2  ����3  ����  �繫����  DB  server   Programming" << endl;
						gotoxy(20, i + 4);
						cout << line << endl;
						visible = true;
					}
				}
				if (visible == false) {
					gotoxy(40, i + 3);
					cout << "�ش� �й��� �Էµ� ������ �����ϴ�" << endl;
				}
				third_grade.close();
				visible = false;
				return line;
			}
		}
	}
}

// �л� -> ���� ����
void showGrade() {
	string line = searchGrade(1);

	int i, j;
	int x = 9;
	int y = 4;
	char flag;

	int studentMenuSelect = 0;

	int where;

	gotoxy(x, y);
	printf("��");
	for (i = 0; i < 98; i++) {
		printf("��");
	}
	printf("��");
	for (i = 0; i < 30; i++) {
		y++;
		gotoxy(x, y);
		printf("��");
		x += 99;
		gotoxy(x, y);
		printf("��");
		x = 9;
	}
	gotoxy(x, y);
	printf("��");
	for (i = 0; i < 98; i++) {
		printf("��");
	}
	printf("��\n\n\n");

	boolean success = true;

	for (j = 0; j < 30; j++) {
		if (j == 16) {
			gotoxy(35, j + 5);
			cout << "(0 : ����ȭ��, 1 : �л�ȭ��, 2 : �ٽ� �˻�) : ";
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
				cout << "�������� �ʴ� �޴��Դϴ�";
				gotoxy(35, j + 3);
				cout << "(0 : ����ȭ��, 1 : �л�ȭ��, 2 : �ٽ� �˻�) : ";
				cin >> where;
			}
		}
	}
}

// ���� -> �л� �˻��ϱ�
void showGradeT() {
	string line = searchGrade(0);

	int i, j;
	int x = 9;
	int y = 4;
	char flag;

	int studentMenuSelect = 0;

	int where;

	gotoxy(x, y);
	printf("��");
	for (i = 0; i < 98; i++) {
		printf("��");
	}
	printf("��");
	for (i = 0; i < 30; i++) {
		y++;
		gotoxy(x, y);
		printf("��");
		x += 99;
		gotoxy(x, y);
		printf("��");
		x = 9;
	}
	gotoxy(x, y);
	printf("��");
	for (i = 0; i < 98; i++) {
		printf("��");
	}
	printf("��\n\n\n");

	boolean success = true;

	for (j = 0; j < 30; j++) {
		if (j == 16) {
			gotoxy(35, j + 5);
			cout << "(0 : ����ȭ��, 1 : ����ȭ��, 2 : �ٽ� �˻�) : ";
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
				cout << "�������� �ʴ� �޴��Դϴ�";
				gotoxy(35, j + 3);
				cout << "(0 : ����ȭ��, 1 : ����ȭ��, 2 : �ٽ� �˻�) : ";
				cin >> where;
			}
		}
	}
}

// ���� �Է� �Ϸ� ȭ��
void GradeSuccess() {
	system("cls");
	int i, j;
	int x = 9;
	int y = 4;
	char flag;

	int studentMenuSelect = 0;

	gotoxy(x, y);
	printf("��");
	for (i = 0; i < 98; i++) {
		printf("��");
	}
	printf("��");
	for (i = 0; i < 30; i++) {
		y++;
		gotoxy(x, y);
		printf("��");
		x += 99;
		gotoxy(x, y);
		printf("��");
		x = 9;
	}
	gotoxy(x, y);
	printf("��");
	for (i = 0; i < 98; i++) {
		printf("��");
	}
	printf("��\n\n\n");

	boolean success = true;

	for (j = 0; j < 30; j++) {
		if (j == 15) {
			while (success == true) {
				gotoxy(45, j);
				cout << "�����Է��� �Ϸ�Ǿ����ϴ�!!" << endl;
				gotoxy(30, 17);
				cout << "(0 �Է� : ����ȭ��, 1 �Է� : ����޴�, 2 �Է� : ���� �Է��ϱ�) : ";
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
					cout << "0�̳� 1�� �Է����ּ���" << endl;
				}
			}
		}
	}
} // end of GradeSuccess

// ObjectionŬ���� (���ǽ�û Ŭ����)
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

// ���ǽ�û ȭ��
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
	printf("��");
	for (i = 0; i < 98; i++) {
		printf("��");
	}
	printf("��");
	for (i = 0; i < 30; i++) {
		y++;
		gotoxy(x, y);
		printf("��");
		x += 99;
		gotoxy(x, y);
		printf("��");
		x = 9;
	}
	gotoxy(x, y);
	printf("��");
	for (i = 0; i < 98; i++) {
		printf("��");
	}
	printf("��\n\n\n");
	for (j = 0; j < 30; j++) {
		if (j == 14) {
			gotoxy(35, j);
			cout << "�й��� �Է����ּ��� : ";
			cin >> student_num;
			string remainder;
			getline(cin, remainder);
		}
		if (j == 16) {
			gotoxy(35, j);
			cout << "���ǽ�û�� ������ �Է����ּ��� : ";
			getline(cin, subject, '\n'); // ������� �ص� �Է� ����
		}
		if (j == 18) {
			gotoxy(35, j);
			cout << "������ �����ּ���(�ִ� 50��) : ";
			getline(cin, reason); // ������� �ص� �Է� ����
		}
	}
	Objection ob(student_num, subject, reason);
	return ob;
} // end of Objection::writeObjection

// ���ǽ�û �Ϸ� ȭ��
void ObjectionSuccess() {
	system("cls");
	int i, j;
	int x = 9;
	int y = 4;
	char flag;

	int studentMenuSelect = 0;

	gotoxy(x, y);
	printf("��");
	for (i = 0; i < 98; i++) {
		printf("��");
	}
	printf("��");
	for (i = 0; i < 30; i++) {
		y++;
		gotoxy(x, y);
		printf("��");
		x += 99;
		gotoxy(x, y);
		printf("��");
		x = 9;
	}
	gotoxy(x, y);
	printf("��");
	for (i = 0; i < 98; i++) {
		printf("��");
	}
	printf("��\n\n\n");

	boolean success = true;

	for (j = 0; j < 30; j++) {
		if (j == 15) {
			while (success == true) {
				gotoxy(45, j);
				cout << "���ǽ�û�� �Ϸ�Ǿ����ϴ�!!" << endl;
				gotoxy(30, 17);
				cout << "(0 �Է� : ����ȭ��, 1 �Է� : �л��޴�, 2 �Է� : ���ǽ�û�ϱ�) : ";
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
					cout << "0�̳� 1�� �Է����ּ���" << endl;
				}
			}
		}
	}
} // end of ObjectionSuccess

// ���������� Ȯ���ϴ� â (��й�ȣ ���)
void IsTeacher() {
	system("cls");
	int i;
	int x = 9;
	int y = 4;

	string teacherPw;

	gotoxy(x, y);
	printf("��");
	for (i = 0; i < 98; i++) {
		printf("��");
	}
	printf("��");

	for (i = 0; i < 30; i++) {
		y++;
		gotoxy(x, y);
		printf("��");
		x += 99;
		gotoxy(x, y);
		printf("��");
		x = 9;
	}
	gotoxy(x, y);
	printf("��");
	for (i = 0; i < 98; i++) {
		printf("��");
	}
	printf("��\n\n\n");

	for (int k = 0; k < 30; k++) {
		if (k == 12) {
			gotoxy(50, k);
			cout << "���� ���� Ȯ��" << endl;
		}
		if (k == 17) {
			while (teacherPw != TEACHER_PASSWORD) {
				gotoxy(47, k + 5);
				cout << "(�ڷΰ����� 0�Է�)" << endl;
				gotoxy(35, k);
				cout << "���� ��й�ȣ�� �Է����ּ��� : ";
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
					cout << "��й�ȣ�� Ʋ�Ƚ��ϴ�" << endl;
					gotoxy(35, k);
					cout << "���� ��й�ȣ�� �Է����ּ��� : ";
					cin >> teacherPw;
					gotoxy(47, k + 5);
					cout << "(�ڷΰ����� 0 �Է�)" << endl;
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

// �л� ���� ������ �Լ�
void StudentPage() {
	system("cls");
	int i;
	int x = 9;
	int y = 4;

	int studentMenuSelect = 0;

	gotoxy(x, y);
	printf("��");
	for (i = 0; i < 98; i++) {
		printf("��");
	}
	printf("��");

	for (i = 0; i < 30; i++) {
		y++;
		gotoxy(x, y);
		printf("��");

		if (i == 14) {
			gotoxy(56, i);
			printf("�л� �޴�");
		}
		if (i == 18) {
			gotoxy(53, i);
			printf("01. ��������");
		}
		if (i == 20) {
			gotoxy(53, i);
			printf("02. ���ǽ�û�ϱ�");
		}
		if (i == 22) {
			gotoxy(53, i);
			printf("03. �ڷΰ���");
		}

		x += 99;
		gotoxy(x, y);
		printf("��");
		x = 9;
	}
	gotoxy(x, y);
	printf("��");
	for (i = 0; i < 98; i++) {
		printf("��");
	}
	printf("��\n\n\n");

	gotoxy(53, 25);
	printf("��ȣ �Է� : ");
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
			printf("�������� �ʴ� �޴��Դϴ�");
			gotoxy(53, 25);
			printf("��ȣ �Է� : ");
			scanf_s("%d", &studentMenuSelect);
		}
	}
}

// ���� ���� ������ �Լ�
void TeacherPage() {
	system("cls");
	int i;
	int x = 9;
	int y = 4;

	int teacherMenuSelect = 0;

	gotoxy(x, y);
	printf("��");
	for (i = 0; i < 98; i++) {
		printf("��");
	}
	printf("��");

	for (i = 0; i < 30; i++) {
		y++;
		gotoxy(x, y);
		printf("��");

		if (i == 8) {
			gotoxy(54, i);
			printf("����޴�");
		}
		if (i == 12) {
			gotoxy(46, i);
			printf("01. ��ü �л� ���� ����");
		}
		if (i == 14) {
			gotoxy(46, i);
			printf("02. �л� �˻��ϱ�");
		}
		if (i == 16) {
			gotoxy(46, i);
			printf("03. �л� ���� �Է��ϱ�");
		}
		if (i == 18) {
			gotoxy(46, i);
			printf("04. �л� ���� �����ϱ�");
		}
		if (i == 20) {
			gotoxy(46, i);
			printf("05. ���ǽ�û ��� ����");
		}
		if (i == 22) {
			gotoxy(46, i);
			printf("06. ��й�ȣ ����");
		}if (i == 24) {
			gotoxy(46, i);
			printf("07. �ڷΰ���");
		}

		x += 99;
		gotoxy(x, y);
		printf("��");
		x = 9;
	}

	gotoxy(x, y);
	printf("��");
	for (i = 0; i < 98; i++) {
		printf("��");
	}
	printf("��\n\n\n");

	gotoxy(53, 27);
	printf("��ȣ �Է� : ");
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
		printf("�������� �ʴ� �޴��Դϴ�");
		gotoxy(53, 27);
		printf("��ȣ �Է� : ");
		scanf_s("%d", &teacherMenuSelect);
	}
}

// ����ȭ�� (ùȭ��) �Լ�
void MainPage() {
	system("mode con:cols=120 lines=40");

	int i;
	int x = 9;
	int y = 4;

	int menuSelect = 0;

	gotoxy(x, y);
	printf("��");
	for (i = 0; i < 98; i++) {
		printf("��");
	}
	printf("��");

	for (i = 0; i < 30; i++) {
		y++;
		gotoxy(x, y);
		printf("��");

		if (i == 14) {
			gotoxy(48, i);
			printf("�л� ���� ���� ���α׷�");
		}
		if (i == 18) {
			gotoxy(53, i);
			printf("01. �л��޴�");
		}
		if (i == 20) {
			gotoxy(53, i);
			printf("02. ����޴�");
		}

		x += 99;
		gotoxy(x, y);
		printf("��");
		x = 9;
	}
	gotoxy(x, y);
	printf("��");
	for (i = 0; i < 98; i++) {
		printf("��");
	}
	printf("��\n\n\n");

	gotoxy(53, 23);
	printf("��ȣ �Է� : ");
	scanf_s("%d", &menuSelect);
	if (menuSelect == 1) {
		StudentPage();
	}
	else if (menuSelect == 2) {
		IsTeacher();
	}
	else if (typeid(menuSelect).name() == "int") {
		gotoxy(47, 18);
		printf("�������� �ʴ� �޴��Դϴ�");
	}
	else {
		gotoxy(47, 18);
		printf("���ڸ� �Է����ּ���");
	}
}

// �г��� �����ϴ� �Լ�
int ChoiceGrade() {
	system("cls");

	int i;
	int x = 9;
	int y = 4;

	int gradeSelect = 0;

	gotoxy(x, y);
	printf("��");
	for (i = 0; i < 98; i++) {
		printf("��");
	}
	printf("��");

	for (i = 0; i < 30; i++) {
		y++;
		gotoxy(x, y);
		printf("��");

		if (i == 13) {
			gotoxy(48, i);
			printf("�г��� �������ּ���");
		}
		if (i == 17) {
			gotoxy(53, i);
			printf("01. 1�г�");
		}
		if (i == 19) {
			gotoxy(53, i);
			printf("02. 2�г�");
		}
		if (i == 21) {
			gotoxy(53, i);
			printf("03. 3�г�");
		}

		x += 99;
		gotoxy(x, y);
		printf("��");
		x = 9;
	}
	gotoxy(x, y);
	printf("��");
	for (i = 0; i < 98; i++) {
		printf("��");
	}
	printf("��\n\n\n");

	gotoxy(50, 25);
	printf("��ȣ �Է� : ");
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
		// 1, 2, 3 �г� �� �ƴ� �ٸ� ���� �������� �� ó��
	}
}

// ���� -> ���ǽ�û ��� ����
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
		printf("��");
		for (i = 0; i < 98; i++) {
			printf("��");
		}
		printf("��");
		for (i = 0; i < 30; i++) {
			y++;
			gotoxy(x, y);
			printf("��");
			x += 99;
			gotoxy(x, y);
			printf("��");
			x = 9;
		}
		gotoxy(x, y);
		printf("��");
		for (i = 0; i < 98; i++) {
			printf("��");
		}
		printf("��\n\n\n");

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
		printf("��");
		for (i = 0; i < 98; i++) {
			printf("��");
		}
		printf("��");
		for (i = 0; i < 30; i++) {
			y++;
			gotoxy(x, y);
			printf("��");
			x += 99;
			gotoxy(x, y);
			printf("��");
			x = 9;
		}
		gotoxy(x, y);
		printf("��");
		for (i = 0; i < 98; i++) {
			printf("��");
		}
		printf("��\n\n\n");

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
		printf("��");
		for (i = 0; i < 98; i++) {
			printf("��");
		}
		printf("��");
		for (i = 0; i < 30; i++) {
			y++;
			gotoxy(x, y);
			printf("��");
			x += 99;
			gotoxy(x, y);
			printf("��");
			x = 9;
		}
		gotoxy(x, y);
		printf("��");
		for (i = 0; i < 98; i++) {
			printf("��");
		}
		printf("��\n\n\n");

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
			cout << "(0 �Է� : ����ȭ��, 1 �Է� : ����޴�, 2 �Է� : ���ǽ�û ��Ϻ���) : ";
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
				cout << "0�̳� 1�� �Է����ּ���" << endl;
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
		printf("��");
		for (i = 0; i < 98; i++) {
			printf("��");
		}
		printf("��");
		for (i = 0; i < 30; i++) {
			y++;
			gotoxy(x, y);
			printf("��");
			x += 99;
			gotoxy(x, y);
			printf("��");
			x = 9;
		}
		gotoxy(x, y);
		printf("��");
		for (i = 0; i < 98; i++) {
			printf("��");
		}
		printf("��\n\n\n");

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
		printf("��");
		for (i = 0; i < 98; i++) {
			printf("��");
		}
		printf("��");
		for (i = 0; i < 30; i++) {
			y++;
			gotoxy(x, y);
			printf("��");
			x += 99;
			gotoxy(x, y);
			printf("��");
			x = 9;
		}
		gotoxy(x, y);
		printf("��");
		for (i = 0; i < 98; i++) {
			printf("��");
		}
		printf("��\n\n\n");

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
		printf("��");
		for (i = 0; i < 98; i++) {
			printf("��");
		}
		printf("��");
		for (i = 0; i < 30; i++) {
			y++;
			gotoxy(x, y);
			printf("��");
			x += 99;
			gotoxy(x, y);
			printf("��");
			x = 9;
		}
		gotoxy(x, y);
		printf("��");
		for (i = 0; i < 98; i++) {
			printf("��");
		}
		printf("��\n\n\n");

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
			cout << "(0 �Է� : ����ȭ��, 1 �Է� : ����޴�, 2 �Է� : ��ü ���� ����) : ";
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
				cout << "0�̳� 1�� �Է����ּ���" << endl;
			}
		}
	}
} // end of ShowGrades

// �����Լ�
int main() {
	MainPage();
	return 0;
} // end of main