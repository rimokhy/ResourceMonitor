//
// Created by rimokh_y on 27/05/2017.
//

#include "include/DataOperation.hpp"

__int64 DataOperation::makePourcentage(__int64 reference, __int64 value) {
    return (value * 100) / reference;
}

double DataOperation::bytesToGigabytes(__int64 val) {
    return val / static_cast<double>(1000000000);
}
