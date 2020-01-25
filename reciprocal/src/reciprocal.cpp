/*-----------------------------------------------------------------------------
* File Name: reciprocal.cpp
* Purpose:
* Creation Date: 25-01-2020
* Last Modified: Sat 25 Jan 2020 11:33:57 PM MSK
* Created by: dima
-----------------------------------------------------------------------------*/

#include <cassert>
#include "reciprocal.hpp"

double reciprocal(int i) {

    assert(i != 0);
    return 1.0 / i;
}
