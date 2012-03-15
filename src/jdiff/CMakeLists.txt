QT4_UI_FILES(UI_FILES ui/jdiff.ui)
#QT4_MOC_FILES(MOC_FILES view.h dialog.h application.h)

include_directories(${PROJECT_SOURCE_DIR})

set(SOURCES
main.cpp
${UI_FILES}
${MOC_FILES}
)

SOURCE_GROUP("Source Files\\gen" FILES ${MOC_FILES} ${UI_FILES} ${RESOURCE_FILES})

add_executable(jdiff ${SOURCES})

target_link_libraries(jdiff ${QT_LIBRARIES} common ${EXR_LIB})
