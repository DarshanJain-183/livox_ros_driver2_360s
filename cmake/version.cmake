#---------------------------------------------------------------------------------------
# Get livox_ros_driver2_360s version from include/livox_ros_driver2_360s.h
#---------------------------------------------------------------------------------------
file(READ "${CMAKE_CURRENT_LIST_DIR}/../src/include/livox_ros_driver2_360s.h" livox_ros_driver2_360s_VERSION_FILE)
string(REGEX MATCH "livox_ros_driver2_360s_VER_MAJOR ([0-9]+)" _  "${livox_ros_driver2_360s_VERSION_FILE}")
set(ver_major ${CMAKE_MATCH_1})

string(REGEX MATCH "livox_ros_driver2_360s_VER_MINOR ([0-9]+)" _  "${livox_ros_driver2_360s_VERSION_FILE}")
set(ver_minor ${CMAKE_MATCH_1})
string(REGEX MATCH "livox_ros_driver2_360s_VER_PATCH ([0-9]+)" _  "${livox_ros_driver2_360s_VERSION_FILE}")
set(ver_patch ${CMAKE_MATCH_1})

if (NOT DEFINED ver_major OR NOT DEFINED ver_minor OR NOT DEFINED ver_patch)
    message(FATAL_ERROR "Could not extract valid version from include/livox_ros_driver2_360s.h")
endif()
set (livox_ros_driver2_360s_VERSION "${ver_major}.${ver_minor}.${ver_patch}")
