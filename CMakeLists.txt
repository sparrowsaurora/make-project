cmake_minimum_required(VERSION 3.16)
project(make_project C)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Include headers
include_directories(include)

# Find ncurses
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

# Source files
file(GLOB SRC_FILES src/*.c)

add_executable(make_project ${SRC_FILES})

# add include dir
target_include_directories(make_project PRIVATE 
    ${PROJECT_SOURCE_DIR}/include
)

# Link ncurses
target_link_libraries(make_project PRIVATE ${CURSES_LIBRARIES})
