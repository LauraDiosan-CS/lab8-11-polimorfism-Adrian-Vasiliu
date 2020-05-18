cmake_minimum_required(VERSION 3.16)
project(Lab14)

set(CMAKE_CXX_STANDARD 17)

add_executable(Lab14 main.cpp Domain/Plane.cpp Domain/Plane.h Domain/Table.cpp Domain/Table.h
        Repository/TemplateRepository.h)
