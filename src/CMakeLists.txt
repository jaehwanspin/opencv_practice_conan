set (OPENGL_GL_PREFERENCE LEGACY)
find_package(OpenGL REQUIRED COMPONENTS OpenGL)
find_package(OpenCL REQUIRED)

if (OpenCL_FOUND)
    message("OpenCL_FOUND")
    include_directories(${OpenCL_INCLUDE_DIR})
endif (OpenCL_FOUND)
if (OPENGL_FOUND)
    message("OpenGL_FOUND")
    
endif (OPENGL_FOUND)

add_executable(01_pg
    01_main.cpp
)
target_link_libraries(01_pg ${CONAN_LIBS})

add_executable(02_pg
    02_main.cpp
)
target_link_libraries(02_pg ${CONAN_LIBS})

add_executable(03_pg
    03_main.cpp
)
target_link_libraries(03_pg ${CONAN_LIBS})

add_executable(04_pg
    04_main.cpp
)
target_link_libraries(04_pg ${CONAN_LIBS})
target_link_libraries(04_pg ${OpenCL_LIBRARY})

add_executable(05_pg
    05_main.cpp
)
target_link_libraries(05_pg ${CONAN_LIBS})
target_link_libraries(05_pg ${OpenCL_LIBRARY})

add_executable(06_pg
    06_main.cpp
)
target_link_libraries(06_pg ${CONAN_LIBS})
target_link_libraries(06_pg ${OpenCL_LIBRARY})
target_link_libraries(06_pg ${OPENGL_gl_LIBRARY})

add_executable(00_pg
    00_main.cpp
)
target_link_libraries(00_pg ${CONAN_LIBS})
target_link_libraries(00_pg ${OpenCL_LIBRARY})
target_link_libraries(00_pg ${OPENGL_gl_LIBRARY})

add_executable(07_pg
    07_main.cpp
)
target_link_libraries(07_pg ${CONAN_LIBS})
target_link_libraries(07_pg ${OpenCL_LIBRARY})
target_link_libraries(07_pg ${OPENGL_gl_LIBRARY})

add_executable(08_pg
    08_main.cpp
)
target_link_libraries(08_pg ${CONAN_LIBS})
target_link_libraries(08_pg ${OpenCL_LIBRARY})
target_link_libraries(08_pg ${OPENGL_gl_LIBRARY})

add_executable(09_pg
    09_main.cpp
)
target_link_libraries(09_pg ${CONAN_LIBS})
target_link_libraries(09_pg ${OpenCL_LIBRARY})
target_link_libraries(09_pg ${OPENGL_gl_LIBRARY})
