#include <iostream>
#include "myLib.h"
#include <fstream>
/*
1)Создайте проект из 2х cpp файлов и заголовочного (main.cpp, mylib.cpp, mylib.h) во втором модуле mylib объявить 3 функции:
для инициализации массива (типа float), печати его на экран и подсчета количества отрицательных и положительных элементов.
Вызывайте эти 3-и функции из main для работы с массивом.
2)Описать макрокоманду (через директиву define), проверяющую, входит ли переданное ей число (введенное с клавиатуры) в диапазон от нуля (включительно)
до переданного ей второго аргумента (исключительно) и возвращает true или false, вывести на экран «true» или «false».
3)Задайте массив типа int. Пусть его размер задается через директиву препроцессора #define. Инициализируйте его через ввод с клавиатуры.
Напишите для него свою функцию сортировки (например Пузырьком). Реализуйте перестановку элементов как макрокоманду SwapINT(a, b).
Вызывайте ее из цикла сортировки.
* Объявить структуру Сотрудник с различными полями. Сделайте для нее побайтовое выравнивание с помощью директивы pragma pack. Выделите динамически
переменную этого типа. Инициализируйте ее. Выведите ее на экран и ее размер с помощью sizeof. Сохраните эту структуру в текстовый файл.
* Сделайте задание 1 добавив свой неймспейс во втором модуле (первое задание тогда можно не делать).
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

