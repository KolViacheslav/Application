cmake_minimum_required(VERSION 3.12)

set(PROJECT_LIB MyLib)

set(PUBLIC_INCLUDES
    ./includes/mylib/Application.hpp
)

#set(PRIVATE_INCLUDES
#
#)

set(PRIVATE_SOURCES
    ./src/mylib/Application.cpp
)

set(ALL_SOURCES
    ${PUBLIC_INCLUDES}
#    ${PRIVATE_INCLUDES}
    ${PRIVATE_SOURCES}
)

add_library(${PROJECT_LIB} STATIC ${ALL_SOURCES})

source_group(TREE ${CMAKE_SOURCE_DIR} FILES
	${ALL_SOURCES}
)

target_include_directories(${PROJECT_LIB} PUBLIC include)
target_include_directories(${PROJECT_LIB} PRIVATE src)

target_compile_features(${PROJECT_LIB} PUBLIC cxx_std_17)