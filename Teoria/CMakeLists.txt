cmake_minimum_required(VERSION 3.10)
project(Teoria)

file(GLOB SOURCES "src/*")

add_executable(run ${SOURCES})