#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

char** make_arr(int n) {
	char** arr_ptr;
	char str[1024];
	arr_ptr = (char**)malloc(n * sizeof(char));
	for (int i = 0; i < n; i++) {
		cout << "Введите строку номер : " << i << endl;
		cin >> str;
		//		cout << "строка " << str << endl;
		int len = strlen(str);
		arr_ptr[i] = (char*)malloc(len + 1);
		//		arr_ptr[i] = new char[len + 1];
		strcpy(arr_ptr[i], str);
		//		cout << "строка i " << arr_ptr[i] << endl;
	}
	return arr_ptr;
}

void print_arr(char** arr_ptr, int size) {
	for (int i = 0; i < size; i++) {
		if (arr_ptr[i] != NULL) {
			cout << arr_ptr[i] << endl;
		}
	}
}

void arr_modify(char** arr_ptr, int start, int amount, int size) {
	for (int i = 0; i < size; i++) {
		if (i > start && i < (start + amount)) {
			free(arr_ptr[i]);
			arr_ptr[i] = NULL;
		}
	}
}

int main(void) {
	char** arr;
	int arr_size, arr_start, arr_amount;

	cout << "Введите размер массива" << endl;
	cin >> arr_size;
	arr = make_arr(arr_size);
	cout << "Печать созданного массива" << endl;
	print_arr(arr, arr_size);
	cout << "Введите количество удаляемых строк" << endl;
	cin >> arr_amount;
	cout << "С какой строки начать ?" << endl;
	cin >> arr_start;
	arr_modify(arr, arr_start, arr_amount, arr_size);
	arr_size = arr_size - arr_amount;
	cout << "Печать измененного массива" << endl;
	print_arr(arr, arr_size);
	//	arr_del(arr);
}
