cmake_minimum_required (VERSION 3.15)
project(games)
set(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup")
set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
FILE(GLOB ALL_SOURCE src/main.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/engine/*.cpp)
add_executable(games ${ALL_SOURCE})
target_compile_features(games PRIVATE cxx_std_17)
target_include_directories(games PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

find_package(raylib CONFIG REQUIRED)
target_link_libraries(games PRIVATE raylib)

