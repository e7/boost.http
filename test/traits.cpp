#include <boost/http/request.hpp>
#include <boost/http/response.hpp>
#include <boost/http/buffered_socket.hpp>
#include <boost/http/server_socket_adaptor.hpp>

using namespace boost;
using namespace std;

class dummy_server_socket {};

namespace boost {
namespace http {
template<>
struct is_server_socket<dummy_server_socket>: public std::true_type {};
} // namespace http {
} // namespace boost {

static_assert(!http::is_message<int>::value, "int is a message?!");
static_assert(http::is_message<http::request>::value,
              "http::request is not a message?!");
static_assert(http::is_request_message<http::request>::value,
              "http::request is not a request?!");
static_assert(!http::is_request_message<http::response>::value,
              "http::response is a request?!");
static_assert(http::is_message<http::response>::value,
              "http::response is not a message?!");
static_assert(http::is_response_message<http::response>::value,
              "http::response is not a response?!");
static_assert(!http::is_response_message<http::request>::value,
              "http::request is a response?!");
static_assert(http::is_message<http::basic_request<int, int, int>>::value,
              "http::basic_request<int, int, int> is not a message?!");
static_assert(http::is_message<http::basic_response<int, int, int>>::value,
              "http::basic_response<int, int, int> is not a message?!");

static_assert(!http::is_server_socket<int>::value,
              "int is a server_socket?!");
static_assert(http::is_server_socket<http::socket>::value,
              "http::socket is not a server_socket?!");
static_assert(http::is_server_socket<http::basic_socket<int>>::value,
              "http::basic_socket<int> is not a server_socket?!");
static_assert(http::is_server_socket<dummy_server_socket>::value,
              "dummy_server_socket is not a server_socket?!");

static_assert(!http::is_socket<int>::value, "int is a socket?!");
static_assert(http::is_socket<http::socket>::value,
              "http::socket is not a socket?!");
static_assert(http::is_socket<http::basic_socket<int>>::value,
              "http::basic_socket<int> is not a socket?!");
static_assert(http::is_socket<dummy_server_socket>::value,
              "dummy_server_socket is not a socket?!");

static_assert(http::is_server_socket<http::buffered_socket>::value,
              "http::buffered_socket is not a server_socket?!");
static_assert(http::is_server_socket<http::basic_buffered_socket<int>>::value,
              "http::basic_buffered_socket<int> is not a server_socket?!");

static_assert(http::is_socket<http::buffered_socket>::value,
              "http::buffered_socket is not a socket?!");
static_assert(http::is_socket<http::basic_buffered_socket<int>>::value,
              "http::basic_buffered_socket<int> is not a socket?!");

static_assert(!http::is_server_socket<http::polymorphic_socket_base>::value,
              "http::polymorphic_socket_base is a server_socket?!");
static_assert(!http::is_server_socket<http::basic_polymorphic_socket_base<int>>
              ::value,
              "http::basic_polymorphic_socket_base<int> is a server_socket?!");

static_assert(http::is_socket<http::polymorphic_socket_base>::value,
              "http::polymorphic_socket_base is not a socket?!");
static_assert(http::is_socket<http::basic_polymorphic_socket_base<int>>::value,
              "http::basic_polymorphic_socket_base<int> is not a socket?!");

static_assert(http::is_server_socket<http::polymorphic_server_socket>::value,
              "http::polymorphic_server_socket is a server_socket?!");
static_assert(http::is_server_socket<http::basic_polymorphic_server_socket<int,
                                                                           int>>
              ::value,
              "http::basic_polymorphic_server_socket<int> is not a"
              " server_socket?!");

static_assert(http::is_socket<http::polymorphic_server_socket>::value,
              "http::polymorphic_server_socket is not a socket?!");
static_assert(http::is_socket<http::basic_polymorphic_server_socket<int, int>>
              ::value,
              "http::basic_polymorphic_server_socket<int> is not a socket?!");

static_assert(http::is_server_socket<http::server_socket_adaptor<int>>::value,
              "http::server_socket_adaptor<int> is not a server_socket?!");
static_assert(http::is_socket<http::server_socket_adaptor<int>>::value,
              "http::server_socket_adaptor<int> is not a socket?!");

int main() {}
