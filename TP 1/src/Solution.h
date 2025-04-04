#ifndef SOLUTION_H
#define SOLUTION_H

#include <vector>
#include <iostream>
using namespace std;

class Solution {
private:
    vector<bool> sol_;
public:
    Solution(int numItems); // Constructor to initialize size
    void addItem(int item);
    void removeItem(int item);
    bool contains(int item) const;
    void printSolution() const;
    vector<bool> solucion();
    // Pueden agregar los metodos que consideren necesarios.
};
    
#endif // SOLUTION_H

