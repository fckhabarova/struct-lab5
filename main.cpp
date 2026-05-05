#include "solver.hpp"

#include <iostream>

using namespace std;

int main() {
    UnitsSolver solver;
    cout << "Введите число n: ";
    cin >> solver;   // Ввод числа n
    cout << "Результат: " << solver << endl;  // Вывод результата
    return 0;
}
