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
	this->S_name = new char[my_len(S_name) + 1]; //���ڸ� �޾ƿ� Name�� ���̸�ŭ �����Ҵ�
	my_cpy(this->S_name, S_name);
}
//SetMail
void Student::SetMail(char *S_mail)
{
	this->S_mail = new char[my_len(S_mail) + 1];	//�޾ƿ� Mail��ŭ �����Ҵ�
	my_cpy(this->S_mail, S_mail);
}
//SetPhone
void Student::SetPhone(char *S_phone)
{
	this->S_phone = new char[my_len(S_phone) + 1];	//�޾ƿ� Phone��ŭ �����Ҵ�
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

	for (int i = 0; str1[i] != 0; i++)	//�����Ϸ��� ���ڿ� ������ for���� ����
	{
		str2[i] = str1[i];	//�����Ϸ��� ���ڿ� Str1�� Str2�� �־��ش�.
		str2[i + 1] = 0;	//���ڿ��� ���� NULL���� ����
	}

	return str2;	//������ ���ڿ��� ����
}
//strtok
char* Student::my_tok(char *str1, char *par) {

	static char *start = NULL;	//���ڿ�
	static char *tracer = NULL; //���ڿ��� �����ϴ� ����
	char *delem;	//Delimeter

	if (str1 != NULL) tracer = str1;	//���ο�ڿ��� ���� �� tracer������ ����
	if (par == NULL || *par == NULL) return NULL; //Delimeter�� ���� ���ڿ��� NULL�϶�
	if (tracer == NULL || *tracer == '\0') return NULL;

	while (*tracer)
	{	//���繮�ڿ� �и����ڿ��� ��
		for (delem = par; *delem; delem++) {
			if (*tracer == *delem) break;
		}
		if (*delem == '\0') break;
		tracer++;
	}
	//ã�� ���ڰ� ���� �� ���� �˻��ϴ� for��
	for (start = tracer; *tracer; tracer++) {
		for (delem = par; *delem; delem++) {
			if (*tracer == *delem) break; // ������ break
		}
		if (*delem) {
			*tracer++ = '\0';
			break; //�и����ڰ� NULL�� ��� break
		}
	}

	return(start); //�и��� ���ڿ��� ����
}
//strlen
int Student::my_len(char *str1) {

	int len = 0;

	while (str1[len] != NULL) //���ڿ��� ���� �� ���� While���� ����
	{
		len = len + 1;
	}
	return len;	//���ڿ��� ���̸� return�Ѵ�.
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
} //Ŭ���� �� �Լ� �״ϱ� Ŭ����
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
	int InfoCount = 0;	//�޸��忡�� ù�ٿ��� ���������� ������ ����
	int StoreCount = 0; //�޸��忡�� �ҷ��� �ټ��� üũ�ϱ� ���� ����

	fstream Read;
	Read.open("information.txt");	//����������ִ� �޸����� Open

	if (Read.fail()) {	//���� Open ���н� ���
		cout << "������ �ҷ� �� �� �����ϴ�." << endl;
	}

	else {	//���� Open�� �����ߴٸ� �޸��忡�� ���� ���������� ����ִ� ù���� �ҷ��´�. 
		Read.getline(data, sizeof(data));
	}

	InfoCount = atoi(data);	//���� ���������� InfoCount�� �����Ѵ�.
	cout << InfoCount << endl;

	Student *Info = new Student[InfoCount];	//���� �������� ��ŭ �����迭�� �Ҵ�޴´�.

	while (!Read.eof())
	{	
		char *name;	
		char *mail;
		char *phone;
		int idnum = 0;
		int age = 0;

		Read.getline(data, sizeof(data));
		name = my_tok(data, " ");	
		Info[StoreCount].SetName(name); //ó�� ��ū�� �и��ؼ� name�� �ְ� SetName
		mail = my_tok(NULL, " ");
		Info[StoreCount].SetMail(mail); //��ū�� �и��ؼ� Mail�� �ְ� SetMail
		phone = my_tok(NULL, " ");
		Info[StoreCount].SetPhone(phone); //��ū�� �и��ؼ� Phone�� �ְ� SetPhone
		idnum = atoi(my_tok(NULL, " "));
		Info[StoreCount].SetID(idnum);  //��ū�� �и��ؼ� ID�� �ְ� SetID
		age = atoi(my_tok(NULL, " "));
		Info[StoreCount].SetAge(age); //��ū�� �и��ؼ� Age�� �ְ� SetAge
		StoreCount = StoreCount + 1;
	}

	Read.close();

	for (int i = 0; i < StoreCount; i++)
	{
		cout << i + 1 << "." << Info[i].InfoName() << " " << Info[i].InfoMail() << " " << Info[i].InfoPhone() << " " <<
			Info[i].InfoID() << " " << Info[i].InfoAge() << endl;
	}	//Ŭ������ ����� �������� �ҷ��ͼ� �������� ������ش�.

	Student temp;
	//���̰� ���� ��� �й��� ���� ��츦 ����ؾ��Ѵ�.
	for (int i = 0; i < StoreCount; i++) {	//�й��� ���ؼ� ���� Sorting
		for (int j = i + 1; j < StoreCount; j++) {
			if (Info[i].InfoID() > Info[j].InfoID()) {
				temp = Info[i];
				Info[i] = Info[j];
				Info[j] = temp;
			}
		}
	}
	
	for (int i = 0; i < StoreCount; i++) { //���̿� ���ؼ� Sorting
		for (int j = i + 1; j < StoreCount; j++) {
			if (Info[i].InfoAge() < Info[j].InfoAge()) {
				temp = Info[i];
				Info[i] = Info[j];
				Info[j] = temp;
			}
		}
	}
	
	cout << endl << endl << "The oldest one is" << endl;	//���� ���̰� ���� ����� ���
	cout << Info[0].InfoName() << " " << Info[0].InfoMail() << " " << Info[0].InfoPhone() << " " << Info[0].InfoID() << " "
		 << Info[0].InfoAge() << endl;

	delete[] Info;	//�����迭 �Ҵ� ���� ���� ����
	return 0;
}

