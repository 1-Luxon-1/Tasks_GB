#include <chrono>
#include <exception>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <string>
#include <thread>
#include <vector>

#ifdef _WIN32
#   define ioctl ioctlsocket
#else
extern "C"
{
#   include <netinet/tcp.h>
#   include <sys/ioctl.h>
}
#endif

#include <socket_wrapper/socket_headers.h>
#include <socket_wrapper/socket_wrapper.h>
#include <socket_wrapper/socket_class.h>


using namespace std::chrono_literals;

const auto MAX_RECV_BUFFER_SIZE = 256;

int main(int argc, const char* const argv[])
{
    if (argc != 2)
    {
        std::cout << "Usage: " << argv[0] << " <host> <port>" << std::endl;
        return EXIT_FAILURE;
    }

    socket_wrapper::SocketWrapper sock_wrap;
    socket_wrapper::Socket sock = { AF_INET, SOCK_STREAM, IPPROTO_TCP };
    int newsockfd;
    if (!sock)
    {
        std::cerr << sock_wrap.get_last_error_string() << std::endl;
        return EXIT_FAILURE;
    }

    struct sockaddr_in addr =
    {
        .sin_family = AF_INET,
        .sin_port = htons(std::stoi(argv[2]))
    };

    addr.sin_addr.s_addr = *reinterpret_cast<const in_addr_t*>(remote_host->h_addr);

    if (bind(sock, reinterpret_cast<const sockaddr* const>(&addr), sizeof(addr)) != 0)
    {
        std::cerr << sock_wrap.get_last_error_string() << std::endl;
        return EXIT_FAILURE;
    }

    if (listen(sock, SOMAXCONN) != 0)
    {
        return WSAGetLastError();
    }

    while (true)
    {
        newsockfd = accept(sockfd, reinterpret_cast<const sockaddr*>(&client_addr), &client_len);
        if (newsockfd < 0)
        {
            throw std::runtime_error("ERROR on accept");
            break;
        }

        if (connect(sock, reinterpret_cast<const sockaddr* const>(&addr), sizeof(addr)) == 0)
        {
            auto recv_bytes = recv(sock, buffer, sizeof(buffer) - 1, 0);

            if (recv_bytes > 0)
            {
                buffer[recv_bytes] = '\0';
                std::cout << "------------\n" << std::string(buffer.begin(), std::next(buffer.begin(), recv_bytes)) << std::endl;
                continue;
            }
            else if (-1 == recv_bytes)
            {
                if (EINTR == errno) continue;
                if (0 == errno) break;
                break;
            }

            if (send(newsockfd, "2", 1, 0) > 0)
            {
                continue;
            }
            break;
        }

        return EXIT_SUCCESS;
    }