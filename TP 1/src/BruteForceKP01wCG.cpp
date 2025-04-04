// BacktrackingKP01.cpp
#include "BruteForceKP01wCG.h"

BruteForceKP01wCG::BruteForceKP01wCG() {}

void BruteForceKP01wCG::BF(Solution & B,Solution S, KP01withCGInstance  instance ,int k){
    if(k==instance.getNumItems()){
        if(instance.suma_de_pesos(S.solucion())<=instance.getCapacity() && instance.suma_de_beneficios(S.solucion())>instance.suma_de_beneficios(B.solucion()) && instance.no_hay_conflictos(S.solucion())){
            B=S;
        }
    }else{
        S.addItem(k);
        BF(B,S,instance,k+1);
        S.removeItem(k);
        BF(B,S,instance,k+1);
    }
}

Solution BruteForceKP01wCG::solve(const KP01withCGInstance& instance) {
    Solution bestSolution(instance.getNumItems());
    Solution partial(instance.getNumItems());
    BF(bestSolution,partial,instance,0);
    return bestSolution;
}