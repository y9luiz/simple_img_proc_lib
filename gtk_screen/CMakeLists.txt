project(my_img_proc_lib)

#SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib)

add_library(gkt_screen MODULE ${PROJECT_SOURCE_DIR}/gtk_screen.cpp  ${PROJECT_SOURCE_DIR}/gtk_screen.h)
target_link_libraries(gkt_screen ${GTK2_LIBRARIES})
target_include_directories(gkt_screen PRIVATE ${GTK2_INCLUDE_DIRS})
target_sources(test_lib PRIVATE ${PROJECT_SOURCE_DIR}/gtk_screen.cpp )
