cmake_minimum_required(VERSION 3.10)

project(ISI_TP2_isiviewer-1.4)

find_package(OpenGL REQUIRED)
find_package(Qt5 COMPONENTS Core Gui OpenGL Xml REQUIRED)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)

include_directories(glm ${PROJECT_SOURCE_DIR} ${PROJECT_BINARY_DIR})

set(SOURCES my_qglviewer.cpp my_main_window.cpp my_scene.cpp my_object3d.cpp
            main.cpp objects/triMesh.cpp objects/off_loader.cpp objects/func_surface.cpp objects/tore.cpp objects/sphere.cpp objects/cone.cpp objects/disk.cpp objects/cylindre.cpp objects/cube_corner.cpp objects/cube.cpp objects/pyramid.cpp objects/disk_hole.cpp)

add_executable(isiviewer ${SOURCES})

target_link_libraries (isiviewer QGLViewer-qt5 Qt5::OpenGL Qt5::Xml ${OPENGL_LIBRARIES})

# add a symbolic link toward the source directory
add_custom_command(TARGET isiviewer POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E create_symlink ${CMAKE_CURRENT_SOURCE_DIR}/data ${CMAKE_CURRENT_BINARY_DIR}/data
  )


option(BUILD_DOCUMENTATION "Create and install the HTML based API documentation (requires Doxygen)" OFF)
IF(BUILD_DOCUMENTATION)

  FIND_PACKAGE(Doxygen)
  IF(NOT DOXYGEN_FOUND)
    MESSAGE(FATAL_ERROR "Doxygen is needed to build the documentation.")
  ENDIF()

  SET( doxyfile_in          ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in     )
  SET( doxyfile             ${PROJECT_BINARY_DIR}/Doxyfile              )
  SET( doxy_html_index_file ${CMAKE_CURRENT_BINARY_DIR}/html/index.html )
  SET( doxy_output_root     ${CMAKE_CURRENT_BINARY_DIR}                 ) # Pasted into Doxyfile.in
  SET( doxy_input           ${PROJECT_SOURCE_DIR}                       ) # Pasted into Doxyfile.in
  #SET( doxy_extra_files     ${CMAKE_CURRENT_SOURCE_DIR}/mainpage.dox    ) # Pasted into Doxyfile.in

  CONFIGURE_FILE( ${doxyfile_in} ${doxyfile} @ONLY )

  ADD_CUSTOM_COMMAND( OUTPUT ${doxy_html_index_file}
                      COMMAND ${DOXYGEN_EXECUTABLE} ${doxyfile}
                      # The following should be ${doxyfile} only but it
                      # will break the dependency.
                      # The optimal solution would be creating a
                      # custom_command for ${doxyfile} generation
                      # but I still have to figure out how...
                      MAIN_DEPENDENCY ${doxyfile} ${doxyfile_in}
                      DEPENDS ${SOURCES}
                      COMMENT "Generating HTML documentation")

  ADD_CUSTOM_TARGET( doc ALL DEPENDS ${doxy_html_index_file} )

  INSTALL( DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/html DESTINATION share/doc )
ENDIF()
