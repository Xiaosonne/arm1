#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <errno.h>
#define nil NULL

void *proc(void *par)
{
    char *buf = "111222333";
    int err;
    int errlen = 0;
    socklen_t slen=4;
    int soc = socket(AF_INET, SOCK_DGRAM, 0);
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr("192.168.1.255");
    addr.sin_port = htons(7070);
    int canBroadcast=1;
    setsockopt(soc, SOL_SOCKET, SO_BROADCAST, &canBroadcast, slen);
    const struct sockaddr *paddr = (const struct sockaddr *)&addr;
    while (1)
    {
        time_t tm=time(0);
        size_t sended = sendto(soc, buf, strlen(buf), 0, paddr, sizeof(addr));
        getsockopt(soc, SOL_SOCKET, SO_ERROR, &err, &slen);
        printf("thread %d socket:%d send:%d soerr:%s err:%s\r\n",tm, soc, sended,strerror(err),strerror(errno));
        sleep(1);
    }
    return nil;
}
int main(int argn, char *args[])
{
    printf("hello world\r\n");
    pthread_t thread1;
    pthread_create(&thread1, nil, proc, nil);
    getchar();
    return 0;
}
