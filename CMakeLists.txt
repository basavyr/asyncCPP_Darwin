cmake_minimum_required(VERSION 3.0)

set(project_name "FUTURE-ASYNC-(arch)DARWIN")

project(${project_name})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

add_library(future SHARED src/futures.cc)
add_library(threads SHARED src/threads.cc)
# add_library(main SHARED src/main.cc)
# target_link_libraries(future LINK_PUBLIC main)
# add_executable(futures src/futures.cc src/main.cc)
add_executable(thread src/threads.cc src/futures.cc src/main.cc)

target_include_directories(future PUBLIC include/futures.hh)
target_include_directories(threads PUBLIC include/threads.hh)

install(TARGETS thread RUNTIME DESTINATION bin)
install(TARGETS future LIBRARY DESTINATION lib)
install(TARGETS threads LIBRARY DESTINATION lib)