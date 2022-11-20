cmake_minimum_required(VERSION 3.13)

enable_testing()

add_executable(unitTests src/sample_test.cpp)
target_link_libraries(unitTests gtest Ratio)
target_compile_features(unitTests PRIVATE cxx_std_14)

add_test(NAME unitTests
    COMMAND unitTests)



