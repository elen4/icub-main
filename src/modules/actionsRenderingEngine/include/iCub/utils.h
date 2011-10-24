// -*- mode:C++; tab-width:4; c-basic-offset:4; indent-tabs-mode:nil -*-

/* 
* Copyright (C) 2010 RobotCub Consortium, European Commission FP6 Project IST-004370
* Author: Carlo Ciliberto, Vadim Tikhanoff
* email:   carlo.ciliberto@iit.it vadim.tikhanoff@iit.it
* website: www.robotcub.org
* Permission is granted to copy, distribute, and/or modify this program
* under the terms of the GNU General Public License, version 2 or any
* later version published by the Free Software Foundation.
*
* A copy of the license can be found at
* http://www.robotcub.org/icub/license/gpl.txt
*
* This program is distributed in the hope that it will be useful, but
* WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General
* Public License for more details
*/

#ifndef __VISUO_MOTOR_UTILS__
#define __VISUO_MOTOR_UTILS__

#include <yarp/os/ResourceFinder.h>
#include <yarp/os/Port.h>
#include <yarp/os/Semaphore.h>
#include <yarp/sig/Vector.h>

#include <iostream>
#include <string>


#define LEFT                        0
#define RIGHT                       1
#define ARM_IN_USE                  -1
#define ARM_MOST_SUITED             -2


using namespace std;
using namespace yarp::os;
using namespace yarp::sig;




class ObjectPropertiesCollectorPort: public Port
{
public:
    bool getStereoPosition(const string &obj_name, Vector &stereo);
    bool getCartesianPosition(const string &obj_name, Vector &x);
    bool getKinematicOffsets(const string &obj_name, Vector *kinematic_offset);
    bool setKinematicOffset(const string &obj_name, const Vector *kinematic_offset);
};



class StereoTarget: public Vector
{
private:
    Semaphore                   mutex;

public:
    void set(const Vector &stereo)
    {
        mutex.wait();
        (Vector)*this=stereo;
        mutex.post();
    }

    Vector get()
    {
        Vector s;
        mutex.wait();
        s=(Vector)*this;
        this->clear();
        mutex.post();
        return s;
    }
};



class Initializer
{
public:
    StereoTarget                        stereo_target;

    ObjectPropertiesCollectorPort       port_opc;

public:
    Initializer(ResourceFinder &rf)
    {
        string name=rf.find("name").asString().c_str();
        port_opc.open(("/"+name+"/OPC:io").c_str());
    }

    bool interrupt()
    {
        port_opc.interrupt();
        return true;
    }

    bool close()
    {
        port_opc.close();
        return true;
    }
};




#endif

