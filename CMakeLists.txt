project(Calculator)

cmake_minimum_required(VERSION 3.5)

list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

# C++14
set(CMAKE_CXX_STANDARD 14)

# set-up ANTLR
add_definitions(-DANTLR4CPP_STATIC)
set(ANTLR_EXECUTABLE ${PROJECT_SOURCE_DIR}/deps/antlr/antlr-4.7.2-complete.jar)
set(ANTLR4_ZIP_REPOSITORY ${PROJECT_SOURCE_DIR}/deps/antlr/antlr4-master.zip)
include(ExternalAntlr4Cpp)
include_directories(${ANTLR4_INCLUDE_DIRS})

# generate ANTLR files
find_package(ANTLR REQUIRED)
antlr_target(
        Calculantlr
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Calculantlr.g4
        PACKAGE calculantlr
        LISTENER
)
include_directories(${ANTLR_Calculantlr_OUTPUT_DIR})


# build calculantlr
file(GLOB CALCULANTLR_SRC "src/*.cpp")
include_directories(${PROJECT_SOURCE_DIR}/cmake-build-debug/antlr4cpp_generated_src/Calculantlr)
include_directories(${PROJECT_SOURCE_DIR}/deps)
add_executable(calculantlr ${CALCULANTLR_SRC}
        ${ANTLR_Calculantlr_CXX_OUTPUTS} src/CalcListener.cpp src/CalcListener.h)
target_link_libraries(calculantlr antlr4_static)

