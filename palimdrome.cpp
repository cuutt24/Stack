//nama:afriza tri rizki
//kelas:informatika-b
//SDA SATCK-palimdrome
#include <iostream>
#include <cstring>

using namespace std;

char normal[10], rev[10];
int n_top = -1, r_top = -1;

void n_push(char val) {
	n_top++;
	normal[n_top] = val;
}

void n_pop() {
	n_top--;
}

void r_push(char val) {
	r_top++;
	rev[r_top] = val;
}

void r_pop() {
	r_top--;
}

void parse_to_stack(string s) {
	for (int i = 0; i < (int)s.length(); i++) {
		n_push(s[i]);
	}
}

void reverse_from_stack() {
	for (int i = n_top; i > -1 ; i--) {
		r_push(normal[i]);
	}
}

int main() {
	string target = "katakatak";

	parse_to_stack(target);

	reverse_from_stack();

	if (strcmp(normal, rev) == 0) {
		cout << target << " adalah palindrome" << endl;
	}
	else {
		cout << target << " bukan palindrome" << endl;
	}

}