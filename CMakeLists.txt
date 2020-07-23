cmake_minimum_required(VERSION 3.14)

project(nonosolver)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_C_FLAGS "")
set(CMAKE_CXX_FLAGS "")

if(${CMAKE_COMPILER_IS_GNUCXX})
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wpedantic -Wno-unused-but-set-variable -Wnarrowing")
    set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_RELEASE} -g -ggdb -O0")
    set(CMAKE_CXX_FLAGS "%{CMAKE_CXX_FLAGS} -fno-exceptions -Wall -Wpedantic -Wno-unused-but-set-variable -Wnarrowing")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_RELEASE} -g -ggdb -O0")
elseif(${MSVC})
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /GS- /FR")
    set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_RELEASE} /ZI /Od")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /GS- /FR")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_RELEASE} /ZI /Od")
endif()
set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -O3")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")


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
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${CMAKE_PROJECT_NAME})
