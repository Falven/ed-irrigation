#include <string>
#include <iostream>

#include "../src/http-parser.hpp"

using namespace falven::ad;

void ProcessRequest() {
  std::string request(
      "GET http://192.168.1.2/\nUser-Agent: PostmanRuntime/7.28.0\nAccept: "
      "*/*\nCache-Control: no-cache\nPostman-Token: "
      "a891ef3a-1e6a-415d-9d86-b6ab110bc911\nHost: "
      "192.168.1.2\nAccept-Encoding: gzip, deflate, br\nConnection: "
      "keep-alive\n\n");
  std::vector<char> buffer_;
  buffer_.reserve(8192u);
  HttpParser parser;
  auto lineStart = buffer_.begin();
  auto lineEnd = buffer_.end();
  for (const auto c : request) {
    buffer_.push_back(c);
    lineEnd++;
    if (c == '\n') {
      auto at = &(*lineStart);
      const auto len = std::distance(lineStart, lineEnd);
      const boost::string_view currentLine(at, len);
      parser.Parse(currentLine);
      const auto lineStartChar = *lineStart;
      const auto lineEndChar = *(lineEnd - 1);
      if ((len == 2 && lineStartChar == '\r' && lineEndChar == '\n') ||
          (len == 1 && lineEndChar == '\n')) {
        // that's the end of the client HTTP request, so send a response:
        break;
      }
      lineStart = lineEnd;
    }
  }
  buffer_.clear();
}

int main(int argc, char* argv[]) { ProcessRequest(); }