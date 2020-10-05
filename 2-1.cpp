#include <iostream>
#include <fstream>
using namespace std;



int my_len(char *str1); // strlen
char* my_cpy(char *str2, char *str1); // strcpy
char* my_tok(char *str1, char *par); // strtok

int main() {
	char data[100] = { 0, };

	ifstream fin;
	fin.open("input.txt"); // "input.txt" file open

	if (fin.fail()) { // file open exeption handling
		cout << "파일 불러오기에 실패했습니다." << endl;
		return 0;
	}

	while (!fin.eof()) {
		fin.getline(data, 100);
		cout << data << endl;
		cout << "string length: " << my_len(data) << endl;
		char *data2 = new char[my_len(data) + 1]; // new Dynamic allocation
		cout << "print new parameter: " << my_cpy(data2, data);
		cout << endl << "the result of truncating string (delimeter is ' ')" << endl;
		cout << my_tok(data2, " ") << endl;
		cout << my_tok(NULL, " ") << endl;
		cout << my_tok(NULL, " ") << endl;
		delete[] data2; //delete Dynamic allocation
	}

	fin.close(); // file close
	
	cout << endl;

	return 0;
	
}

//strlen
int my_len(char *str1) {

	int len = 0;

	while (str1[len] != NULL) //문자열이 끝날 때 까지 While문을 수행
	{
		len = len + 1;
	}
	return len;	//문자열의 길이를 return한다.
}
//strcpy
char* my_cpy(char *str2, char *str1) {

	for (int i = 0; str1[i] != 0; i++)	//복사하려는 문자열 끝까지 for문을 수행
	{
		str2[i] = str1[i];	//복사하려는 문자열 Str1을 Str2에 넣어준다.
		str2[i + 1] = 0;	//문자열의 끝을 NULL값을 삽입
		
	}

	return str2;	//복사한 문자열을 리턴
}
//strtok
char* my_tok(char *str1, char *par) {

	static char *start = NULL;	//문자열
	static char *tracer = NULL; //문자열을 추적하는 변수
	char *delem;	//Delimeter

	if (str1 != NULL) tracer = str1;	//새로운문자열이 들어올 시 tracer변수에 삽입
	if (par == NULL || *par == NULL) return NULL; //Delimeter와 들어온 문자열이 NULL일때
	if (tracer == NULL || *tracer == '\0') return NULL;

	while (*tracer)
	{	//현재문자와 분리문자열과 비교
		for (delem = par; *delem; delem++) {
			if (*tracer == *delem) break;
		}
		if (*delem == '\0') break;
		tracer++;
	}
	//찾는 문자가 있을 때 까지 검사하는 for문
	for (start = tracer; *tracer; tracer++) {
		for (delem = par; *delem; delem++) {
			if (*tracer == *delem) break; // 같으면 break
		}
		if (*delem) {
			*tracer++ = '\0';
			break; //분리문자가 NULL일 경우 break
		}
	}

	return(start); //분리한 문자열을 리턴
}
