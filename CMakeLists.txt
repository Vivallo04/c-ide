cmake_minimum_required(VERSION 3.7)
project(C-IDE)
set(CMAKE_CXX_STANDARD 11)

set(wxWidgets_ROOT_DIR </usr/include/wx-3.0-unofficial>)
set(wxWidgets_CONFIGURATION mswu)
find_package(wxWidgets COMPONENTS core base REQUIRED)
include(${wxWidgets_USE_FILE})

set(SOURCE_FILES main.cpp src/App.cpp include/App.h include/main.h)
add_executable(C-IDE ${SOURCE_FILES})

target_link_libraries(C-IDE ${wxWidgets_LIBRARIES})