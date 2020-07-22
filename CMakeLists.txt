project(nonosolver)

set(CMAKE_C_FLAGS "-std=c11 -Wpedantic -Wall -Wno-unused-but-set-variable -Wnarrowing")
set(CMAKE_CXX_FLAGS "-std=c++17 -fno-exceptions -Wpedantic -Wall -Wno-unused-but-set-variable -Wnarrowing")

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


