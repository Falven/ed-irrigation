// "Copyright 2021 Francisco Aguilera"

#include "http-server.hpp"

#include <string>
#include <vector>
#include <Arduino.h>
#include <ArduinoJson.h>
#include <SPI.h>
#include <WiFiNINA.h>
#include <boost_1_76_0.h>
#include <boost/utility/string_view.hpp>

#include "debug.hpp"
#include "http-parser.hpp"

namespace falven {
namespace ad {

HttpServer::HttpServer(uint16_t port) : server_(port), buffer_() {
  buffer_.reserve(kMaxRequestSize);
}

void HttpServer::Start() {
  DEBUG_LOCATION();
  server_.begin();
}

void HttpServer::Listen() {
  auto client = server_.available();
  if (client) {
    HttpParser parser;
    auto lineStart = buffer_.begin();
    auto lineEnd = buffer_.end();
    DEBUG_PRINTLN("Client available: " << client.remoteIP() << ":"
                                       << client.remotePort());
    while (client.connected()) {
      if (client.available()) {
        const auto c = static_cast<char>(client.read());
        buffer_.push_back(c);
        lineEnd++;
        if (c == '\n') {
          const auto lineStartValue = *lineStart;
          const auto lineEndValue = *(lineEnd - 1);
          const auto at = &(lineStartValue);
          const auto len = std::distance(lineStart, lineEnd);
          const boost::string_view currentLine(at, len);
          parser.Parse(currentLine);
          if ((len == 2 && lineStartValue == '\r' && lineEndValue == '\n') ||
              (len == 1 && lineEndValue == '\n')) {
            // that's the end of the client HTTP request, so send a response:
            break;
          }
          lineStart = lineEnd;
        }
      }
    }
    client.stop();
    buffer_.clear();
  }
}

}  // namespace ad
}  // namespace falven
