#include "ComponentManager.hpp"

template<class T>
std::shared_ptr<ComponentArray<T>> ComponentManager::getComponentArray() {
  const char* typeName = typeid(T).name();
  assert(mComponentTypes.find(typeName) != mComponentTypes.end());
  return std::static_pointer_cast<ComponentArray<T>>(mComponentArrays[typeName]);
}

template<class T>
void ComponentManager::registerComponent() {
  const char* typeName = typeid(T).name();
  assert(mComponentTypes.find(typeName) == mComponentTypes.end());

  mComponentTypes.insert({typeName, mNextComponentType});
  mComponentArrays.insert({typeName, std::make_shared<ComponentArray<T>>()});

  mNextComponentType ++;
}

template<class T>
ComponentType ComponentManager::getComponentType() {
  const char* typeName = typeid(T).name();
  assert(mComponentTypes.find(typeName) != mComponentTypes.end());
  return mComponentTypes[typeName];
}

template<class T>
void ComponentManager::addComponent(Entity entity, T component) {
  getComponentArray<T>()->insertData(entity, component);
}

template<class T>
void ComponentManager::removeComponent(Entity entity) {
  getComponentArray<T>()->removeData(entity);
}

template<class T>
T& ComponentManager::getComponent(Entity entity) {
  return getComponentArray<T>()->getData(entity);
}

void ComponentManager::entityDestroyed(Entity entity) {
  for (auto const& pair : mComponentArrays) {
    auto const& component = pair.second;
    component->entityDestroyed(entity);
  }
}
