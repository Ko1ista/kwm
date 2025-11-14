cmake_minimum_required(VERSION 3.16)
project(kwm VERSION 1.0.0 LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

# Добавьте флаг для wlroots
add_compile_definitions(WLR_USE_UNSTABLE)

# Поиск зависимостей
find_package(PkgConfig REQUIRED)
pkg_check_modules(WAYLAND REQUIRED wayland-server)
pkg_check_modules(WLROOTS REQUIRED wlroots)
pkg_check_modules(XKBCOMMON REQUIRED xkbcommon)
pkg_check_modules(PIXMAN REQUIRED pixman-1)

add_executable(${PROJECT_NAME}
    src/main.c
    src/wm.c
    src/utils/die.c
)

target_include_directories(${PROJECT_NAME} PRIVATE include)

# Подключение библиотек и флагов
target_link_libraries(${PROJECT_NAME} 
    PRIVATE 
    ${WAYLAND_LIBRARIES}
    ${WLROOTS_LIBRARIES}
    ${XKBCOMMON_LIBRARIES}
    ${PIXMAN_LIBRARIES}
)

target_include_directories(${PROJECT_NAME} PRIVATE 
    ${WAYLAND_INCLUDE_DIRS}
    ${WLROOTS_INCLUDE_DIRS}
    ${XKBCOMMON_INCLUDE_DIRS}
    ${PIXMAN_INCLUDE_DIRS}
)

target_compile_options(${PROJECT_NAME} PRIVATE 
    ${WAYLAND_CFLAGS_OTHER}
    ${WLROOTS_CFLAGS_OTHER}
)

install(TARGETS ${PROJECT_NAME} DESTINATION bin)
