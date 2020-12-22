/***************************************************************
 * Copyright (C) 2020
 *    Reshetnyak Ivan
 ***************************************************************/

#include "lcg.h"

lcg::lcg( long long Seed, long long Modulus, long long Increment ) :
    Modulus(Modulus), Increment(Increment) {
  Reseed(Seed);
}


long long lcg::Next() {
  return Value = (Multiplier * Value + Increment) % Modulus;
}


lcg & lcg::Reseed( long long NewSeed ) {
  Seed = NewSeed;
  return Reset();
}


lcg & lcg::Reset() {
  Value = Seed;
  return *this;
}
