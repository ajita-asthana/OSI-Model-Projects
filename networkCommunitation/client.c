#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include <arpa/inet.h>
#include <errno.h>

#define DEFAULT_PORT 8080
#define BUFFER_SIZE 1024

void error_exit(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

void connect_to_server(int socket_fd, const char *server_ip, int port) {
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);

    if(inet_pton(AF_INET, server_ip, &server_address.sin_addr) <= 0) {
        fprintf(stderr, "Invalid address/ Address not supported\n");
        exit(1);
    }

    if(connect(socket_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        fprintf(stderr, "Connection failed: %s\n", strerror(errno));
        exit(1);
    }
}

void communicate_with_server(int socket_fd, struct timeval start, struct timeval end) {
    char buffer[BUFFER_SIZE] = {0};
    char *hello = "Hello from client";

    gettimeofday(&start, NULL);
    send(socket_fd, hello, strlen(hello), 0);
    printf("Hello message sent\n");
    int bytes_read = read(socket_fd, buffer, BUFFER_SIZE);
    printf("Message from server: %s\n", buffer);
    gettimeofday(&end, NULL);
}

int create_socket() {
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(socket_fd == 0) {
        fprintf(stderr, "Socket creation failed: %s\n", strerror(errno));
        exit(1);
    }
    return socket_fd;
}

double calculate_rtt(struct timeval start, struct timeval end) {
    return (double)(end.tv_usec - start.tv_usec) / 1000;
}

int main(int argc, char const *argv[]) {
    struct timeval start, end;
    const char *server_ip = "127.0.0.1";
    int port = (argc > 1) ? atoi(argv[1]) : DEFAULT_PORT;

    int socket_fd = create_socket();
    connect_to_server(socket_fd, server_ip, port);
    communicate_with_server(socket_fd, start, end);

    double rtt = calculate_rtt(start, end);
    printf("RTT: %.3f ms\n", rtt);
    close(socket_fd);

    return 0;
}