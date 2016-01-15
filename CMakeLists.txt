project(nonosolver)

set(CMAKE_C_FLAGS "-std=c11")
set(CMAKE_CXX_FLAGS "-std=c++11 -fno-exceptions")

set(SOURCES
    display.h
    display.cpp
    solver.h
    solver.cpp
    raster.h
    raster.cpp
    nonogram.h
    nonogram.cpp
    nonofile.h
    nonofile.cpp
    main.cpp
)

add_executable(nonosolver ${SOURCES})


