#include "source/up_counter.h"

static UpCounter *this;

static void count() { this->base.count(1); }

void UpCounter_Init(UpCounter *const self, const int lower_limit, const int upper_limit) {
    this = self;
    this->count = count;
    Counter_Init(&this->base);
    this->base.initLimits(lower_limit, upper_limit);
}
