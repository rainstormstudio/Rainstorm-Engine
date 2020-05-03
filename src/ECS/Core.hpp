#pragma once
#include <bitset>

using Entity = std::uint32_t;
const Entity MAX_ENTITYS = 3000;
using ComponentType = std::uint8_t;
const ComponentType MAX_COMPONENTS = 32;
using Signature = std::bitset<MAX_COMPONENTS>;
