include (FetchContent)

function(fetch_content TARGET REPO TAG)
#	set(_options)
#	set(_one_value_args TAG)
#	set(_multi_value_args )
#
#	cmake_parse_arguments(FETCH_REPO_ARG "${_options}" "${_one_value_args}" "${_multi_value_args}" "${ARGN}")

    message(STATUS "get " ${TARGET} "...")

    FetchContent_Declare(
        ${TARGET}
        GIT_REPOSITORY ${REPO}
        GIT_TAG        ${TAG}
    )

    FetchContent_MakeAvailable(${TARGET})
endfunction()
