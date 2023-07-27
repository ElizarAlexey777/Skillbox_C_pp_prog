cmake_minimum_required(VERSION 3.0.0)

add_executable(Operations_Simulator main.cpp ${INCLUDE_PATH}/funcTools.h ${INCLUDE_PATH}/dots.h)

target_include_directories(Operations_Simulator PUBLIC ${INCLUDE_PATH})