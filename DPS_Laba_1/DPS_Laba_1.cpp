// DPS_Laba_1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "ComplexNumber.h"

#define _USE_MATH_DEFINES // for C++
#include <cmath>
#include "DPS_Laba_1.h"

//#define M_PI ;

constexpr double M_PI = 3.14159265358979323846;

//y=sin(2x)+cos(7x) исходная функция
void AmplitudeFunk(float* array_amplitude)
{
    //array_amplitude = new float[64];
    for (int i = 0; i < 64; i++) {
        array_amplitude[i] = sin(2 * i) + cos(7 * i);
    }
}

void DPF(float* array_amplitude, ComplexNumber* result, float* phase, float* amplitude) {

    for (int i = 0; i < 64; ++i) {
        for (int j = 0; j < 64; j++) {
            result[i].Sum(result[i], ComplexNumber::Mul(array_amplitude[j], ComplexNumber(cos(2 * M_PI * i * j / 64), sin(2 * M_PI * i * j / 64))  ));
        }
        amplitude[i] = sqrt(result[i].r_part * result[i].r_part + result[i].i_part * result[i].i_part);
        phase[i] = atan(result[i].r_part * result[i].r_part + result[i].i_part * result[i].i_part);
    }
}

void RDPF(ComplexNumber* array_amplitude, ComplexNumber* result, float* amplitude) {
    for (int i = 0; i < 64; ++i) {
        for (int j = 0; j < 64; j++)
        {
            result[i].Sum(result[i], ComplexNumber:: Mul(array_amplitude[j], ComplexNumber(cos(2 * M_PI * i * j / 64), (-1) * sin(2 * M_PI * i * j / 64)) ));
        }
        amplitude[i] = result[i].r_part / 64;
    }
}






int main()
{
    setlocale(LC_ALL, "rus");

    float* array_amplitude = new float[64];
    float* phase = new float[64];
    float* amplitude = new float[64];
    
    

    float* phase1 = new float[64];
    float* amplitude1 = new float[64];
    AmplitudeFunk(array_amplitude);

    ComplexNumber* complex_numberDPF = new ComplexNumber[64];
    ComplexNumber* complex_numberDPF2 = new ComplexNumber[64];

    DPF(array_amplitude, complex_numberDPF,phase,amplitude);
    RDPF(complex_numberDPF, complex_numberDPF2, amplitude1);


    for (int i = 0; i < 64; i++) {

        cout << amplitude[i] << " " << phase[i] << " " << array_amplitude[i] << " " << amplitude1[i]<<" "<< phase1[i]<<endl;
    }
}


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
