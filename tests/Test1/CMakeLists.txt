cmake_minimum_required (VERSION 3.8)

set (project "Test1")
project(${project} CXX)
my_find_src_files (src_files ${project})
add_executable (${project} ${src_files})

my_inc_import_threadx(${project})
my_lib_import_threadx(${project})

include("${MY_MACRO_DIR}/MyInstall.cmake")

