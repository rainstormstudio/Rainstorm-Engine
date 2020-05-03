#pragma once
#include "ECS.hpp"
#include <array>
#include <cassert>
#include <unordered_map>

class IComponentArray {
public:
  virtual ~IComponentArray() = default;
  virtual void entityDestroyed(Entity entity) = 0;
};

template<typename T>
class ComponentArray : public IComponentArray {
private:
  std::array<T, MAX_ENTITYS> mComponentArray{};
  std::unordered_map<Entity, size_t> mEntityToIndexMap{};
  std::unordered_map<size_t, Entity> mIndexToEntityMap{};
  size_t mSize{};

public:
  void insertData(Entity entity, T component);
  void removeData(Entity entity);
  T& getData(Entity entity);
  void entityDestroyed(Entity entity) override;
};
