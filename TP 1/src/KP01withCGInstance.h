// KP01withCGInstance.h
#ifndef KP01WITHCGINSTANCE_H
#define KP01WITHCGINSTANCE_H

#include "Graph.h"
#include <fstream>
#include<string>

class KP01withCGInstance {
private:
        int num_items_;
        int capacidad_m_;
        vector<int> pesos_;
        vector<int> beneficios_;
        Graph grafo_conflictos_;

    
public:
    KP01withCGInstance();
    KP01withCGInstance(int n, int cap);
    void setWeight(int index, int weight);
    void setProfit(int index, int profit);
    int getWeight(int index) const;
    int getProfit(int index) const;
    int getNumItems() const;
    int getCapacity() const;
    void addConflict(int item1, int item2);
    void removeConflict(int item1, int item2);
    bool conflict(int item1, int item2)  ;
    int suma_de_pesos(vector<bool>S) const;
    int suma_de_beneficios(vector<bool> S) const;
    bool no_hay_conflictos(vector<bool> S) ;
    int suma_b_desde_k(int k);
    void setInstance(string archivo);
    // Agregar los metodos que consideren necesarios, en particular para obtener los conflictos

};

#endif // KP01WITHCGINSTANCE_H