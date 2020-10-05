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
		cout << "���� �ҷ����⿡ �����߽��ϴ�." << endl;
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

	while (str1[len] != NULL) //���ڿ��� ���� �� ���� While���� ����
	{
		len = len + 1;
	}
	return len;	//���ڿ��� ���̸� return�Ѵ�.
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
