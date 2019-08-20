cmake_minimum_required(VERSION 3.10.2)
project(play)

include_directories(headers)

#set(SOURCES srcs/Objetos.cpp)
 
file(GLOB SOURCES "srcs/*.cpp")
 
add_executable(play ${SOURCES})
SET(CMAKE_CXX_FLAGS "-lglut -lGL -lGLU -lm")
#SET(CMAKE_CXX_FLAGS -lGL)
#SET(CMAKE_CXX_FLAGS -lGLU)
#SET(CMAKE_CXX_FLAGS -lm)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} )

target_link_libraries(play ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} )
