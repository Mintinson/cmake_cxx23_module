add_rules("mode.release", "mode.debug")

add_rules("plugin.compile_commands.autoupdate", {outputdir = "."})

includes("toolchains/clang_libcxx.lua")

set_languages("c++23")

if is_plat("windows") then
    add_cxflags("/utf-8", {toolchain = "cl"})
end

target("demo")
    set_kind("binary")
    add_files("main.cpp", "my_module.cppm")