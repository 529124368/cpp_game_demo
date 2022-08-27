cmake_minimum_required (VERSION 3.15)
project(games)
set(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup")
set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
SET(CMAKE_SHARED_LINKER_FLAGS ${CMAKE_SHARED_LINKER_FLAGS} "/NODEFAULTLIB:library" )
add_executable(games src/main.cpp)
target_compile_features(games PRIVATE cxx_std_17)

find_package(raylib CONFIG REQUIRED)
target_link_libraries(games PRIVATE raylib)


