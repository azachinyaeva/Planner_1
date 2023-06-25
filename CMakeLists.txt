cmake_minimum_required (VERSION 3.8)

project ("Planner")

add_executable (Planner "Source.cpp")

target_compile_features("Planner" PRIVATE cxx_std_17)
