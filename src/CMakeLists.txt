cmake_minimum_required(VERSION 3.12)
project(ConcurrencyDemo)

set(CMAKE_CXX_STANDARD 11)

# Adăugați subdirectorul pentru gestionarea firelor de execuție
add_subdirectory(threads)

# Adăugați executabilul
add_executable(ConcurrencyDemo main.cpp)

# Legați biblioteca la executabil
target_link_libraries(ConcurrencyDemo PRIVATE threads)
