#include "List.hpp"

#include <stdio.h>

void setup() {
  // Serial.begin(9600);
}

int comp(const void *elem1, const void *elem2) {
  int f = *((int *)elem1);
  int s = *((int *)elem2);
  if (f > s)
    return 1;
  if (f < s)
    return -1;
  return 0;
}

typedef struct {
  int i;
} i_t;

List<i_t> l, f;
void loop() {

  int s = 12313;
  l.add(*(new i_t{.i = 8}));
  for (int i = 0; i < l.getSize(); ++i) {
    // Serial.println(l.getValue(i));
    // Serial.flush();
    printf("%d\n", l.getValue(i).i);
  }

  //bool t = l != f;
  //printf("%i\n", t);
}

int main() {
  setup();

  for (int i = 0; i != 1; i++) {
    loop();
  }
}