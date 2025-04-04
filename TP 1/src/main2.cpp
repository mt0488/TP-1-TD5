#include "Graph.h"
#include "KP01withCGInstance.h"
#include "Solution.h"
#include "BruteForceKP01wCG.h"
#include "BacktrackingKP01wCG.h"
#include "DynamicProgrammingKP01.h"
using namespace std;

int main(){
    KP01withCGInstance a(20,100);

    for(int i=0;i<a.getNumItems();i++){
        a.setWeight(i,i+5);
        a.setProfit(i,i+10);
    }
    
    DynamicProgrammingKP01 f;

    Solution b=f.solve(a);

    b.printSolution();
    return 0;
}