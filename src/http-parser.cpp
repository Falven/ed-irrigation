// "Copyright 2021 Francisco Aguilera"

#include "http-parser.hpp"

#include <vector>
#include <sstream>
#include <llhttp.h>
#include <boost_1_76_0.h>
#include <boost/utility/string_view.hpp>

#include "debug.hpp"

namespace falven {
namespace ad {

HttpParser::HttpParser() : settings_(), parser_() {
  llhttp_settings_init(&settings_);
  settings_.on_message_begin =
      &CbAdapter<HttpParser, &HttpParser::OnMessageBegin>;
  settings_.on_url =
      &CbAdapter<HttpParser, const char *, size_t, &HttpParser::OnUrl>;
  settings_.on_status =
      &CbAdapter<HttpParser, const char *, size_t, &HttpParser::OnStatus>;
  settings_.on_header_field =
      &CbAdapter<HttpParser, const char *, size_t, &HttpParser::OnHeaderField>;
  settings_.on_header_value =
      &CbAdapter<HttpParser, const char *, size_t, &HttpParser::OnHeaderValue>;
  settings_.on_headers_complete =
      &CbAdapter<HttpParser, &HttpParser::OnHeadersComplete>;
  settings_.on_body =
      &CbAdapter<HttpParser, const char *, size_t, &HttpParser::OnBody>;
  settings_.on_message_complete =
      &CbAdapter<HttpParser, &HttpParser::OnMessageComplete>;
  settings_.on_chunk_header =
      &CbAdapter<HttpParser, &HttpParser::OnChunkHeader>;
  settings_.on_chunk_complete =
      &CbAdapter<HttpParser, &HttpParser::OnChunkComplete>;
  settings_.on_url_complete =
      &CbAdapter<HttpParser, &HttpParser::OnUrlComplete>;
  settings_.on_status_complete =
      &CbAdapter<HttpParser, &HttpParser::OnStatusComplete>;
  settings_.on_header_field_complete =
      &CbAdapter<HttpParser, &HttpParser::OnHeaderFieldComplete>;
  settings_.on_header_value_complete =
      &CbAdapter<HttpParser, &HttpParser::OnHeaderValueComplete>;

  llhttp_init(&parser_, llhttp_type_t::HTTP_BOTH, &settings_);
  parser_.data = this;
}

void HttpParser::Parse(const boost::string_view &chunk) {
  auto data = &chunk.front();
  auto len = chunk.size();
  llhttp_errno_t result = llhttp_execute(&parser_, data, len);
  if (result == llhttp_errno_t::HPE_OK) {
    DEBUG_PRINTLN("Successfully parsed: " << chunk);
  } else {
    DEBUG_PRINTLN("Parsing error! " << llhttp_errno_name(result) << ": "
                                    << parser_.reason);
  }
}

template <typename T, int (T::*Cb)(llhttp_t *)>
int HttpParser::CbAdapter(llhttp_t *parser) {
  return (static_cast<T *>(parser->data)->*Cb)(parser);
}

template <typename T, typename A, typename L, int (T::*Cb)(llhttp_t *, A, L)>
int HttpParser::CbAdapter(llhttp_t *parser, A a, L l) {
  return (static_cast<T *>(parser->data)->*Cb)(parser, a, l);
}

int HttpParser::OnMessageBegin(llhttp_t *parser) {
  DEBUG_LOCATION();
  return 0;
}

int HttpParser::OnUrl(llhttp_t *parser, const char *at, size_t length) {
  const boost::string_view url(at, length);
  DEBUG_PRINTLN(url);
  return 0;
}

int HttpParser::OnStatus(llhttp_t *parser, const char *at, size_t length) {
  const boost::string_view status(at, length);
  DEBUG_PRINTLN(status);
  return 0;
}

int HttpParser::OnHeaderField(llhttp_t *parser, const char *at, size_t length) {
  const boost::string_view headerField(at, length);
  DEBUG_PRINTLN(headerField);
  return 0;
}

int HttpParser::OnHeaderValue(llhttp_t *parser, const char *at, size_t length) {
  const boost::string_view headerValue(at, length);
  DEBUG_PRINTLN(headerValue);
  return 0;
}

int HttpParser::OnHeadersComplete(llhttp_t *parser) {
  DEBUG_LOCATION();
  return 0;
}

int HttpParser::OnBody(llhttp_t *parser, const char *at, size_t length) {
  const boost::string_view body(at, length);
  DEBUG_PRINTLN(body);
  return 0;
}

int HttpParser::OnMessageComplete(llhttp_t *parser) {
  DEBUG_LOCATION();
  return 0;
}

int HttpParser::OnChunkHeader(llhttp_t *parser) {
  DEBUG_LOCATION();
  return 0;
}

int HttpParser::OnChunkComplete(llhttp_t *parser) {
  DEBUG_LOCATION();
  return 0;
}

int HttpParser::OnUrlComplete(llhttp_t *parser) {
  DEBUG_LOCATION();
  return 0;
}

int HttpParser::OnStatusComplete(llhttp_t *parser) {
  DEBUG_LOCATION();
  return 0;
}

int HttpParser::OnHeaderFieldComplete(llhttp_t *parser) {
  DEBUG_LOCATION();
  return 0;
}

int HttpParser::OnHeaderValueComplete(llhttp_t *parser) {
  DEBUG_LOCATION();
  return 0;
}

}  // namespace ad
}  // namespace falven
