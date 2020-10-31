#include <iostream>
#include <vector>
#include <Windows.h>
using namespace std;

class student {
private:
	int id;
	char* name;
	double totalPoint;

	vector<int> month;
	vector<int> day;
	vector<double> point;
	vector < string> recode;

	vector<int> vmonth;
	vector<int> vday;
	vector<string> vtime;
public:
	student(int id, const char* myname, double totalPoint) {
		this->id = id;
		int len = strlen(myname) + 1;
		name = new char[len];
		strcpy_s(name, len, myname);
		this->totalPoint = 0;
	}
	void addPointRecode(int month, int day, double point, string myrecode) {
		this->month.push_back(month);
		this->day.push_back(day);
		this->point.push_back(point);
		this->recode.push_back(myrecode);
		this->totalPoint += point;
	}
	void addVolunteer(int vmonth, int vday, string vtime) {
		this->vmonth.push_back(vmonth);
		this->vday.push_back(vday);
		this->vtime.push_back(vtime);
	}
	void printPointRecode() {
		for (int i = 0; i < 0; i++) {
			cout << this->id << "\t";
			cout << this->name << "\t";
			cout << this << month[i] << "월\t";
			cout << this << day[i] << "일\t";
			cout << this << point[i] << "점\t";
			cout << this << recode[i] << endl;
		}
	}
	void student_apply_volunteer(int id) {
		int i, x = 10, y = 3;
		int vmonth, vday, vtime;
		system("cls");

		gotoxy(x, y++);
		cout << "봉사 신청할 월 >> ";
		cin >> vmonth; y++;
	}
};