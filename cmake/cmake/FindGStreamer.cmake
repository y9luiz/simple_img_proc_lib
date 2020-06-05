# find gstreamer 1.x libraries
pkg_search_module(GSTREAMER REQUIRED gstreamer-1.0)
find_library(LIB_GSTREAMER NAMES ${GSTREAMER_LIBRARIES} HINTS ${GSTREAMER_LIBRARY_DIRS})
FIND_LIBRARY(GST_RTSP_SERVER_LIBRARY_DIRS NAMES libgstrtsp.so PATHS "/usr/lib/x86_64-linux-gnu/gstreamer-1.0/")
FIND_PATH(GST_RTSP_SERVER_INCLUDE_DIRS gst/rtsp-server/rtsp-server.h PATHS "/usr/include/gstreamer-1.0")
pkg_search_module(GSTREAMER_APP REQUIRED gstreamer-app-1.0 gstreamer-plugins-base-1.0) # for appsrc

include_directories (
        "${PROJECT_SOURCE_DIR}/include"
        "${GSTREAMER_INCLUDE_DIRS}"
        "${GST_RTSP_SERVER_INCLUDE_DIRS}"
	"${GSTREAMER_APP_INCLUDE_DIRS}"
)

message("testando ..." ${GSTREAMER_INCLUDE_DIRS})
link_directories (
  "${GSTREAMER_LIBRARY_DIRS}"
  "${GST_RTSP_SERVER_LIBRARY_DIRS}"
  "${GSTREAMER_APP_LIBRARY_DIRS}"
)
