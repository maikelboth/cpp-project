cmake_minimum_required(VERSION 3.15)
project(mathbender)

set(CMAKE_CXX_STANDARD 14)

add_executable(${PROJECT_NAME}.elf
        src/main.cpp src/StartScreen.cpp src/StartScreen.h src/Level.cpp src/Level.h src/EntityManager.cpp src/EntityManager.h src/Entity.cpp src/Entity.h src/Player.cpp src/Player.h src/sprites/kul.h)

target_link_libraries(${PROJECT_NAME}.elf gba-sprite-engine)

add_custom_command(TARGET ${PROJECT_NAME}.elf POST_BUILD
        COMMAND ${CMAKE_OBJCOPY} -v -O binary ${PROJECT_NAME}.elf ${PROJECT_NAME}.gba
        )