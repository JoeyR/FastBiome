// Copyright(c) 2021-present JoeyR
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#include <iostream>

#include "FastBiome/FastBiome.h"

int main() {
  // precipitation -> (0,45)
  int precipitation_m(0);

  // temperature -> (-15,30)
  int temperature_c(0);

  auto biome = FastBiome::GetWhittakerBiome(precipitation_m, temperature_c);

  if (biome) {
    std::cout << "Found Biome: " << std::to_string(*biome) << std::endl;
  } else {
    std::cout << "Could not find biome for input: " << std::endl;
    std::cout << " Precipitation: " << precipitation_m << std::endl;
    std::cout << " Temperature: " << temperature_c << std::endl;
  }
}