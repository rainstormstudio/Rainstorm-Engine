#include "SystemManager.hpp"

template<class T>
std::shared_ptr<T> SystemManager::registerSystem() {
  const char* typeName = typeid(T).name();
  assert(mSystems.find(typeName) == mSystems.end());

  auto system = std::make_shared<T>();
  mSystems.insert({typeName, system});
  return system;
}

template<class T>
void SystemManager::setSignature(Signature signature) {
  const char* typeName = typeid(T).name();
  assert(mSystems.find(typeName) != mSystems.end());
  mSignatures.insert({typeName, signature});
}

void SystemManager::entityDestroyed(Entity entity) {
  for (auto const& pair : mSystems) {
    auto const& system = pair.second;
    system->mEntities.erase(entity);
  }
}

void SystemManager::entitySignatureChanged(Entity entity, Signature entitySignature) {
  for (auto const& pair : mSystems) {
    auto const& type = pair.first;
    auto const& system = pair.second;
    auto const& systemSignature = mSignatures[type];

    if ((entitySignature & systemSignature) == systemSignature) {
      system->mEntities.insert(entity);
    } else {
      system->mEntities.erase(entity);
    }
  }
}
