cmake_minimum_required(VERSION 3.15)
project(mathbender)

set(CMAKE_CXX_STANDARD 14)

add_executable(${PROJECT_NAME}.elf
        src/main.cpp src/Level1Screen.cpp src/Level1Screen.h src/EntityManager.cpp src/EntityManager.h src/Entity/Player.cpp src/Entity/Player.h src/Entity/Boss.cpp src/Entity/Boss.h src/Entity/Attack.h src/Entity/Fireball.cpp src/Entity/Fireball.h src/MainScreen.cpp src/MainScreen.h src/Sprite/mainScreenBG.h src/Sprite/level1BG.h src/Entity/Bullet.cpp src/Entity/Bullet.h src/Sprite/sprites.h src/EndScreen.cpp src/EndScreen.h src/Entity/Water.cpp src/Entity/Water.h)

target_link_libraries(${PROJECT_NAME}.elf gba-sprite-engine)

add_custom_command(TARGET ${PROJECT_NAME}.elf POST_BUILD
        COMMAND ${CMAKE_OBJCOPY} -v -O binary ${PROJECT_NAME}.elf ${PROJECT_NAME}.gba
        )