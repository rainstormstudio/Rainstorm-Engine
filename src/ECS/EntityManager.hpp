#pragma once
#include "Core.hpp"
#include <array>
#include <queue>
#include <cassert>

class EntityManager {
private:
  std::queue<Entity> mEntities{};
  std::array<Signature, MAX_ENTITYS> mSignatures{};
  uint32_t mEntityCount{};
public:
  EntityManager();

  Entity createEntity();
  void destroyEntity(Entity entity);
  void setSignature(Entity entity, Signature signature);
  Signature getSignature(Entity entity);
};

