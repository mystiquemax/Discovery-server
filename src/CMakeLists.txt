
cmake_minimum_required(VERSION 3.20)

project(discovery_server_simple VERSION 1 LANGUAGES CXX)

find_package(fastcdr 2 REQUIRED)
find_package(fastrtps 2.12 REQUIRED)

file(GLOB SOURCES_CXX types/*.cxx)
file(GLOB SERVER server/*.cpp server/*.hpp)
file(GLOB CLIENT_ONE client_one/*.cpp client_one/*.hpp)
file(GLOB CLIENT_TWO client_two/*.cpp client_two/*.hpp)

add_executable(server ${SOURCES_CXX} ${SERVER})
target_link_libraries(server fastrtps fastcdr fastdds::optionparser)

add_executable(client_one ${SOURCES_CXX} ${CLIENT_ONE})
target_link_libraries(client_one fastrtps fastcdr fastdds::optionparser)

add_executable(client_two ${SOURCES_CXX} ${CLIENT_TWO})
target_link_libraries(client_two fastrtps fastcdr fastdds::optionparser)