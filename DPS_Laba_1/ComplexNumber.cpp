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

ComplexNumber ComplexNumber::Mul(const ComplexNumber& complex_number1, const ComplexNumber& complex_number2) {
	/*float new_i_part = 
	float new_r_part = *//*
	this->i_part = new_i_part;
	this->r_part = new_r_part;*/
	return ComplexNumber(complex_number2.r_part * complex_number1.r_part - complex_number1.i_part * complex_number2.i_part ,
		complex_number2.i_part * complex_number1.r_part + complex_number1.i_part * complex_number2.r_part);
}

ComplexNumber ComplexNumber::Mul(float complex_number1, const ComplexNumber& complex_number2) {
	/*float new_i_part = 
	float new_r_part = *//*
	this->i_part = new_i_part;
	this->r_part = new_r_part;*/
	return ComplexNumber(complex_number2.r_part * complex_number1,
		complex_number2.i_part * complex_number1);
}

void ComplexNumber:: Sum(ComplexNumber a, ComplexNumber b) {
	this->i_part = a.i_part + b.i_part;
	this->r_part = a.r_part + b.r_part;
}



ComplexNumber* ComplexNumber:: DivArray(ComplexNumber* complex_number_array, int how_many, int from)
{
	ComplexNumber* result = new ComplexNumber[how_many];
	for(int i =from,j=0;i<from+how_many;j++,i++)
	{
		result[j] = complex_number_array[i];
	}
	return result;
}

ComplexNumber* ComplexNumber::ComArray( ComplexNumber* complex_number_array_a,  ComplexNumber* complex_number_array_b, int how_many)
{
	ComplexNumber* result = new ComplexNumber[how_many * 2];
	for(int i=0;i<how_many;i++)
	{
		result[i] = complex_number_array_a[i];
		result[i] = complex_number_array_b[i];
	}
	return result;
}


ComplexNumber ComplexNumber::Minus(ComplexNumber complex_number_array_a, ComplexNumber complex_number_array_b)
{
	return ComplexNumber(complex_number_array_a.r_part-complex_number_array_b.r_part,complex_number_array_a.i_part-complex_number_array_b.i_part);
}