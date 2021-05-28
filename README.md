# FastBiome

Constant time function to return an enumerated biome based on [Whittaker Biome Types](https://en.wikipedia.org/wiki/Biome#Whittaker_(1962,_1970,_1975)_biome-types).

The Whittaker Biome Type is determined by:
1. Annual Precipitiation
2. Average Temperature


## Parameters

```c++
GetWhittakerBiome(int precipitation_dm, int temperature_c);
```

Valid values for precipitation are in decimeters from 0 to 45, and temperature in celsius from -15 to 30.

The underlying data structure is a compile-time 2D array which is filled with integers that correspond to an enumerated biome.

If the value is 0, there is no biome associated with it, and it will return an empty optional.


## Usage

```c++
#include <iostream>

#include "FastBiome/FastBiome.h"

int main() {
  // precipitation -> (0,45)
  int precipitation_dm(20);

  // temperature -> (-15,30)
  int temperature_c(15);

  auto biome = FastBiome::GetWhittakerBiome(precipitation_dm, temperature_c);

  if (biome) {
    // returned value is associated with the FastBiome::whittaker::biome_name enumeration.
    std::cout << "Found Biome: " << *biome << std::endl;
  } else {
    std::cout << "Could not find biome for input: " << std::endl;
    std::cout << " Precipitation: " << precipitation_m << std::endl;
    std::cout << " Temperature: " << temperature_c << std::endl;
  }
}
```

---

## Disclaimer

This library is untested!

The calculated biome is an approximation. I noticed that both axes on the graph are around 45 units, which fits well into a 2d array. So I discretized it by overlaying the existing graph onto a 45x45 grid and noting the biome at each cell. This also means that for half of the graph there is no biome. I'm not really sure how to deal with that besides an optional value. This could potentially be solved by returning the closest value diagonally, or closest by temperature, or closest by precipitation. Any input would be appreciated!

I don't currently plan on adding any more biome models, but who knows.
