// This is an automatically-generated file.
// It could get re-generated if the ALLOW_IDL_GENERATION flag is on.

#include <iCub/iSpeak/iSpeakThrift.h>
#include <yarp/os/idl/WireTypes.h>



class iSpeakThrift_stat : public yarp::os::Portable {
public:
  std::string _return;
  virtual bool write(yarp::os::ConnectionWriter& connection) {
    yarp::os::idl::WireWriter writer(connection);
    if (!writer.writeListHeader(1)) return false;
    if (!writer.writeTag("stat",1,1)) return false;
    return true;
  }
  virtual bool read(yarp::os::ConnectionReader& connection) {
    yarp::os::idl::WireReader reader(connection);
    if (!reader.readListReturn()) return false;
    if (!reader.readString(_return)) {
      reader.fail();
      return false;
    }
    return true;
  }
};

class iSpeakThrift_get_opt : public yarp::os::Portable {
public:
  std::string _return;
  virtual bool write(yarp::os::ConnectionWriter& connection) {
    yarp::os::idl::WireWriter writer(connection);
    if (!writer.writeListHeader(2)) return false;
    if (!writer.writeTag("get_opt",1,2)) return false;
    return true;
  }
  virtual bool read(yarp::os::ConnectionReader& connection) {
    yarp::os::idl::WireReader reader(connection);
    if (!reader.readListReturn()) return false;
    if (!reader.readString(_return)) {
      reader.fail();
      return false;
    }
    return true;
  }
};

class iSpeakThrift_set_opt : public yarp::os::Portable {
public:
  std::string options;
  bool _return;
  virtual bool write(yarp::os::ConnectionWriter& connection) {
    yarp::os::idl::WireWriter writer(connection);
    if (!writer.writeListHeader(3)) return false;
    if (!writer.writeTag("set_opt",1,2)) return false;
    if (!writer.writeString(options)) return false;
    return true;
  }
  virtual bool read(yarp::os::ConnectionReader& connection) {
    yarp::os::idl::WireReader reader(connection);
    if (!reader.readListReturn()) return false;
    if (!reader.readBool(_return)) {
      reader.fail();
      return false;
    }
    return true;
  }
};

std::string iSpeakThrift::stat() {
  std::string _return = "";
  iSpeakThrift_stat helper;
  if (!yarp().canWrite()) {
    fprintf(stderr,"Missing server method '%s'?\n","std::string iSpeakThrift::stat()");
  }
  bool ok = yarp().write(helper,helper);
  return ok?helper._return:_return;
}
std::string iSpeakThrift::get_opt() {
  std::string _return = "";
  iSpeakThrift_get_opt helper;
  if (!yarp().canWrite()) {
    fprintf(stderr,"Missing server method '%s'?\n","std::string iSpeakThrift::get_opt()");
  }
  bool ok = yarp().write(helper,helper);
  return ok?helper._return:_return;
}
bool iSpeakThrift::set_opt(const std::string& options) {
  bool _return = false;
  iSpeakThrift_set_opt helper;
  helper.options = options;
  if (!yarp().canWrite()) {
    fprintf(stderr,"Missing server method '%s'?\n","bool iSpeakThrift::set_opt(const std::string& options)");
  }
  bool ok = yarp().write(helper,helper);
  return ok?helper._return:_return;
}

bool iSpeakThrift::read(yarp::os::ConnectionReader& connection) {
  yarp::os::idl::WireReader reader(connection);
  reader.expectAccept();
  if (!reader.readListHeader()) { reader.fail(); return false; }
  yarp::os::ConstString tag = reader.readTag();
  while (!reader.isError()) {
    // TODO: use quick lookup, this is just a test
    if (tag == "stat") {
      std::string _return;
      _return = stat();
      yarp::os::idl::WireWriter writer(reader);
      if (!writer.isNull()) {
        if (!writer.writeListHeader(1)) return false;
        if (!writer.writeString(_return)) return false;
      }
      reader.accept();
      return true;
    }
    if (tag == "get_opt") {
      std::string _return;
      _return = get_opt();
      yarp::os::idl::WireWriter writer(reader);
      if (!writer.isNull()) {
        if (!writer.writeListHeader(1)) return false;
        if (!writer.writeString(_return)) return false;
      }
      reader.accept();
      return true;
    }
    if (tag == "set_opt") {
      std::string options;
      if (!reader.readString(options)) {
        reader.fail();
        return false;
      }
      bool _return;
      _return = set_opt(options);
      yarp::os::idl::WireWriter writer(reader);
      if (!writer.isNull()) {
        if (!writer.writeListHeader(1)) return false;
        if (!writer.writeBool(_return)) return false;
      }
      reader.accept();
      return true;
    }
    if (reader.noMore()) { reader.fail(); return false; }
    yarp::os::ConstString next_tag = reader.readTag();
    if (next_tag=="") break;
    tag = tag + "_" + next_tag;
  }
  return false;
}


