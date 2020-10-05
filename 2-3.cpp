#include <iostream>
#include <fstream>

using namespace std;


char* my_cpy(char *str2, char *str1); //strcpy
char* my_tok(char *str1, char *par); //strtok
int my_strcmp(char str1[], char str2[]); //strcmp


typedef struct Music {	//음악의 정보를 가지고 다닐 구조체 선언
	int rank;
	char title[50];
	char singer[50];
	int year;
}Music;

int main() {
	Music Info[100];	//Music구조체를 담고 있는 배열
	char data[100]; //메모장 불러올 때 받을 배열
	char *token; //문자열 "/"기준으로 짜를 떄 쓰는 변수
	char str[100] = { 0, }; // rank, Singer, Title, Year 입력받을 변수
	int count = 0; // Info 구조체에 삽입시 개수를 세주는 변수
	char input[100]; // 어떤거 선택할지 선택하는 변수
	int equal = 0; //update에서 rank를 찾을 때 쓰는 변수

	ifstream read("MusicList.txt");	//File Open

	if (read.fail()) {	//File Open Exeption handling
		cout << "파일 불러오기에 실패했습니다." << endl;
	}

	while (!read.eof()) {	//파일을 불러오기에 성공했다면 진행하는 While문
							//getline으로 한줄씩 메모장을 한줄씩 불러와 Music구조체 배열에 넣어준다.
		read.getline(data, 100);
		token = my_tok(data, "/");
		Info[count].rank = atoi(token);

		token = my_tok(NULL, "/");
		my_cpy(Info[count].title, token);
		token = my_tok(NULL, "/");
		my_cpy(Info[count].singer, token);

		token = my_tok(NULL, "/");
		Info[count].year = atoi(token);

		count = count + 1;	//한줄을 불러와 Music구조체 배열에 넣을 경우 카운트를 증가시킨다.
	}

	read.close();	//파일을 닫는다.

	while (1) {
		cout << "1.Insert\t 2.Update\t 3.Delete\t 4.Sort\t 5.Quit" << endl;
		cout << "Input number: ";
		cin >> input;

		while (true) {	//Input number Exeption handling
			if (atoi(input) == 0) {
				cout << "Input number를 숫자로 입력해 주세요." << endl << "Input number: ";
				cin >> input;
			}
			else break;
		}
		//********************************************Insert********************************************************//
		if (atoi(input) == 1) {	

			int InsertOverlap = 0; //이미 메모장에 존재하는 Rank가 있는지 확인하기 위해 사용하는 변수

			ofstream InsertWrite;	//파일을 쓰기용으로 Open
			InsertWrite.open("MusicList.txt", ios::app); //쓰기용 파일을 Open할 때 파일포인터를 끝에 위치하면서 Open한다.

			if (InsertWrite.fail()) {	//File open exeption handling
				cout << "파일을 불러 올 수 없습니다." << endl;
			}

			cout << endl;
			cout << "** Insert **" << endl;
			cout << ">Rank: ";
			cin >> str;

			while (true) {	//Rank에 문자를 입력했을 경우 예외처리 하는 부분

				if (atoi(str) == 0) {
					cout << "Rank에는 숫자만 입력해 주세요." << endl << ">Rank: ";
					cin >> str;
				}
				else break;
			}

			while (true) {	//같은 Rank를 입력했을 경우 예외처리 하는 부분

				InsertOverlap = 0;

				for (int i = 0; i < count - 1; i++) {
					if (Info[i].rank == atoi(str)) {
						InsertOverlap = InsertOverlap + 1;
					}
				}

				if (InsertOverlap == 1) {
					cout << "이미 입력한 Rank입니다. 다시 입력해 주세요." << endl << ">Rank: ";
					cin >> str;
				}

				else break;
			}
			//새로 추가할 음악의 Rank, Title, Singer, Year를 삽입하는 부분
			cin.ignore();
			Info[count].rank = atoi(str);

			cout << ">Title: ";
			cin.getline(str, 100);
			my_cpy(Info[count].title, str);

			cout << ">Singer: ";
			cin.getline(str, 100);
			my_cpy(Info[count].singer, str);

			cout << ">Release Year: ";
			cin >> str;
			while (true) {	//Year에 문자열이 들어왔을 경우 예외처리 하는 부분
				if (atoi(str) == 0) {
					cout << "Year에는 숫자만 입력해 주세요." << endl << ">Year: ";
					cin >> str;
				}
				else break;
			}
			Info[count].year = atoi(str);

			cout << endl;
			//위에서 입력했던 Insert할 것을 메모장에 써준다.
			InsertWrite << endl << Info[count].rank << "/" << Info[count].title << "/" << Info[count].singer << "/" << Info[count].year;
			count = count + 1;	//Insert가 되었으니 Count는 1 증가
			InsertWrite.close();	//쓰기용 파일을 닫는다.
		}
		//********************************************Update********************************************************//
		if (atoi(input) == 2) {

			int UpdateLine = 0; // Update부분에 사용 하는 변수
			int UpdateOverlap = 0;	//Rank값이 중복됬는지 찾기 위한 변수
			int OverlapLine = 0;	//업데이트를 할 부분으로 사용하는 변수

			ifstream UpdateRead;	//읽기용파일로 File Open
			UpdateRead.open("MusicList.txt"); 

			if (UpdateRead.fail()) {	//File Open Exeption handling
				cout << "파일을 불러올 수 없습니다." << endl;
			}

			cout << endl << "**Update**" << endl;
			cout << "Input rank: ";
			cin >> str;

			while (true) {	//Rank에 문자열을 입력했을 경우 예외처리 하는 부분

				if (atoi(str) == 0) {
					cout << "Rank를 숫자로 입력해주세요. " << endl << "Input rank: ";
					cin >> str;
				}
				else break;
			}

			cout << endl;

			for (UpdateLine = 0; UpdateLine < count; UpdateLine++) {	//현재 메모장에 내가 입력한 Rank가 있는지 Search하기 위한 for문
				if (Info[UpdateLine].rank == atoi(str)) {
					equal = equal + 1;	//입력한 Rank가 현재 메모장에 존재한다면 equal = equal + 1
					break;
				}
				OverlapLine = OverlapLine + 1;
			}

			UpdateRead.close(); //읽기용 파일을 닫는다.

			if (equal == 0) {	//바꾸려는 정보의 Rank가 있지 않다면 수행

				cout << "Ther is not the music which the rank is " << atoi(str) << "in the music list!" << endl;

			}

			else {	//바꾸려는 정보의 Rank가 있다면 수행

				cout << ">Rank: ";
				cin >> str;

				while (true) {	//Rank를 문자열로 입력했을 경우 예외처리

					if (atoi(str) == 0) {
						cout << "Rank를 숫자로 입력해주세요. " << endl << "Input rank: ";
						cin >> str;
					}
					else break;
				}

				while (true) {

					UpdateOverlap = 0;	//

					for (int i = 0; i < OverlapLine; i++) {
						if (Info[i].rank == atoi(str)) {	//만약 바꾸려고 입력한 Rank가 이미 메모장에 존재한다면
							UpdateOverlap = UpdateOverlap + 1;	//UpdateOverlap = 1
							break;
						}
					}
					//바꾸려는 정보의 Rank값은 변하지 않고 그대로 입력 할수도있기 때문에 Update하는 라인의 정보는 제외하고 for문을 수행
					for (int i = OverlapLine + 1; i < count - 1; i++) {
						if (Info[i].rank == atoi(str)) {
							UpdateOverlap = UpdateOverlap + 1;
							break;
						}
					}

					if (UpdateOverlap != 0) {	//바꾸려고 하는 Rank값이 이미 메모장에 존재하는 경우 수행
						cout << "List에 변경하려는 Rank가 이미 존재합니다. 다른 Rank를 입력해 주세요." << endl << ">Rank: ";
						cin >> str;
						OverlapLine = 0;
						for (int i = 0; i < count - 1; i++) {
							if (Info[i].rank == atoi(str)) {
								break;
							}
							OverlapLine = OverlapLine + 1;
						}
					}
					else break;
				}
				//바꿀 정보들 ( Rank, Title, Singer, Year )를 입력
				cin.ignore();
				Info[UpdateLine].rank = atoi(str);

				cout << ">Title: ";
				cin.getline(str, 100);
				my_cpy(Info[UpdateLine].title, str);

				cout << ">Singer: ";
				cin.getline(str, 100);
				my_cpy(Info[UpdateLine].singer, str);

				cout << ">Release Year: ";
				cin >> str;
				while (true) {	//Year에 문자열을 입력한 경우 예외처리
					if (atoi(str) == 0) {
						cout << "Year에는 숫자만 입력해 주세요." << endl << ">Year: ";
						cin >> str;
					}
					else break;
				}
				Info[UpdateLine].year = atoi(str);

				ofstream update;
				update.open("MusicList.txt", ios::trunc);	//이름이 같은 파일의 메모장의 내용을 다지우고 File을 Open한다.

				for (UpdateLine = 0; UpdateLine < count - 1; UpdateLine++) { //현재 구조체 배열에 들어있는 정보들의 마지막줄 전까지 쓰기용 파일에 써준다.
					update << Info[UpdateLine].rank << "/" << Info[UpdateLine].title << "/" << Info[UpdateLine].singer << "/" << Info[UpdateLine].year << endl;
				}
				//마지막줄은 \n이 들어가면 안되므로 따로 빼서 쓰기용 파일에 써준다.
				update << Info[UpdateLine].rank << "/" << Info[UpdateLine].title << "/" << Info[UpdateLine].singer << "/" << Info[UpdateLine].year;

				update.close();	//쓰기용 파일을 Close
			}
		}
		//********************************************Delete********************************************************//
		if (atoi(input) == 3) {

			int DeleteLine = 0;
			int DeleteOverlap = 0;
			int Line = 0;

			ifstream DeleteRead;
			DeleteRead.open("MusicList.txt");	//읽기용 파일로 MusicList를 열어준다.

			if (DeleteRead.fail()) {	//File Open exeption handling
				cout << "파일을 불러 올 수 없습니다." << endl;
			}

			cout << endl << "** Delete **" << endl;
			cout << ">Input rank: ";
			cin >> str;

			while (true) {	//Rank에 문자열을 입력했을 경우 예외처리
				if (atoi(str) == 0) {
					cout << "Rank에는 숫자만 입력해 주세요." << endl << ">Input rank: ";
					cin >> str;
				}
				else break;
			}

			for (int i = 0; i < count; i++) {	//삭제하려는 Rank가 메모장에 있는지 확인하는 for문
				if (Info[i].rank == atoi(str)) {
					DeleteLine = i;	//삭제하려는 Line과 메모장에 이다면 Overlap = 1
					DeleteOverlap = DeleteOverlap + 1;
					break;
				}
			}

			DeleteRead.close();	//읽기용 파일을 Close

			if (DeleteOverlap == 0) {	//삭제하려는 정보의 Rank가 메모장에 없다면 수행
				cout << "Ther is not the music which the rank is " << atoi(str) << "in the music list!" << endl;
			}

			else {	//삭제하려는 정보의 rANK가 메모장에 있다면 수행

				ofstream DeleteWrite;
				DeleteWrite.open("MusicList.txt", ios::trunc);	//MusicList파일을 쓰기용 파일로 빈상태로 열어준다.

				for (int i = DeleteLine + 1; i < count; i++) { //삭제하려는 Line의 다음 부터 앞쪽 배열로 정보를 옮긴다.
					Info[i - 1].rank = Info[i].rank;
					my_cpy(Info[i - 1].title, Info[i].title);
					my_cpy(Info[i - 1].singer, Info[i].singer);
					Info[i - 1].year = Info[i].year;
				}

				count = count - 1;	//Delete되었기 때문에 전체적인 Count는 1개 감소

				for (int i = 0; i < count - 1; i++) {	//Music 구조체 배열에 들어있는 마지막 전까지 파일에 쓴다.
					DeleteWrite << Info[i].rank << "/" << Info[i].title << "/" << Info[i].singer << "/" << Info[i].year << endl;
					Line = Line + 1;
				}	//Music 구조체 배열에 들어있는 마지막은 \n을 제외해서 파일에 쓴다.
				DeleteWrite << Info[Line].rank << "/" << Info[Line].title << "/" << Info[Line].singer << "/" << Info[Line].year;
			}
		}
		//********************************************Sort**********************************************************//
		if (atoi(input) == 4) {

			cout << endl << "** Sort **" << endl;
			cout << "1.Sort by the rank    2.Sort by the title    3. Sort by the singer    4. Sort by the release year" << endl;
			cout << ">Input number: ";
			cin >> str;

			while (true) {	//Input number에 문자열을 입력한 경우 예외처리

				if (atoi(str) == 0) {
					cout << "Input number에는 숫자만 입력해 주세요." << endl << ">Input number: ";
					cin >> str;
				}
				else break;
			}

			if (atoi(str) == 1) {	//Sort by the rank

				Music temp;
				int Sort1Line = 0;

				for (int i = 0; i < count; i++) {	//rank를 비교하면서 오름차순으로 정렬한다, 이 때 Music 구조체 배열이 수정
					for (int j = i + 1; j < count; j++) {
						if (Info[j].rank < Info[i].rank)
						{
							temp = Info[i];
							Info[i] = Info[j];
							Info[j] = temp;
						}
					}
				}

				ofstream Sort1;	//메모장의 내용을 모두 삭제한 상태로 쓰기용 파일로 Open한다.
				Sort1.open("MusicList.txt", ios::trunc);

				for (int i = 0; i < count - 1; i++) {	//바뀐 정보들을 메모장에 입력시 마지막 전까지 메모장에 써준다.

					Sort1 << Info[i].rank << "/" << Info[i].title << "/" << Info[i].singer << "/" << Info[i].year << endl;
					Sort1Line = Sort1Line + 1;

				}
				//바뀐 정보의 마지막줄을 메모장에 써준다. ( \n 제외 하기 위해서 )
				Sort1 << Info[Sort1Line].rank << "/" << Info[Sort1Line].title << "/" << Info[Sort1Line].singer << "/" << Info[Sort1Line].year;

				Sort1.close();	//파일 Close
			}

			else if (atoi(str) == 2) { //sort by the title

				Music temp; //Music 구조체 배열을 Sorting 및 Swap할 때 사용하는 구조체 배열
				int Sort2Line = 0;

				for (int i = 0; i < count; i++) {	//title을 String Compare를 사용해서 오름차순으로 Music 구조체 배열을 Sorting
					for (int j = i + 1; j < count; j++) {
						if (my_strcmp(Info[i].title, Info[j].title) < 0)
						{
							temp = Info[i];
							Info[i] = Info[j];
							Info[j] = temp;
						}
					}
				}

				ofstream Sort2;
				Sort2.open("MusicList.txt", ios::trunc);	//메모장의 내용을 모두 삭제하고 쓰기용 파일로 Open

				for (int i = 0; i < count - 1; i++) {	//Sorting된 구조체 배열 마지막줄 전까지를 메모장에 쓴다.

					Sort2 << Info[i].rank << "/" << Info[i].title << "/" << Info[i].singer << "/" << Info[i].year << endl;
					Sort2Line = Sort2Line + 1;

				}
				//Sorting된 구조체 배열 마지막줄을 메모장에 쓴다 ( \n 떄문에 )
				Sort2 << Info[Sort2Line].rank << "/" << Info[Sort2Line].title << "/" << Info[Sort2Line].singer << "/" << Info[Sort2Line].year;

				Sort2.close(); // 메모장 Close
			}

			else if (atoi(str) == 3) { //sort by the singer

				Music temp;	//Sorting 및 Swap처리할 때 사용하는 Music 구조체 배열
				int Sort3Line = 0;

				for (int i = 0; i < count; i++) { //Singer가 같을 경우 Rank에 의해 Sort되므로 Rank에 대해서 먼저 Sorting한다.
					for (int j = i + 1; j < count; j++) {
						if (Info[j].rank < Info[i].rank)
						{
							temp = Info[i];
							Info[i] = Info[j];
							Info[j] = temp;
						}
					}
				}

				for (int i = 0; i < count; i++) {	//Singer에 대해서 오름차순 Sorting
					for (int j = i + 1; j < count; j++) {
						if (my_strcmp(Info[i].singer, Info[j].singer) < 0)
						{
							temp = Info[i];
							Info[i] = Info[j];
							Info[j] = temp;
						}
					}
				}

				ofstream Sort3;
				Sort3.open("MusicList.txt", ios::trunc);	//메모장의 내용을 모두 지우고 쓰기용 파일로 Open

				for (int i = 0; i < count - 1; i++) {	//Sorting된 구조체 배열을 마지막줄 전까지 메모장에 써준다.

					Sort3 << Info[i].rank << "/" << Info[i].title << "/" << Info[i].singer << "/" << Info[i].year << endl;
					Sort3Line = Sort3Line + 1;

				}
				//Sorting된 구조체 배열 마지막줄을 메모장에 써준다 ( \n 때문에 )
				Sort3 << Info[Sort3Line].rank << "/" << Info[Sort3Line].title << "/" << Info[Sort3Line].singer << "/" << Info[Sort3Line].year;

				Sort3.close();	//File Close
			}

			else {	//Sort by the release year

				Music temp;	//Sorting 및 Swap처리 시 사용하는 구조체 배열
				int Sort4Line = 0;

				for (int i = 0; i < count; i++) {	//Release Year가 같을경우 Rank에 따라 Sorting되므로 Rank에 대해서 Sorting을 먼저 진행
					for (int j = i + 1; j < count - 1; j++) {
						if (Info[j].rank < Info[i].rank)
						{
							temp = Info[i];
							Info[i] = Info[j];
							Info[j] = temp;
						}
					}
				}

				for (int i = 0; i < count; i++) {	//Release Year에 대해서 Sorting 내림차순
					for (int j = i + 1; j < count - 1; j++) {
						if (Info[i].year < Info[j].year)
						{
							temp = Info[i];
							Info[i] = Info[j];
							Info[j] = temp;
						}
					}
				}

				ofstream Sort4;
				Sort4.open("MusicList.txt", ios::trunc); //메모장의 내용을 모두 삭제하고 쓰기용 파일로 Open

				for (int i = 0; i < count - 1; i++) { //Sorting된 구조체 배열의 마지막줄 전까지 메모장에 써준다.

					Sort4 << Info[i].rank << "/" << Info[i].title << "/" << Info[i].singer << "/" << Info[i].year << endl;
					Sort4Line = Sort4Line + 1;

				}
				//Sorting된 구조체 배열의 마지막줄을 메모장에 써준다.
				Sort4 << Info[Sort4Line].rank << "/" << Info[Sort4Line].title << "/" << Info[Sort4Line].singer << "/" << Info[Sort4Line].year;

				Sort4.close(); //File Close
			}

		}
		//********************************************Quit**********************************************************//
		if (atoi(input) == 5) {	//Quit
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
//Strtok
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
//Strcmp
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
