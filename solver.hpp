#include <vector>
#include <iostream>

class UnitsSolver {
private:
    int n;
    std::vector<int> dist;
    int result;
    
//приватный метод
    void solve();
    
public:

    UnitsSolver();
    UnitsSolver(int n);
    
    int getResult() const;
    
//дружественные функции 
    friend std::istream& operator>>(std::istream& in, UnitsSolver& solver);
    friend std::ostream& operator<<(std::ostream& out, const UnitsSolver& solver);
};


