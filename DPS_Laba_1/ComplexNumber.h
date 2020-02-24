#pragma once
#include <iostream>



using namespace std;


class ComplexNumber
{
public:
	float i_part;
	float r_part;



	ComplexNumber() {
		i_part = 0; r_part = 0;
	}

	ComplexNumber(float r_part, float i_part) {
		this->i_part = i_part;
		this->r_part = r_part;
	}

	ComplexNumber(const ComplexNumber& object) {
		this->i_part = object.i_part;
		this->r_part = object.r_part;
	}

	ComplexNumber& operator=(const ComplexNumber& copy) {
		this->i_part = copy.i_part;
		this->r_part - copy.r_part;
		return *this;
	}
	



	friend void operator<<(ostream& object, ComplexNumber complex_number) {
		cout << "Дейсвительная часть: ";
		object << complex_number.r_part << endl;
		cout << "Мнимая часть: ";
		object << complex_number.i_part << endl;
	}

	void Printf();

	void Sum(ComplexNumber a, ComplexNumber b);

	friend ComplexNumber operator+(const ComplexNumber& a, const ComplexNumber& b) {
		return ComplexNumber(a.r_part + b.r_part, a.i_part + b.i_part);
	}

	static ComplexNumber Mul(const ComplexNumber& complex_number1, const ComplexNumber& complex_number2);
	static ComplexNumber Mul(const float complex_number1, const ComplexNumber& complex_number2);

};


