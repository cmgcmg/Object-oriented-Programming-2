#include <iostream>
#include <fstream>
#include "OOP.h"
using namespace std;

//OOPŬ�������� ��ӹ��� ������ Class
class Wed : public OOP {
private:
public:
	//strcpy
	char* my_cpy(char *str2, char *str1) {

		for (int i = 0; str1[i] != 0; i++)	//�����Ϸ��� ���ڿ� ������ for���� ����
		{
			str2[i] = str1[i];	//�����Ϸ��� ���ڿ� Str1�� Str2�� �־��ش�.
			str2[i + 1] = 0;	//���ڿ��� ���� NULL���� ����
		}

		return str2;	//������ ���ڿ��� ����
	}
	//OOPŬ���� ���� ������ SetName�Լ��� ����
	void SetName(char* name, int sequence) 
	{
		Info[sequence].SetInfoName(name);	//�ش��ϴ� �迭�� Name�� Set�Ѵ�.
	}
	//OOPŬ���� ���� ������ SetScore�Լ��� ����
	void SetScore(int Score, int sequence)
	{
		Info[sequence].SetInfoScore(Score);	//�ش��ϴ� �迭�� Score�� Set�Ѵ�.
	}
	//OOPŬ���� ���� ������ GetName�Լ��� ����
	char* GetName(int sequence) 
	{
		return Info[sequence].GetInfoName();	//�ش��ϴ� �迭�� Name������ Return �Ѵ�.
	}
	//OOPŬ���� ���� ������ GetScore�Լ��� ����
	int GetScore(int sequence) 
	{
		return Info[sequence].GetInfoScore();	//�ش��ϴ� �迭�� Score ������ Return�Ѵ�.
	}
	//Sorting�ϰ� ���� ��ȣ�� ���ڷ� �޾Ƽ� ��� Sorting �� ������ ���
	void PrintTitle(int num)
	{	
		if (num == 1)	//1���� ��� Name�� ���� Sorting
			cout << "** Score List of Wednesday Sorted by Name **" << endl;
		else			//2���� ��� Score�� ���� Sorting
			cout << "** Score List of Wednesday Sorted by Score **" << endl;
	}
	//Sorting�ϰ� ���� ��ȣ�� ���ڷ� �޾Ƽ� �׿��°� Sorting�ϰ� ���
	void PrintInfo(int num)
	{	
		int Sort[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };	//�迭 Sequence�� ������� ���� �迭
		int temp;

		if (num == 1) {	//Name�� ���ؼ� Sorting

			for (int i = 0; i < 10; i++) {
				for (int j = i + 1; j < 10; j++) {

					if (my_strcmp(Info[Sort[i]].GetInfoName(), Info[Sort[j]].GetInfoName()) < 0) {
						temp = Sort[i];
						Sort[i] = Sort[j];
						Sort[j] = temp;
					}
				}
			}

			for (int i = 0; i < 10; i++) { //Name�� ���ؼ� Sorting�� ������ ���
				cout << "�� " << Info[Sort[i]].GetInfoName() << " " << Info[Sort[i]].GetInfoScore() << endl;
			}
		}

		
		else {	//Score�� ���ؼ� Sorting

			for (int i = 0; i < 10; i++) {
				for (int j = i + 1; j < 10; j++) {
					if (Info[Sort[i]].GetInfoScore() > Info[Sort[j]].GetInfoScore() ) {
						temp = Sort[i];
						Sort[i] = Sort[j];
						Sort[j] = temp;
					}
				}
			}

			for (int i = 0; i < 10; i++) {	//Socre�� ���ؼ� Sorting�� ����� ���
				cout << "�� " << Info[Sort[i]].GetInfoName() << " " << Info[Sort[i]].GetInfoScore() << endl;
			}
		}

	}
};

