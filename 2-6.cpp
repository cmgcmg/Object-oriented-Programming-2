#include <iostream>
#include <fstream>
#include "OOP.h"
using namespace std;

//OOP클래스에서 상속받은 수요일 Class
class Wed : public OOP {
private:
public:
	//strcpy
	char* my_cpy(char *str2, char *str1) {

		for (int i = 0; str1[i] != 0; i++)	//복사하려는 문자열 끝까지 for문을 수행
		{
			str2[i] = str1[i];	//복사하려는 문자열 Str1을 Str2에 넣어준다.
			str2[i + 1] = 0;	//문자열의 끝을 NULL값을 삽입
		}

		return str2;	//복사한 문자열을 리턴
	}
	//OOP클래스 에서 선언한 SetName함수를 정의
	void SetName(char* name, int sequence) 
	{
		Info[sequence].SetInfoName(name);	//해당하는 배열의 Name을 Set한다.
	}
	//OOP클래스 에서 선언한 SetScore함수를 정의
	void SetScore(int Score, int sequence)
	{
		Info[sequence].SetInfoScore(Score);	//해당하는 배열의 Score를 Set한다.
	}
	//OOP클래스 에서 선언한 GetName함수를 정의
	char* GetName(int sequence) 
	{
		return Info[sequence].GetInfoName();	//해당하는 배열의 Name정보를 Return 한다.
	}
	//OOP클래스 에서 선언한 GetScore함수를 정의
	int GetScore(int sequence) 
	{
		return Info[sequence].GetInfoScore();	//해당하는 배열의 Score 정보를 Return한다.
	}
	//Sorting하고 싶은 번호를 인자로 받아서 어떻게 Sorting 할 것인지 출력
	void PrintTitle(int num)
	{	
		if (num == 1)	//1번일 경우 Name에 관해 Sorting
			cout << "** Score List of Wednesday Sorted by Name **" << endl;
		else			//2번일 경우 Score에 관해 Sorting
			cout << "** Score List of Wednesday Sorted by Score **" << endl;
	}
	//Sorting하고 싶은 번호를 인자로 받아서 그에맞게 Sorting하고 출력
	void PrintInfo(int num)
	{	
		int Sort[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };	//배열 Sequence를 순서대로 담은 배열
		int temp;

		if (num == 1) {	//Name에 대해서 Sorting

			for (int i = 0; i < 10; i++) {
				for (int j = i + 1; j < 10; j++) {

					if (my_strcmp(Info[Sort[i]].GetInfoName(), Info[Sort[j]].GetInfoName()) < 0) {
						temp = Sort[i];
						Sort[i] = Sort[j];
						Sort[j] = temp;
					}
				}
			}

			for (int i = 0; i < 10; i++) { //Name에 대해서 Sorting한 정보를 출력
				cout << "수 " << Info[Sort[i]].GetInfoName() << " " << Info[Sort[i]].GetInfoScore() << endl;
			}
		}

		
		else {	//Score에 대해서 Sorting

			for (int i = 0; i < 10; i++) {
				for (int j = i + 1; j < 10; j++) {
					if (Info[Sort[i]].GetInfoScore() > Info[Sort[j]].GetInfoScore() ) {
						temp = Sort[i];
						Sort[i] = Sort[j];
						Sort[j] = temp;
					}
				}
			}

			for (int i = 0; i < 10; i++) {	//Socre에 대해서 Sorting한 결과를 출력
				cout << "수 " << Info[Sort[i]].GetInfoName() << " " << Info[Sort[i]].GetInfoScore() << endl;
			}
		}

	}
};

