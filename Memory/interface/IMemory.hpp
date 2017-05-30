//
// Created by rimokh_y on 27/05/2017.
//

#ifndef RESOURCEMONITOR_MEMORY_HPP
#define RESOURCEMONITOR_MEMORY_HPP

#include <string>

class IMemory {
public:
    virtual ~IMemory() {}
    virtual __int64 getTotal() = 0;
    virtual __int64 getCurrent() = 0;
    virtual __int64 getCurrent(std::string const &processName) = 0;
};


#endif //RESOURCEMONITOR_MEMORY_HPP
