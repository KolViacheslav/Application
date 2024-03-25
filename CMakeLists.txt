cmake_minimum_required(VERSION 3.12)

set(PROJECT_NAME Application CXX)
project(${PROJECT_NAME})

add_subdirectory(lib)

add_executable(${PROJECT_NAME} 
	src/main.cpp
)

target_link_libraries(${PROJECT_NAME} MyLib)
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)

set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/)
set_property(DIRECTORY ${CMAKE_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})