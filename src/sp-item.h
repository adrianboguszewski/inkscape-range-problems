#ifndef SEEN_SP_ITEM_H
#define SEEN_SP_ITEM_H

#include "sp-object.h"

#define SP_ITEM(obj) (dynamic_cast<SPItem*>((SPObject*)obj))
#define SP_IS_ITEM(obj) (dynamic_cast<const SPItem*>((SPObject*)obj) != NULL)

class SPItem : public SPObject {
public:
    SPItem();
    virtual ~SPItem();

};

#endif // SEEN_SP_ITEM_H
