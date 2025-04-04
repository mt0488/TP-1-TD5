// BacktrackingKP01.cpp
#include "BacktrackingKP01wCG.h"

BacktrackingKP01wCG::BacktrackingKP01wCG() {}

void BacktrackingKP01wCG::BT(Solution & B,Solution S, KP01withCGInstance  instance ,int k){
    if(k==instance.getNumItems()){
        if(instance.suma_de_pesos(S.solucion())<=instance.getCapacity() && instance.suma_de_beneficios(S.solucion())>instance.suma_de_beneficios(B.solucion()) && instance.no_hay_conflictos(S.solucion())){
            B=S;
        }
    }else{
        if(instance.suma_de_pesos(S.solucion())<=instance.getCapacity() && (instance.suma_de_beneficios(S.solucion())+instance.suma_b_desde_k(k))>instance.suma_de_beneficios(B.solucion())){
            S.addItem(k);
            BT(B,S,instance,k+1);
            S.removeItem(k);
            BT(B,S,instance,k+1);
        }
    }
}


Solution BacktrackingKP01wCG::solve(const KP01withCGInstance& instance) {
    Solution solution(instance.getNumItems());
    Solution bestSolution(instance.getNumItems());
    BT(bestSolution,solution,instance,0);

    return bestSolution;
}