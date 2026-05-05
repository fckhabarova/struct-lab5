#include "solver.hpp"

#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

//конструктор
UnitsSolver::UnitsSolver() : n(0), result(0) {}

//конструктор с параметром
UnitsSolver::UnitsSolver(int n) : n(n), result(0) {
    solve();
}

//геттер для результата
int UnitsSolver::getResult() const {
    return result;
}

//метод решения
//BFS
void UnitsSolver::solve() {
    if (n == 0) {
        result = 0;
        return;
    }
    
    if (n == 1) {
        result = 1;
        return;
    }
    
    dist.assign(n + 1, INT_MAX);
    dist[1] = 1;
    
    queue<int> q;
    q.push(1);
    
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        
//перебираем числа, которые уже достигнуты
        for (int y = 1; y <= n; y++) {
            if (dist[y] == INT_MAX) continue; // y еще не достигнуто
            
//сложение
            int sum = x + y;
            if (sum <= n) {
                int newDist = dist[x] + dist[y];
                if (newDist < dist[sum]) {
                    dist[sum] = newDist;
                    q.push(sum);
                }
            }
            
//умножение
            int prod = x * y;
            if (prod <= n) {
                int newDist = dist[x] + dist[y];
                if (newDist < dist[prod]) {
                    dist[prod] = newDist;
                    q.push(prod);
                }
            }
        }
    }
    
    result = dist[n];
}

 //дружественная функция для ввода
istream& operator>>(istream& in, UnitsSolver& solver) {
    in >> solver.n;
    solver.solve();
    return in;
}

//дружественная функция для вывода
ostream& operator<<(ostream& out, const UnitsSolver& solver) {
    out << solver.result;
    return out;
}
