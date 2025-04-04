#include "Solution.h"

using namespace std;

Solution::Solution(int numItems) {
    for(int i=0;i<numItems;i++){
        sol_.push_back(false);
    }
}

void Solution::addItem(int item) {
    sol_[item]=true;
}

void Solution::removeItem(int item) {
    sol_[item]=false;
}

bool Solution::contains(int item) const {
    if(item<=0 || item>=sol_.size()){
        return false;
    }
    return sol_[item];
}

void Solution::printSolution() const {
    for(int i=0;i<(sol_).size();i++){
        if(sol_[i]){
           cout<< i <<",";
        }
    }
    cout<<endl;
}

vector<bool> Solution::solucion(){
    return sol_;
}