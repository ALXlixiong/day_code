cmake_minimun_required(VERSION 3.0.0) #cmake最低版本需求，不加入此行会受到警告信息

project(5_17_test) #项目名称　　

aux_source_directory(. SRC_LIST) #把当前目录(.)下所有源代码文件和头文件加入变量SRC_LIST

add_executable(test ${SRC_LIST}) #生成应用程序 test (在windows下会自动生成hello.exe)
