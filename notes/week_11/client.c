#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
// #include "socketio.h"

#define BUF_SIZE 1024

void check_error(int status) {
	if (status < 0) {
		printf("Socket error: [%s]\n", strerror(errno));
		exit(-1);
	}
}

int main() {
	char guess[BUF_SIZE];
	fgets(guess, BUF_SIZE, stdin);
	strcar(guess, "\n");

	int sid = socket(PF_INET, SOCK_STREAM, 0);

	struct sockaddr_in srv;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(8080);

	struct hostent* server = gethostbyname("localhost");
	memcpy(&srv.sin_addr.s_addr, server->h_addr, server->h_length);
	
	int status = connect(sid, (struct sockaddr*)&srv, sizeof(srv));
	check_error(status);

	int rv = send_str(sid, guess);
	check_error(status);
	return 0;
}
