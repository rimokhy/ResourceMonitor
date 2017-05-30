//
// Created by rimokh_y on 27/05/2017.
//

#ifndef RESOURCEMONITOR_CPUINFO_HPP
#define RESOURCEMONITOR_CPUINFO_HPP

#include <string>
#include <windows.h>
#include <pdh.h>
#include <vector>
#include "ICPUInfo.hpp"

class CPUInfo: public ICPUInfo {
private:
    HQUERY           _cpuQuery;
    PDH_HCOUNTER        _cpuTotal;
    SYSTEM_INFO         _sysinfo;
public:
    CPUInfo();
    ~CPUInfo();
    unsigned long       CPUsNumber();
    std::string         CPUArchitecture();
    std::string         CPUType();
    double             CPUUsage();
    double              CPUUsage(int coreId);
    __int64             CPUUsage(std::string const &processName);
    double              CPUMaxSpeed();
    double              CPUCurrentSpeed();
    double              CPUTemperature();
};


#endif //RESOURCEMONITOR_CPUINFO_HPP
