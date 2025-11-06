cmake_minimum_required(VERSION 4.0)
project(wGameEngine LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.2
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

add_executable(main src/main.cpp
        src/States/StateManager.cpp
        src/States/State.cpp
        src/States/MenuState.cpp
        src/States/Level1State.cpp
        src/Core/Game.cpp
        src/Utils/Button.cpp
        include/Utils/Button.h
        src/Entities/player.cpp
        include/Entities/player.h
        include/Entities/player.h
)
target_compile_features(main PRIVATE cxx_std_17)
target_link_libraries(main PRIVATE SFML::Graphics)