//OOP에서 상속받은 목요일 Class
class Thu : public OOP {
private:
public:
	//strcpy
	char* my_cpy(char *str2, char *str1) {

		for (int i = 0; str1[i] != 0; i++)	//복사하려는 문자열 끝까지 for문을 수행
		{
			str2[i] = str1[i];	//복사하려는 문자열 Str1을 Str2에 넣어준다.
			str2[i + 1] = 0;	//문자열의 끝을 NULL값을 삽입
		}

		return str2;	//복사한 문자열을 리턴
	}
	//OOP클래스 에서 선언한 SetName함수를 정의
	void SetName(char* name, int sequence)
	{
		Info[sequence].SetInfoName(name);	//해당하는 배열의 Name을 Set한다.
	}
	//OOP클래스 에서 선언한 SetScore함수를 정의
	void SetScore(int Score, int sequence)
	{
		Info[sequence].SetInfoScore(Score);	//해당하는 배열의 Score를 Set한다.
	}
	//OOP클래스 에서 선언한 GetName함수를 정의
	char* GetName(int sequence)
	{
		return Info[sequence].GetInfoName();	//해당하는 배열의 Name정보를 Return 한다.
	}
	//OOP클래스 에서 선언한 GetScore함수를 정의
	int GetScore(int sequence)
	{
		return Info[sequence].GetInfoScore();	//해당하는 배열의 Score 정보를 Return한다.
	}
	//Sorting하고 싶은 번호를 인자로 받아서 어떻게 Sorting 할 것인지 출력
	void PrintTitle(int num)
	{
		if (num == 1)	//1번일 경우 Name에 관해 Sorting
			cout << "** Score List of Wednesday Sorted by Name **" << endl;
		else			//2번일 경우 Score에 관해 Sorting
			cout << "** Score List of Wednesday Sorted by Score **" << endl;
	}
	//Sorting하고 싶은 번호를 인자로 받아서 그에맞게 Sorting하고 출력
	void PrintInfo(int num)
	{
		int Sort[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };	//배열 Sequence를 순서대로 담은 배열
		int temp;

		if (num == 1) {	//Name에 대해서 Sorting

			for (int i = 0; i < 10; i++) {
				for (int j = i + 1; j < 10; j++) {

					if (my_strcmp(Info[Sort[i]].GetInfoName(), Info[Sort[j]].GetInfoName()) < 0) {
						temp = Sort[i];
						Sort[i] = Sort[j];
						Sort[j] = temp;
					}
				}
			}

			for (int i = 0; i < 10; i++) { //Name에 대해서 Sorting한 정보를 출력
				cout << "목 " << Info[Sort[i]].GetInfoName() << " " << Info[Sort[i]].GetInfoScore() << endl;
			}
		}


		else {	//Score에 대해서 Sorting

			for (int i = 0; i < 10; i++) {
				for (int j = i + 1; j < 10; j++) {
					if (Info[Sort[i]].GetInfoScore() > Info[Sort[j]].GetInfoScore()) {
						temp = Sort[i];
						Sort[i] = Sort[j];
						Sort[j] = temp;
					}
				}
			}

			for (int i = 0; i < 10; i++) {	//Socre에 대해서 Sorting한 결과를 출력
				cout << "목 " << Info[Sort[i]].GetInfoName() << " " << Info[Sort[i]].GetInfoScore() << endl;
			}
		}

	}
};

