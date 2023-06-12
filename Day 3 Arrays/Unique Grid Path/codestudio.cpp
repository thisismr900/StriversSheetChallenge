#include <bits/stdc++.h> 
int uniquePaths(int m, int n) {

    //OPTIMAL : using combination
    int steps=(m-1)+(n-1);
    int r=m-1;//no of rights
    double res=1;

    for(int i=1; i<=r; i++)
    {
        // res = res * (steps - r + i) / i;
        res=res* (steps)/i ;
        steps=steps-1;
    }
    
    return (int)res;
  

}