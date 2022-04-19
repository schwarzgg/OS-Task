/*
gcc pc-sem.c -O2 -lpthread && ./a.out num;
*/
#include "thread.h"
#include "thread-sync.h"

sem_t fill, empty;

void Cal(){
    //do somehting
}

void Print(){
  // do something
}

void producer() {
  while (1) {
    P(&empty);
    Cal();
    V(&fill);
  }
}

void consumer() {
  while (1) {
    P(&fill);
    Print();
    V(&empty);
  }
}

int main(int argc, char *argv[]) {
  assert(argc == 2);
  SEM_INIT(&fill, 0);
  SEM_INIT(&empty, atoi(argv[1]));

  for (int i=0;i<8;i++)
  {
    create(producer);
    create(consumer);
  }
}