//OOP���� ��ӹ��� ����� Class
class Thu : public OOP {
private:
public:
	//strcpy
	char* my_cpy(char *str2, char *str1) {

		for (int i = 0; str1[i] != 0; i++)	//�����Ϸ��� ���ڿ� ������ for���� ����
		{
			str2[i] = str1[i];	//�����Ϸ��� ���ڿ� Str1�� Str2�� �־��ش�.
			str2[i + 1] = 0;	//���ڿ��� ���� NULL���� ����
		}

		return str2;	//������ ���ڿ��� ����
	}
	//OOPŬ���� ���� ������ SetName�Լ��� ����
	void SetName(char* name, int sequence)
	{
		Info[sequence].SetInfoName(name);	//�ش��ϴ� �迭�� Name�� Set�Ѵ�.
	}
	//OOPŬ���� ���� ������ SetScore�Լ��� ����
	void SetScore(int Score, int sequence)
	{
		Info[sequence].SetInfoScore(Score);	//�ش��ϴ� �迭�� Score�� Set�Ѵ�.
	}
	//OOPŬ���� ���� ������ GetName�Լ��� ����
	char* GetName(int sequence)
	{
		return Info[sequence].GetInfoName();	//�ش��ϴ� �迭�� Name������ Return �Ѵ�.
	}
	//OOPŬ���� ���� ������ GetScore�Լ��� ����
	int GetScore(int sequence)
	{
		return Info[sequence].GetInfoScore();	//�ش��ϴ� �迭�� Score ������ Return�Ѵ�.
	}
	//Sorting�ϰ� ���� ��ȣ�� ���ڷ� �޾Ƽ� ��� Sorting �� ������ ���
	void PrintTitle(int num)
	{
		if (num == 1)	//1���� ��� Name�� ���� Sorting
			cout << "** Score List of Wednesday Sorted by Name **" << endl;
		else			//2���� ��� Score�� ���� Sorting
			cout << "** Score List of Wednesday Sorted by Score **" << endl;
	}
	//Sorting�ϰ� ���� ��ȣ�� ���ڷ� �޾Ƽ� �׿��°� Sorting�ϰ� ���
	void PrintInfo(int num)
	{
		int Sort[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };	//�迭 Sequence�� ������� ���� �迭
		int temp;

		if (num == 1) {	//Name�� ���ؼ� Sorting

			for (int i = 0; i < 10; i++) {
				for (int j = i + 1; j < 10; j++) {

					if (my_strcmp(Info[Sort[i]].GetInfoName(), Info[Sort[j]].GetInfoName()) < 0) {
						temp = Sort[i];
						Sort[i] = Sort[j];
						Sort[j] = temp;
					}
				}
			}

			for (int i = 0; i < 10; i++) { //Name�� ���ؼ� Sorting�� ������ ���
				cout << "�� " << Info[Sort[i]].GetInfoName() << " " << Info[Sort[i]].GetInfoScore() << endl;
			}
		}


		else {	//Score�� ���ؼ� Sorting

			for (int i = 0; i < 10; i++) {
				for (int j = i + 1; j < 10; j++) {
					if (Info[Sort[i]].GetInfoScore() > Info[Sort[j]].GetInfoScore()) {
						temp = Sort[i];
						Sort[i] = Sort[j];
						Sort[j] = temp;
					}
				}
			}

			for (int i = 0; i < 10; i++) {	//Socre�� ���ؼ� Sorting�� ����� ���
				cout << "�� " << Info[Sort[i]].GetInfoName() << " " << Info[Sort[i]].GetInfoScore() << endl;
			}
		}

	}
};

