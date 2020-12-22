/***************************************************************
 * Copyright (C) 2020
 *    Reshetnyak Ivan
 ***************************************************************/

#include "lcg.h"

lcg::lcg( long long Seed, long long Modulus, long long Multiplier, long long Increment ) :
    Modulus(Modulus), Increment(Increment), Multiplier(Multiplier) {
  Reseed(Seed);
}


/*
lcg::lcg( long long N1, long long N2, long long N3, long long N4 ) {
  // N1 = (a * N0 + c) % m; Let Seed = N1
  // N2 = (a * N1 + c) % m <=> m * t1 + N2 = a * N1 + c; a = (m * t1 + N2 - c) / N1
  // N3 = (a * N2 + c) % m <=> m * t2 + N3 = a * N2 + c; c = m * t2 + N3 - a * N2
  // N4 = (a * N3 + c) % m <=> m * t3 + N4 = a * N3 + c; m = (a * N3 + c - N4) / t3
}
*/


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
