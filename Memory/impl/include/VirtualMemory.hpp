//
// Created by rimokh_y on 27/05/2017.
//

#ifndef RESOURCEMONITOR_VIRTUALMEMORY_HPP
#define RESOURCEMONITOR_VIRTUALMEMORY_HPP

#include "IMemory.hpp"
#include "windows.h"

class VirtualMemory: public IMemory {
private:
    MEMORYSTATUSEX  _memInfo;
public:
    VirtualMemory();
    ~VirtualMemory();
    __int64 getTotal();
    __int64 getCurrent();
    __int64 getCurrent(std::string const &processName);
};


#endif //RESOURCEMONITOR_VIRTUALMEMORY_HPP
