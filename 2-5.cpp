#include <iostream>
#include <fstream>
using namespace std;

class Item {	//Item Ŭ���� ����

private:	//Item Ŭ������ ����Ǿ��ִ� Private ������
	char *name;
	int price;
	int quantity;
	int sequence;
public:
	Item() { };
	void Load(char *name, int price, int quantity, int sequence);	//Load Function
	void Insert(char *name, int price, int quantity, int sequence);	//Insert Function
	void Update(char *name, int price, int quantity, int sequence);	//Update Function
	void Delete(Item Info[], int sequence, int Store);	//Delete Function
	void Print(Item Info[], int Store, int SortNumber);	//Print Function
	void Save(std::ofstream &Write, Item Info[], int count, int Store);	//Save Function
	char* my_cpy(char *str2, char *str1);	//strcpy
	char* my_tok(char *str1, char *delemeter);	//strtok
	int my_len(char *str1);	//strlen
	int my_strcmp(char str1[], char str2[]);	//strcmp
	~Item() { };
};
//**Load Function**//
void Item::Load(char *name, int price, int quantity, int sequence)
{
	this->name = new char[my_len(name) + 1];	//������ �̸� ��ŭ ���� �迭�� �Ҵ� �޴´� ( + 1���������� \n ���� )

	my_cpy(this->name, name);	//���ڷ� �޾ƿ� Name�� Ŭ���� Private ���� Name�� ����
	this->price = price;		//���ڷ� �޾ƿ� price�� Ŭ���� Private ���� Price�� ����
	this->quantity = quantity;	//���ڷ� �޾ƿ� quantity�� Ŭ���� Private ���� Quantity�� ����
	this->sequence = sequence;	//���ڷ� �޾ƿ� sequence�� Ŭ���� Private ���� Sequence�� ����

}
//**Insert Function**//
void Item::Insert(char *name, int price, int quantity, int sequence)
{
	this->name = new char[my_len(name) + 1]; //Insert�� �̸��� ������ ���ؼ� ���� �迭�� �Ҵ� �޴´� ( +1 ���������� \n ���� )

	my_cpy(this->name, name);	//Insert�� Name�� Ŭ���� Private���� Name�� ����
	this->price = price;		//Insert�� Pricce�� Ŭ���� Private���� Price�� ����
	this->quantity = quantity;	//Insert�� Quantity�� Ŭ���� Private���� Quantity�� ����
	this->sequence = sequence;	//Insert�� Sequence�� Ŭ���� Private���� Sequence�� ����
}
//**Update Function**//
void Item::Update(char *name, int price, int quantity, int sequence)
{
	this->name = new char[my_len(name) + 1];	//Update�� �̸��� ������ ���ؼ� ���� �迭�� �Ҵ� �޴´� ( +1 ���� ������ \n ���� )

	my_cpy(this->name, name);	//Update�� Name�� Ŭ���� Private���� Name�� ����
	this->price = price;		//Update�� Price�� Ŭ���� Private���� Price�� ����
	this->quantity = quantity;	//Update�� Quantity�� Ŭ���� Private���� Quantity�� ����
	this->sequence = sequence;	//Update�� Sequence�� Ŭ���� Private���� Sequence�� ����
}
//**Delete Function**//
void Item::Delete(Item Info[], int sequence, int Store) //Ư���� ���� Store(���� ����� Line ��ȣ ���ڸ� ���ڷ� �޾ƿ´�)
{
	if (sequence == Store - 1) {	//������ Sequence�� ��� NULL������ �ʱ�ȭ
		Info[sequence].name = NULL;
		Info[sequence].sequence = 0;
		Info[sequence].price = 0;
		Info[sequence].quantity = 0;
	}
	else {	// DeleteLine�� �������� �ؼ� ������ Sequence�� �ƴ� ��� DeleteLine ���� �迭�� �ش��ϴ� ������ ��ĭ�� ������ ����. 
		Info[sequence].name = new char[my_len(Info[sequence + 1].name) + 1];
		my_cpy(Info[sequence].name, Info[sequence + 1].name);
		Info[sequence].sequence = Info[sequence + 1].sequence;
		Info[sequence].price = Info[sequence + 1].price;
		Info[sequence].quantity = Info[sequence + 1].quantity;
	}
}
//**Print Function**//
void Item::Print(Item Info[], int Store, int SortNumber)
{
	if (SortNumber == 1) {	//Sequence Sorting
		cout << "** Sequence Sort **" << endl;
		cout << endl << "KW Store Item List" << endl;
		for (int i = 0; i < Store; i++) {	//����Ǿ� �ִ� �������� Sequence������ ���
			cout << i + 1 << ". " << Info[i].name << "($" << Info[i].price << ", " << Info[i].quantity << ")" << endl;
		}
		cout << endl;
	}

	else if (SortNumber == 2) {	//Name Sorting
		cout << "** Name Sort **" << endl;
		cout << endl << "KW Store Item List" << endl;
		int temp;
		int Sort[10];
		for (int i = 0; i < Store; i++) {	//0~����� ��ȣ���� ����Ǿ��ִ� Sort�迭�� ����
			Sort[i] = i;
		}

		for (int i = 0; i < Store - 1; i++) {	//Name�� ���ؼ� ������ Sort�迭�� ������� ��ȣ�� �ؼ� ���� �������� Sorting
			for (int j = i + 1; j < Store; j++) {	//����Ǿ� �ִ� ������ �ٲ㼭 ����ϸ� �ȵǱ� ����
				if (my_strcmp(Info[Sort[i]].name, Info[Sort[j]].name) < 0) {
					temp = Sort[i];
					Sort[i] = Sort[j];
					Sort[j] = temp;
				}
			}
		}

		
		cout << endl;

		for (int i = 0; i < Store; i++) {	//Name���� Sorting�� Item �������� ���
			cout << i+1 << ". " << Info[Sort[i]].name << "($" << Info[Sort[i]].price << ", " << Info[Sort[i]].quantity << ")" << endl;
		}
	}

	else if (SortNumber == 3) {
		cout << "** Price Sort **" << endl;
		cout << endl << "KW Store Item List" << endl;
		int temp;
		int Sort[10];
		for (int i = 0; i < Store; i++) { //0~����� ��ȣ���� ����Ǿ��ִ� Sort�迭�� ����
			Sort[i] = i;
		}
		for (int i = 0; i < Store - 1; i++) {	//Price�� ���ؼ� ������ Sort�迭�� ������� ��ȣ�� �ؼ� ���� �������� Sorting
			for (int j = i + 1; j < Store; j++) { //����Ǿ� �ִ� ������ �ٲ㼭 ����ϸ� �ȵǱ� ����
				if (Info[Sort[i]].price > Info[Sort[j]].price ) {
					temp = Sort[i];
					Sort[i] = Sort[j];
					Sort[j] = temp;
				}
			}
		}
		cout << endl;

		for (int i = 0; i < Store; i++) {	//Price�� ���ؼ� Sorting�� Item �������� ���
			cout << i+1 << ". " << Info[Sort[i]].name << "($" << Info[Sort[i]].price << ", " << Info[Sort[i]].quantity << ")" << endl;
		}
	}

	else {
		cout << "** Quantity Sort **" << endl;
		cout << endl << "KW Store Item List" << endl;
		int temp;
		int Sort[10];
		for (int i = 0; i < Store; i++) { //0~����� ��ȣ���� ����Ǿ��ִ� Sort�迭�� ����
			Sort[i] = i;
		}
		for (int i = 0; i < Store - 1; i++) { //Quantity�� ���ؼ� ������ Sort�迭�� ������� ��ȣ�� �ؼ� ���� �������� Sorting
			for (int j = i + 1; j < Store; j++) { //����Ǿ� �ִ� ������ �ٲ㼭 ����ϸ� �ȵǱ� ����
				if (Info[Sort[i]].quantity > Info[Sort[j]].quantity) {
					temp = Sort[i];
					Sort[i] = Sort[j];
					Sort[j] = temp;
				}
			}
		}
		cout << endl;

		for (int i = 0; i < Store; i++) {	//Quantity�� ���ؼ� Sorting�� Item������ ���
			cout << i+1 << ". " << Info[Sort[i]].name << "($" << Info[Sort[i]].price << ", " << Info[Sort[i]].quantity << ")" << endl;
		}
	}
}
//**Save Function**//
void Item::Save(std::ofstream &Write, Item Info[], int count, int Store)	//�ٹ�ȣ�� �迭 �׸��� �޸����� ���ڷ� �޾ƿ´�.
{
	if (count == Store - 1) {	//������ ���ϰ�� \n�� �����ϰ� �޸��忡 ����.
		Write << this->name << "/" << this->price << "/" << this->quantity;
	}
	else                       //������ ���� �ƴҰ�� \n�� �����ؼ� �޸��忡 ����.
		Write << this->name << "/" << this->price << "/" << this->quantity << endl;



}
//strcpy
char* Item::my_cpy(char *str2, char *str1) {

	for (int i = 0; str1[i] != 0; i++)	//�����Ϸ��� ���ڿ� ������ for���� ����
	{
		str2[i] = str1[i];	//�����Ϸ��� ���ڿ� Str1�� Str2�� �־��ش�.
		str2[i + 1] = 0;	//���ڿ��� ���� NULL���� ����
	}

	return str2;	//������ ���ڿ��� ����
}
//strtok
char* Item::my_tok(char *str1, char *par) {

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
int Item::my_len(char *str1) {

	int len = 0;

	while (str1[len] != NULL) //���ڿ��� ���� �� ���� While���� ����
	{
		len = len + 1;
	}
	return len;	//���ڿ��� ���̸� return�Ѵ�.
}
//strcmp
int Item::my_strcmp(char str1[], char str2[]) {

	int i = 0;
	int j = 0;

	while (str1[i] != NULL && str2[i] != NULL) //�� ���ڿ��� NULL�� �ƴҶ�����
	{
		if (str1[i] != str2[i])	//�� ���ڿ��� �ٸ���
			return str2[i] - str1[i];
		i++;
	}
	//���ڿ� �񱳰� ���� ���� ���ϰ�
	if (str1[i] == NULL)
		return str2[i];
	if (str2[i] == NULL)
		return -str1[i];
}

char* my_cpy(char *str2, char *str1); //strcpy
char* my_tok(char *str1, char *delemeter);	//strtok
int my_len(char *str1);	//strlen
int my_strcmp(char str1[], char str2[]);	//strcmp

int main() {

	char Input[100] = { 0, };
	int Store;
	Item Info[10]; // Item Ŭ���� �迭 10�� ���� ( Item list�� 10�� )

	while (1) {
		cout << "1.Load  2.Insert  3.Update  4.Delete  5.Print  6.Save  7.Quit" << endl;
		cout << ">Input number: ";
		cin.getline(Input, sizeof(Input));

		while (1) {	//Input Number�� ���ڰ� �ƴҰ�� ����ó��

			if (atoi(Input) != 0) break;

			else {
				cout << "���ڸ� �Է��ϼ���." << endl;
				cout << ">Input number";
				cin.getline(Input, sizeof(Input));
			}
		}
		//***********Load************//
		if (atoi(Input) == 1)
		{
			char LoadData[100] = { 0, };	//Load�� �������� ������ ����
			char *Loadname;
			int Loadprice;
			int Loadquantity;
			Store = 0;

			fstream LoadRead;
			LoadRead.open("ItemList.txt");	//ItemList������ �б�� ���Ϸ� Open

			if (LoadRead.fail())	//���� Open ���н� ����ó��
			{
				cout << "������ �ҷ��� �� �����ϴ�." << endl;
				cout << "Load Error" << endl;
			}
			else
			{
				while (!LoadRead.eof())	//������ ������ �� �ҷ��Ë�����
				{
					LoadRead.getline(LoadData, sizeof(LoadData));	//������ �޾ƿͼ� Name, Price, Quantitiy�� token�� ����ؼ� ����
					Loadname = my_tok(LoadData, "/");
					Loadprice = atoi(my_tok(NULL, "/"));
					Loadquantity = atoi(my_tok(NULL, "/"));
					if (Store < 10) {	//Load�� �� �ִ� ������ 10����.
						Info[Store].Load(Loadname, Loadprice, Loadquantity, (Store + 1));
						Store = Store + 1;
					}	//10 ���� ���� ����ó�� ���
					else cout << Loadname << " could not be loaded. " << endl;

				}
			}

			cout << endl << "** Load Complete **" << endl;
			LoadRead.close();	//File Close
		}
		//***********Insert************//
		if (atoi(Input) == 2)
		{
			char InsertName[100];	//Insert�� ������
			char InsertPrice[100];
			char InsertQuantity[100];

			cout << endl << "** Insert **" << endl;
			cout << "Item Name: ";
			cin.getline(InsertName, sizeof(InsertName));

			cout << "Price: ";
			cin.getline(InsertPrice, sizeof(InsertPrice));

			while (1)		//Price�� ���ڿ��� �Է����� ��� ����ó��
			{			
				if (atoi(InsertPrice) != 0) break;
				else {
					cout << "Item Price�� ���ڷ� �Է����ּ���. " << endl;
					cout << ">Price: ";
					cin.getline(InsertPrice, sizeof(InsertPrice));
				}
			}

			cout << "Quantity: ";
			cin.getline(InsertQuantity, sizeof(InsertQuantity));
			while (1)	//Quantity�� ���ڿ��� �Է����� ��� ����ó��
			{
				if (atoi(InsertQuantity) != 0) break;
				else {
					cout << "Item Quantity�� ���ڷ� �Է����ּ���. " << endl;
					cout << ">Quantity: ";
					cin.getline(InsertQuantity, sizeof(InsertQuantity));
				}
			}
			if (Store != 10) {	// 10���� ������ �� ������ �ʴٸ� Insert �Լ� ���
				Info[Store].Insert(InsertName, atoi(InsertPrice), atoi(InsertQuantity), (Store + 1));
				Store = Store + 1;
				cout << endl;
			}

			else {	//10���� ������ �� �������� ����ó��
				cout << "10���� ������ ��� �� ���ֽ��ϴ�." << endl;
				cout << "Insert�� �� �����ϴ�." << endl;
			}

		}
		//***********Update************//
		if (atoi(Input) == 3) {

			char UpdateSequence[100];	//Update�� ������ ���� ������
			char UpdateName[100];
			char UpdatePrice[100];
			char UpdateQuantity[100];

			cout << endl << "** Update **" << endl;
			cout << "Input Sequence: ";
			cin.getline(UpdateSequence, sizeof(UpdateSequence));
			cout << endl;
			while (1)
			{	//Sequence�� ���ڷ� �Է����� �ʾҰų� 10�� �ʰ����� ��� ����ó��
				if (atoi(UpdateSequence) != 0 && atoi(UpdateSequence) <= 10) break;
				else
				{
					cout << "Input Sequence�� ���ڷ� �Է����� �ʾҰų� 10�ʰ��Դϴ�." << endl;
					cout << "Input Sequence: ";
					cin.getline(UpdateSequence, sizeof(UpdateSequence));
				}
			}

			while (1)
			{	//Input Sequence�� ���ڷ� �Է� ������ ��� ����ó��
				if (atoi(Input) != 0) break;

				cout << "���ڸ� �Է��ϼ���." << endl;
				cout << ">Input Sequence";
				cin.getline(Input, sizeof(Input));
			}

			cout << "Item Name: ";
			cin.getline(UpdateName, sizeof(UpdateName));

			cout << "Price: ";
			cin.getline(UpdatePrice, sizeof(UpdatePrice));
			while (1)
			{	//Price�� ���ڿ��� �Է����� ��� ����ó��
				if (atoi(UpdatePrice) != 0) break;
				else {
					cout << "Item Price�� ���ڷ� �Է����ּ���. " << endl;
					cout << ">Price: ";
					cin.getline(UpdatePrice, sizeof(UpdatePrice));
				}
			}

			cout << "Quantity: ";
			cin.getline(UpdateQuantity, sizeof(UpdateQuantity));
			while (1)
			{	//Quantity�� ���ڿ��� �Է����� ��� ����ó��
				if (atoi(UpdateQuantity) != 0) break;
				else {
					cout << "Item Quantity�� ���ڷ� �Է����ּ���. " << endl;
					cout << ">Quantity: ";
					cin.getline(UpdateQuantity, sizeof(UpdateQuantity));
				}
			}	//Update�� �������� ���ڷ� �־ Ŭ���� Update�Լ� Ȱ��
			Info[atoi(UpdateSequence) - 1].Update(UpdateName, atoi(UpdatePrice), atoi(UpdateQuantity), atoi(UpdateSequence));
			cout << endl;
		}
		//***********Delete************//
		if (atoi(Input) == 4) {

			char DeleteSequence[100];	//Delete�� ���� ã�� ����
			int DeleteOverlap = 0;

			cout << endl << "** Delete **" << endl;
			cout << ">Input sequence: ";
			cin.getline(DeleteSequence, sizeof(DeleteSequence));

			while (1)
			{	//Delete Sequence�� ���ڷ� �Է����� �ʾҰų� 10�ʰ��� ��� ����ó��
				if (atoi(DeleteSequence) != 0 && atoi(DeleteSequence) <= 10) break;
				else
				{
					cout << "Delete Sequence�� ���ڷ� �Է����� �ʾҰų� 10�ʰ��Դϴ�" << endl;
					cout << ">Delete Sequence: ";
					cin.getline(DeleteSequence, sizeof(DeleteSequence));
					cout << endl;
				}
			}

			for (int i = 1; i <= Store; i++) {	//Delete�� �������� �����۸���Ʈ�� �ִ��� Ȯ���ϴ� for��
				if (atoi(DeleteSequence) == i) {
					DeleteOverlap = DeleteOverlap + 1;	//�ִٸ� Overlap + 1 ���ְ� break
					break;
				}
			}
			if (DeleteOverlap == 1) {	//������ Sequence�� ������ ����Ʈ�� �ִٸ� ����
				for (int i = atoi(DeleteSequence) - 1; i < Store; i++)
					Info[atoi(DeleteSequence) - 1].Delete(Info, i, Store);	//������ ���κ��� ���ΰ� Sequence�� ���ڷ� �Ѱܼ� Class Delete�Լ� Ȱ��
				Store = Store - 1;	//���������Ƿ� �� �ټ��� - 1
				cout << endl;
			}
			else cout << "���� �� Sequence ������ �����ϴ�." << endl << endl;	//������ Sequence�� ������ ����Ʈ�� ���ٸ� ����
		}
		//************Print***********//
		if (atoi(Input) == 5) {
			cout << "1. sequence   2. name   3. price   4. quantity " << endl;
			cout << ">Input: ";
			cin.getline(Input, sizeof(Input));
			while (true)
			{	//1~4���̿� ���ڸ� �Է����� �ʾ��� ���� ���ڿ��� �Է��� ��� ����ó��
				if (atoi(Input) != 0 && atoi(Input) < 5 )  break;
				else {
					cout << "1~4���̿� ���ڸ� �Է��ϼ��� !!!" << endl;
					cout << "1. sequence   2. name   3. price   4. quantity " << endl;
					cout << ">Input: ";
					cin.getline(Input, sizeof(Input));
				}

			}
			Info->Print(Info, Store, atoi(Input));	//Sorting�� ��ȣ�� �ٹ�ȣ �迭�� ���ڷ� �Ѱܼ� Ŭ���� Print �Լ� ���
		}
		//*************Save************//
		if (atoi(Input) == 6) {
			ofstream Write;
			Write.open("ItemList.txt", ios::trunc);	//ItemList ������ ��� �����ϰ� ����� ���Ϸ� �д´�.
			if (Write.fail()) {	//���� Open ������ ����ó��
				cout << "������ �ҷ��� �� �����ϴ�." << endl;
				cout << "Save Error" << endl;
			}
			else {	//���� �ҷ����⿡ ������ ���
				for (int i = 0; i < Store; i++) {	//����Ǿ��ִ� Sequence���� Ŭ���� Save�Լ� ���
					Info[i].Save(Write, Info, i, Store);	//�޸���� �迭 �ٹ�ȣ�� ���ڷ� �ѱ��.
				}
				cout << endl;
				Write.close();	//����� ������ �ݴ´�.
				cout << " **Save Complete **" << endl;
			}
		}
		//*************Quit************//
		if (atoi(Input) == 7) {
			cout << endl;
			break;
		}
	}
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
//strcmp
int my_strcmp(char str1[], char str2[]) {

	int i = 0;
	int j = 0;

	while (str1[i] != NULL && str2[i] != NULL) //�� ���ڿ��� NULL�� �ƴҶ�����
	{
		if (str1[i] != str2[i])	//�� ���ڿ��� �ٸ���
			return str2[i] - str1[i];
		i++;
	}
	//���ڿ� �񱳰� ���� ���� ���ϰ�
	if (str1[i] == NULL)
		return str2[i];
	if (str2[i] == NULL)
		return -str1[i];
}