#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define BUF_SIZE 1024

void check_error(int status) {
	if (status < 0) {
		printf("Socket error: [%s]\n", strerror(errno));
		exit(-1);
	}
}

int main() {
	char ans[BUF_SIZE];
	int sid = socket(PF_INET, SOCK_STREAM, 0);
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(8080);
	addr.sin_addr.s_addr = INADDR_ANY;
	
	int status = bind(sid, (struct sockaddr*)&addr, sizeof(addr));
	check_error(status);

	status = listen(sid, 10);
	check_error(status);

	while (1) {
		struct sockaddr_in client;
		socklen_t client_size;
		int chat_socket = accept(sid, (struct sockadr*)&client, &client_size);
		checkerror(status);
		printf("Socket accepted: %d\n", chat_socket);
		int rv = recv_lines(chat_socket, ans, BUF_SIZE);
		printf("Received message: %s\n", ans);
		close(chat_socket);
	}
}
