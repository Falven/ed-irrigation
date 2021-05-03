// "Copyright 2021 Francisco Aguilera"

#ifndef INCLUDE_LOGGER_HPP_
#define INCLUDE_LOGGER_HPP_

#include <USB/USBAPI.h>
#include <boost_1_76_0.h>
#include <boost/utility/string_view.hpp>
#include <oprintstream.hpp>

namespace falven {
namespace ad {

class Logger : public OPrintStream<Logger> {
public:
  Logger(USBDeviceClass &usb) : OPrintStream(usb) {}
  ~Logger() override = default;

  void begin(uint32_t baudRate) {
    Serial_::begin(baudRate);
    while (!Serial) {
    }
  }

  /**
   * @brief Prints the string referenced by the provided boost::string_view.
   *
   * @param arg The boost::stringview to print.
   * @return OPrintStream& Returns the OPrintStream reference for
   * continuation.
   */
  OPrintStream &operator<<(const boost::string_view &arg) {
    print(arg.data());
    return *this;
  }

  using OPrintStream<Logger>::operator<<;
};

} // namespace ad
} // namespace falven

#endif // INCLUDE_LOGGER_HPP_
