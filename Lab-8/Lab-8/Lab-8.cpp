#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE 
#include "windows.h"
#include <locale>
#include <iostream>

using namespace std;

FILE* file;	
int n;		


struct OwnerAvto {
	char lastname[50];			
	char name[50];				
	char patronymic[50];		
	int num_avto;
	int pasport;
	int gai;
};

OwnerAvto create() {
	OwnerAvto el;
	cout << "Фамилия: ";
	cin >> el.lastname;

	cout << "Имя: ";
	cin >> el.name;

	cout << "Отчество: ";
	cin >> el.patronymic;

	cout << "Номер авто: ";
	cin >> el.num_avto;

	cout << "Номер техпаспорта: ";
	cin >> el.pasport;

	cout << "Отделение регистрации ГАИ: ";
	cin >> el.gai;

	return el;
}

void createFile() {
	cout << "*Формирование файла*" << endl;

	file = fopen("OwnerAvto.dat", "wb");

	if (file == NULL) {
		cout << "Ошибка при открытии файла";
		exit(1);
	}

	cout << "Для начала формирования файла введите первый элемент" << endl;
	OwnerAvto el = create();
	fwrite(&el, sizeof(OwnerAvto), 1, file);

	if (ferror(file) != NULL) {
		cout << "Ошибка при записи в файл";
		exit(2);
	}

	n = 1;
	cout << "*Файл сформирован*" << endl;
	fclose(file);
}

void readFile() {
	cout << "--- Содержимое файла ----" <<  endl;
	file = fopen("OwnerAvto.dat", "rb");

	OwnerAvto el;
	int k = 0;
	while (!feof(file) && k < n) {
		fread(&el, sizeof(OwnerAvto), 1, file);
		

		cout << "Фамилия: " << el.lastname << endl;
		cout << "Имя: " << el.name << endl;
		cout << "Отчество: " << el.patronymic << endl;
		cout << "Номер авто: " << el.num_avto << endl;
		cout << "Номер техпаспорта: " << el.pasport << endl;
		cout << "Отделение регистрации ГАИ: " << el.gai << endl;

		cout << "---------" << endl;
		k++;
	}
	fclose(file);
}

void addFile() {
	cout << "*Добавление нового элемента в файл" << endl;
	OwnerAvto new_el;
	new_el = create();

	char after_sur[50];										
	cout << endl << "После элемента с какой фамилией добавить новый элемент?" << endl;
	cin >> after_sur;

	file = fopen("OwnerAvto.dat", "rb");


	FILE* temp;
	temp = fopen("temp.dat", "wb");


	bool isAdded = false;
	OwnerAvto el;
	for (int i = 1; i <= n; i++) {
		fread(&el, sizeof(OwnerAvto), 1, file);


		fwrite(&el, sizeof(OwnerAvto), 1, temp);


		if (!strcmp(el.lastname, after_sur)) {
			fwrite(&new_el, sizeof(OwnerAvto), 1, temp);

			if (ferror(temp) != NULL) {
				exit(2);
			}

			isAdded = true;
		}
	}

	if (isAdded) {
		n++;
		cout << "Элемент добавлен" << endl;
	}
	else cout << endl << "Элемента с выбранной фамилией не найдено" << endl;

	fclose(file);
	fclose(temp);
	remove("OwnerAvto.dat");
	rename("temp.dat", "OwnerAvto.dat");
}

void deleteFile() {
	int num;
	cout << "*Удаление элемента из файла*" << endl;
	cout << "Укажите номер элемента для удаления: ";
	cin >> num;

	file = fopen("OwnerAvto.dat", "rb");

	FILE* temp;
	temp = fopen("temp.dat", "wb");

	OwnerAvto el;
	for (int i = 1; i <= n; i++) {
		fread(&el, sizeof(OwnerAvto), 1, file);

		if (ferror(file) != NULL) {
			exit(4);
		}

		if (i != num) {
			fwrite(&el, sizeof(OwnerAvto), 1, temp);

			if (ferror(temp) != NULL) {
				exit(2);
			}
		}
		else {
			n--;
			break;
		}
	}
	fclose(file);
	fclose(temp);
	remove("OwnerAvto.dat");
	rename("temp.dat", "OwnerAvto.dat");
}

void main() {
	setlocale(LC_ALL, "russian");

	SetConsoleCP(1251);	
	SetConsoleOutputCP(1251);

	createFile();

	int decision = -1;
	while (decision != 0) {
		switch (decision) {
		case 1: readFile(); break;
		case 2: addFile(); break;
		case 3: deleteFile(); break;
		}
		if (n == 0) exit(1);
		cout << endl << "~ Выберите дальнейшее действие: 1 - читать файл, 2 - добавить в файл, 3 - удалить из файла ~" << endl << "~ ";
		cin >> decision;
		cout << endl;
	}

	system("pause");
}