# Add source files
file(GLOB_RECURSE SOURCES
    business/*.cpp
    file/*.cpp
    ui/*.cpp
    utility/*.cpp
)

# Create a library
add_library(WebLinkExplorerLib ${SOURCES})
