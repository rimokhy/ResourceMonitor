//
// Created by rimokh_y on 27/05/2017.
//

#include "include/PhysicalMemory.hpp"

PhysicalMemory::PhysicalMemory() {
    _memInfo.dwLength = sizeof(MEMORYSTATUSEX);
    GlobalMemoryStatusEx(&_memInfo);
}

PhysicalMemory::~PhysicalMemory() {

}

__int64 PhysicalMemory::getTotal() {
    return _memInfo.ullTotalPhys;
}

__int64  PhysicalMemory::getCurrent() {
    return _memInfo.ullTotalPhys - _memInfo.ullAvailPhys;
}

__int64 PhysicalMemory::getCurrent(std::string const &processName) {
/*
    PROCESS_MEMORY_COUNTERS_EX pmc;
    GetProcessMemoryInfo(GetCurrentProcess(), &pmc, sizeof(pmc));
    SIZE_T virtualMemUsedByMe = pmc.PrivateUsage;
    return std::to_string(virtualMemUsedByMe);
    return "";
*/
    return 0;
} // TODO WHEN PROCESS LIST IS CODED