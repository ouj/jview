include_directories(${PROJECT_SOURCE_DIR})

set(SOURCES
main.cpp
)

add_executable(jdiff ${SOURCES})

target_link_libraries(jdiff ${QT_LIBRARIES} common ${EXR_LIB})
