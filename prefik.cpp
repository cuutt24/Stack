//nama:afriza tri rizki
//kelas:informatika-b
//SDA STACK-prefix
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>

using namespace std;

//init
char stack[50], result[50], infix[50];
int pos = 0, len = 0, top = -1, exclude = 0;
//end init

//parse string ke char array
void parseToChar(string target) {
	for (int i = 0; i < target.length(); i++) {
		infix[i] = target[i];
		pos++;
		len++;
	}
}

//reverse char array 
void reverseChar(char chr[]) {
	char temp[50];
	memcpy(temp, chr, len);
	int j = 0;
	for (int i = len -1; i > -1; i--) {
		chr[j] = temp[i];
		j++;
	}
}

//prioritas dari sebuah operator
int precedence(char op) {
	if (op == '^') {
		return 3;
	}
	if (op == '*' || op == '/') {
		return 2;
	}
	if (op == '+' || op == '-') {
		return 1;
	}
	return 0;
}


//print hasil char array result
void print(char out[]) {
	for (int i = 0; out[i] != '\0'; i++) {
		cout << out[i];
	}
}

//add data ke stack dari array infix berdasarkan indexnya
void push(int i) {
	if (top >= 49) {
		return;
	}
	else {
		top++;
		stack[top] = infix[i];
	}
}

//menghapus pada stack (awal)
char pop() {
	if (top < 0) {
		return '\0';
	}
	else {
		char deletedChar = stack[top];
		stack[top] = '\0';
		top--;
		return deletedChar;
	}
}

//konversi infix ke prefix
void convert() {
	int i = 0, j = 0;
	while (i != pos) {
		//jika char nya adalah huruf maka langsung di pindahkan ke char array result
		if ((infix[i] >= 'a' && infix[i] <= 'z' || infix[i] >= 'A' && infix[i] <= 'Z' || infix[i] >= '0' && infix[i] <= '9') && infix[i] != '^') {
			result[j] = infix[i];
			j++;
			i++;
		}
		//jika charnya kurung (bracket) maka di masukkan ke dalam stack
		else if (infix[i] == ')' || infix[i] == '}' || infix[i] == ']'){
			push(i);
			i++;
		}
		else if (infix[i] == '(' || infix[i] == '{' || infix[i] == '[') {
			//jika charnya kurung buka (open bracket) maka semua operator dalam stack 
			//akan di pindahkan ke result sampai ketemu kurung tutup (close bracket)
			// ...
			//memakai kurung buka (open bracket) bukan kurung tutup (close bracket) ? 
			//karena char array yang di konversi adalah 
			//array yang sudah di balik (invers)
			switch (infix[i]) {
				case '(':
					while (stack[top] != ')') {
						result[j] = pop();
						j++;
					}
					pop();
					len -= 2; //mengurangi length(panjang) dikarenakan dalam prefix kurung/bracket "()" tidak dipakai atau dihapus
					i++;
					break;
				case '{':
					while (stack[top] != '}') {
						result[j] = pop();
						j++;
					}
					pop();
					len -= 2;
					i++;
					break;
				case '[':
					while (stack[top] != ']') {
						result[j] = pop();
						j++;
					}
					pop();
					len -= 2;
					i++;
					break;
			}
		}
		else {
			if (top == -1) {
				push(i);
				i++;
			}
			else if (precedence(infix[i]) < precedence(stack[top])) {
				result[j] = pop();
				j++;
				while (precedence(stack[top]) > precedence(infix[i])) {
					result[j] = pop();
					j++;
					if (top != -1) {
						break;
					}
				}
				push(i);
				i++;
			}
			else if (precedence(infix[i]) == precedence(stack[top])) {
				result[j] = pop();
				push(i);
				j++;
				i++;
			}
			else if (precedence(infix[i]) > precedence(stack[top])) {
				push(i);
				i++;
			} 
		}
	}
	//pemindahan jika masih ada operator yang tersisa dalam stack
	while (stack[0] != '\0') {
		result[j] = pop();
	}
}

//pengoprasian matematika berbentuk prefix
int evaluate(char prefix[]) {
	int i = len - 1, local_top = 0, res = '\0', res_array[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };

	while (i > -1) {
		if (prefix[i] >= '0' && prefix[i] <= '9' && !(prefix[i] >= 'a' && prefix[i] <= 'z' || prefix[i] >= 'A' && prefix[i] <= 'Z') && !(prefix[i] == '^')) {
			res_array[local_top] = prefix[i] - '0';
			local_top++;
			i--;
		}
		else if (prefix[i] == '+' || prefix[i] == '-' || prefix[i] == '*' || prefix[i] == '/' || prefix[i] == '^') {
			int x, y;
			switch (prefix[i]) {
			case '+':
				x = res_array[local_top - 1];
				y = res_array[local_top - 2];
				res = x + y;
				res_array[local_top] = 0;
				local_top--;
				res_array[local_top] = 0;
				local_top--;
				res_array[local_top] = res;
				local_top++;
				break;
			case '-':
				x = res_array[local_top - 1];
				y = res_array[local_top - 2];
				res = x - y;
				res_array[local_top] = 0;
				local_top--;
				res_array[local_top] = 0;
				local_top--;
				res_array[local_top] = res;
				local_top++;
				break;
			case '*':
				x = res_array[local_top - 1];
				y = res_array[local_top - 2];
				res = x * y;
				res_array[local_top] = 0;
				local_top--;
				res_array[local_top] = 0;
				local_top--;
				res_array[local_top] = res;
				local_top++;
				break;
			case '/':
				x = res_array[local_top - 1];
				y = res_array[local_top - 2];
				res = x / y;
				res_array[local_top] = 0;
				local_top--;
				res_array[local_top] = 0;
				local_top--;
				res_array[local_top] = res;
				local_top++;
				break;
			case '^':
				x = res_array[local_top - 1];
				y = res_array[local_top - 2];
				res = (int)pow(x, y);
				res_array[local_top] = 0;
				local_top--;
				res_array[local_top] = 0;
				local_top--;
				res_array[local_top] = res;
				local_top++;
				break;
			}
			i--;
		}
	} if (res_array[1] == 0) {
		return res;
	}
	return 0;
}


int main() {
	//string bahan (inputan)
	string target = "(3+5)-1*4^2";

	//parse string inputan ke char
	parseToChar(target);

	//reverse char terlebih dahulu
	reverseChar(infix);

	//konversi infix
	convert();

	//hasilnya di revere kembali menjadi bentuk prefix
	reverseChar(result);

	//print
	print(result);

	//print
	cout << endl << "hasil dari prefix adalah : " << evaluate(result);
}