//OOPŬ�������� ��ӹ��� �ݿ��� Class
class Fri : public OOP {
private:
public:
	//strcpy
	char* my_cpy(char *str2, char *str1) {

		for (int i = 0; str1[i] != 0; i++)	//�����Ϸ��� ���ڿ� ������ for���� ����
		{
			str2[i] = str1[i];	//�����Ϸ��� ���ڿ� Str1�� Str2�� �־��ش�.
			str2[i + 1] = 0;	//���ڿ��� ���� NULL���� ����
		}

		return str2;	//������ ���ڿ��� ����
	}
	//OOPŬ���� ���� ������ SetName�Լ��� ����
	void SetName(char* name, int sequence)
	{
		Info[sequence].SetInfoName(name);	//�ش��ϴ� �迭�� Name�� Set�Ѵ�.
	}
	//OOPŬ���� ���� ������ SetScore�Լ��� ����
	void SetScore(int Score, int sequence)
	{
		Info[sequence].SetInfoScore(Score);	//�ش��ϴ� �迭�� Score�� Set�Ѵ�.
	}
	//OOPŬ���� ���� ������ GetName�Լ��� ����
	char* GetName(int sequence)
	{
		return Info[sequence].GetInfoName();	//�ش��ϴ� �迭�� Name������ Return �Ѵ�.
	}
	//OOPŬ���� ���� ������ GetScore�Լ��� ����
	int GetScore(int sequence)
	{
		return Info[sequence].GetInfoScore();	//�ش��ϴ� �迭�� Score ������ Return�Ѵ�.
	}
	//Sorting�ϰ� ���� ��ȣ�� ���ڷ� �޾Ƽ� ��� Sorting �� ������ ���
	void PrintTitle(int num)
	{
		if (num == 1)	//1���� ��� Name�� ���� Sorting
			cout << "** Score List of Wednesday Sorted by Name **" << endl;
		else			//2���� ��� Score�� ���� Sorting
			cout << "** Score List of Wednesday Sorted by Score **" << endl;
	}
	//Sorting�ϰ� ���� ��ȣ�� ���ڷ� �޾Ƽ� �׿��°� Sorting�ϰ� ���
	void PrintInfo(int num)
	{
		int Sort[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };	//�迭 Sequence�� ������� ���� �迭
		int temp;

		if (num == 1) {	//Name�� ���ؼ� Sorting

			for (int i = 0; i < 10; i++) {
				for (int j = i + 1; j < 10; j++) {

					if (my_strcmp(Info[Sort[i]].GetInfoName(), Info[Sort[j]].GetInfoName()) < 0) {
						temp = Sort[i];
						Sort[i] = Sort[j];
						Sort[j] = temp;
					}
				}
			}

			for (int i = 0; i < 10; i++) { //Name�� ���ؼ� Sorting�� ������ ���
				cout << "�� " << Info[Sort[i]].GetInfoName() << " " << Info[Sort[i]].GetInfoScore() << endl;
			}
		}


		else {	//Score�� ���ؼ� Sorting

			for (int i = 0; i < 10; i++) {
				for (int j = i + 1; j < 10; j++) {
					if (Info[Sort[i]].GetInfoScore() > Info[Sort[j]].GetInfoScore()) {
						temp = Sort[i];
						Sort[i] = Sort[j];
						Sort[j] = temp;
					}
				}
			}

			for (int i = 0; i < 10; i++) {	//Socre�� ���ؼ� Sorting�� ����� ���
				cout << "�� " << Info[Sort[i]].GetInfoName() << " " << Info[Sort[i]].GetInfoScore() << endl;
			}
		}

	}
};

