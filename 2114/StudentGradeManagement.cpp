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
//void WriteGrade();
int ChoiceGrade(); // �г� ���� ȭ��
//void ShowAllGrades();
//void ShowGrade();

void GradeSuccess(); // ���� �Է� �Ϸ� ȭ��
void ShowGrades(); // ���� ���� ȭ��

void ShowObjections(); // ���ǽ�û ���� ȭ��
void ObjectionSuccess(); // ���ǽ�û �Ϸ� ȭ��

void IsTeacher(); // ���� ��й�ȣ �Է� ȭ��

void modityGrade(); // �л� ���� ����

string searchGrade(int isStudent); // �л� ���� �˻����ִ� �Լ�

void showGrade(); // �л� �޴� => �л� ���� �����ִ� �Լ�

void showGradeT(); // ���� �޴� => �л� ���� �����ִ� �Լ�

void changeTeacherPW(); // ������ ��й�ȣ �ٲ��ִ� �Լ� - �� �� �� ���� ��� �� �����ϱ�===================================================================================

// ���� ��й�ȣ
const string TEACHER_PASSWORD = "teacher";

// gotoxy �Լ�
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

// ���� ����
void modityGrade() {
	int hakbun;
	string hakbun2;
	string line;
	int offset;

	// �й� �Է¹ޱ�
	int flag = ChoiceGrade();

	// �ش� �й��� �ִ� �ٿ� �������ϱ�
	if (flag == 1) {
		ifstream first_grade("first_grade.txt");
		cout << "�ڽ��� �й��� �Է��ϼ��� : ";
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
	
	// �������� �ٲ� ���� �����
	// ���� �Է��ϱ�
	// ���� �Ϸ�
	FILE* p_file = NULL;
	char temp[256], * p;
	int find_pos;

	if (0 == fopen_s(&p_file, "first_grade.txt", "r+t")) {
		while (fgets(temp, 256, p_file) != NULL) {
			p = strstr(temp, "������");
			if (p != NULL) {
				find_pos = strlen(temp) - (p - temp) + 1;
				fseek(p_file, (-1) * find_pos, SEEK_CUR);
				fwrite("������", 4, 1, p_file);
				fseek(p_file, find_pos - 4, SEEK_CUR);
			}
		}
		fclose(p_file);
		//fout.seekp(-1, ios::end);
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

// ���ǽ�û Ŭ����
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

		if (i == 10) {
			gotoxy(54, i);
			printf("����޴�");
		}
		if (i == 14) {
			gotoxy(46, i);
			printf("01. ��ü �л� ���� ����");
		}
		if (i == 16) {
			gotoxy(46, i);
			printf("02. �л� �˻��ϱ�");
		}
		if (i == 18) {
			gotoxy(46, i);
			printf("03. �л� ���� �Է��ϱ�");
		}
		if (i == 20) {
			gotoxy(46, i);
			printf("04. �л� ���� �����ϱ�");
		}
		if (i == 22) {
			gotoxy(46, i);
			printf("05. ���ǽ�û ��� ����");
		}
		if (i == 24) {
			gotoxy(46, i);
			printf("06. �ڷΰ���");
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
	case 4:modityGrade();  break;
	case 5: ShowObjections();  break;
	case 6: MainPage(); break;
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
		TeacherPage();
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
//		printf("��");
//		for (i = 0; i < 98; i++) {
//			printf("��");
//		}
//		printf("��");
//
//		for (i = 0; i < 30; i++) {
//			y++;
//			gotoxy(x, y);
//			printf("��");
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
//			printf("��");
//			x = 9;
//		}
//		gotoxy(x, y);
//		printf("��");
//		for (i = 0; i < 98; i++) {
//			printf("��");
//		}
//		printf("��\n\n\n");
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
//		printf("��");
//		for (i = 0; i < 98; i++) {
//			printf("��");
//		}
//		printf("��");
//
//		for (i = 0; i < 30; i++) {
//			y++;
//			gotoxy(x, y);
//			printf("��");
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
//			printf("��");
//			x = 9;
//		}
//		gotoxy(x, y);
//		printf("��");
//		for (i = 0; i < 98; i++) {
//			printf("��");
//		}
//		printf("��\n\n\n");
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
//		printf("��");
//		for (i = 0; i < 98; i++) {
//			printf("��");
//		}
//		printf("��");
//
//		for (i = 0; i < 30; i++) {
//			y++;
//			gotoxy(x, y);
//			printf("��");
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
//			printf("��");
//			x = 9;
//		}
//		gotoxy(x, y);
//		printf("��");
//		for (i = 0; i < 98; i++) {
//			printf("��");
//		}
//		printf("��\n\n\n");
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
//		printf("��");
//		for (i = 0; i < 98; i++) {
//			printf("��");
//		}
//		printf("��");
//
//		for (i = 0; i < 30; i++) {
//			y++;
//			gotoxy(x, y);
//			printf("��");
//
//			x += 99;
//			gotoxy(x, y);
//			printf("��");
//			x = 9;
//		}
//		gotoxy(x, y);
//		printf("��");
//		for (i = 0; i < 98; i++) {
//			printf("��");
//		}
//		printf("��\n\n\n");
//		gotoxy(45, 17);
//		cout << "�й��� �Է��ϼ��� : ";
//		cin >> studnet_num;
//		// ���Ͽ��� �ش� �й��� ���� �����б�=======================================================================
//	}
//	else if (flag == 2) {
//
//	}
//	else {
//
//	}
//}

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
} // end of ShowGrades

// �����Լ�
int main() {
	MainPage();
	return 0;
} // end of main