//OOP클래스에서 상속받은 금요일 Class
class Fri : public OOP {
private:
public:
	//strcpy
	char* my_cpy(char *str2, char *str1) {

		for (int i = 0; str1[i] != 0; i++)	//복사하려는 문자열 끝까지 for문을 수행
		{
			str2[i] = str1[i];	//복사하려는 문자열 Str1을 Str2에 넣어준다.
			str2[i + 1] = 0;	//문자열의 끝을 NULL값을 삽입
		}

		return str2;	//복사한 문자열을 리턴
	}
	//OOP클래스 에서 선언한 SetName함수를 정의
	void SetName(char* name, int sequence)
	{
		Info[sequence].SetInfoName(name);	//해당하는 배열의 Name을 Set한다.
	}
	//OOP클래스 에서 선언한 SetScore함수를 정의
	void SetScore(int Score, int sequence)
	{
		Info[sequence].SetInfoScore(Score);	//해당하는 배열의 Score를 Set한다.
	}
	//OOP클래스 에서 선언한 GetName함수를 정의
	char* GetName(int sequence)
	{
		return Info[sequence].GetInfoName();	//해당하는 배열의 Name정보를 Return 한다.
	}
	//OOP클래스 에서 선언한 GetScore함수를 정의
	int GetScore(int sequence)
	{
		return Info[sequence].GetInfoScore();	//해당하는 배열의 Score 정보를 Return한다.
	}
	//Sorting하고 싶은 번호를 인자로 받아서 어떻게 Sorting 할 것인지 출력
	void PrintTitle(int num)
	{
		if (num == 1)	//1번일 경우 Name에 관해 Sorting
			cout << "** Score List of Wednesday Sorted by Name **" << endl;
		else			//2번일 경우 Score에 관해 Sorting
			cout << "** Score List of Wednesday Sorted by Score **" << endl;
	}
	//Sorting하고 싶은 번호를 인자로 받아서 그에맞게 Sorting하고 출력
	void PrintInfo(int num)
	{
		int Sort[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };	//배열 Sequence를 순서대로 담은 배열
		int temp;

		if (num == 1) {	//Name에 대해서 Sorting

			for (int i = 0; i < 10; i++) {
				for (int j = i + 1; j < 10; j++) {

					if (my_strcmp(Info[Sort[i]].GetInfoName(), Info[Sort[j]].GetInfoName()) < 0) {
						temp = Sort[i];
						Sort[i] = Sort[j];
						Sort[j] = temp;
					}
				}
			}

			for (int i = 0; i < 10; i++) { //Name에 대해서 Sorting한 정보를 출력
				cout << "금 " << Info[Sort[i]].GetInfoName() << " " << Info[Sort[i]].GetInfoScore() << endl;
			}
		}


		else {	//Score에 대해서 Sorting

			for (int i = 0; i < 10; i++) {
				for (int j = i + 1; j < 10; j++) {
					if (Info[Sort[i]].GetInfoScore() > Info[Sort[j]].GetInfoScore()) {
						temp = Sort[i];
						Sort[i] = Sort[j];
						Sort[j] = temp;
					}
				}
			}

			for (int i = 0; i < 10; i++) {	//Socre에 대해서 Sorting한 결과를 출력
				cout << "금 " << Info[Sort[i]].GetInfoName() << " " << Info[Sort[i]].GetInfoScore() << endl;
			}
		}

	}
};

