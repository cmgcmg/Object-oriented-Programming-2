#include <iostream>
#include <fstream>
using namespace std;

class Item {	//Item 클래스 선언

private:	//Item 클래스에 선언되어있는 Private 변수들
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
	this->name = new char[my_len(name) + 1];	//물건의 이름 만큼 동적 배열을 할당 받는다 ( + 1해준이유는 \n 때문 )

	my_cpy(this->name, name);	//인자로 받아온 Name을 클래스 Private 변수 Name에 삽입
	this->price = price;		//인자로 받아온 price를 클래스 Private 변수 Price에 삽입
	this->quantity = quantity;	//인자로 받아온 quantity를 클래스 Private 변수 Quantity에 삽입
	this->sequence = sequence;	//인자로 받아온 sequence를 클래스 Private 변수 Sequence에 삽입

}
//**Insert Function**//
void Item::Insert(char *name, int price, int quantity, int sequence)
{
	this->name = new char[my_len(name) + 1]; //Insert할 이름의 정보에 대해서 동적 배열을 할당 받는다 ( +1 해준이유는 \n 때문 )

	my_cpy(this->name, name);	//Insert할 Name을 클래스 Private변수 Name에 삽입
	this->price = price;		//Insert할 Pricce를 클래스 Private변수 Price에 삽입
	this->quantity = quantity;	//Insert할 Quantity를 클래스 Private변수 Quantity에 삽입
	this->sequence = sequence;	//Insert할 Sequence를 클래스 Private변수 Sequence에 삽입
}
//**Update Function**//
void Item::Update(char *name, int price, int quantity, int sequence)
{
	this->name = new char[my_len(name) + 1];	//Update할 이름의 정보에 대해서 동적 배열을 할당 받는다 ( +1 해준 이유는 \n 때문 )

	my_cpy(this->name, name);	//Update할 Name을 클래스 Private변수 Name에 삽입
	this->price = price;		//Update할 Price를 클래스 Private변수 Price에 삽입
	this->quantity = quantity;	//Update할 Quantity를 클래스 Private변수 Quantity에 삽입
	this->sequence = sequence;	//Update할 Sequence를 클래스 Private변수 Sequence에 삽입
}
//**Delete Function**//
void Item::Delete(Item Info[], int sequence, int Store) //특이한 점은 Store(현재 저장된 Line 번호 숫자를 인자로 받아온다)
{
	if (sequence == Store - 1) {	//마지막 Sequence일 경우 NULL값으로 초기화
		Info[sequence].name = NULL;
		Info[sequence].sequence = 0;
		Info[sequence].price = 0;
		Info[sequence].quantity = 0;
	}
	else {	// DeleteLine을 기준으로 해서 마지막 Sequence가 아닐 경우 DeleteLine 다음 배열에 해당하는 정보를 한칸씩 앞으로 당긴다. 
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
		for (int i = 0; i < Store; i++) {	//저장되어 있는 정보들을 Sequence순으로 출력
			cout << i + 1 << ". " << Info[i].name << "($" << Info[i].price << ", " << Info[i].quantity << ")" << endl;
		}
		cout << endl;
	}

	else if (SortNumber == 2) {	//Name Sorting
		cout << "** Name Sort **" << endl;
		cout << endl << "KW Store Item List" << endl;
		int temp;
		int Sort[10];
		for (int i = 0; i < Store; i++) {	//0~저장된 번호까지 저장되어있는 Sort배열을 생성
			Sort[i] = i;
		}

		for (int i = 0; i < Store - 1; i++) {	//Name에 대해서 정렬한 Sort배열을 순서대로 번호로 해서 원래 정보들을 Sorting
			for (int j = i + 1; j < Store; j++) {	//저장되어 있는 정보를 바꿔서 출력하면 안되기 때문
				if (my_strcmp(Info[Sort[i]].name, Info[Sort[j]].name) < 0) {
					temp = Sort[i];
					Sort[i] = Sort[j];
					Sort[j] = temp;
				}
			}
		}

		
		cout << endl;

		for (int i = 0; i < Store; i++) {	//Name으로 Sorting된 Item 정보들을 출력
			cout << i+1 << ". " << Info[Sort[i]].name << "($" << Info[Sort[i]].price << ", " << Info[Sort[i]].quantity << ")" << endl;
		}
	}

	else if (SortNumber == 3) {
		cout << "** Price Sort **" << endl;
		cout << endl << "KW Store Item List" << endl;
		int temp;
		int Sort[10];
		for (int i = 0; i < Store; i++) { //0~저장된 번호까지 저장되어있는 Sort배열을 생성
			Sort[i] = i;
		}
		for (int i = 0; i < Store - 1; i++) {	//Price에 대해서 정렬한 Sort배열을 순서대로 번호로 해서 원래 정보들을 Sorting
			for (int j = i + 1; j < Store; j++) { //저장되어 있는 정보를 바꿔서 출력하면 안되기 때문
				if (Info[Sort[i]].price > Info[Sort[j]].price ) {
					temp = Sort[i];
					Sort[i] = Sort[j];
					Sort[j] = temp;
				}
			}
		}
		cout << endl;

		for (int i = 0; i < Store; i++) {	//Price에 대해서 Sorting한 Item 정보들을 출력
			cout << i+1 << ". " << Info[Sort[i]].name << "($" << Info[Sort[i]].price << ", " << Info[Sort[i]].quantity << ")" << endl;
		}
	}

	else {
		cout << "** Quantity Sort **" << endl;
		cout << endl << "KW Store Item List" << endl;
		int temp;
		int Sort[10];
		for (int i = 0; i < Store; i++) { //0~저장된 번호까지 저장되어있는 Sort배열을 생성
			Sort[i] = i;
		}
		for (int i = 0; i < Store - 1; i++) { //Quantity에 대해서 정렬한 Sort배열을 순서대로 번호로 해서 원래 정보들을 Sorting
			for (int j = i + 1; j < Store; j++) { //저장되어 있는 정보를 바꿔서 출력하면 안되기 때문
				if (Info[Sort[i]].quantity > Info[Sort[j]].quantity) {
					temp = Sort[i];
					Sort[i] = Sort[j];
					Sort[j] = temp;
				}
			}
		}
		cout << endl;

		for (int i = 0; i < Store; i++) {	//Quantity에 대해서 Sorting한 Item정보를 출력
			cout << i+1 << ". " << Info[Sort[i]].name << "($" << Info[Sort[i]].price << ", " << Info[Sort[i]].quantity << ")" << endl;
		}
	}
}
//**Save Function**//
void Item::Save(std::ofstream &Write, Item Info[], int count, int Store)	//줄번호와 배열 그리고 메모장을 인자로 받아온다.
{
	if (count == Store - 1) {	//마지막 줄일경우 \n을 제외하고 메모장에 쓴다.
		Write << this->name << "/" << this->price << "/" << this->quantity;
	}
	else                       //마지막 줄이 아닐경우 \n을 포함해서 메모장에 쓴다.
		Write << this->name << "/" << this->price << "/" << this->quantity << endl;



}
//strcpy
char* Item::my_cpy(char *str2, char *str1) {

	for (int i = 0; str1[i] != 0; i++)	//복사하려는 문자열 끝까지 for문을 수행
	{
		str2[i] = str1[i];	//복사하려는 문자열 Str1을 Str2에 넣어준다.
		str2[i + 1] = 0;	//문자열의 끝을 NULL값을 삽입
	}

	return str2;	//복사한 문자열을 리턴
}
//strtok
char* Item::my_tok(char *str1, char *par) {

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
int Item::my_len(char *str1) {

	int len = 0;

	while (str1[len] != NULL) //문자열이 끝날 때 까지 While문을 수행
	{
		len = len + 1;
	}
	return len;	//문자열의 길이를 return한다.
}
//strcmp
int Item::my_strcmp(char str1[], char str2[]) {

	int i = 0;
	int j = 0;

	while (str1[i] != NULL && str2[i] != NULL) //두 문자열이 NULL이 아닐때까지
	{
		if (str1[i] != str2[i])	//두 문자열이 다르면
			return str2[i] - str1[i];
		i++;
	}
	//문자열 비교가 끝난 이후 리턴값
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
	Item Info[10]; // Item 클래스 배열 10개 선언 ( Item list는 10개 )

	while (1) {
		cout << "1.Load  2.Insert  3.Update  4.Delete  5.Print  6.Save  7.Quit" << endl;
		cout << ">Input number: ";
		cin.getline(Input, sizeof(Input));

		while (1) {	//Input Number가 숫자가 아닐경우 예외처리

			if (atoi(Input) != 0) break;

			else {
				cout << "숫자를 입력하세요." << endl;
				cout << ">Input number";
				cin.getline(Input, sizeof(Input));
			}
		}
		//***********Load************//
		if (atoi(Input) == 1)
		{
			char LoadData[100] = { 0, };	//Load할 정보들을 저장할 변수
			char *Loadname;
			int Loadprice;
			int Loadquantity;
			Store = 0;

			fstream LoadRead;
			LoadRead.open("ItemList.txt");	//ItemList파일을 읽기용 파일로 Open

			if (LoadRead.fail())	//파일 Open 실패시 예외처리
			{
				cout << "파일을 불러올 수 없습니다." << endl;
				cout << "Load Error" << endl;
			}
			else
			{
				while (!LoadRead.eof())	//파일의 정보를 다 불러올떄까지
				{
					LoadRead.getline(LoadData, sizeof(LoadData));	//한줄을 받아와서 Name, Price, Quantitiy로 token을 사용해서 저장
					Loadname = my_tok(LoadData, "/");
					Loadprice = atoi(my_tok(NULL, "/"));
					Loadquantity = atoi(my_tok(NULL, "/"));
					if (Store < 10) {	//Load할 수 있는 개수는 10개다.
						Info[Store].Load(Loadname, Loadprice, Loadquantity, (Store + 1));
						Store = Store + 1;
					}	//10 이후 부터 예외처리 출력
					else cout << Loadname << " could not be loaded. " << endl;

				}
			}

			cout << endl << "** Load Complete **" << endl;
			LoadRead.close();	//File Close
		}
		//***********Insert************//
		if (atoi(Input) == 2)
		{
			char InsertName[100];	//Insert할 정보들
			char InsertPrice[100];
			char InsertQuantity[100];

			cout << endl << "** Insert **" << endl;
			cout << "Item Name: ";
			cin.getline(InsertName, sizeof(InsertName));

			cout << "Price: ";
			cin.getline(InsertPrice, sizeof(InsertPrice));

			while (1)		//Price를 문자열로 입력했을 경우 예외처리
			{			
				if (atoi(InsertPrice) != 0) break;
				else {
					cout << "Item Price를 숫자로 입력해주세요. " << endl;
					cout << ">Price: ";
					cin.getline(InsertPrice, sizeof(InsertPrice));
				}
			}

			cout << "Quantity: ";
			cin.getline(InsertQuantity, sizeof(InsertQuantity));
			while (1)	//Quantity를 문자열로 입력했을 경우 예외처리
			{
				if (atoi(InsertQuantity) != 0) break;
				else {
					cout << "Item Quantity를 숫자로 입력해주세요. " << endl;
					cout << ">Quantity: ";
					cin.getline(InsertQuantity, sizeof(InsertQuantity));
				}
			}
			if (Store != 10) {	// 10개의 정보가 다 차있지 않다면 Insert 함수 사용
				Info[Store].Insert(InsertName, atoi(InsertPrice), atoi(InsertQuantity), (Store + 1));
				Store = Store + 1;
				cout << endl;
			}

			else {	//10개의 정보가 다 차있으면 예외처리
				cout << "10개의 정보가 모두 다 차있습니다." << endl;
				cout << "Insert할 수 없습니다." << endl;
			}

		}
		//***********Update************//
		if (atoi(Input) == 3) {

			char UpdateSequence[100];	//Update할 정보를 담을 변수들
			char UpdateName[100];
			char UpdatePrice[100];
			char UpdateQuantity[100];

			cout << endl << "** Update **" << endl;
			cout << "Input Sequence: ";
			cin.getline(UpdateSequence, sizeof(UpdateSequence));
			cout << endl;
			while (1)
			{	//Sequence를 숫자로 입력하지 않았거나 10을 초과했을 경우 예외처리
				if (atoi(UpdateSequence) != 0 && atoi(UpdateSequence) <= 10) break;
				else
				{
					cout << "Input Sequence를 숫자로 입력하지 않았거나 10초과입니다." << endl;
					cout << "Input Sequence: ";
					cin.getline(UpdateSequence, sizeof(UpdateSequence));
				}
			}

			while (1)
			{	//Input Sequence를 숫자로 입력 안했을 경우 예외처리
				if (atoi(Input) != 0) break;

				cout << "숫자를 입력하세요." << endl;
				cout << ">Input Sequence";
				cin.getline(Input, sizeof(Input));
			}

			cout << "Item Name: ";
			cin.getline(UpdateName, sizeof(UpdateName));

			cout << "Price: ";
			cin.getline(UpdatePrice, sizeof(UpdatePrice));
			while (1)
			{	//Price를 문자열로 입력했을 경우 예외처리
				if (atoi(UpdatePrice) != 0) break;
				else {
					cout << "Item Price를 숫자로 입력해주세요. " << endl;
					cout << ">Price: ";
					cin.getline(UpdatePrice, sizeof(UpdatePrice));
				}
			}

			cout << "Quantity: ";
			cin.getline(UpdateQuantity, sizeof(UpdateQuantity));
			while (1)
			{	//Quantity를 문자열로 입력했을 경우 예외처리
				if (atoi(UpdateQuantity) != 0) break;
				else {
					cout << "Item Quantity를 숫자로 입력해주세요. " << endl;
					cout << ">Quantity: ";
					cin.getline(UpdateQuantity, sizeof(UpdateQuantity));
				}
			}	//Update할 정보들을 인자로 넣어서 클래스 Update함수 활용
			Info[atoi(UpdateSequence) - 1].Update(UpdateName, atoi(UpdatePrice), atoi(UpdateQuantity), atoi(UpdateSequence));
			cout << endl;
		}
		//***********Delete************//
		if (atoi(Input) == 4) {

			char DeleteSequence[100];	//Delete할 줄을 찾는 변수
			int DeleteOverlap = 0;

			cout << endl << "** Delete **" << endl;
			cout << ">Input sequence: ";
			cin.getline(DeleteSequence, sizeof(DeleteSequence));

			while (1)
			{	//Delete Sequence를 숫자로 입력하지 않았거나 10초과일 경우 예외처리
				if (atoi(DeleteSequence) != 0 && atoi(DeleteSequence) <= 10) break;
				else
				{
					cout << "Delete Sequence를 숫자로 입력하지 않았거나 10초과입니다" << endl;
					cout << ">Delete Sequence: ";
					cin.getline(DeleteSequence, sizeof(DeleteSequence));
					cout << endl;
				}
			}

			for (int i = 1; i <= Store; i++) {	//Delete할 시퀀스가 아이템리스트에 있는지 확인하는 for문
				if (atoi(DeleteSequence) == i) {
					DeleteOverlap = DeleteOverlap + 1;	//있다면 Overlap + 1 해주고 break
					break;
				}
			}
			if (DeleteOverlap == 1) {	//삭제할 Sequence가 아이템 리스트에 있다면 수행
				for (int i = atoi(DeleteSequence) - 1; i < Store; i++)
					Info[atoi(DeleteSequence) - 1].Delete(Info, i, Store);	//삭제할 라인부터 라인과 Sequence를 인자로 넘겨서 Class Delete함수 활용
				Store = Store - 1;	//삭제했으므로 총 줄수는 - 1
				cout << endl;
			}
			else cout << "삭제 할 Sequence 정보가 없습니다." << endl << endl;	//삭제할 Sequence가 아이템 리스트에 없다면 수행
		}
		//************Print***********//
		if (atoi(Input) == 5) {
			cout << "1. sequence   2. name   3. price   4. quantity " << endl;
			cout << ">Input: ";
			cin.getline(Input, sizeof(Input));
			while (true)
			{	//1~4사이에 숫자를 입력하지 않았을 때와 문자열을 입력한 경우 예외처리
				if (atoi(Input) != 0 && atoi(Input) < 5 )  break;
				else {
					cout << "1~4사이에 숫자를 입력하세요 !!!" << endl;
					cout << "1. sequence   2. name   3. price   4. quantity " << endl;
					cout << ">Input: ";
					cin.getline(Input, sizeof(Input));
				}

			}
			Info->Print(Info, Store, atoi(Input));	//Sorting할 번호와 줄번호 배열을 인자로 넘겨서 클래스 Print 함수 사용
		}
		//*************Save************//
		if (atoi(Input) == 6) {
			ofstream Write;
			Write.open("ItemList.txt", ios::trunc);	//ItemList 파일을 모두 삭제하고 쓰기용 파일로 읽는다.
			if (Write.fail()) {	//파일 Open 에러시 예외처리
				cout << "파일을 불러올 수 없습니다." << endl;
				cout << "Save Error" << endl;
			}
			else {	//파일 불러오기에 성공한 경우
				for (int i = 0; i < Store; i++) {	//저장되어있는 Sequence까지 클래스 Save함수 사용
					Info[i].Save(Write, Info, i, Store);	//메모장과 배열 줄번호를 인자로 넘긴다.
				}
				cout << endl;
				Write.close();	//쓰기용 파일을 닫는다.
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
//strcmp
int my_strcmp(char str1[], char str2[]) {

	int i = 0;
	int j = 0;

	while (str1[i] != NULL && str2[i] != NULL) //두 문자열이 NULL이 아닐때까지
	{
		if (str1[i] != str2[i])	//두 문자열이 다르면
			return str2[i] - str1[i];
		i++;
	}
	//문자열 비교가 끝난 이후 리턴값
	if (str1[i] == NULL)
		return str2[i];
	if (str2[i] == NULL)
		return -str1[i];
}