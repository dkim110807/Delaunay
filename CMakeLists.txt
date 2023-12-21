cmake_minimum_required(VERSION 3.26)
project(Delaunay)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES opengl/glad/src/glad.c main.cpp)
set(HEADER_FILES shader/shader.h
        delaunay/delaunay.h)

include_directories(include)

include_directories(opengl/glad/include)
include_directories(opengl/glm/include)

file(COPY assets/resources DESTINATION ${dir}/build)
file(COPY assets/shaders DESTINATION ${dir}/build)

add_subdirectory(opengl/glfw/glfw-3.3.8)

add_executable(Delaunay ${SOURCE_FILES} ${HEADER_FILES})

target_link_libraries(Delaunay glfw opengl32)
