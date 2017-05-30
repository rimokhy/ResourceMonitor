cmake_minimum_required(VERSION 3.6)
project(ResourceMonitor)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

add_subdirectory(common)
add_subdirectory(Memory)
add_subdirectory(CPU)

set(SOURCE_FILES main.cpp)

include_directories(Memory/impl/include
                    Memory/interface
                    CPU/impl/include
                    CPU/interface
                    common/impl/include)
add_executable(ResourceMonitor ${SOURCE_FILES})
target_link_libraries(ResourceMonitor   ResourceMonitorMemory
                                        ResourceMonitorCommon
                                        ResourceMonitorCPU)
