#
# Copyright (C) 2013 RobotCub Consortium
# Author: Alberto Cardellino
# CopyPolicy: Released under the terms of the GNU GPL v2.0.
#

SET(PROJECTNAME imu3DM_GX3)
PROJECT(${PROJECTNAME})

PREPARE_DEVICE(${PROJECTNAME} TYPE ${PROJECTNAME} INCLUDE 3dm_gx3.h WRAPPER inertial)

if (ENABLE_${PROJECTNAME})
    INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR} ${YARP_INCLUDE_DIRS})
    ADD_LIBRARY(${PROJECTNAME} 3dm_gx3.cpp 3dm_gx3.h )
    target_link_libraries(${PROJECTNAME} ${YARP_LIBRARIES})
    icub_export_library(${PROJECTNAME})
    yarp_install(FILES imu3DM_GX3.ini DESTINATION ${ICUB_PLUGIN_MANIFESTS_INSTALL_DIR})
endif (ENABLE_${PROJECTNAME})
