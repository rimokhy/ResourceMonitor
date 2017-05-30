//
// Created by rimokh_y on 27/05/2017.
//

#ifndef RESOURCEMONITOR_PHYSICALMEMORY_HPP
#define RESOURCEMONITOR_PHYSICALMEMORY_HPP

#include "IMemory.hpp"
#include "windows.h"

class PhysicalMemory: public IMemory {
private:
    MEMORYSTATUSEX  _memInfo;
public:
    PhysicalMemory();
    ~PhysicalMemory();
    __int64 getTotal();
    __int64 getCurrent();
    __int64 getCurrent(std::string const &processName);
};


#endif //RESOURCEMONITOR_PHYSICALMEMORY_HPP
