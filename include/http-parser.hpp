// "Copyright 2021 Francisco Aguilera"

#ifndef SRC_HTTP_PARSER_HPP_
#define SRC_HTTP_PARSER_HPP_

#include <functional>
#include <vector>
#include <llhttp.h>
#include <boost_1_76_0.h>
#include <boost/utility/string_view.hpp>

namespace falven {
namespace ad {

/**
 * @brief A class that represents an Http Request or Response object
 * parsed from a provided buffer.
 * Internally uses [nodejs/http-parser](https://github.com/nodejs/http-parser)
 * to perform the Request or Response parsing. The class does not perform any
 * memory allocations in the heap, and instead maintains references to the
 * particular Request/Response properties from the provided buffer.
 */
class HttpParser {
 public:
  HttpParser();

  void Parse(const boost::string_view &chunk);

 private:
  llhttp_settings_t settings_;
  llhttp_t parser_;

  template <typename T, int (T::*Cb)(llhttp_t *)>
  static int CbAdapter(llhttp_t *parser);
  template <typename T, typename A, typename L, int (T::*Cb)(llhttp_t *, A, L)>
  static int CbAdapter(llhttp_t *parser, A a, L l);

  int OnMessageBegin(llhttp_t *parser);
  int OnUrl(llhttp_t *parser, const char *at, size_t length);
  int OnStatus(llhttp_t *parser, const char *at, size_t length);
  int OnHeaderField(llhttp_t *parser, const char *at, size_t length);
  int OnHeaderValue(llhttp_t *parser, const char *at, size_t length);
  int OnHeadersComplete(llhttp_t *parser);
  int OnBody(llhttp_t *parser, const char *at, size_t length);
  int OnMessageComplete(llhttp_t *parser);
  int OnChunkHeader(llhttp_t *parser);
  int OnChunkComplete(llhttp_t *parser);
  int OnUrlComplete(llhttp_t *parser);
  int OnStatusComplete(llhttp_t *parser);
  int OnHeaderFieldComplete(llhttp_t *parser);
  int OnHeaderValueComplete(llhttp_t *parser);
};

}  // namespace ad
}  // namespace falven

#endif  // SRC_HTTP_PARSER_HPP_
