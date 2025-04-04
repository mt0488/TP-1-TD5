#include "Graph.h"

Graph::Graph(){}

Graph::Graph(int n){
    for(int i=0;i<n;i++){
        nodos_.insert(i);
        vecinos_[i]={};
        cant_vecinos_[i]=0; //Por default ningun nodo tiene vecinos
        cant_nodos++; //Actualizar la cantidad de nodos
    }
    aristas_={}; //No hay aristas al iniciar
}

void Graph::addNode(int n){ //Añadir un nodo al gradfo
    nodos_.insert(n);
    vecinos_[n]={};
    cant_vecinos_[n]=0;
    cant_nodos++;
}

void Graph::addEdge(int n1, int n2){
    if(nodos_.find(n1)==nodos_.end() || nodos_.find(n2)==nodos_.end()){ //Se verifica que los nodos que quieren conectarse estén en el grafo
        cout<<"La arista no es posible"<<endl;
        return;
    }

    if(n1<n2){ //Asumimos que cuando se pasan los índices, no están en orden necesariamente
        aristas_.insert({n1,n2});
    }else{
        aristas_.insert({n2,n1});
    }
    vecinos_[n1].insert(n2); cant_vecinos_[n1]++; //Actualizamos los vecinos
    vecinos_[n2].insert(n1); cant_vecinos_[n2]++;
}

void Graph::delEdge(int n1,int n2){
    if(n1<n2){
        if(aristas_.find({n1,n2})==aristas_.end()){ //Verificar que la arista exista
            cout<<"La arista no existe"<<endl;
            return;
        }
        aristas_.erase({n1,n2}); //Si no existe no arroja error, solo devuelve 0
        cant_vecinos_[n1]--;cant_vecinos_[n2]--;
    }else{
        if(aristas_.find({n2,n1})==aristas_.end()){
            cout<<"La arista no existe"<<endl;
            return;
        }
        aristas_.erase({n2,n1}); 
        cant_vecinos_[n1]--;cant_vecinos_[n2]--;
    }
     //Actualizamos los vecinos
    vecinos_[n1].erase(n2);vecinos_[n2].erase(n1);
}


void Graph::delNode(int n){
    nodos_.erase(n);
    cant_vecinos_.erase(n);
    vecinos_.erase(n);
    cant_nodos--;
    set<pair<int,int>>::iterator it=aristas_.begin();
    while(it!=aristas_.end()){ //Borramos las aristas que incluyen al nodo a borrar
        if((*it).first==n||(*it).second==n){
            it=aristas_.erase(it);
        }else{
            it++;
        }
    }

    map<int,set<int>>::iterator i=vecinos_.begin(); //Borramos a N de los conjuntos que lo tengan como vecino
    while(i !=vecinos_.end()){
        ((*i).second).erase(n);
        cant_vecinos_[(*i).first]--;
        i++;
    }


}

set<int> Graph::getNeighbors(int n){ //Devuelve los vecinos de n
    return vecinos_[n];
}

set<pair<int,int>> Graph::edges(){ //Devuelve las aristas
    return aristas_;
}

int Graph::qNeighbors(int n){ 
    if(cant_vecinos_.count(n)){ //Verificar que exista el nodo
        cout<<"El nodo no existe"<<endl;
    }
    return cant_vecinos_[n];
}

bool Graph::conflicto(int n1,int n2){ //Verificar si dos nodos son vecinos
    if(aristas_.count({n1,n2})||aristas_.count({n2,n1})){ //Ver que la arista existe
        return true;
    }else{
        return false;
    }
}

set<int> Graph::nodes(){
    return nodos_;
}

int Graph::qNodes(){
    return cant_nodos;
}