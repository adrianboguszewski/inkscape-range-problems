#include "object-set.h"

bool ObjectSet::add(SPObject* object) {
    container.push_back(object);
    return true;
}

ObjectSet::~ObjectSet() {
}
