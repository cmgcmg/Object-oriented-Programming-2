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
	int line[100] = { 0, }; // ���ڿ� ���̸� ��� ���� ����� �迭
	char data[128] = { 0, }; //�޸����� �޾Ƶ��� �迭, ������ ���̰� 128

	ifstream fin;
	fin.open("input.txt");	//File Open

	if (!fin) {	//File Open Exeption handling
		cout << "���� �ҷ����⿡ �����߽��ϴ�." << endl;
		return 0;
	}

	while (!fin.eof()) {
		fin.getline(data, 128); //File�� ����Ÿ�� ���پ��ҷ��´�
		line[i] = my_len(data); //i�� ��, line[i]���� ���ڿ��� ����
		char *data2 = new char[my_len(data) + 1]; //���ڿ� ���� ��ŭ �����迭 �Ҵ�, \n�������� len + 1
		my_cpy(data2, data); //Data2�� ���پ� �о�� �����͸� ����
		cout << data2 << " - " << my_len(data2) << endl;
		i++;
		delete[] data2; // �����迭�Ҵ� ����
	}
	cout << endl;

	for (int j = 0; j < i; j++) {
		result += line[j];
	}
	avg = ((double)result / (double)i);
	cout.setf(ios::fixed);
	cout.precision(1); // �Ҽ��� 1�ڸ��� ����ϱ� ���� �Լ�
	cout << "The average legnth is " << avg << endl;
	
	max = i - 1; // max���� �迭�� ������ ��ȣ�� ����

	//�迭�� ���������� for���� �̿��ؼ� ���� �� ������ ã�´�.
	for (int j = i - 2; j >= 0; j--) {
		if (line[max] <= line[j]) {
			max = j;
		}
	}
	
	//�迭 ��ȣ�� ã���Ŵϱ� max + 1�� ����ϸ� ���� ������̴�.
	cout << "The longest line is line " << max + 1 << endl; // ���� �� ���� ���

	fin.close(); // File Close

	return 0;
}

char* my_cpy(char *str2, char *str1) {

	for (int i = 0; str1[i] != 0; i++)	//�����Ϸ��� ���ڿ� ������ for���� ����
	{
		str2[i] = str1[i];	//�����Ϸ��� ���ڿ� Str1�� Str2�� �־��ش�.
		str2[i + 1] = 0;	//���ڿ��� ���� NULL���� ����
	}

	return str2;	//������ ���ڿ��� ����
}

int my_len(char *str1) {

	int len = 0;

	while (str1[len] != NULL) //���ڿ��� ���� �� ���� While���� ����
	{
		len = len + 1;
	}
	return len;	//���ڿ��� ���̸� return�Ѵ�.
}