//strcpy
char* my_cpy(char *str2, char *str1) {

	for (int i = 0; str1[i] != 0; i++)	//�����Ϸ��� ���ڿ� ������ for���� ����
	{
		str2[i] = str1[i];	//�����Ϸ��� ���ڿ� Str1�� Str2�� �־��ش�.
		str2[i + 1] = 0;	//���ڿ��� ���� NULL���� ����
	}

	return str2;	//������ ���ڿ��� ����
}
//strtok
char* my_tok(char *str1, char *par) {

	static char *start = NULL;	//���ڿ�
	static char *tracer = NULL; //���ڿ��� �����ϴ� ����
	char *delem;	//Delimeter

	if (str1 != NULL) tracer = str1;	//���ο�ڿ��� ���� �� tracer������ ����
	if (par == NULL || *par == NULL) return NULL; //Delimeter�� ���� ���ڿ��� NULL�϶�
	if (tracer == NULL || *tracer == '\0') return NULL;

	while (*tracer)
	{	//���繮�ڿ� �и����ڿ��� ��
		for (delem = par; *delem; delem++) {
			if (*tracer == *delem) break;
		}
		if (*delem == '\0') break;
		tracer++;
	}
	//ã�� ���ڰ� ���� �� ���� �˻��ϴ� for��
	for (start = tracer; *tracer; tracer++) {
		for (delem = par; *delem; delem++) {
			if (*tracer == *delem) break; // ������ break
		}
		if (*delem) {
			*tracer++ = '\0';
			break; //�и����ڰ� NULL�� ��� break
		}
	}

	return(start); //�и��� ���ڿ��� ����
}
//strlen
int my_len(char *str1) {

	int len = 0;

	while (str1[len] != NULL) //���ڿ��� ���� �� ���� While���� ����
	{
		len = len + 1;
	}
	return len;	//���ڿ��� ���̸� return�Ѵ�.
}

