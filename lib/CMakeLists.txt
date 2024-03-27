cmake_minimum_required(VERSION 3.12)

set(PROJECT_LIB MyLib)

set(PUBLIC_INCLUDES
    include/mylib/Application.hpp
)

set(PRIVATE_INCLUDES
    include/mylib/Log.hpp
)

set(PRIVATE_SOURCES
    src/mylib/Application.cpp
)

set(ALL_SOURCES
    ${PUBLIC_INCLUDES}
    ${PRIVATE_INCLUDES}
    ${PRIVATE_SOURCES}
)

add_library(${PROJECT_LIB} STATIC ${ALL_SOURCES})

source_group(TREE ${CMAKE_SOURCE_DIR} FILES
	${ALL_SOURCES}
)

target_include_directories(${PROJECT_LIB} PUBLIC include)
target_include_directories(${PROJECT_LIB} PRIVATE src)

add_subdirectory(../external/spdlog ${CMAKE_CURRENT_BINARY_DIR}/spdlog)
target_link_libraries(${PROJECT_LIB} PRIVATE spdlog)

add_subdirectory(../external/sqlite ${CMAKE_CURRENT_BINARY_DIR}/sqlite)
target_link_libraries(${PROJECT_LIB} PRIVATE sqlite3)

#add_subdirectory(../external/sqlite_orm ${CMAKE_CURRENT_BINARY_DIR}/sqlite_orm)
#target_link_libraries(${PROJECT_LIB} PRIVATE sqlite_orm)

add_subdirectory(../external/fastcgipp ${CMAKE_CURRENT_BINARY_DIR}/fastcgipp)
target_link_libraries(${PROJECT_LIB} PRIVATE fastcgipp)

target_compile_features(${PROJECT_LIB} PUBLIC cxx_std_17)

