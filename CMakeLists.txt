project(nonosolver)

set(CMAKE_C_FLAGS "-std=c11")
set(CMAKE_CXX_FLAGS "-std=c++11")

set(SOURCES solver.cpp raster.cpp nonogram.cpp nonofile.cpp main.cpp)

add_executable(nonosolver ${SOURCES})
