#pragma once
#include "System.hpp"
#include "Core.hpp"
#include <cassert>
#include <memory>
#include <unordered_map>

class SystemManager {
private:
  std::unordered_map<const char*, Signature> mSignatures{};
  std::unordered_map<const char*, std::shared_ptr<System>> mSystems{};
  
public:
  template<typename T>
  std::shared_ptr<T> registerSystem();

  template<typename T>
  void setSignature(Signature signature);

  void entityDestroyed(Entity entity);

  void entitySignatureChanged(Entity entity, Signature entitySignature);
};