//OOPŬ�������� ��ӹ��� �̼��� Class
class None : public OOP {
private:
public:
	//strcpy
	char* my_cpy(char *str2, char *str1) {

		for (int i = 0; str1[i] != 0; i++)	//�����Ϸ��� ���ڿ� ������ for���� ����
		{
			str2[i] = str1[i];	//�����Ϸ��� ���ڿ� Str1�� Str2�� �־��ش�.
			str2[i + 1] = 0;	//���ڿ��� ���� NULL���� ����
		}

		return str2;	//������ ���ڿ��� ����
	}
	//OOPŬ���� ���� ������ SetName�Լ��� ����
	void SetName(char* name, int sequence)
	{
		Info[sequence].SetInfoName(name);	//�ش��ϴ� �迭�� Name�� Set�Ѵ�.
	}
	//OOPŬ���� ���� ������ SetScore�Լ��� ����
	void SetScore(int Score, int sequence)
	{
		Info[sequence].SetInfoScore(Score);	//�ش��ϴ� �迭�� Score�� Set�Ѵ�.
	}
	//OOPŬ���� ���� ������ GetName�Լ��� ����
	char* GetName(int sequence)
	{
		return Info[sequence].GetInfoName();	//�ش��ϴ� �迭�� Name������ Return �Ѵ�.
	}
	//OOPŬ���� ���� ������ GetScore�Լ��� ����
	int GetScore(int sequence)
	{
		return Info[sequence].GetInfoScore();	//�ش��ϴ� �迭�� Score ������ Return�Ѵ�.
	}
	//Sorting�ϰ� ���� ��ȣ�� ���ڷ� �޾Ƽ� ��� Sorting �� ������ ���
	void PrintTitle(int num)
	{
		if (num == 1)	//1���� ��� Name�� ���� Sorting
			cout << "** Score List of Wednesday Sorted by Name **" << endl;
		else			//2���� ��� Score�� ���� Sorting
			cout << "** Score List of Wednesday Sorted by Score **" << endl;
	}
	//Sorting�ϰ� ���� ��ȣ�� ���ڷ� �޾Ƽ� �׿��°� Sorting�ϰ� ���
	void PrintInfo(int num)
	{
		int Sort[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };	//�迭 Sequence�� ������� ���� �迭
		int temp;

		if (num == 1) {	//Name�� ���ؼ� Sorting

			for (int i = 0; i < 10; i++) {
				for (int j = i + 1; j < 10; j++) {

					if (my_strcmp(Info[Sort[i]].GetInfoName(), Info[Sort[j]].GetInfoName()) < 0) {
						temp = Sort[i];
						Sort[i] = Sort[j];
						Sort[j] = temp;
					}
				}
			}

			for (int i = 0; i < 10; i++) { //Name�� ���ؼ� Sorting�� ������ ���
				cout << "�̼��� " << Info[Sort[i]].GetInfoName() << " " << Info[Sort[i]].GetInfoScore() << endl;
			}
		}


		else {	//Score�� ���ؼ� Sorting

			for (int i = 0; i < 10; i++) {
				for (int j = i + 1; j < 10; j++) {
					if (Info[Sort[i]].GetInfoScore() > Info[Sort[j]].GetInfoScore()) {
						temp = Sort[i];
						Sort[i] = Sort[j];
						Sort[j] = temp;
					}
				}
			}

			for (int i = 0; i < 10; i++) {	//Socre�� ���ؼ� Sorting�� ����� ���
				cout << "�̼��� " << Info[Sort[i]].GetInfoName() << " " << Info[Sort[i]].GetInfoScore() << endl;
			}
		}

	}
};


