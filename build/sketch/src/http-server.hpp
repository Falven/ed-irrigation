#line 1 "c:\\source\\repos\\ed-irrigation\\src\\http-server.hpp"
// "Copyright 2021 Francisco Aguilera"

#ifndef INCLUDE_HTTP_SERVER_HPP_
#define INCLUDE_HTTP_SERVER_HPP_

#include "http-parser.hpp"

#include <vector>
#include <Arduino.h>
#include <SPI.h>
#include <WiFiNINA.h>

namespace falven {
namespace ad {

class HttpServer {
 public:
  static const uint16_t kDefaultPort = 80U;
  static const size_t kMaxRequestSize = 8192u;

  explicit HttpServer(uint16_t port = kDefaultPort);

  void Start();
  void Listen();

 private:
  WiFiServer server_;
  std::vector<char> buffer_;
};

}  // namespace ad
}  // namespace falven

#endif  // INCLUDE_HTTP_SERVER_HPP_