//OOP클래스에서 상속받은 미수강 Class
class None : public OOP {
private:
public:
	//strcpy
	char* my_cpy(char *str2, char *str1) {

		for (int i = 0; str1[i] != 0; i++)	//복사하려는 문자열 끝까지 for문을 수행
		{
			str2[i] = str1[i];	//복사하려는 문자열 Str1을 Str2에 넣어준다.
			str2[i + 1] = 0;	//문자열의 끝을 NULL값을 삽입
		}

		return str2;	//복사한 문자열을 리턴
	}
	//OOP클래스 에서 선언한 SetName함수를 정의
	void SetName(char* name, int sequence)
	{
		Info[sequence].SetInfoName(name);	//해당하는 배열의 Name을 Set한다.
	}
	//OOP클래스 에서 선언한 SetScore함수를 정의
	void SetScore(int Score, int sequence)
	{
		Info[sequence].SetInfoScore(Score);	//해당하는 배열의 Score를 Set한다.
	}
	//OOP클래스 에서 선언한 GetName함수를 정의
	char* GetName(int sequence)
	{
		return Info[sequence].GetInfoName();	//해당하는 배열의 Name정보를 Return 한다.
	}
	//OOP클래스 에서 선언한 GetScore함수를 정의
	int GetScore(int sequence)
	{
		return Info[sequence].GetInfoScore();	//해당하는 배열의 Score 정보를 Return한다.
	}
	//Sorting하고 싶은 번호를 인자로 받아서 어떻게 Sorting 할 것인지 출력
	void PrintTitle(int num)
	{
		if (num == 1)	//1번일 경우 Name에 관해 Sorting
			cout << "** Score List of Wednesday Sorted by Name **" << endl;
		else			//2번일 경우 Score에 관해 Sorting
			cout << "** Score List of Wednesday Sorted by Score **" << endl;
	}
	//Sorting하고 싶은 번호를 인자로 받아서 그에맞게 Sorting하고 출력
	void PrintInfo(int num)
	{
		int Sort[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };	//배열 Sequence를 순서대로 담은 배열
		int temp;

		if (num == 1) {	//Name에 대해서 Sorting

			for (int i = 0; i < 10; i++) {
				for (int j = i + 1; j < 10; j++) {

					if (my_strcmp(Info[Sort[i]].GetInfoName(), Info[Sort[j]].GetInfoName()) < 0) {
						temp = Sort[i];
						Sort[i] = Sort[j];
						Sort[j] = temp;
					}
				}
			}

			for (int i = 0; i < 10; i++) { //Name에 대해서 Sorting한 정보를 출력
				cout << "미수강 " << Info[Sort[i]].GetInfoName() << " " << Info[Sort[i]].GetInfoScore() << endl;
			}
		}


		else {	//Score에 대해서 Sorting

			for (int i = 0; i < 10; i++) {
				for (int j = i + 1; j < 10; j++) {
					if (Info[Sort[i]].GetInfoScore() > Info[Sort[j]].GetInfoScore()) {
						temp = Sort[i];
						Sort[i] = Sort[j];
						Sort[j] = temp;
					}
				}
			}

			for (int i = 0; i < 10; i++) {	//Socre에 대해서 Sorting한 결과를 출력
				cout << "미수강 " << Info[Sort[i]].GetInfoName() << " " << Info[Sort[i]].GetInfoScore() << endl;
			}
		}

	}
};


