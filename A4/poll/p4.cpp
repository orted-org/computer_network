#include <stdio.h>
#include <iostream>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <string.h>
#include <poll.h>
#include <unistd.h>
using namespace std;

int main()
{
    mkfifo("/tmp/fifo4", 0777);
    int fd = open("/tmp/fifo4", O_RDWR);
    string s = "Message from P4";
    write(fd, s.c_str(), s.size() + 1);
    cout << "Exiting P4\n";
    close(fd);
    return 0;
}