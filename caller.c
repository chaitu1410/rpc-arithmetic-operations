#include<stdio.h>
#include<rpc/rpc.h>
#include<stdlib.h>
#include<rpc/xdr.h>
#include "./structure.h"

int main(int argc, char *argv[]) {
	CLIENT *cl;
	char *server;
	long *lres;
	if (argc != 2) {
		fprintf(stderr, "usage: %s hostname\n", argv[0]);
		exit(1);
	}
	server = argv[1];
	
	if ((cl = clnt_create(server, FUNCTIONSVERS, FUNCTIONSVERS, "udp")) == NULL) {
		printf("can't establish connection with host %s\n", server);
		exit(2);
	}
	
	if (( lres = add_1(1, 2, cl)) == NULL){
		printf("remote procedure bindate() failure\n");
		exit(3);
	}
	printf("time on host %s = %ld\n", server, *lres);
	clnt_destroy(cl);
	return 0;
}
