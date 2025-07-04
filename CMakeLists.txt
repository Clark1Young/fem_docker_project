cmake_minimum_required(VERSION 3.10)
project(MPI_OpenMP_Test)

find_package(MPI REQUIRED)
find_package(OpenMP REQUIRED)

add_executable(main main.cpp)
target_link_libraries(main MPI::MPI_C OpenMP::OpenMP_CXX)
