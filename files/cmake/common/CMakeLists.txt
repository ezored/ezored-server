# Header search paths
set(PROJECT_HEADER_SEARCH_PATHS
    "${PROJECT_ROOT_PATH}/projects/server/src"
    CACHE INTERNAL ""
)

# Library search paths
set(PROJECT_LIBRARY_SEARCH_PATHS "" CACHE INTERNAL "")

# Header files
file(GLOB H_FILES_PROJECT "${PROJECT_ROOT_PATH}/projects/server/src/*.hpp")
file(GLOB H_FILES_PROJECT_FACTORIES "${PROJECT_ROOT_PATH}/projects/server/src/ezored/server/factories/*.hpp")
file(GLOB H_FILES_PROJECT_HANDLERS "${PROJECT_ROOT_PATH}/projects/server/src/ezored/server/handlers/*.hpp")
file(GLOB H_FILES_PROJECT_HELPERS "${PROJECT_ROOT_PATH}/projects/server/src/ezored/server/helpers/*.hpp")
file(GLOB H_FILES_PROJECT_APPS "${PROJECT_ROOT_PATH}/projects/server/src/ezored/server/apps/*.hpp")
file(GLOB H_FILES_PROJECT_CONTROLLERS "${PROJECT_ROOT_PATH}/projects/server/src/ezored/server/controllers/*.hpp")

# Source files
file(GLOB S_FILES_PROJECT "${PROJECT_ROOT_PATH}/projects/server/src/*.cpp")
file(GLOB S_FILES_PROJECT_FACTORIES "${PROJECT_ROOT_PATH}/projects/server/src/ezored/server/factories/*.cpp")
file(GLOB S_FILES_PROJECT_HANDLERS "${PROJECT_ROOT_PATH}/projects/server/src/ezored/server/handlers/*.cpp")
file(GLOB S_FILES_PROJECT_HELPERS "${PROJECT_ROOT_PATH}/projects/server/src/ezored/server/helpers/*.cpp")
file(GLOB S_FILES_PROJECT_APPS "${PROJECT_ROOT_PATH}/projects/server/src/ezored/server/apps/*.cpp")
file(GLOB S_FILES_PROJECT_CONTROLLERS "${PROJECT_ROOT_PATH}/projects/server/src/ezored/server/controllers/*.cpp")

# Merge lists
set(
    PROJECT_HEADER_FILES
    ${H_FILES_PROJECT}
    ${H_FILES_PROJECT_FACTORIES}
    ${H_FILES_PROJECT_HANDLERS}
    ${H_FILES_PROJECT_HELPERS}
    ${H_FILES_PROJECT_APPS}
    ${H_FILES_PROJECT_CONTROLLERS}
    CACHE INTERNAL ""
)

set(
    PROJECT_SOURCE_FILES
    ${S_FILES_PROJECT}
    ${S_FILES_PROJECT_FACTORIES}
    ${S_FILES_PROJECT_HANDLERS}
    ${S_FILES_PROJECT_HELPERS}
    ${S_FILES_PROJECT_APPS}
    ${S_FILES_PROJECT_CONTROLLERS}
    CACHE INTERNAL ""
)

set(
    PROJECT_SOURCE_FILES
    ${PROJECT_HEADER_FILES}
    ${PROJECT_SOURCE_FILES} 
    CACHE INTERNAL ""
)

# Framework links
set(PROJECT_FRAMEWORK_LINKS "" CACHE INTERNAL "")

# Library links
set(PROJECT_LIBRARY_LINKS "" CACHE INTERNAL "")

# CFlags
set(PROJECT_CMAKE_C_FLAGS "${PROJECT_CMAKE_C_FLAGS} -Wall" CACHE INTERNAL "")

# CXXFlags
set(PROJECT_CMAKE_CXX_FLAGS "${PROJECT_CMAKE_CXX_FLAGS} -std=c++${PROJECT_CONFIG_CPP_STANDARD} -Wall" CACHE INTERNAL "")

# Compile options
set(PROJECT_COMPILE_OPTIONS "" CACHE INTERNAL "")

# Flags
set(CMAKE_C_FLAGS "${PROJECT_CMAKE_C_FLAGS}" CACHE INTERNAL "")
set(CMAKE_CXX_FLAGS "${PROJECT_CMAKE_CXX_FLAGS}" CACHE INTERNAL "")
