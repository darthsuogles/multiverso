# - Try to find ZMQ
# Once done this will define
# ZMQ_FOUND - System has ZMQ
# ZMQ_INCLUDE_DIRS - The ZMQ include directories
# ZMQ_LIBRARIES - The libraries needed to use ZMQ
# ZMQ_DEFINITIONS - Compiler switches required for using ZMQ

set ( ZMQ_ROOT $ENV{ZMQ_ROOT} )
message( "ZeroMQ root dir " ${ZMQ_ROOT} )
find_path ( ZMQ_INCLUDE zmq.h PATHS ${ZMQ_ROOT}/include )
find_library ( ZMQ_LIBRARY zmq PATHS ${ZMQ_ROOT}/lib  )

set ( ZMQ_LIBRARIES ${ZMQ_LIBRARY} )
set ( ZMQ_INCLUDE_DIRS ${ZMQ_INCLUDE_DIR} )

include ( FindPackageHandleStandardArgs )
# handle the QUIETLY and REQUIRED arguments and set ZMQ_FOUND to TRUE
# if all listed variables are TRUE
#find_package_handle_standard_args ( ZMQ DEFAULT_MSG ZMQ_ROOT )
