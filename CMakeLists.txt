cmake_minimum_required (VERSION 3.20)

project(common)

include (FetchContent)
FetchContent_Declare(cmake_tool GIT_REPOSITORY https://github.com/nearmeng/cmake_tools.git GIT_TAG master)
FetchContent_MakeAvailable(cmake_tool)

fetch_content(thirdparty https://github.com/nearmeng/thirdparty.git master)

init_project()

pre_project(common STATIC)

add_project()

post_project()

if (MSVC)
    add_definitions(-DCURL_STATICLIB)
elseif(UNIX)
    target_link_libraries(${TARGET_NAME} dl)
endif()

target_include_directories(${TARGET_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/inc)
target_link_libraries (${TARGET_NAME}
    3rd::libevent::event 
    3rd::libevent::core 
    3rd::libevent::extra
	3rd::lua
	3rd::toluapp
	3rd::protobuf
    3rd::curl
    3rd::tbase
    3rd::lmdb
)