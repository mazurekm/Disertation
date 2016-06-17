#include <armadillo>
#include <iostream>

using namespace arma;
using namespace std;

int main()
{
    mat A = randn(20, 50);
    mat B = randn(50, 20);
    mat C = A * B;
    
    mat C_p = pinv(C);
    
    mat U,V;
    vec S;
    svd(U, S, V, C_p);
    
    mat D = orth(C);
    cout << D;
    return 0;
}
