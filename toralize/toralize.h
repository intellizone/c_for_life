#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdlib.h>

#define PROXY "127.0.0.1"
#define PROXYPORT 9050
#define reqsize sizeof(struct proxy_request)
#define ressize sizeof(struct proxy_response)
#define USERNAME "toraliz"


typedef unsigned char       int8;
typedef unsigned short int  int16;
typedef unsigned long int   int32;


/*
                +----+----+----+----+----+----+----+----+----+----+....+----+
                | VN | CD | DSTPORT |      DSTIP        | USERID       |NULL|
                +----+----+----+----+----+----+----+----+----+----+....+----+
 # of bytes:	   1    1      2              4           variable       1
*/

struct proxy_request{
    int8 vn;
    int8 cd;
    int16 dstport;
    int32 dstip;
    int8 userid[64];
} __attribute__((packed));

typedef struct proxy_request Req;

/*
                +----+----+----+----+----+----+----+----+
                | VN | CD | DSTPORT |      DSTIP        |
                +----+----+----+----+----+----+----+----+
 # of bytes:	   1    1      2              4
*/

struct proxy_response{
    int8 vn;
    int8 cd;
    int16 _;
    int32 __;
} __attribute__((packed));

typedef struct proxy_response Res;


Req *request(const char*, const int);
int main(int, char**);