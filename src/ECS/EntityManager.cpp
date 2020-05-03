#include "EntityManager.hpp"

EntityManager::EntityManager() {
  for (Entity entity = 0; entity < MAX_ENTITYS; entity ++) {
    mEntities.push(entity);
  }
}

Entity EntityManager::createEntity() {
  assert(mEntityCount < MAX_ENTITYS);

  Entity id = mEntities.front();
  mEntities.pop();
  mEntityCount ++;

  return id;
}

void EntityManager::destroyEntity(Entity entity) {
  assert(entity < MAX_ENTITYS);

  mSignatures[entity].reset();
  mEntities.push(entity);
  mEntityCount --;
}

void EntityManager::setSignature(Entity entity, Signature signature) {
  assert(entity < MAX_ENTITYS);

  mSignatures[entity] = signature;
}

Signature EntityManager::getSignature(Entity entity) {
  assert(entity < MAX_ENTITYS);

  return mSignatures[entity];
}
