/***************************************************************
 * Copyright (C) 2020
 *    Reshetnyak Ivan
 ***************************************************************/

#pragma once

class lcg {
public:
  lcg( long long Seed, long long Modulus, long long Increment );
  long long Next();
  lcg & Reseed( long long NewSeed );
  lcg & Reset();

protected:
  long long Modulus, Multiplier, Increment, Value, Seed;
};
