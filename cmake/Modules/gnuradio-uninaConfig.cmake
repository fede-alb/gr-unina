find_package(PkgConfig)

PKG_CHECK_MODULES(PC_GR_UNINA gnuradio-unina)

FIND_PATH(
    GR_UNINA_INCLUDE_DIRS
    NAMES gnuradio/unina/api.h
    HINTS $ENV{UNINA_DIR}/include
        ${PC_UNINA_INCLUDEDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/include
          /usr/local/include
          /usr/include
)

FIND_LIBRARY(
    GR_UNINA_LIBRARIES
    NAMES gnuradio-unina
    HINTS $ENV{UNINA_DIR}/lib
        ${PC_UNINA_LIBDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/lib
          ${CMAKE_INSTALL_PREFIX}/lib64
          /usr/local/lib
          /usr/local/lib64
          /usr/lib
          /usr/lib64
          )

include("${CMAKE_CURRENT_LIST_DIR}/gnuradio-uninaTarget.cmake")

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(GR_UNINA DEFAULT_MSG GR_UNINA_LIBRARIES GR_UNINA_INCLUDE_DIRS)
MARK_AS_ADVANCED(GR_UNINA_LIBRARIES GR_UNINA_INCLUDE_DIRS)
