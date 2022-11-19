cmake_minimum_required(VERSION 3.13)

# give a name to the project
project(libRational)

# add ratio lib
message(STATUS "ratio cmake part ..." )
add_subdirectory(ratio INTERFACE)
include_directories(${CMAKE_SOURCE_DIR}/ratio/include) # important : other projects call by this cmake will know this include directory

# add code
message(STATUS "code cmake part ..." )
add_subdirectory(code)

# add google test
message(STATUS "google test cmake part ..." )
add_subdirectory(googletest)

# add myTest
message(STATUS "myUnitTests cmake part ..." )
add_subdirectory(myUnitTests)
