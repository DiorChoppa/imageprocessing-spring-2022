project(lab03)
add_executable(lab03 lab03.cpp lab03.report.md.in.txt)
target_link_libraries(lab03 ${OpenCV_LIBS})

file(READ lab03.cpp cpp_source)
# prepare report md file
configure_file(lab03.report.md.in.txt ${CMAKE_CURRENT_BINARY_DIR}/lab03.report.md @ONLY)
add_custom_command(TARGET ${PROJECT_NAME}
  POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_BINARY_DIR}/lab03.report.md" "$<TARGET_FILE_DIR:${PROJECT_NAME}>")