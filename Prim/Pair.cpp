#include "Pair.h"

Pair::Pair(int p, int v) :priority(p), value(v) {}
int Pair::getPriority() { return priority; }
int Pair::getValue() { return value; }
