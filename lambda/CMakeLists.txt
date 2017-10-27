project(Lambda CXX)
cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_FLAGS "-std=c++1z")

add_executable(lambda-test
	main.cpp
  ast.cpp
  substitute.cpp
	)

set(files ast.cpp main.cpp substitute.cpp)

add_custom_target(printout
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
  COMMAND a2ps -Afill -o- ${files} | ps2pdf - ${CMAKE_BINARY_DIR}/printout.pdf)