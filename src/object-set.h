#ifndef INKSCAPE_PROTOTYPE_OBJECTSET_H
#define INKSCAPE_PROTOTYPE_OBJECTSET_H

#include <boost/multi_index_container.hpp>
#include <boost/multi_index/identity.hpp>
#include <boost/multi_index/random_access_index.hpp>
#include <boost/range/adaptor/filtered.hpp>
#include <boost/range/adaptor/transformed.hpp>
#include <boost/range/any_range.hpp>
#include "sp-object.h"
#include "sp-item.h"

struct random_access{};

struct is_item {
    bool operator()(SPObject* obj) {
        return SP_IS_ITEM(obj);
    }
};

struct object_to_item {
    typedef SPItem* result_type;
    SPItem* operator()(SPObject* obj) const {
        return SP_ITEM(obj);
    }
};

typedef boost::multi_index_container<
        SPObject*,
        boost::multi_index::indexed_by<
                boost::multi_index::random_access<
                        boost::multi_index::tag<random_access>>
        >> multi_index_container;

typedef boost::any_range<
        SPObject*,
        boost::random_access_traversal_tag,
        SPObject* const&,
        std::ptrdiff_t> SPObjectRange;

typedef boost::any_range<
        SPItem*,
        boost::bidirectional_traversal_tag,
        SPItem* const&,
        std::ptrdiff_t> SPItemRange;

class ObjectSet {
public:
    ObjectSet() {};
    virtual ~ObjectSet();
//    typedef decltype(multi_index_container().get<random_access>() | boost::adaptors::filtered(is_item()) | boost::adaptors::transformed(object_to_item())) SPItemRange;
    bool add(SPObject* object);

    SPObjectRange objects() {
        return SPObjectRange(container.get<random_access>().begin(), container.get<random_access>().end());
    };

    SPItemRange items() {
        return SPItemRange(container.get<random_access>()
           | boost::adaptors::filtered(is_item())
           | boost::adaptors::transformed(object_to_item()));
    };

protected:
    multi_index_container container;
};

#endif //INKSCAPE_PROTOTYPE_OBJECTSET_H