int main() {

	char data[100];	//�޸��������� �޾ƿ� ������
	char *day;		//����
	char *name;		//�̸�
	int score;		//����
	
	//�� ���� ������ 10���� �޴� ���̹Ƿ� �� ���Ϻ��� ����� Count�� ���� ���� ������
	int WedStore = 0;
	int ThuStore = 0;
	int FriStore = 0;
	int NoneStore = 0;

	//Sorting ����� �����ϴ� Input�� � ������ �����ϴ����� ���� Input ����
	char Input[128] = { 0, };
	char DayInput[128] = { 0, };

	//OOPŬ�������� �� ���Ϻ��� �θ�Ŭ������ ��ӹް� ������
	OOP *WedDay = new Wed();
	OOP *ThuDay = new Thu();
	OOP *FriDay = new Fri();
	OOP *NoneDay = new None();

	fstream Read;
	Read.open("ScoreList.txt");	//ScoreList �б�� ���Ϸ� �д´�.

	if (Read.fail()) {	//File open ���н� ����ó��
		cout << "������ �о�� �� �����ϴ�." << endl;
	}
	else {
		//File Opne ������ ���پ� �ҷ��ͼ� ������ Ȯ���ѵ� �� ���Ͽ� �ش��ϴ� Set�Լ��� ����ؼ� �̸�, ���� ������ �����Ѵ�.
		while (!Read.eof()) {
			Read.getline(data, sizeof(data));
			day = my_tok(data, "/");
			name = my_tok(NULL, "/");
			score = atoi(my_tok(NULL, " "));

			if (WedStore == 11 || ThuStore  == 11 || FriStore == 11 || NoneStore == 11) {//�� ���� ������������ 10������ �Է¹޴´�.
				cout << "�� ���� ������ ������ 10�� �� 40�� �Է°����մϴ�. " << endl; //�� ���� ������������ 10�� �ʰ��� ���α׷��� ���� ����ó��
				return 0;
			}

			if (my_strcmp(day, "��") == 0) {		//�ҷ��� ������ �������� �������� ���
			
				WedDay->SetName(name, WedStore);	//�����Ϲ� �迭�� 0������ 9������ Name�� Score������ �������ش�.
				WedDay->SetScore(score, WedStore);	//������ �Ͼ �� ���� ����� ���ڴ� 1�� ���������ش�.
				WedStore = WedStore + 1;
			}

			else if (my_strcmp(day, "��") == 0) {
		
				ThuDay->SetName(name, ThuStore);	//����Ϲ� �迭�� 0������ 9������ Name�� Score������ �������ش�.
				ThuDay->SetScore(score, ThuStore);	//������ �Ͼ �� ���� ����� ���ڴ� 1�� ���������ش�.
				ThuStore = ThuStore + 1;
			}

			else if (my_strcmp(day, "��") == 0) {
				
				FriDay->SetName(name, FriStore);	//�ݿ��Ϲ� �迭�� 0������ 9������ Name�� Score������ �������ش�.
				FriDay->SetScore(score, FriStore);	//������ �Ͼ �� ���� ����� ���ڴ� 1�� ���������ش�.
				FriStore = FriStore + 1;	
			}

			else {
				
				NoneDay->SetName(name, NoneStore); //�̼����� �迭�� 0������ 9������ Name�� Score������ �������ش�.
				NoneDay->SetScore(score, NoneStore); //������ �Ͼ �� ���� ����� ���ڴ� 1�� ���������ش�.
				NoneStore = NoneStore + 1;
			}
		}
	}

	while (1) {
		cout << "1. Print sorted by name 2.Print sorted by score 3. Quit" << endl;

		while (true)	 //Input Number�� ���ڿ��� �ȹް� ����ó�� �� �κ�	
		{				 //���� �޴������� 3���� �̱� ������ ���ڸ� 1, 2, 3�� �Է¹ް��� ����ó��
			cout << ">Input number: ";
			cin.getline(Input, sizeof(Input));
			if (atoi(Input) == 1 || atoi(Input) == 2 || atoi(Input) == 3) break;
		}

		//3���� �Է��ؼ� Quit�ϴ� �κ�
		if (atoi(Input) == 3) {
			delete WedDay;
			delete ThuDay;
			delete FriDay;
			delete NoneDay;
			cout << endl;
			break;
		}

		cout << "1. Wednesday 2.Thursday 3. Friday 4. Non-attendance" << endl;

		while (true)	 //Input Day�� ���ڿ��� �ȹް� ����ó�� �� �κ�	
		{				 //���� Input Day�� 1, 2, 3, 4�� �Է¹��� �� �ְ� ����ó��
			cout << ">Input day: ";
			cin.getline(DayInput, sizeof(DayInput));
			if (atoi(DayInput) == 1 || atoi(DayInput) == 2 || atoi(DayInput) == 3 || atoi(DayInput) == 4) break;
		}

		if (atoi(DayInput) == 1) {	//�����Ϲ� ������ �Է¹��� Sorting�� �°� Print�Լ� ���

			WedDay->PrintTitle(atoi(Input));
			WedDay->PrintInfo(atoi(Input));
		}

		else if (atoi(DayInput) == 2) { //����Ϲ� ������ �Է¹��� Sorting�� �°� Print�Լ� ���

			ThuDay->PrintTitle(atoi(Input));
			ThuDay->PrintInfo(atoi(Input));
		}

		else if (atoi(DayInput) == 3) { //�ݿ��Ϲ� ������ �Է¹��� Sorting�� �°� Print�Լ� ���

			FriDay->PrintTitle(atoi(Input));
			FriDay->PrintInfo(atoi(Input));
		}

		else { //�̼����� ������ �Է¹��� Sorting�� �°� Print�Լ� ���
			NoneDay->PrintTitle(atoi(Input));
			NoneDay->PrintInfo(atoi(Input));
		}

		cout << endl;
	}

	return 0;
}
