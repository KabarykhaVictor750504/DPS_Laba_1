#include "ComplexNumber.h"

//friend void ComplexNumber:: operator<<(ostream& object) {
//	
//}


void ComplexNumber::Printf() {

	cout << "Дейсвительная часть: ";
	cout << this->r_part << endl;
	cout << "Мнимая часть: ";
	cout << this->i_part << endl;
}

void ComplexNumber::Mul(const ComplexNumber& complex_number1, const ComplexNumber& complex_number2) {
	float new_i_part = complex_number2.i_part * complex_number1.r_part + complex_number1.i_part * complex_number2.r_part;
	float new_r_part = complex_number2.r_part * complex_number1.r_part - complex_number1.i_part * complex_number2.i_part;
	this->i_part = new_i_part;
	this->r_part = new_r_part;
}