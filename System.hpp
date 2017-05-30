//
// Created by rimokh_y on 27/05/2017.
//

#ifndef RESOURCEMONITOR_SYSTEM_HPP
#define RESOURCEMONITOR_SYSTEM_HPP


class System {
public:
    std::string const &getTotalVirtualMemory();
    std::string const &getCurrentVirtualMemory();
    std::string const &getCurrentVirtualMemory(std::string const &processName);
    std::string const &getTotalRAM();
    std::string const &getCurrentRAM();
};


#endif //RESOURCEMONITOR_SYSTEM_HPP
