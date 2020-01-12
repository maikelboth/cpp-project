cmake_minimum_required(VERSION 3.15)
project(mathbender)

set(CMAKE_CXX_STANDARD 14)

add_executable(${PROJECT_NAME}.elf
        src/main.cpp src/Level1Screen.cpp src/Level1Screen.h src/Level.cpp src/Level.h src/EntityManager.cpp src/EntityManager.h src/Entity/Player.cpp src/Entity/Player.h src/Sprite/kul.h src/Entity/Boss.cpp src/Entity/Boss.h src/Sprite/SpriteBoss.h src/Entity/Attack.h src/Entity/Ball.cpp src/Entity/Ball.h src/Sprite/SpriteBall.h src/MainScreen.cpp src/MainScreen.h src/Sprite/test.h src/Sprite/mainScreenBG.h src/Sprite/level1BG.h src/Entity/Fire.cpp src/Entity/Fire.h src/Sprite/player.h)

target_link_libraries(${PROJECT_NAME}.elf gba-sprite-engine)

add_custom_command(TARGET ${PROJECT_NAME}.elf POST_BUILD
        COMMAND ${CMAKE_OBJCOPY} -v -O binary ${PROJECT_NAME}.elf ${PROJECT_NAME}.gba
        )