# CMakeLists.txt pentru gestionarea firelor de execuție

# Adăugați sursele pentru firele de execuție
add_library(threads threads.cpp)

# Acesta adaugă directorul curent al subproiectului în loc de directorul principal
target_include_directories(threads PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
