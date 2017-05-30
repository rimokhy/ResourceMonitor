cmake_minimum_required(VERSION 3.6)
project(ResourceMonitor)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(MONITOR_CPU_SRC_PATH impl)
set(MONITOR_CPU_USAGE_SRC_PATH CPUUsage)
set(MONITOR_CPU_HEADER_PATH
        interface
        impl/include)
set(SOURCE_FILES
        ${MONITOR_CPU_SRC_PATH}/CPUInfo.cpp)

include_directories(${MONITOR_CPU_HEADER_PATH})
add_library(ResourceMonitorCPU STATIC ${SOURCE_FILES})
target_link_libraries(ResourceMonitorCPU pdh
        wbemuuid)