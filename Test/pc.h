#ifndef PC_H
#define PC_H

#include "base.h"
#include <complex>

class PC : virtual public Base
{
public:
    std::complex<double> value;
    PC();
};

#endif // PC_H
