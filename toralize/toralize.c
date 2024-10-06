#include "toralize.h"
#include <stddef.h>

Req *request(const char *dstip, const int dstport){
    Req *req;
    req = malloc(reqsize);
    req->vn = 4;
    req->cd = 1;
    req->dstport = htons(dstport);
    req->dstip = inet_addr(dstip);
    memset(req->userid, 0x00, sizeof(req->userid));

    return req;
}

int main(int argc, char *argv[]){
    int port, s;
    char *host;
    struct sockaddr_in sock;
    Req *req;
    Res *res;
    int success;

    char buff[ressize];
    char tmp[512];

    host = argv[1];
    port = atoi(argv[2]);

    if( argc < 3 ){
        fprintf(stderr, "usage: %s <host> <port>\n", argv[0]);
        return -1;
    }
    printf("Recived inputs\n\thost: %s, port: %d\n", host, port);
    
    s = socket(AF_INET, SOCK_STREAM, 0);
    if (s < 0){
        perror("Socket");
        return -1;
    }

    sock.sin_family = AF_INET;
    sock.sin_port = htons(PROXYPORT);
    sock.sin_addr.s_addr = inet_addr(PROXY);

    if (connect(s, (struct sockaddr *)&sock, sizeof(sock)) < 0 ){
        perror("connect");
        return -1;
    } 

    printf("connected to the proxy...\n");

    // req = request(host, port);
    // if ( write(s, req, reqsize) < reqsize)
    // {
    //     perror("write");
    //     free(req);
    //     close(s);
    //     return -1;
    // }
    // Prepare SOCKS4 request
    char socks_request[9]; // 8 bytes for the request + 1 for the user ID
    socks_request[0] = 0x04; // SOCKS version
    socks_request[1] = 0x01; // Command: CONNECT
    // socks_request[2] = (port >> 8) & 0xFF; // Port high byte
    // socks_request[3] = port & 0xFF; // Port low byte
    uint32_t pooo = htons(port);
    memcpy(&socks_request[2], &pooo, sizeof(pooo));
    uint32_t ip_addr = inet_addr(host);
    memcpy(&socks_request[4], &ip_addr, sizeof(ip_addr)); // Destination IP
    socks_request[8] = 0x00; // Null-terminated user ID
// Send SOCKS4 request
    if (write(s, socks_request, sizeof(socks_request)) < sizeof(socks_request)) {
        perror("write");
        close(s);
        return -1;
    }
    // ensure buffer is empty

    memset(buff, 0, ressize);
    if ( read(s, buff, ressize) < 0)
    {
        perror("read");
        free(req);
        close(s);
        return -1;
    }

    res = (Res *)buff;
    success = (res->cd == 90);
    if(!success){
        fprintf(stderr, "Read failed");
        free(req);
        close(s);
        return -1;
    }
    printf("Successfully connected to the proxy to %s:%d\n",host, port);

    

    memset(tmp, 0, 512);
    snprintf(tmp, 511,  
        "GET / HTTP/1.1\r\n"
        "Host: 199.185.178.80\r\n"
        "User-Agent: curl/8.7.1\r\n"
        "Accept: */*\r\n"
        "\r\n"
        );
    write(s, tmp, 512);
    memset(tmp, 0, 512);

    read(s, tmp, 511);
    printf("'%s'\n", tmp);

    // free(req);
    close(s);
    return 0;
}