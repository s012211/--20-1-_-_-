#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	int MAX=255;
	FILE *in,*out;
	in = fopen("leason9-1.txt","r");
	out = fopen("leason9-out.txt","rw");
	char buf[MAX];

	int word_num = 0;
	int mark = 0;

	while (fgets (buf, MAX, in)!=NULL){
		int i = 0;
		mark = 0;
		while (buf[i] == ' ' && buf[i] != '\0'){
			i++;
		}
		while (buf[i] != '\0'){
			if(buf[i] != ' ' && mark == 0){
				mark = 1;
				word_num ++;
			}
			else if (buf[i] == ' '){
				mark = 0;
			}
		i++;
		}
		if (word_num > 2){
			fputs(buf,out);
		}
		word_num=0;
	}
	int anum = 0;
	int latest_cool_word_anum = 0;
	int latest_cool_word = 0;
	word_num=0;
	while (fgets (buf, MAX, out)!=NULL){
		int i = 0;
		mark = 0;
		while (buf[i] == ' ' && buf[i] != '\0'){
			i++;
		}
		while (buf[i] != '\0'){
			if(buf[i] != ' ' && mark == 0){
				if (anum != 0 && latest_cool_word_anum < anum){
					latest_cool_word_anum = anum;
					latest_cool_word = word_num;
				}
				anum = 0;
				mark = 1;
				word_num ++;
			}
			else if (buf[i] == ' '){
				mark = 0;
			}

			if(buf[i] != ' ' && mark == 1){
				if (buf[i] == 'a' || buf[i] == 'A') anum ++;
				else if (buf[i] == 'e' || buf[i] == 'E') anum ++;
				else if (buf[i] == 'i' || buf[i] == 'I') anum ++;
				else if (buf[i] == 'o' || buf[i] == 'O') anum ++;
				else if (buf[i] == 'u' || buf[i] == 'U') anum ++;
				else if (buf[i] == 'y' || buf[i] == 'Y') anum ++;
			}
		i++;
		}
	}
	cout << "больше всего гласных в слове номер " << latest_cool_word << " " << "количество гласных " << latest_cool_word_anum << endl;
}
