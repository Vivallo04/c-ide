cmake_minimum_required(VERSION 3.7)
project(C-IDE)
set(CMAKE_CXX_STANDARD 14)

set(wxWidgets_ROOT_DIR </usr/include/wx-3.0-unofficial>)
set(wxWidgets_CONFIGURATION mswu)
find_package(wxWidgets COMPONENTS core base REQUIRED)
include(${wxWidgets_USE_FILE})


set(SOURCE_FILES src/ide/App.cpp include/App.h src/ide/Frame.cpp include/Frame.h src/ide/console/Console.cpp src/ide/console/Console.h
        src/mserver/mserver.c src/mserver/client.c src/mserver/node.c src/mserver/node.h src/mserver/server.c
        src/ide/ram_live_view/RAMLV.cpp src/ide/ram_live_view/RAMLV.h src/ide/application_log/LoggingFrame.cpp src/ide/application_log/LoggingFrame.h src/ide/code_editor/CodeEditor.cpp src/ide/code_editor/CodeEditor.h src/interpreter/Parser.cpp src/interpreter/Parser.h src/interpreter/Interpreter.cpp src/interpreter/Interpreter.h src/interpreter/error.cpp src/interpreter/error.cpp src/interpreter/error.h src/interpreter/include.cpp src/interpreter/include.h src/interpreter/misc.h src/interpreter/Buffer.cpp src/interpreter/Buffer.h src/interpreter/common.cpp src/interpreter/common.h)

add_executable(C-IDE ${SOURCE_FILES})
target_link_libraries(C-IDE ${wxWidgets_LIBRARIES})