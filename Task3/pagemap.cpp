#include <bits/stdc++.h>
#include <fcntl.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
typedef long long ll;
using namespace std;

void mem_addr(ll addr, ll *pt) {
  int size = getpagesize();

  ll page = addr / size;
  ll offset = page * sizeof(uint64_t);
  ll page_offset = addr % size;
  
  uint64_t item = 0;

  int fd = open("/proc/self/pagemap", O_RDONLY);
  if (fd == -1) {
    printf("open /proc/self/pagemap error\n");
    return;
  }

  if (lseek(fd, offset, SEEK_SET) == -1) {
    printf("sleek error\n");
    return;
  }

  if (read(fd, &item, sizeof(uint64_t)) != sizeof(uint64_t)) {
    printf("read item error\n");
    return;
  }

  if ((((uint64_t)1 << 63) & item) == 0) {
    printf("page present is 0\n");
    return;
  }

  uint64_t ph_page = (((uint64_t)1 << 55) - 1) & item;

  *pt = (ph_page * size) + page_offset;
}

const int a = 100;

int main() {
  int b = 100;
  static int c = 100;
  const int d = 100;
  char *str = "The Best!";

  ll ph = 0;

  char *p = (char *)malloc(100);

  int pid = fork();
  if (pid == 0) {
    mem_addr((ll)&a, &ph);
    printf("pid = %d, virtual addr = %x , physical addr = %x\n", getpid(), &a,
           ph);
  } else {
    mem_addr((ll)&a, &ph);
    printf("pid = %d, virtual addr = %x , physical addr = %x\n", getpid(), &a,
           ph);
  }

  usleep(1000);
  free(p);
  waitpid();
  return 0;
}
