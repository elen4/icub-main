# Copyright: (C) 2010 RobotCub Consortium
# Authors: Lorenzo Natale
# CopyPolicy: Released under the terms of the GNU GPL v2.0.

PREPARE_DEVICE(icublegscalibrator TYPE iCubLegsCalibrator INCLUDE iCubLegsCalibrator.h)


if (NOT SKIP_icublegscalibrator)

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR} ${YARP_INCLUDE_DIRS})
ADD_LIBRARY(legscalibrator iCubLegsCalibrator.cpp iCubLegsCalibrator.h)

target_link_libraries(legscalibrator ${YARP_LIBRARIES})

icub_export_library(legscalibrator)
    yarp_install(FILES legscalibrator.ini DESTINATION ${ICUB_PLUGIN_MANIFESTS_INSTALL_DIR})

endif (NOT SKIP_icublegscalibrator)
