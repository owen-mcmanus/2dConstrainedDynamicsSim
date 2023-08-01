#ifndef GAUSIAN
#define GAUSIAN

#include "martrix.h"

class GaussianElimination {
public:
    GaussianElimination();
    static void solve(Matrix* a, Matrix* b, Matrix* x);

    
};

#endif 
