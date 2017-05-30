//
// Created by rimokh_y on 27/05/2017.
//

#ifndef RESOURCEMONITOR_ICPUINFO_HPP
#define RESOURCEMONITOR_ICPUINFO_HPP

#include <basetsd.h>
#include <string>

class ICPUInfo {
public:
    virtual ~ICPUInfo() {}
    virtual unsigned long       CPUsNumber() = 0;
    virtual std::string         CPUArchitecture() = 0;
    virtual std::string         CPUType() = 0;
    virtual double             CPUUsage() = 0;
    virtual __int64             CPUUsage(std::string const &processName) = 0;
    virtual double              CPUMaxSpeed() = 0;
    virtual double              CPUCurrentSpeed() = 0;
    virtual double              CPUTemperature() = 0;
};


#endif //RESOURCEMONITOR_ICPUINFO_HPP
