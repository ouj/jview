cmake_minimum_required(VERSION 2.8)

# options
option(BUILD_VERBOSE "verbose makefile build" OFF)
option(BUILD_NEWGCC "use a new version of GCC" OFF)

if(BUILD_NEWGCC)
    set(CMAKE_C_COMPILER "gcc-mp-4.6")
    set(CMAKE_CXX_COMPILER "c++-mp-4.6")
endif()

# main project name defined
project(jview)

# osx architectures
if(NOT BUILD_NEWGCC)
    set(CMAKE_OSX_ARCHITECTURES "x86_64")
endif()

# set default build to release
set(CMAKE_BUILD_TYPE Release)

# output directories
if(CMAKE_GENERATOR STREQUAL "Unix Makefiles")
    #set(BIN_DIR_SUFFIX mk)
    set(MAKEFILES ON)
    set(CMAKE_VERBOSE_MAKEFILE ${BUILD_VERBOSE})
elseif(CMAKE_GENERATOR STREQUAL "Xcode")
    #set(BIN_DIR_SUFFIX xcode)
    set(XCODE ON)
elseif(CMAKE_GENERATOR STREQUAL "Visual Studio 10 Win64")
	add_definitions(-D_SCL_SECURE_NO_WARNINGS)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
endif(CMAKE_GENERATOR STREQUAL "Unix Makefiles")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin/${BIN_DIR_SUFFIX})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin/${BIN_DIR_SUFFIX})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin/${BIN_DIR_SUFFIX})


GET_FILENAME_COMPONENT(NEAR_PATH "${PROJECT_SOURCE_DIR}/../near/src" ABSOLUTE)
GET_FILENAME_COMPONENT(COMMON_PATH "${NEAR_PATH}/common" ABSOLUTE)


#include directories
include_directories(${PROJECT_SOURCE_DIR}/src)
include_directories(/homebrew/include)
include_directories(/usr/local/include)
include_directories(${NEAR_PATH})

#library directories
link_directories(/homebrew/lib)
link_directories(/usr/local/lib)

if(APPLE)
    find_library(TBB tbb /homebrew/lib /usr/local/lib)
    find_library(TBB_MALLOC tbbmalloc /homebrew/lib /usr/local/lib)
endif()


if(WIN32)
	GET_FILENAME_COMPONENT(QT_PATH "${PROJECT_SOURCE_DIR}/../Qt.win" ABSOLUTE)
elseif(APPLE)
	GET_FILENAME_COMPONENT(QT_PATH "./" ABSOLUTE)
endif()
include(${QT_PATH}/use_qt.cmake)


if(WIN32)
    GET_FILENAME_COMPONENT(BOOST_PATH ../boost ABSOLUTE)
    include(${BOOST_PATH}/use_boost.cmake)
    GET_FILENAME_COMPONENT(TBB_PATH ../tbb ABSOLUTE)
    include(${TBB_PATH}/use_tbb.cmake)
endif()

if(UNIX AND NOT APPLE)
    GET_FILENAME_COMPONENT(BOOST_PATH ../boost ABSOLUTE)
    include(${BOOST_PATH}/use_boost.cmake)
    GET_FILENAME_COMPONENT(TBB_PATH ../tbb ABSOLUTE)
    include(${TBB_PATH}/use_tbb.cmake)
endif()

# compiler flags
if(MAKEFILES)
    if(NOT BUILD_NEWGCC)
        add_definitions(-O3)
        add_definitions(-mfpmath=sse)
        add_definitions(-funroll-loops)
        add_definitions(-ftree-vectorize)
    
        add_definitions(-funsafe-loop-optimizations)
        add_definitions(-fstrict-aliasing)
        add_definitions(-ffast-math)
    else()
        add_definitions(-Ofast)
    endif()
endif()
if(WIN32)
    add_definitions(-DNOMINMAX)
    add_definitions(-DBOOST_ALL_NO_LIB)
endif()

add_subdirectory(${COMMON_PATH} common)
add_subdirectory(src)

