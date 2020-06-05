project(my_img_proc_lib)
cmake_minimum_required(VERSION 3.0)


list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

find_package(GTK2 REQUIRED)

include_directories(common io gtk_screen)


add_subdirectory(common)
add_executable(test_lib  main.cpp) 
add_subdirectory(io)
add_subdirectory(gtk_screen)


target_link_libraries(test_lib common ${GTK2_LIBRARIES})
target_include_directories(test_lib PUBLIC io ${GTK2_INCLUDE_DIRS})
