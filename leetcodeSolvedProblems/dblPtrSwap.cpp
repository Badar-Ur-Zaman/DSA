#include <iostream>
using namespace std;

void swap(int *x, int *y){
	int temp = *x;
	*x = *y;
	*y = temp;
}
void swap(int **x, int **y){
	int temp = **x;
	**x = **y;
	**y = temp;
}

int main() {
	int a = 5, b = 10;
	int *pa = &a; //pa and pb are pointer variables of type int. 
int *pb = &b;
/*Will take input as address of a and b variable. & sign tell compiler to take address of variable/*
	swap(&a,&b);
	cout << "a = " <<a << "\nb = " << b << endl;
	int **ppa = &pa; //ppa and ppb are called double pointers or pointers-to-pointers.
	int **ppb = &pb;
	swap(ppa,ppb);
	cout << "a = " <<a << "\nb = " << b << endl;
}
