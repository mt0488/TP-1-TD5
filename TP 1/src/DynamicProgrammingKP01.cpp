// DynamicProgrammingKP01.cpp
#include "DynamicProgrammingKP01.h"
#include <vector>
#include <algorithm>

DynamicProgrammingKP01::DynamicProgrammingKP01() {}

Solution DynamicProgrammingKP01::solve(const KP01withCGInstance& instance) {
    int C=instance.getCapacity(); int n=instance.getNumItems();
    Solution b(instance.getNumItems());
    vector<vector<int>> m(n+1,vector<int>(C+1));

    for(int i=0;i<=n;i++){
        m[i][0]=0;
    }
    for(int c=0;c<=C;c++){
        m[0][c]=0;
    }

    for(int k=1;k<=n;k++){
        for(int c=1;c<=C;c++){
            if(instance.getWeight(k-1)>c){
                m[k][c]=m[k-1][c];
            }else{
                m[k][c]=max(m[k-1][c],instance.getProfit(k-1)+m[k-1][c-instance.getWeight(k-1)]);
                if(m[k][c]!=m[k-1][c]){
                }
            }
        }
    }

    

    return b;
}
