//
// Created by rimokh_y on 27/05/2017.
//

#ifndef RESOURCEMONITOR_DATAOPERATION_HPP
#define RESOURCEMONITOR_DATAOPERATION_HPP

#include <basetsd.h>


class DataOperation {
public:
    static __int64 makePourcentage(__int64 n1, __int64 n2);
    static double bytesToGigabytes(__int64 val);
};


#endif //RESOURCEMONITOR_DATAOPERATION_HPP
