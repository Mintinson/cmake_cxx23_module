cmake_minimum_required(VERSION 4.2.0)
set(CMAKE_EXPERIMENTAL_CXX_IMPORT_STD "d0edc3af-4c50-42ea-a356-e2862fe7a444")
project(Cpp23StdModules CXX)

# Tell CMake that we explicitly want `import std`. This will initialize the
# property on all targets declared after this to 1
set(CMAKE_CXX_MODULE_STD 1)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_COLOR_DIAGNOSTICS ON)  # colorize output

add_executable(demo main.cpp)

# 3. 确保目标开启了模块扫描 (通常默认是 ON，但显式声明更安全)
set_property(TARGET demo PROPERTY CXX_SCAN_FOR_MODULES ON)

# 注意：这里使用了 FILE_SET CXX_MODULES 来明确告诉 CMake 这是模块文件)
target_sources(demo PUBLIC FILE_SET CXX_MODULES FILES my_module.cppm)

if(MSVC)
    target_compile_options(demo PRIVATE /utf-8)
endif()

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
# 添加一个自定义目标，每次构建时检查并复制
add_custom_target(CopyCompileCommands ALL
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    "${CMAKE_BINARY_DIR}/compile_commands.json"
    "${CMAKE_SOURCE_DIR}/compile_commands.json"
    COMMENT "Copying compile_commands.json to source root..."
    VERBATIM
)
