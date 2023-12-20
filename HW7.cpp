#include <iostream>
#include "myLib.h"
#include <fstream>
/*
1)�������� ������ �� 2� cpp ������ � ������������� (main.cpp, mylib.cpp, mylib.h) �� ������ ������ mylib �������� 3 �������:
��� ������������� ������� (���� float), ������ ��� �� ����� � �������� ���������� ������������� � ������������� ���������.
��������� ��� 3-� ������� �� main ��� ������ � ��������.
2)������� ������������ (����� ��������� define), �����������, ������ �� ���������� �� ����� (��������� � ����������) � �������� �� ���� (������������)
�� ����������� �� ������� ��������� (�������������) � ���������� true ��� false, ������� �� ����� �true� ��� �false�.
3)������� ������ ���� int. ����� ��� ������ �������� ����� ��������� ������������� #define. ��������������� ��� ����� ���� � ����������.
�������� ��� ���� ���� ������� ���������� (�������� ���������). ���������� ������������ ��������� ��� ������������ SwapINT(a, b).
��������� �� �� ����� ����������.
* �������� ��������� ��������� � ���������� ������. �������� ��� ��� ���������� ������������ � ������� ��������� pragma pack. �������� �����������
���������� ����� ����. ��������������� ��. �������� �� �� ����� � �� ������ � ������� sizeof. ��������� ��� ��������� � ��������� ����.
* �������� ������� 1 ������� ���� ��������� �� ������ ������ (������ ������� ����� ����� �� ������).
*/

#define inBounds(numA, numB) if(numA >=0 && numA < numB) std::cout << "True" ;\
else std::cout << "False"

#define SIZE(size) std::cin>>size
#define swapINT(a, b) a = a*b, b = a/b, a = a/b 

struct Employee1
{
    long id;
    int salary;
    char mark;
    short grade;
    char var1;
    friend std::ostream& operator << (std::ostream &s, Employee1 &my)
    {
        return s << "id= " << my.id << " , salary= " << my.salary << ", mark= " << my.mark << ", grade= " << my.grade << ", var= " << my.grade;
    }
};

#pragma pack(push, 1)
struct Employee2
{
    long id;
    int salary;
    char mark;
    short grade;
    char var1;
    friend std::ostream& operator << (std::ostream &s, Employee2 &my)
    {
        return s << "id= " << my.id << " , salary= " << my.salary << ", mark= " << my.mark << ", grade= " << my.grade << ", var= " << my.grade;
    }
};
#pragma pack(pop)



int main()
{
    std::cout << "Enter array size: " << std::endl;
    int size;
    std::cin >> size;
    float* arr = test1::initArr(size);
    test1::printArr(arr, size);
    test1::arrCounter(arr, size);
    int a;
    int b;
    std::cin >> a;
    std::cin >> b;

    inBounds(a, b);
    srand(time(NULL));
    int size{ 0 };
    std::cout << "enter array size: " << std::endl;
    SIZE(size);
    int* arr = new int[size];
    for (size_t i = 0; i < size; i++)
    {
        arr[i] = rand() % 100;

        std::cout << arr[i] << " ";
    }

    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = i; j < size; j++)
        {
            if (arr[i] > arr[j])
            {
                try{
                    swapINT(arr[i], arr[j]);
                }
                catch (std::logic_error e) {
                    std::cerr << e.what();
                }
            }
        }
    }

    std::cout << "------------" << std::endl;

    for (size_t i = 0; i < size; i++)
    {
     std::cout << arr[i] << " ";
    }

    delete[] arr;
    arr = nullptr;

    std::cout << sizeof(Employee1) << "\n" << sizeof(Employee2) << std::endl;

    std::ofstream fout1("struct.txt");
    Employee1* worker1 = new Employee1{ 1, 5000, 'c', 4 , 's'};
    Employee2* worker2 = new Employee2{ 2, 5500, 'a', 5 , 's'};

    
    std::cout << *worker1;
    std::cout << *worker2;
    fout1 << "worker1(" << *worker1 << ")" << sizeof(worker1) << std::endl;
    fout1 << "worker2(" << *worker2 << ")" << sizeof(worker2) << std::endl;
    delete worker1;
    delete worker2;
    worker1 = nullptr;
    worker2 = nullptr;

}

