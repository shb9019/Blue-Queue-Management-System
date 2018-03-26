cmake_minimum_required(VERSION 3.9)
project(networks_project)

set(CMAKE_CXX_STANDARD 11)

add_executable(networks_project
        Network.cpp
        Node.cpp
        Packet.cpp
        README.md)
