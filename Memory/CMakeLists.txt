cmake_minimum_required(VERSION 3.6)
project(ResourceMonitor)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(MONITOR_MEMORY_SRC_PATH impl)
set(MONITOR_MEMORY_HEADER_PATH
        impl/include
        interface)
set(SOURCE_FILES
        ${MONITOR_MEMORY_SRC_PATH}/PhysicalMemory.cpp
        ${MONITOR_MEMORY_SRC_PATH}/VirtualMemory.cpp)

include_directories(${MONITOR_MEMORY_HEADER_PATH})
add_library(ResourceMonitorMemory STATIC ${SOURCE_FILES})