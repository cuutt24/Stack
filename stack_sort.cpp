//nama:afriza tri rizki
//kelas:informatika-b
//SDA STACK-sort
#include <iostream>


using namespace std;

//inisialisasi
int stack[10], temp[10];
int s_top = -1, t_top = -1;
	

//pengeccheckan jika array stack ada isinya
bool s_empty() {
	if (s_top == -1) {
		return true;
	}
	return false;
}

//pengeccheckan jika array temp ada isinya
bool t_empty() {
	if (t_top == -1) {
		return true;
	}
	return false;
}

//menghapus dan mengembalikan data paling atas dari stack
int s_pop() {
	if (s_empty()) {
		return 0;
	}
	else {
		int del = stack[s_top];
		s_top--;
		return del;
	}
}

//menghapus dan mengembalikan data paling atas dari temp
int t_pop() {
	if (t_empty()) {
		return 0;
	}
	else {
		int del = temp[t_top];
		t_top--;
		return del;
	}
}

//menambahkan data ke array stack secara berurutan
void push(int val) {
	//jika stack kosong maka langsung di masukkan
	if (s_empty()) {
		s_top++;
		stack[s_top] = val;
	}
	else {
		//jika data yang di input lebih besar dari data sebelumnya maka langsung di masukkan kedalam array stack
		if (val > stack[s_top]) {
			s_top++;
			stack[s_top] = val;
		}
		else {
			//jika data lebih kecil maka semua data dari stack yang nilainya lebih besar dari yang diinputkan
			//maka akan data akan dihapus dan dimasukkan ke dalam array temp
			while (!s_empty() && stack[s_top] > val) {
				t_top++;
				temp[t_top] = s_pop();
			}

			//setelah semua data yang lebih besar berada di temp
			//data nilai kecil tsb akan masuk ke stack
			s_top++;
			stack[s_top] = val;

			//setelah data yang paling kecil masuk maka semua data yang ada pada temp akan dikembalikan ke dalam stack
			while (!t_empty()){
				s_top++;
				stack[s_top] = t_pop();

			}
		}
	}
}

void print() {
	int j = 0;
	for (int i = s_top; i != -1; i--) {
		cout << stack[j] << "\t";
		j++;
	}
	cout << endl;
}

int main(){
	push(25);
	print();
	push(15);
	print();
	push(7);
	print();
	push(5);
	print();
}