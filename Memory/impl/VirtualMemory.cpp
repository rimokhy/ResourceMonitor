//
// Created by rimokh_y on 27/05/2017.
//

#include "include/VirtualMemory.hpp"
#include <iostream>
VirtualMemory::VirtualMemory() {
    _memInfo.dwLength = sizeof(MEMORYSTATUSEX);
    GlobalMemoryStatusEx(&_memInfo);
}

VirtualMemory::~VirtualMemory() {

}

__int64 VirtualMemory::getTotal() {
    return _memInfo.ullTotalPageFile;
}

__int64 VirtualMemory::getCurrent() {
    return _memInfo.ullTotalPageFile - _memInfo.ullAvailPageFile;
}

__int64 VirtualMemory::getCurrent(std::string const &processName) {
/*
    PROCESS_MEMORY_COUNTERS_EX pmc;
    GetProcessMemoryInfo(GetCurrentProcess(), &pmc, sizeof(pmc));
      SIZE_T physMemUsedByMe = pmc.WorkingSetSize;
    return std::to_string(physMemUsedByMe);
    return "";
*/
    return 0;
} // TODO WHEN PROCESS LIST IS CODED