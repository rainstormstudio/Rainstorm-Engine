#pragma once
#include "ComponentManager.hpp"
#include "EntityManager.hpp"
#include "SystemManager.hpp"
#include "Core.hpp"
#include <memory>

class ECS {
private:
  std::unique_ptr<ComponentManager> mComponentManager;
  std::unique_ptr<EntityManager> mEntityManager;
  std::unique_ptr<SystemManager> mSystemManager;

public:
  void init();

  // Entity methods
  Entity createEntity();
  void DestroyEntity(Entity entity);

  // Component methods
  template<typename T>
  void registerComponent();

  template<typename T>
  void addComponent(Entity entity, T component);

  template<typename T>
  void removeComponent(Entity entity);

  template<typename T>
  T& getComponent(Entity entity);

  template<typename T>
  ComponentType getComponentType();

  // System methods
  template<typename T>
  std::shared_ptr<T> registerSystem();

  template<typename T>
  void setSystemSignature(Signature signature);
};
