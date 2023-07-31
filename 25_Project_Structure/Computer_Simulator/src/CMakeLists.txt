cmake_minimum_required(VERSION 3.8)

add_executable (Computer_Simulator_1 
									"main.cpp" 
									"${MY_INCLUDE_DIR}/const.h"
									"cpu.cpp" "${MY_INCLUDE_DIR}/cpu.h"
									"disk.cpp" "${MY_INCLUDE_DIR}/disk.h"
									"gpu.cpp" "${MY_INCLUDE_DIR}/gpu.h"
									"kbd.cpp" "${MY_INCLUDE_DIR}/kbd.h" 
									"ram.cpp" "${MY_INCLUDE_DIR}/ram.h")

target_include_directories(Computer_Simulator_1 PUBLIC ${MY_INCLUDE_DIR})