#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <errno.h>

#define DEFAULT_PORT 8080
#define BUFFER_SIZE 1024

//struct sockaddr_in {
//    sa_family_t    sin_family; /* address family: AF_INET */
//    in_port_t      sin_port;   /* port in network byte order */
//    struct in_addr sin_addr;   /* internet address  };

// Internet address/ IP Address. 
//    struct in_addr {
//    uint32_t       s_addr;     //address in network byte order 
// };

void error_exit(const char *message)
{
    perror(message);
    exit(EXIT_FAILURE);
}
int create_socket() {
    int tcp_socketfd = socket(AF_INET, SOCK_STREAM, 0); //ipV4, TCP, default protocol
    if(tcp_socketfd == 0) {
        error_exit("socket failed");
    }
    return tcp_socketfd;
}

void bind_socket(int sockfd, struct sockaddr_in *address, int port) {
    int opt = 1;
    if(setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        error_exit("setsockopt failed");
    }
    address->sin_family = AF_INET;
    address->sin_port = htons(port); // convert to network byte order
    address->sin_addr.s_addr = INADDR_ANY;
    // bind a socket to an source address
    if(bind(sockfd, (struct sockaddr *)address, sizeof(*address)) < 0) {
        error_exit("bind failed");
    }
}

void start_listening(int sockfd) {
    if(listen(sockfd, 3) < 0) {
        error_exit("listen failed");
    }
}

int accept_connection(int sockfd, struct sockaddr_in *address) {
    int addrlen = sizeof(*address);
    int new_socket = accept(sockfd, (struct sockaddr *)address, (socklen_t*)&addrlen);
    if(new_socket < 0) {
        error_exit("accept failed");
    }
    return new_socket;
}

void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE] = {0};
    char *hello = "Hello from server";
    read(client_socket, buffer, BUFFER_SIZE);
    printf("Message from client: %s\n", buffer);
    send(client_socket, hello, strlen(hello), 0);
    printf("Hello message sent\n");
}

int main(int argc, char const *argv[]) {
    int port = (argc > 1) ? atoi(argv[1]) : DEFAULT_PORT;
    int server_fd;
    struct sockaddr_in address;

    server_fd = create_socket();
    bind_socket(server_fd, &address, port);
    start_listening(server_fd);

    printf("Server listening on port %d\n", port);

    while(1) {
        int client_socket = accept_connection(server_fd, &address);
        handle_client(client_socket);
        close(client_socket);
    }

    close(server_fd);
    return 0;
}