#include "gtest/gtest.h"
#include "../src/object-set.h"
#include "../src/sp-object.h"

TEST(RangeTest, Ranges) {
    ObjectSet* set = new ObjectSet();
    SPObject* x = new SPItem();
    SPObject* y = new SPItem();
    set->add(x);
    set->add(y);

    auto objs = set->objects();
    EXPECT_EQ(2, boost::distance(objs));
    EXPECT_NE(objs.end(), objs.begin());
    auto a = objs.front();
    auto b = objs.back();
    EXPECT_EQ(x, a);
    EXPECT_EQ(y, b);
    std::cout << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;

    auto items = set->items();
    EXPECT_EQ(++items.begin(), --items.end());
    EXPECT_EQ(2, boost::distance(items));
    EXPECT_NE(items.end(), items.begin());
    auto c = items.front();
    auto d = items.back();
    EXPECT_EQ(x, c);
    EXPECT_EQ(y, d);
    std::cout << std::endl;
    std::cout << c << std::endl;
    std::cout << d << std::endl;
//    EXPECT_EQ(nullptr, c->parent);
//    EXPECT_EQ(nullptr, d->parent);
}