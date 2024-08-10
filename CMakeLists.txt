cmake_minimum_required(VERSION 3.10)
project(2048)

set(CMAKE_CXX_STANDARD 11)
set(PROJECT_ROOT VS)
include_directories(${PROJECT_ROOT})

find_package(Catch2 REQUIRED)

add_executable(game2048 2048/src/main.cpp 2048/src/Game.cpp 2048/src/Utils.cpp 2048/src/Kbhit.cpp 2048/src/KeyPushManager.cpp)

add_executable(tests
    catch2/test_main.cpp
    catch2/test_init.cpp
    2048/src/Game.cpp
    2048/src/Utils.cpp
    2048/src/Kbhit.cpp
    2048/src/KeyPushManager.cpp
)

target_link_libraries(tests Catch2::Catch2)
