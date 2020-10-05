#include <iostream>
#include <fstream>

using namespace std;


char* my_cpy(char *str2, char *str1); //strcpy
char* my_tok(char *str1, char *par); //strtok
int my_strcmp(char str1[], char str2[]); //strcmp


typedef struct Music {	//������ ������ ������ �ٴ� ����ü ����
	int rank;
	char title[50];
	char singer[50];
	int year;
}Music;

int main() {
	Music Info[100];	//Music����ü�� ��� �ִ� �迭
	char data[100]; //�޸��� �ҷ��� �� ���� �迭
	char *token; //���ڿ� "/"�������� ¥�� �� ���� ����
	char str[100] = { 0, }; // rank, Singer, Title, Year �Է¹��� ����
	int count = 0; // Info ����ü�� ���Խ� ������ ���ִ� ����
	char input[100]; // ��� �������� �����ϴ� ����
	int equal = 0; //update���� rank�� ã�� �� ���� ����

	ifstream read("MusicList.txt");	//File Open

	if (read.fail()) {	//File Open Exeption handling
		cout << "���� �ҷ����⿡ �����߽��ϴ�." << endl;
	}

	while (!read.eof()) {	//������ �ҷ����⿡ �����ߴٸ� �����ϴ� While��
							//getline���� ���پ� �޸����� ���پ� �ҷ��� Music����ü �迭�� �־��ش�.
		read.getline(data, 100);
		token = my_tok(data, "/");
		Info[count].rank = atoi(token);

		token = my_tok(NULL, "/");
		my_cpy(Info[count].title, token);
		token = my_tok(NULL, "/");
		my_cpy(Info[count].singer, token);

		token = my_tok(NULL, "/");
		Info[count].year = atoi(token);

		count = count + 1;	//������ �ҷ��� Music����ü �迭�� ���� ��� ī��Ʈ�� ������Ų��.
	}

	read.close();	//������ �ݴ´�.

	while (1) {
		cout << "1.Insert\t 2.Update\t 3.Delete\t 4.Sort\t 5.Quit" << endl;
		cout << "Input number: ";
		cin >> input;

		while (true) {	//Input number Exeption handling
			if (atoi(input) == 0) {
				cout << "Input number�� ���ڷ� �Է��� �ּ���." << endl << "Input number: ";
				cin >> input;
			}
			else break;
		}
		//********************************************Insert********************************************************//
		if (atoi(input) == 1) {	

			int InsertOverlap = 0; //�̹� �޸��忡 �����ϴ� Rank�� �ִ��� Ȯ���ϱ� ���� ����ϴ� ����

			ofstream InsertWrite;	//������ ��������� Open
			InsertWrite.open("MusicList.txt", ios::app); //����� ������ Open�� �� ���������͸� ���� ��ġ�ϸ鼭 Open�Ѵ�.

			if (InsertWrite.fail()) {	//File open exeption handling
				cout << "������ �ҷ� �� �� �����ϴ�." << endl;
			}

			cout << endl;
			cout << "** Insert **" << endl;
			cout << ">Rank: ";
			cin >> str;

			while (true) {	//Rank�� ���ڸ� �Է����� ��� ����ó�� �ϴ� �κ�

				if (atoi(str) == 0) {
					cout << "Rank���� ���ڸ� �Է��� �ּ���." << endl << ">Rank: ";
					cin >> str;
				}
				else break;
			}

			while (true) {	//���� Rank�� �Է����� ��� ����ó�� �ϴ� �κ�

				InsertOverlap = 0;

				for (int i = 0; i < count - 1; i++) {
					if (Info[i].rank == atoi(str)) {
						InsertOverlap = InsertOverlap + 1;
					}
				}

				if (InsertOverlap == 1) {
					cout << "�̹� �Է��� Rank�Դϴ�. �ٽ� �Է��� �ּ���." << endl << ">Rank: ";
					cin >> str;
				}

				else break;
			}
			//���� �߰��� ������ Rank, Title, Singer, Year�� �����ϴ� �κ�
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
			while (true) {	//Year�� ���ڿ��� ������ ��� ����ó�� �ϴ� �κ�
				if (atoi(str) == 0) {
					cout << "Year���� ���ڸ� �Է��� �ּ���." << endl << ">Year: ";
					cin >> str;
				}
				else break;
			}
			Info[count].year = atoi(str);

			cout << endl;
			//������ �Է��ߴ� Insert�� ���� �޸��忡 ���ش�.
			InsertWrite << endl << Info[count].rank << "/" << Info[count].title << "/" << Info[count].singer << "/" << Info[count].year;
			count = count + 1;	//Insert�� �Ǿ����� Count�� 1 ����
			InsertWrite.close();	//����� ������ �ݴ´�.
		}
		//********************************************Update********************************************************//
		if (atoi(input) == 2) {

			int UpdateLine = 0; // Update�κп� ��� �ϴ� ����
			int UpdateOverlap = 0;	//Rank���� �ߺ������ ã�� ���� ����
			int OverlapLine = 0;	//������Ʈ�� �� �κ����� ����ϴ� ����

			ifstream UpdateRead;	//�б�����Ϸ� File Open
			UpdateRead.open("MusicList.txt"); 

			if (UpdateRead.fail()) {	//File Open Exeption handling
				cout << "������ �ҷ��� �� �����ϴ�." << endl;
			}

			cout << endl << "**Update**" << endl;
			cout << "Input rank: ";
			cin >> str;

			while (true) {	//Rank�� ���ڿ��� �Է����� ��� ����ó�� �ϴ� �κ�

				if (atoi(str) == 0) {
					cout << "Rank�� ���ڷ� �Է����ּ���. " << endl << "Input rank: ";
					cin >> str;
				}
				else break;
			}

			cout << endl;

			for (UpdateLine = 0; UpdateLine < count; UpdateLine++) {	//���� �޸��忡 ���� �Է��� Rank�� �ִ��� Search�ϱ� ���� for��
				if (Info[UpdateLine].rank == atoi(str)) {
					equal = equal + 1;	//�Է��� Rank�� ���� �޸��忡 �����Ѵٸ� equal = equal + 1
					break;
				}
				OverlapLine = OverlapLine + 1;
			}

			UpdateRead.close(); //�б�� ������ �ݴ´�.

			if (equal == 0) {	//�ٲٷ��� ������ Rank�� ���� �ʴٸ� ����

				cout << "Ther is not the music which the rank is " << atoi(str) << "in the music list!" << endl;

			}

			else {	//�ٲٷ��� ������ Rank�� �ִٸ� ����

				cout << ">Rank: ";
				cin >> str;

				while (true) {	//Rank�� ���ڿ��� �Է����� ��� ����ó��

					if (atoi(str) == 0) {
						cout << "Rank�� ���ڷ� �Է����ּ���. " << endl << "Input rank: ";
						cin >> str;
					}
					else break;
				}

				while (true) {

					UpdateOverlap = 0;	//

					for (int i = 0; i < OverlapLine; i++) {
						if (Info[i].rank == atoi(str)) {	//���� �ٲٷ��� �Է��� Rank�� �̹� �޸��忡 �����Ѵٸ�
							UpdateOverlap = UpdateOverlap + 1;	//UpdateOverlap = 1
							break;
						}
					}
					//�ٲٷ��� ������ Rank���� ������ �ʰ� �״�� �Է� �Ҽ����ֱ� ������ Update�ϴ� ������ ������ �����ϰ� for���� ����
					for (int i = OverlapLine + 1; i < count - 1; i++) {
						if (Info[i].rank == atoi(str)) {
							UpdateOverlap = UpdateOverlap + 1;
							break;
						}
					}

					if (UpdateOverlap != 0) {	//�ٲٷ��� �ϴ� Rank���� �̹� �޸��忡 �����ϴ� ��� ����
						cout << "List�� �����Ϸ��� Rank�� �̹� �����մϴ�. �ٸ� Rank�� �Է��� �ּ���." << endl << ">Rank: ";
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
				//�ٲ� ������ ( Rank, Title, Singer, Year )�� �Է�
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
				while (true) {	//Year�� ���ڿ��� �Է��� ��� ����ó��
					if (atoi(str) == 0) {
						cout << "Year���� ���ڸ� �Է��� �ּ���." << endl << ">Year: ";
						cin >> str;
					}
					else break;
				}
				Info[UpdateLine].year = atoi(str);

				ofstream update;
				update.open("MusicList.txt", ios::trunc);	//�̸��� ���� ������ �޸����� ������ ������� File�� Open�Ѵ�.

				for (UpdateLine = 0; UpdateLine < count - 1; UpdateLine++) { //���� ����ü �迭�� ����ִ� �������� �������� ������ ����� ���Ͽ� ���ش�.
					update << Info[UpdateLine].rank << "/" << Info[UpdateLine].title << "/" << Info[UpdateLine].singer << "/" << Info[UpdateLine].year << endl;
				}
				//���������� \n�� ���� �ȵǹǷ� ���� ���� ����� ���Ͽ� ���ش�.
				update << Info[UpdateLine].rank << "/" << Info[UpdateLine].title << "/" << Info[UpdateLine].singer << "/" << Info[UpdateLine].year;

				update.close();	//����� ������ Close
			}
		}
		//********************************************Delete********************************************************//
		if (atoi(input) == 3) {

			int DeleteLine = 0;
			int DeleteOverlap = 0;
			int Line = 0;

			ifstream DeleteRead;
			DeleteRead.open("MusicList.txt");	//�б�� ���Ϸ� MusicList�� �����ش�.

			if (DeleteRead.fail()) {	//File Open exeption handling
				cout << "������ �ҷ� �� �� �����ϴ�." << endl;
			}

			cout << endl << "** Delete **" << endl;
			cout << ">Input rank: ";
			cin >> str;

			while (true) {	//Rank�� ���ڿ��� �Է����� ��� ����ó��
				if (atoi(str) == 0) {
					cout << "Rank���� ���ڸ� �Է��� �ּ���." << endl << ">Input rank: ";
					cin >> str;
				}
				else break;
			}

			for (int i = 0; i < count; i++) {	//�����Ϸ��� Rank�� �޸��忡 �ִ��� Ȯ���ϴ� for��
				if (Info[i].rank == atoi(str)) {
					DeleteLine = i;	//�����Ϸ��� Line�� �޸��忡 �̴ٸ� Overlap = 1
					DeleteOverlap = DeleteOverlap + 1;
					break;
				}
			}

			DeleteRead.close();	//�б�� ������ Close

			if (DeleteOverlap == 0) {	//�����Ϸ��� ������ Rank�� �޸��忡 ���ٸ� ����
				cout << "Ther is not the music which the rank is " << atoi(str) << "in the music list!" << endl;
			}

			else {	//�����Ϸ��� ������ rANK�� �޸��忡 �ִٸ� ����

				ofstream DeleteWrite;
				DeleteWrite.open("MusicList.txt", ios::trunc);	//MusicList������ ����� ���Ϸ� ����·� �����ش�.

				for (int i = DeleteLine + 1; i < count; i++) { //�����Ϸ��� Line�� ���� ���� ���� �迭�� ������ �ű��.
					Info[i - 1].rank = Info[i].rank;
					my_cpy(Info[i - 1].title, Info[i].title);
					my_cpy(Info[i - 1].singer, Info[i].singer);
					Info[i - 1].year = Info[i].year;
				}

				count = count - 1;	//Delete�Ǿ��� ������ ��ü���� Count�� 1�� ����

				for (int i = 0; i < count - 1; i++) {	//Music ����ü �迭�� ����ִ� ������ ������ ���Ͽ� ����.
					DeleteWrite << Info[i].rank << "/" << Info[i].title << "/" << Info[i].singer << "/" << Info[i].year << endl;
					Line = Line + 1;
				}	//Music ����ü �迭�� ����ִ� �������� \n�� �����ؼ� ���Ͽ� ����.
				DeleteWrite << Info[Line].rank << "/" << Info[Line].title << "/" << Info[Line].singer << "/" << Info[Line].year;
			}
		}
		//********************************************Sort**********************************************************//
		if (atoi(input) == 4) {

			cout << endl << "** Sort **" << endl;
			cout << "1.Sort by the rank    2.Sort by the title    3. Sort by the singer    4. Sort by the release year" << endl;
			cout << ">Input number: ";
			cin >> str;

			while (true) {	//Input number�� ���ڿ��� �Է��� ��� ����ó��

				if (atoi(str) == 0) {
					cout << "Input number���� ���ڸ� �Է��� �ּ���." << endl << ">Input number: ";
					cin >> str;
				}
				else break;
			}

			if (atoi(str) == 1) {	//Sort by the rank

				Music temp;
				int Sort1Line = 0;

				for (int i = 0; i < count; i++) {	//rank�� ���ϸ鼭 ������������ �����Ѵ�, �� �� Music ����ü �迭�� ����
					for (int j = i + 1; j < count; j++) {
						if (Info[j].rank < Info[i].rank)
						{
							temp = Info[i];
							Info[i] = Info[j];
							Info[j] = temp;
						}
					}
				}

				ofstream Sort1;	//�޸����� ������ ��� ������ ���·� ����� ���Ϸ� Open�Ѵ�.
				Sort1.open("MusicList.txt", ios::trunc);

				for (int i = 0; i < count - 1; i++) {	//�ٲ� �������� �޸��忡 �Է½� ������ ������ �޸��忡 ���ش�.

					Sort1 << Info[i].rank << "/" << Info[i].title << "/" << Info[i].singer << "/" << Info[i].year << endl;
					Sort1Line = Sort1Line + 1;

				}
				//�ٲ� ������ ���������� �޸��忡 ���ش�. ( \n ���� �ϱ� ���ؼ� )
				Sort1 << Info[Sort1Line].rank << "/" << Info[Sort1Line].title << "/" << Info[Sort1Line].singer << "/" << Info[Sort1Line].year;

				Sort1.close();	//���� Close
			}

			else if (atoi(str) == 2) { //sort by the title

				Music temp; //Music ����ü �迭�� Sorting �� Swap�� �� ����ϴ� ����ü �迭
				int Sort2Line = 0;

				for (int i = 0; i < count; i++) {	//title�� String Compare�� ����ؼ� ������������ Music ����ü �迭�� Sorting
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
				Sort2.open("MusicList.txt", ios::trunc);	//�޸����� ������ ��� �����ϰ� ����� ���Ϸ� Open

				for (int i = 0; i < count - 1; i++) {	//Sorting�� ����ü �迭 �������� �������� �޸��忡 ����.

					Sort2 << Info[i].rank << "/" << Info[i].title << "/" << Info[i].singer << "/" << Info[i].year << endl;
					Sort2Line = Sort2Line + 1;

				}
				//Sorting�� ����ü �迭 ���������� �޸��忡 ���� ( \n ������ )
				Sort2 << Info[Sort2Line].rank << "/" << Info[Sort2Line].title << "/" << Info[Sort2Line].singer << "/" << Info[Sort2Line].year;

				Sort2.close(); // �޸��� Close
			}

			else if (atoi(str) == 3) { //sort by the singer

				Music temp;	//Sorting �� Swapó���� �� ����ϴ� Music ����ü �迭
				int Sort3Line = 0;

				for (int i = 0; i < count; i++) { //Singer�� ���� ��� Rank�� ���� Sort�ǹǷ� Rank�� ���ؼ� ���� Sorting�Ѵ�.
					for (int j = i + 1; j < count; j++) {
						if (Info[j].rank < Info[i].rank)
						{
							temp = Info[i];
							Info[i] = Info[j];
							Info[j] = temp;
						}
					}
				}

				for (int i = 0; i < count; i++) {	//Singer�� ���ؼ� �������� Sorting
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
				Sort3.open("MusicList.txt", ios::trunc);	//�޸����� ������ ��� ����� ����� ���Ϸ� Open

				for (int i = 0; i < count - 1; i++) {	//Sorting�� ����ü �迭�� �������� ������ �޸��忡 ���ش�.

					Sort3 << Info[i].rank << "/" << Info[i].title << "/" << Info[i].singer << "/" << Info[i].year << endl;
					Sort3Line = Sort3Line + 1;

				}
				//Sorting�� ����ü �迭 ���������� �޸��忡 ���ش� ( \n ������ )
				Sort3 << Info[Sort3Line].rank << "/" << Info[Sort3Line].title << "/" << Info[Sort3Line].singer << "/" << Info[Sort3Line].year;

				Sort3.close();	//File Close
			}

			else {	//Sort by the release year

				Music temp;	//Sorting �� Swapó�� �� ����ϴ� ����ü �迭
				int Sort4Line = 0;

				for (int i = 0; i < count; i++) {	//Release Year�� ������� Rank�� ���� Sorting�ǹǷ� Rank�� ���ؼ� Sorting�� ���� ����
					for (int j = i + 1; j < count - 1; j++) {
						if (Info[j].rank < Info[i].rank)
						{
							temp = Info[i];
							Info[i] = Info[j];
							Info[j] = temp;
						}
					}
				}

				for (int i = 0; i < count; i++) {	//Release Year�� ���ؼ� Sorting ��������
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
				Sort4.open("MusicList.txt", ios::trunc); //�޸����� ������ ��� �����ϰ� ����� ���Ϸ� Open

				for (int i = 0; i < count - 1; i++) { //Sorting�� ����ü �迭�� �������� ������ �޸��忡 ���ش�.

					Sort4 << Info[i].rank << "/" << Info[i].title << "/" << Info[i].singer << "/" << Info[i].year << endl;
					Sort4Line = Sort4Line + 1;

				}
				//Sorting�� ����ü �迭�� ���������� �޸��忡 ���ش�.
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

	for (int i = 0; str1[i] != 0; i++)	//�����Ϸ��� ���ڿ� ������ for���� ����
	{
		str2[i] = str1[i];	//�����Ϸ��� ���ڿ� Str1�� Str2�� �־��ش�.
		str2[i + 1] = 0;	//���ڿ��� ���� NULL���� ����
	}

	return str2;	//������ ���ڿ��� ����
}
//Strtok
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
//Strcmp
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
