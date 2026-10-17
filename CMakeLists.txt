cmake_minimum_required(VERSION 3.15)

project(color_log
    VERSION 0.1.0
    DESCRIPTION "Small ANSI color logging library"
    LANGUAGES C
)

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

add_library(color_log src/color_log.c)
add_library(color_log::color_log ALIAS color_log)

target_compile_features(color_log PUBLIC c_std_99)

target_include_directories(color_log
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

set_target_properties(color_log PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION ${PROJECT_VERSION_MAJOR}
    EXPORT_NAME color_log
)

install(
    TARGETS color_log
    EXPORT color_logTargets
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

install(
    DIRECTORY include/
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(
    EXPORT color_logTargets
    FILE color_logTargets.cmake
    NAMESPACE color_log::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/color_log
)

configure_package_config_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/cmake/color_logConfig.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/color_logConfig.cmake
    INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/color_log
)

write_basic_package_version_file(
    ${CMAKE_CURRENT_BINARY_DIR}/color_logConfigVersion.cmake
    COMPATIBILITY SameMajorVersion
)

install(
    FILES
        ${CMAKE_CURRENT_BINARY_DIR}/color_logConfig.cmake
        ${CMAKE_CURRENT_BINARY_DIR}/color_logConfigVersion.cmake
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/color_log
)
