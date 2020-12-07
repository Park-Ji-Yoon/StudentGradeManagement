//#include <iostream>
//#include <fstream>
//#include <string>
//
//int main() {
//	FILE* p_file = NULL;
//	char temp[256], * p;
//	int find_pos;
//
//	if (0 == fopen_s(&p_file, "data.txt", "r+t")) {
//		while (fgets(temp, 256, p_file) != NULL) {
//			p = strstr(temp, "10 20 30 40 50");
//			printf("찾기 전");
//			if (p != NULL) {
//				printf("찾기 후");
//				find_pos = strlen(temp) - (p - temp) + 1;
//				fseek(p_file, (-1) * find_pos, SEEK_CUR);
//				fwrite("", 2, 1, p_file);
//				fseek(p_file, find_pos - 4, SEEK_CUR);
//			}
//		}
//		fclose(p_file);
//	}
//}

#include <iostream>
#include <vector>
#include <Windows.h>
#include <conio.h>
#include <fstream>
#include <iomanip>
#include <string>
#define SIZE 100
//int main(void)
//{
//    FILE* fp = NULL;
//    char name[SIZE];
//    char word[SIZE];
//    char line[SIZE];
//    int num = 0;
//    printf("파일 이름: ");
//    gets(name);
//    if ((fp = fopen(name, "r")) == NULL)
//    {
//        printf("파일오픈오류\n");
//        exit(1);
//    }
//    printf("탐색할 단어: ");
//    gets(word);
//    while (!feof(fp))
//    {
//        num++;
//        fgets(line, SIZE, fp);
//        if (strstr(line, word) != NULL)
//        {
//            printf("%s: %d    %s", name, num, line);
//        }
//    }
//    fclose(fp);
//    return 0;
//}

void main() {
    FILE* fd, * fd1;
    char name[80];
    char line[80];
    char temp[2048];

    fd = fopen("data.txt", "rb");
    scanf("%s", &name);
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

    fd = fopen("data.txt", "wb");
    fprintf(fd, "%s", temp);
    fclose(fd);

    printf("삭제되었습니다.\n");
}

//#include <iostream>
//#include <fstream>
//#include <string>
//using namespace std;
//
//int main() {
//    std::fstream yourfile;
//    std::string line, someString;
//
//    yourfile.open("file.txt", ios::in | ios::app);  //The path to your file goes here
//
//    if (yourfile.is_open()) {  //You don't have to ask if the file is open but it's more secure
//        while (getline(cin, line)) {
//            if (line.find(someString) != string::npos) { //the find() documentation might be helpful if you don't understand
//                if (someString == "A") {
//                    //code for replacing the line
//                }
//                else {
//                    yourfile << "newString_2" << endl;
//                }
//            } //end if
//        } //end while
//    } //end if
//    else cerr << "Your file couldn't be opened";
//
//    yourfile.close();
//    return 0;
//}