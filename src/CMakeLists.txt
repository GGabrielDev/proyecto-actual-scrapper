# Add source files
file(GLOB_RECURSE SOURCES
    business/*.cpp
    file/*.cpp
    ui/*.cpp
    utility/*.cpp
)

# Create a library
add_library(WebLinkExplorerLib ${SOURCES})

# Link the library to cURL
target_link_libraries(WebLinkExplorerLib PRIVATE ${CURL_LIBRARIES})
