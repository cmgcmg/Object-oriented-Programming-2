#include <iostream>
#include <fstream>
using namespace std;

char* my_cpy(char *str2, char *str1); //strcpy
int my_len(char *str1);	//strlen

int main() {
	int i = 0;
	int result = 0;
	int max = 0;
	double avg = 0;
	int line[100] = { 0, }; // 문자열 길이를 담기 위해 사용한 배열
	char data[128] = { 0, }; //메모장을 받아들일 배열, 한줄의 길이가 128

	ifstream fin;
	fin.open("input.txt");	//File Open

	if (!fin) {	//File Open Exeption handling
		cout << "파일 불러오기에 실패했습니다." << endl;
		return 0;
	}

	while (!fin.eof()) {
		fin.getline(data, 128); //File의 데이타를 한줄씩불러온다
		line[i] = my_len(data); //i는 줄, line[i]에는 문자열의 길이
		char *data2 = new char[my_len(data) + 1]; //문자열 길이 만큼 동적배열 할당, \n값때문에 len + 1
		my_cpy(data2, data); //Data2에 한줄씩 읽어온 데이터를 복사
		cout << data2 << " - " << my_len(data2) << endl;
		i++;
		delete[] data2; // 동적배열할당 해제
	}
	cout << endl;

	for (int j = 0; j < i; j++) {
		result += line[j];
	}
	avg = ((double)result / (double)i);
	cout.setf(ios::fixed);
	cout.precision(1); // 소수점 1자리수 출력하기 위한 함수
	cout << "The average legnth is " << avg << endl;
	
	max = i - 1; // max값을 배열의 마지막 번호로 설정

	//배열의 전전번부터 for문을 이용해서 가장 긴 라인을 찾는다.
	for (int j = i - 2; j >= 0; j--) {
		if (line[max] <= line[j]) {
			max = j;
		}
	}
	
	//배열 번호를 찾은거니까 max + 1을 출력하면 가장 긴라인이다.
	cout << "The longest line is line " << max + 1 << endl; // 가장 긴 라인 출력

	fin.close(); // File Close

	return 0;
}

char* my_cpy(char *str2, char *str1) {

	for (int i = 0; str1[i] != 0; i++)	//복사하려는 문자열 끝까지 for문을 수행
	{
		str2[i] = str1[i];	//복사하려는 문자열 Str1을 Str2에 넣어준다.
		str2[i + 1] = 0;	//문자열의 끝을 NULL값을 삽입
	}

	return str2;	//복사한 문자열을 리턴
}

int my_len(char *str1) {

	int len = 0;

	while (str1[len] != NULL) //문자열이 끝날 때 까지 While문을 수행
	{
		len = len + 1;
	}
	return len;	//문자열의 길이를 return한다.
}

