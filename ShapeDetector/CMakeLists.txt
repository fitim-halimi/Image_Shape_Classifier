cmake_minimum_required(VERSION 3.5)

project(ShapeDetector)

find_package(OpenCV REQUIRED)

include_directories( 
  ${OpenCV_INCLUDE_DIRS}
)

add_executable( ShapeDetector 
  src/main.cpp
  src/detect_shapes.cpp
)

target_link_libraries( ShapeDetector 
  ${OpenCV_LIBS} 
)