cmake_minimum_required(VERSION 3.7)


project(PA01)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})

file(GLOB MY_SRC 
    "*.h"
    "*.cpp"
)

add_executable(PA01 ${MY_SRC})
target_link_libraries(PA01 ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})
