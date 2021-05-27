// Copyright(c) 2021-present JoeyR
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#include "whittaker.h"

namespace FastBiome {

std::optional<int> GetWhittakerBiome(int precipitation, int temperature) {
  auto prec(whittaker::AdjustPrecipitationToPosition(precipitation));
  auto temp(whittaker::AdjustTemperatureToPosition(temperature));

  if (temp == -1 || prec == -1) {
    // out of bounds, not sure what to do
    return {};
  }

  int new_biome(whittaker::whittaker_lookup_table[prec][temp]);

  if (new_biome > 0 && new_biome <= 9) {
    return whittaker::whittaker_lookup_table[prec][temp];
  } else {
    // garbage
    return {};
  }
}
}  // namespace FastBiome