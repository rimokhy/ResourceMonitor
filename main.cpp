#include <iostream>

#include "IMemory.hpp"
#include "VirtualMemory.hpp"
#include "PhysicalMemory.hpp"
#include "DataOperation.hpp"
#include "ICPUInfo.hpp"
#include "CPUInfo.hpp"

int main() {
    IMemory *physicalMem = new PhysicalMemory();
    IMemory *virtualMem = new VirtualMemory();


    ICPUInfo    *cpuinfo = new CPUInfo();
    while (1) {
        try {
            std::cout << "VIRTUAL MEMORY: " << std::endl
                      << "\tCURR: " << DataOperation::bytesToGigabytes(virtualMem->getCurrent()) << " -> " << DataOperation::makePourcentage(virtualMem->getTotal(), virtualMem->getCurrent()) << "%" << std::endl
                      << "\tTOTAL: " << DataOperation::bytesToGigabytes(virtualMem->getTotal()) << std::endl
                      << "PHYSICAL MEMORY: " << std::endl
                      << "\tCURR: " << DataOperation::bytesToGigabytes(physicalMem->getCurrent()) << " -> "  << DataOperation::makePourcentage(physicalMem->getTotal(), physicalMem->getCurrent()) << "%" <<std::endl
                      << "\tTOTAL: " << DataOperation::bytesToGigabytes(physicalMem->getTotal()) << std::endl;
            std::cout << "CPUINFO: " << std::endl
                      << "\tARCH: " << cpuinfo->CPUArchitecture() << std::endl
                      << "\tPROCESSORS NUMBER: " << cpuinfo->CPUsNumber() << std::endl
                      << "\tCPU Type: " << cpuinfo->CPUType() << std::endl
                      << "\tCPU Usage Total: " << cpuinfo->CPUUsage() << "%" << std::endl
                      << "\tCPU Max Speed: " << cpuinfo->CPUMaxSpeed() << "Ghz" << std::endl
                      << "\tCPU CURR Speed: " << cpuinfo->CPUCurrentSpeed() << "Ghz" << std::endl
                      << "\tCPU CURR Temp: " << cpuinfo->CPUTemperature() << "Ghz" << std::endl;

            std::cout << "--------" << std::endl;

        }
        catch (std::exception &e) {
            std::cerr << e.what() << std::endl;
        }
        Sleep(1000);
    }
    return 0;
}
