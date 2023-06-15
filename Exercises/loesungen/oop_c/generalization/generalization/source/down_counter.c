#include "source/down_counter.h"

static DownCounter *this;

static void count() { this->base.count(-1); }

void DownCounter_Init(DownCounter *self, int lower_limit, int upper_limit) {
    this = self;
    Counter_Init(&this->base);
    this->count = count;
    this->base.initLimits(lower_limit, upper_limit);
    this->base.value = self->base.checker.getUpperLimit();
}

