﻿// quick.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

const unsigned n = 17;

void quick(int(&list)[n], int l, int r) {
    if (l >= r)
        return;
    int p = list[r];
    int l_1 = l;
    int r_1 = r;
    l--;
    r++;
    while (l + 1 < r) {
        while (l + 1 < r && list[l + 1] < p) {
            l++;
        }
        while (l < r - 1 && list[r - 1] >= p) {
            r--;
        }
        if (l + 1 != r)
            std::swap(list[l + 1], list[r - 1]);
    }
    std::swap(list[r_1], list[r]);
    quick(list, l_1, l);
    quick(list, r + 1, r_1);
}

int main() {
    int array[] = { 76, 48, 97, 40, 63, 55, 85, 35, 0, 55, 50, 3, 41, 73, 12, 2, 82 };
    for (int i = 0; i < n; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
    quick(array, 0, n - 1);
    for (int i = 0; i < n; ++i) {
        std::cout << array[i] << " ";
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
