// This is an automatically-generated file.
// It could get re-generated if the ALLOW_IDL_GENERATION flag is on.

#ifndef YARP_THRIFT_GENERATOR_iSpeakThrift
#define YARP_THRIFT_GENERATOR_iSpeakThrift

#include <yarp/os/Wire.h>
#include <yarp/os/idl/WireTypes.h>

class iSpeakThrift;


class iSpeakThrift : public yarp::os::Wire {
public:
  iSpeakThrift() { yarp().setOwner(*this); }
  virtual std::string stat();
  virtual std::string get_opt();
  virtual bool set_opt(const std::string& options);
  virtual bool read(yarp::os::ConnectionReader& connection);
};

#endif

