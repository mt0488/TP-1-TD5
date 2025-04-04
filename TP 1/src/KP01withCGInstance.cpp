#include "KP01withCGInstance.h"

vector<int> split(string s){
    vector<int> res;
    string r;
    for(int i=0;i<s.size();i++){
        if(s[i] != ' '){
            r.push_back(s[i]);
        }else{
            res.push_back(stoi(r));
            r="";
        }
    }
    res.push_back(stoi(r));
    return res;
}

KP01withCGInstance::KP01withCGInstance(){}

KP01withCGInstance::KP01withCGInstance(int n, int cap)
    : grafo_conflictos_(n), num_items_(n), capacidad_m_(cap)
{
    pesos_.resize(n, 0);
    beneficios_.resize(n, 0);
}

void KP01withCGInstance::setWeight(int index, int weight) {
    if (index >= 0 && index < num_items_){
        pesos_[index]= weight;
    }
}



void KP01withCGInstance::setProfit(int index, int profit) {
    if(index >= 0 && index < num_items_){
        beneficios_[index] = profit;
    }
}

int KP01withCGInstance::getWeight(int index) const {
    if (index >=0 && index < num_items_){
        return pesos_[index];
    }
    return -1; //Devolver algo incoherente si el nodo no existe
}

int KP01withCGInstance::getProfit(int index) const {
    if(index >= 0 && index < num_items_){
        return beneficios_[index];
    }
    else{
        return -1; //Devolver algo incoherente si el nodo no existe
    }
}

int KP01withCGInstance::getNumItems() const {
    return num_items_;
}

int KP01withCGInstance::getCapacity() const {
    return capacidad_m_;
}


void KP01withCGInstance::addConflict(int item1, int item2) {
    grafo_conflictos_.addEdge(item1, item2);
}

void KP01withCGInstance::removeConflict(int item1, int item2) {
    grafo_conflictos_.delEdge(item1, item2);
}

int KP01withCGInstance::suma_de_pesos(vector<bool> S) const{
    int res=0;
    for(int i=0;i<num_items_;i++){
        res=res+S[i]*pesos_[i];
    }
    return res;

}

int KP01withCGInstance::suma_de_beneficios(vector<bool> S) const {
    int res = 0;
    for (int i = 0; i < num_items_ && i < S.size(); ++i) {
        res += S[i] * beneficios_[i];
    }
    return res;
}
bool KP01withCGInstance::conflict(int item1,int item2)   {
    return grafo_conflictos_.getNeighbors(item1).count(item2);
}
bool KP01withCGInstance::no_hay_conflictos(vector<bool> S)  {
    for(int i=0;i<num_items_;i++){
        if(S[i]==true){
            for(int j=i+1;j<num_items_;j++){
                if(S[j]==true && conflict(i,j)){
                    return false;
                }
            }
        }
    }
    return true;
}
int KP01withCGInstance::suma_b_desde_k(int k){
    int res=0;
    for(int i=k;i<num_items_;i++){
        res=res+beneficios_[i];
    }
    return res;
}

void KP01withCGInstance::setInstance(string archivo){
    ifstream infile(archivo);
    if(infile.good()==false){
        cout<<"No pudo abrirse el archivo";
        exit(1);
    }
    string linea;
    vector <vector<int>> lineas;
    
    while(!infile.eof()){  
        getline(infile, linea);
        lineas.push_back(split(linea));
    }
    infile.close();
    
    num_items_ = lineas[0][0];
    capacidad_m_ = lineas[1][0];
    
    // Redimensionar vectores según los nuevos valores
    pesos_.resize(num_items_, -1);
    beneficios_.resize(num_items_, -1);
    grafo_conflictos_ = Graph(num_items_);

    for(int i=0;i<lineas[0][0];i++){
        setWeight(i,lineas[2][i]);
        setProfit(i,lineas[3][i]);
    }
    for(int i=5;i<lineas.size();i++){
        addConflict(lineas[i][0],lineas[i][1]);
    }
}