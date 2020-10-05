#include <iostream>
#include <fstream>

using namespace std;

class Student	//Student Class
{
private:	//Private variable
	char* S_name;
	char* S_mail;
	char* S_phone;
	int S_idnum;
	int S_age;

public:	//Public Function
	Student() { };
	void SetName(char *S_name);	//Name Set
	void SetMail(char *S_mail);	//Mail Set
	void SetPhone(char *S_phone);	//Phone Set
	void SetID(int S_idnum);	//ID Set
	void SetAge(int S_age);		//Age Set
	char *InfoName();			//return S_name
	char *InfoMail();			//return S_mail
	char *InfoPhone();			//return S_Phone
	int InfoID();				//return S_ID
	int InfoAge();				//return S_Age
	char* my_cpy(char *str2, char *str1);
	char* my_tok(char *str1, char *delemeter);
	int my_len(char *str1);
	~Student() { };
};
//SetName
void Student::SetName(char* S_name)
{
	this->S_name = new char[my_len(S_name) + 1]; //인자를 받아온 Name에 길이만큼 동적할당
	my_cpy(this->S_name, S_name);
}
//SetMail
void Student::SetMail(char *S_mail)
{
	this->S_mail = new char[my_len(S_mail) + 1];	//받아온 Mail만큼 동적할당
	my_cpy(this->S_mail, S_mail);
}
//SetPhone
void Student::SetPhone(char *S_phone)
{
	this->S_phone = new char[my_len(S_phone) + 1];	//받아온 Phone만큼 동적할당
	my_cpy(this->S_phone, S_phone);
}
//SetID
void Student::SetID(int S_idnum)
{
	this->S_idnum = S_idnum;
}
//SetAge
void Student::SetAge(int S_age)
{
	this->S_age = S_age;
}//strcpy
//strcpy
char* Student::my_cpy(char *str2, char *str1) {

	for (int i = 0; str1[i] != 0; i++)	//복사하려는 문자열 끝까지 for문을 수행
	{
		str2[i] = str1[i];	//복사하려는 문자열 Str1을 Str2에 넣어준다.
		str2[i + 1] = 0;	//문자열의 끝을 NULL값을 삽입
	}

	return str2;	//복사한 문자열을 리턴
}
//strtok
char* Student::my_tok(char *str1, char *par) {

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
//strlen
int Student::my_len(char *str1) {

	int len = 0;

	while (str1[len] != NULL) //문자열이 끝날 때 까지 While문을 수행
	{
		len = len + 1;
	}
	return len;	//문자열의 길이를 return한다.
}
//return Name
char* Student::InfoName()
{
	return S_name;
}
//return Mail
char* Student::InfoMail()
{
	return S_mail;
}
//return Phone
char* Student::InfoPhone()
{
	return S_phone;
}
//return ID
int Student::InfoID()
{
	return S_idnum;
} //클래스 내 함수 그니까 클래스
//return Age
int Student::InfoAge()
{
	return S_age;
}


char* my_cpy(char *str2, char *str1);	//strcpy
char* my_tok(char *str1, char *delemeter);	//strtok
int my_len(char *str1);	//strlen

int main() {

	char data[128] = { 0, };
	int InfoCount = 0;	//메모장에서 첫줄에서 정보개수를 저장할 변수
	int StoreCount = 0; //메모장에서 불러온 줄수를 체크하기 위한 변수

	fstream Read;
	Read.open("information.txt");	//정보가들어있는 메모장을 Open

	if (Read.fail()) {	//파일 Open 실패시 출력
		cout << "파일을 불러 올 수 없습니다." << endl;
	}

	else {	//파일 Open이 성공했다면 메모장에서 파일 정보개수가 들어있는 첫줄을 불러온다. 
		Read.getline(data, sizeof(data));
	}

	InfoCount = atoi(data);	//파일 정보개수를 InfoCount에 저장한다.
	cout << InfoCount << endl;

	Student *Info = new Student[InfoCount];	//파일 정보개수 만큼 동적배열을 할당받는다.

	while (!Read.eof())
	{	
		char *name;	
		char *mail;
		char *phone;
		int idnum = 0;
		int age = 0;

		Read.getline(data, sizeof(data));
		name = my_tok(data, " ");	
		Info[StoreCount].SetName(name); //처음 토큰을 분리해서 name에 넣고 SetName
		mail = my_tok(NULL, " ");
		Info[StoreCount].SetMail(mail); //토큰을 분리해서 Mail에 넣고 SetMail
		phone = my_tok(NULL, " ");
		Info[StoreCount].SetPhone(phone); //토큰을 분리해서 Phone에 넣고 SetPhone
		idnum = atoi(my_tok(NULL, " "));
		Info[StoreCount].SetID(idnum);  //토큰을 분리해서 ID에 넣고 SetID
		age = atoi(my_tok(NULL, " "));
		Info[StoreCount].SetAge(age); //토큰을 분리해서 Age에 넣고 SetAge
		StoreCount = StoreCount + 1;
	}

	Read.close();

	for (int i = 0; i < StoreCount; i++)
	{
		cout << i + 1 << "." << Info[i].InfoName() << " " << Info[i].InfoMail() << " " << Info[i].InfoPhone() << " " <<
			Info[i].InfoID() << " " << Info[i].InfoAge() << endl;
	}	//클래스에 저장된 변수들을 불러와서 정보들을 출력해준다.

	Student temp;
	//나이가 같을 경우 학번이 낮은 경우를 출력해야한다.
	for (int i = 0; i < StoreCount; i++) {	//학번에 대해서 먼저 Sorting
		for (int j = i + 1; j < StoreCount; j++) {
			if (Info[i].InfoID() > Info[j].InfoID()) {
				temp = Info[i];
				Info[i] = Info[j];
				Info[j] = temp;
			}
		}
	}
	
	for (int i = 0; i < StoreCount; i++) { //나이에 대해서 Sorting
		for (int j = i + 1; j < StoreCount; j++) {
			if (Info[i].InfoAge() < Info[j].InfoAge()) {
				temp = Info[i];
				Info[i] = Info[j];
				Info[j] = temp;
			}
		}
	}
	
	cout << endl << endl << "The oldest one is" << endl;	//가장 나이가 많은 사람을 출력
	cout << Info[0].InfoName() << " " << Info[0].InfoMail() << " " << Info[0].InfoPhone() << " " << Info[0].InfoID() << " "
		 << Info[0].InfoAge() << endl;

	delete[] Info;	//동적배열 할당 받은 것을 해제
	return 0;
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
//strlen
int my_len(char *str1) {

	int len = 0;

	while (str1[len] != NULL) //문자열이 끝날 때 까지 While문을 수행
	{
		len = len + 1;
	}
	return len;	//문자열의 길이를 return한다.
}