int main() {

	char data[100];	//메모장정보를 받아올 변수들
	char *day;		//요일
	char *name;		//이름
	int score;		//점수
	
	//각 요일 정보를 10개씩 받는 것이므로 각 요일별로 저장된 Count를 세기 위한 변수들
	int WedStore = 0;
	int ThuStore = 0;
	int FriStore = 0;
	int NoneStore = 0;

	//Sorting 방법을 선택하는 Input과 어떤 요일을 선택하는지에 대한 Input 변수
	char Input[128] = { 0, };
	char DayInput[128] = { 0, };

	//OOP클래스에서 각 요일별로 부모클래에서 상속받고 다형성
	OOP *WedDay = new Wed();
	OOP *ThuDay = new Thu();
	OOP *FriDay = new Fri();
	OOP *NoneDay = new None();

	fstream Read;
	Read.open("ScoreList.txt");	//ScoreList 읽기용 파일로 읽는다.

	if (Read.fail()) {	//File open 실패시 예외처리
		cout << "파일을 읽어올 수 없습니다." << endl;
	}
	else {
		//File Opne 성공시 한줄씩 불러와서 요일을 확인한뒤 각 요일에 해당하는 Set함수를 사용해서 이름, 점수 정보를 삽입한다.
		while (!Read.eof()) {
			Read.getline(data, sizeof(data));
			day = my_tok(data, "/");
			name = my_tok(NULL, "/");
			score = atoi(my_tok(NULL, " "));

			if (WedStore == 11 || ThuStore  == 11 || FriStore == 11 || NoneStore == 11) {//각 반의 수강생정보는 10개씩만 입력받는다.
				cout << "한 반의 수강생 정보는 10명씩 총 40명 입력가능합니다. " << endl; //한 반의 수강생정보다 10개 초과면 프로그램은 종료 예외처리
				return 0;
			}

			if (my_strcmp(day, "수") == 0) {		//불러온 정보의 수강반이 수요일일 경우
			
				WedDay->SetName(name, WedStore);	//수요일반 배열에 0번부터 9번까지 Name과 Score정보를 삽입해준다.
				WedDay->SetScore(score, WedStore);	//저장이 일어날 때 마다 저장된 숫자는 1씩 증가시켜준다.
				WedStore = WedStore + 1;
			}

			else if (my_strcmp(day, "목") == 0) {
		
				ThuDay->SetName(name, ThuStore);	//목요일반 배열에 0번부터 9번까지 Name과 Score정보를 삽입해준다.
				ThuDay->SetScore(score, ThuStore);	//저장이 일어날 때 마다 저장된 숫자는 1씩 증가시켜준다.
				ThuStore = ThuStore + 1;
			}

			else if (my_strcmp(day, "금") == 0) {
				
				FriDay->SetName(name, FriStore);	//금요일반 배열에 0번부터 9번까지 Name과 Score정보를 삽입해준다.
				FriDay->SetScore(score, FriStore);	//저장이 일어날 때 마다 저장된 숫자는 1씩 증가시켜준다.
				FriStore = FriStore + 1;	
			}

			else {
				
				NoneDay->SetName(name, NoneStore); //미수강반 배열에 0번부터 9번까지 Name과 Score정보를 삽입해준다.
				NoneDay->SetScore(score, NoneStore); //저장이 일어날 때 마다 저장된 숫자는 1씩 증가시켜준다.
				NoneStore = NoneStore + 1;
			}
		}
	}

	while (1) {
		cout << "1. Print sorted by name 2.Print sorted by score 3. Quit" << endl;

		while (true)	 //Input Number를 문자열로 안받게 예외처리 한 부분	
		{				 //또한 메뉴정보가 3가지 이기 때문에 숫자를 1, 2, 3만 입력받게한 예외처리
			cout << ">Input number: ";
			cin.getline(Input, sizeof(Input));
			if (atoi(Input) == 1 || atoi(Input) == 2 || atoi(Input) == 3) break;
		}

		//3번을 입력해서 Quit하는 부분
		if (atoi(Input) == 3) {
			delete WedDay;
			delete ThuDay;
			delete FriDay;
			delete NoneDay;
			cout << endl;
			break;
		}

		cout << "1. Wednesday 2.Thursday 3. Friday 4. Non-attendance" << endl;

		while (true)	 //Input Day를 문자열로 안받게 예외처리 한 부분	
		{				 //또한 Input Day를 1, 2, 3, 4만 입력받을 수 있게 예외처리
			cout << ">Input day: ";
			cin.getline(DayInput, sizeof(DayInput));
			if (atoi(DayInput) == 1 || atoi(DayInput) == 2 || atoi(DayInput) == 3 || atoi(DayInput) == 4) break;
		}

		if (atoi(DayInput) == 1) {	//수요일반 정보를 입력받은 Sorting에 맞게 Print함수 출력

			WedDay->PrintTitle(atoi(Input));
			WedDay->PrintInfo(atoi(Input));
		}

		else if (atoi(DayInput) == 2) { //목요일반 정보를 입력받은 Sorting에 맞게 Print함수 출력

			ThuDay->PrintTitle(atoi(Input));
			ThuDay->PrintInfo(atoi(Input));
		}

		else if (atoi(DayInput) == 3) { //금요일반 정보를 입력받은 Sorting에 맞게 Print함수 출력

			FriDay->PrintTitle(atoi(Input));
			FriDay->PrintInfo(atoi(Input));
		}

		else { //미수강반 정보를 입력받은 Sorting에 맞게 Print함수 출력
			NoneDay->PrintTitle(atoi(Input));
			NoneDay->PrintInfo(atoi(Input));
		}

		cout << endl;
	}

	return 0;
}
