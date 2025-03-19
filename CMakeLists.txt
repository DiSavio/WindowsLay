cmake_minimum_required(VERSION 3.16)
project(StreamDeckApp)

set(CMAKE_CXX_STANDARD 17)

# Set Homebrew-installed Qt6 path
set(CMAKE_PREFIX_PATH "/opt/homebrew/Cellar/qt/6.8.2_1/lib/cmake")

# Find Qt6 components
find_package(Qt6 REQUIRED COMPONENTS Widgets)

# Include directories
include_directories(${CMAKE_SOURCE_DIR}/include)

# List all source files
set(SOURCES
    src/main.cpp
    src/backend.cpp
    src/gui.cpp
)

set(HEADERS
    include/backend.h
    include/gui.h
)

# Add executable
add_executable(streamdeck ${SOURCES} ${HEADERS})

# Link Qt6 libraries
target_link_libraries(streamdeck Qt6::Widgets)
