#include <netinet/in.h>

struct sockaddr_in addr;
addr.sin_family = AF_INET;
addr.sin_port = htons(port);
addr.sin_addr.s_addr = htnol(INADDR_ANY);