QT4_UI_FILES(UI_FILES ui/jview.ui)
QT4_MOC_FILES(MOC_FILES view.h dialog.h application.h)

include_directories(${PROJECT_SOURCE_DIR})

set(SOURCES
main.cpp
dialog.h
dialog.cpp
view.h
view.cpp
application.h
application.cpp
${UI_FILES}
${MOC_FILES}
lm.icns
)

SOURCE_GROUP("Source Files\\gen" FILES ${MOC_FILES} ${UI_FILES} ${RESOURCE_FILES})

add_executable(jviewer WIN32 MACOSX_BUNDLE ${SOURCES})

target_link_libraries(jviewer ${QT_LIBRARIES} common)
#set_default_properties(jviewer)

if(APPLE)
	SET( MACOSX_BUNDLE_INFO_STRING "Jiawei's Viewer")
	SET( MACOSX_BUNDLE_BUNDLE_VERSION "0.9.0")
	SET( MACOSX_BUNDLE_ICON_FILE "lm.icns" )
	SET( MACOSX_BUNDLE_GUI_IDENTIFIER "dartmouth.edu")
	SET( MACOSX_BUNDLE_BUNDLE_NAME "J Viewer")
	SET( MACOSX_BUNDLE_COPYRIGHT "Jiawei Ou allright reserved..")

	SET_SOURCE_FILES_PROPERTIES(lm.icns PROPERTIES MACOSX_PACKAGE_LOCATION Resources)
endif()