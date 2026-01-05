cmake_minimum_required(VERSION 3.10)
project(MyProject C)

# 设置 C 标准
set(CMAKE_C_STANDARD 11)
include_directories(${PROJECT_SOURCE_DIR}/include)
file(GLOB SOURCES "src/*.c")
# 添加可执行文件
add_executable(myprogram ${SOURCES})

# 链接数学库
target_link_libraries(myprogram m)
