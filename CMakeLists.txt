
SET(CMAKE_SYSTEM_NAME Linux)

# #OK CONFIG
# #指定C交叉编译器,必须配置或交叉编译器使用绝对地址
 SET(CMAKE_C_COMPILER arm-none-linux-gnueabi-gcc)
# #指定C++交叉编译器
 SET(CMAKE_CXX_COMPILER arm-none-linux-gnueabi-g++)

#SET(CMAKE_C_COMPILER $ENV{ARM_PATH}/bin/gcc)
#SET(CMAKE_CXX_COMPILER  $ENV{ARM_PATH}/bin/g++)

set(ARM_DIR /home/xiaosonne/bin/arm-2011.03)

#不一定需要设置指定交叉编译环境安装目录…
SET(CMAKE_FIND_ROOT_PATH ${ARM_DIR}/bin  ${ARM_DIR}/arm-none-linux-gnueabi/include ${ARM_DIR}/arm-none-linux-gnueabi/lib)
#从来不在指定目录下查找工具程序
SET(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
#只在指定目录下查找库文件
SET(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
#只在指定目录下查找头文件
SET(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

cmake_minimum_required(VERSION 2.8)

project (arm1 )

set(EXECUTABLE_OUTPUT_PATH ${arm1_SOURCE_DIR}/bin)

include_directories(${arm1_SOURCE_DIR}/src) 

aux_source_directory(./src source_code) 

add_executable(arm1 ${source_code})

target_link_libraries(arm1)
