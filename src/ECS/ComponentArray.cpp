#include "ComponentArray.hpp"

template<class T>
void ComponentArray<T>::insertData(Entity entity, T component) {
  assert(mEntityToIndexMap.find(entity) == mEntityToIndexMap.end());

  size_t newIndex = mSize;
  mEntityToIndexMap[entity] = newIndex;
  mIndexToEntityMap[newIndex] = entity;
  mComponentArray[newIndex] = component;
  mSize ++;
}

template<class T>
void ComponentArray<T>::removeData(Entity entity) {
  assert(mEntityToIndexMap.find(entity) != mEntityToIndexMap.end());

  size_t indexOfRemovedEntity = mEntityToIndexMap[entity];
  size_t indexOfLastElement = mSize - 1;
  mComponentArray[indexOfRemovedEntity] = mComponentArray[indexOfLastElement];

  Entity entityOfLastElement = mIndexToEntityMap[indexOfLastElement];
  mEntityToIndexMap[entityOfLastElement] = indexOfRemovedEntity;
  mIndexToEntityMap[indexOfRemovedEntity] = entityOfLastElement;

  mEntityToIndexMap.erase(entity);
  mIndexToEntityMap.erase(indexOfLastElement);

  mSize --;
}

template<class T>
T& ComponentArray<T>::getData(Entity entity) {
  assert(mEntityToIndexMap.find(entity) != mEntityToIndexMap.end());

  return mComponentArray[mEntityToIndexMap[entity]];
}

template<class T>
void ComponentArray<T>::entityDestroyed(Entity entity) {
  if (mEntityToIndexMap.find(entity) != mEntityToIndexMap.end()) {
    removeData(entity);
  }
}
