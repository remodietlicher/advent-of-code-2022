#include "./swap.h"

namespace my_util {

void swap(int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

}  // namespace my_util
