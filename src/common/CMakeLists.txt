include_directories(${PROJECT_SOURCE_DIR})

set(SOURCES
vec.h
array.h
pam.h
pam.cpp
image.h
image.cpp
stdmath.h
raw.h
func.h
debug.h
)

add_library(common ${SOURCES})
