// DPS_Laba_1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.


#include "ComplexNumber.h"
#include <cmath>
#include "DPS_Laba_1.h"



//#define M_PI ;

constexpr double M_PI = 3.14159265358979323846;
constexpr size_t N = 64;


void FDPFFEven(float* amplitude, ComplexNumber* result);
void FDPFFOdd(float* amplitude, ComplexNumber* result);

void RFDPFFEven(ComplexNumber* amplitude, ComplexNumber* result);
//void RFDPFFEven(float* amplitude, ComplexNumber* result, int cycle_size, int start);
void RFDPFFOdd(ComplexNumber* amplitude, ComplexNumber* result);

//y=sin(2x)+cos(7x) исходная функция
void AmplitudeFunk(float* array_amplitude)
{
    //array_amplitude = new float[64];
    for (int i = 0; i < N; i++) {
        array_amplitude[i] = sin(2 * i/7) + cos(7 * i/7);
    }
}

void DPF(float* array_amplitude, ComplexNumber* result, float* phase, float* amplitude)
{

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; j++) {
            result[i].Sum(result[i], ComplexNumber::Mul(array_amplitude[j], ComplexNumber(cos(2 * M_PI * i * j / N), (-1) * sin(2 * M_PI * i * j / N))  ));
        }
        amplitude[i] = sqrt(result[i].r_part * result[i].r_part + result[i].i_part * result[i].i_part);
        phase[i] = atan(result[i].r_part * result[i].r_part + result[i].i_part * result[i].i_part);
    }
}

void RDPF(ComplexNumber* array_amplitude, ComplexNumber* result, float* amplitude) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; j++)
        {
            result[i].Sum(result[i], ComplexNumber:: Mul(array_amplitude[j], ComplexNumber(cos(2 * M_PI * i * j / 64),  sin(2 * M_PI * i * j / 64)) ));
        }
        amplitude[i] = result[i].r_part / N;
    }
}

void FDPFF(float* array_amplitude, ComplexNumber* result, float* phase, float* amplitude) 
{
    FDPFFEven(array_amplitude, result);
   // RFDPFFEven(array_amplitude, result);
    FDPFFOdd(array_amplitude, result);
    for (int i = 0; i < N; i++) {
        amplitude[i] = sqrt(result[i].r_part * result[i].r_part + result[i].i_part * result[i].i_part);
        phase[i] = atan(result[i].r_part * result[i].r_part + result[i].i_part * result[i].i_part);
    }
}

void FDPFFEven(float* amplitude, ComplexNumber* result)
{   
    for (int i = 0; i < N/2; i++) 
    {
        for (int j = 0; j < N/2; j++) {
            result[2*i].Sum(result[2*i], ComplexNumber::Mul(amplitude[j] + amplitude[j + N/2], ComplexNumber(cos(2 * M_PI * i * j / (N/2)), -sin(2 * M_PI * i * j / (N/2))) ));
        }
    }
}

void FDPFFOdd(float* amplitude, ComplexNumber* result)
{   
    for (int i = 0; i < N/2; i++) 
    {
        for (int j = 0; j < N/2; j++) {
            result[2 * i + 1].Sum(result[2 * i + 1], ComplexNumber::Mul(amplitude[j] - amplitude[j + N / 2], 
                ComplexNumber::Mul(ComplexNumber(cos(2 * M_PI * i * j / (N / 2)), -sin(2 * M_PI * i * j / (N / 2))),
                ComplexNumber(cos(2 * M_PI * j / N), -sin(2 * M_PI * j / N)))));
        }
    }
}


void RFDPFF(ComplexNumber* array_amplitude, ComplexNumber* result, float* amplitude)
{
    RFDPFFEven(array_amplitude, result);
    RFDPFFOdd(array_amplitude, result);
    for (int i = 0; i < N; i++) {
        amplitude[i] = result[i].r_part/(N);
    }

}


void RFDPFFEven(ComplexNumber* amplitude, ComplexNumber* result)
{
    for (int i = 0; i < N / 2; i++)
    {
        for (int j = 0; j < N / 2; j++) {
            result[2 * i].Sum(result[2 * i], ComplexNumber::Mul(amplitude[j] + amplitude[j + N / 2],
                ComplexNumber(cos(2 * M_PI * i * j / (N / 2)), sin(2 * M_PI * i * j / (N / 2)))));
        }
    }
}

//void RFDPFFEven(float* amplitude, ComplexNumber* result, int cycle_size, int start)
//{
//    if (cycle_size / 2 != 1)
//    {
//        RFDPFFEven(amplitude, result, cycle_size / 2, start);
//        RFDPFFEven(amplitude, result, cycle_size / 2, start+cycle_size/2);
//    }
//        
//    for (int i = 0; i <cycle_size/2; i++)
//    {
//        for (int j = 0; j < cycle_size/2; j++) {
//            result[2 * i].Sum(result[2 * i], ComplexNumber::Mul(amplitude[j] + amplitude[j + cycle_size/2], ComplexNumber(cos(2 * M_PI * i * j / (cycle_size/2)), sin(2 * M_PI * i * j / (cycle_size/2)))));
//        }
//    }
//}


void RFDPFFOdd(ComplexNumber* amplitude, ComplexNumber* result)
{
    for (int i = 0; i < N / 2; i++)
    {
        for (int j = 0; j < N / 2; j++) {
            result[2 * i + 1].Sum(result[2 * i + 1], ComplexNumber::Mul(ComplexNumber:: Minus(amplitude[j] , amplitude[j + N / 2]),
                ComplexNumber::Mul(ComplexNumber(cos(2 * M_PI * i * j / (N / 2)), sin(2 * M_PI * i * j / (N / 2))),
                    ComplexNumber(cos(2 * M_PI * j / N), sin(2 * M_PI * j / N)))));
        }
    }
}



int main()
{
    setlocale(LC_ALL, "rus");

    float* array_amplitude = new float[N]; //Вывести

    float* phase1 = new float[N];     //Вывести 
    float* amplitude1 = new float[N]; //Вывести
    
   // float* phase2 = new float[N];
    float* amplitude2 = new float[N];  //Вывести
    
    float* phase3 = new float[N];    //Вывести
    float* amplitude3 = new float[N];  //Вывести
    
   // float* phase4 = new float[N];
    float* amplitude4 = new float[N]; //Вывести 

    AmplitudeFunk(array_amplitude); 

    ComplexNumber* complex_numberDPF = new ComplexNumber[N];
    ComplexNumber* complex_numberRDPF = new ComplexNumber[N];
    ComplexNumber* complex_numberFDPFF = new ComplexNumber[N];
    ComplexNumber* complex_numberRFDPFF = new ComplexNumber[N];

    DPF(array_amplitude, complex_numberDPF,phase1,amplitude1);
    RDPF(complex_numberDPF, complex_numberRDPF, amplitude2);

    FDPFF(array_amplitude, complex_numberFDPFF, phase3, amplitude3);
    RFDPFF(complex_numberFDPFF, complex_numberRFDPFF, amplitude4);

    for (int i = 0; i < N; i++) {
        cout << " Амплитуда ";
        cout << amplitude1[i] << " " << amplitude3[i] <<" "<< array_amplitude[i]<<"  "<<amplitude2[i]<<" " <<amplitude4[i]<<endl;

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
