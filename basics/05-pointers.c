#include <stdio.h>


/* NOTES (im skipping many implementation things due to prior exp. but here are a few notes for reference)
 * 



void pass_by_value(int a){
	a += 10;
	printf("passed by value. local value: %d\n", a);

}

void pass_by_ref(int *a){
	*a += 10;
	printf("passed by ref.  original change value: %d\n", *a); 
}

int add (int a, int b) {
	printf("add called\n");
	return a+b;
}

int main(){
	int a = 10, b = 20;
	int *a_ptr = &a, *b_ptr = &b;				// a_ptr holds mem location of a
	int **double_a_ptr = &a_ptr;				// holds mem location of a_ptr
	
	printf("passing by value. before value: %d\n", a);
	pass_by_value(a);					// value wont be changed
	printf("passing by value. after value : %d\n\n", a);

	printf("passing by reference. before value: %d\n", a);
	pass_by_ref(&a);					// value would change
	printf("passing by reference. after value : %d\n\n", a);

	int (*add_ptr) (int, int) = &add;			// pointer to func. & not required
	printf("a+b: %d\n", add_ptr(10, 20)); 			// (*add_ptr) (10, 20) also works
}
