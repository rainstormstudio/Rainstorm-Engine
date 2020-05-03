#include "ECS.hpp"

void ECS::init() {
  mComponentManager = std::make_unique<ComponentManager>();
  mEntityManager = std::make_unique<EntityManager>();
  mSystemManager = std::make_unique<SystemManager>();
}

// Entity methods
Entity ECS::createEntity() {
  return mEntityManager->createEntity();
}

void ECS::DestroyEntity(Entity entity) {
  mEntityManager->destroyEntity(entity);
  mComponentManager->entityDestroyed(entity);
  mSystemManager->entityDestroyed(entity);
}

// Component methods
template<class T>
void ECS::registerComponent() {
  mComponentManager->registerComponent<T>();
}

template<class T>
void ECS::addComponent(Entity entity, T component) {
  mComponentManager->addComponent<T>(entity, component);
  auto signature = mEntityManager->getSignature(entity);
  signature.set(mComponentManager->getComponentType<T>(), true);
  mEntityManager->setSignature(entity, signature);
  mSystemManager->entitySignatureChanged(entity, signature);
}

template<class T>
void ECS::removeComponent(Entity entity) {
  mComponentManager->removeComponent<T>(entity);
  auto signature = mEntityManager->getSignature(entity);
  signature.set(mComponentManager->getComponentType<T>(), false);
  mEntityManager->setSignature(entity, signature);
  mSystemManager->entitySignatureChanged(entity, signature);
}

template<class T>
T& ECS::getComponent(Entity entity) {
  return mComponentManager->getComponent<T>(entity);
}

template<class T>
ComponentType ECS::getComponentType() {
  return mComponentManager->getComponentType<T>();
}

// System methods
template<class T>
std::shared_ptr<T> ECS::registerSystem() {
  return mSystemManager->registerSystem<T>();
}

template<class T>
void ECS::setSystemSignature(Signature signature) {
  mSystemManager->setSignature<T>(signature);
}
