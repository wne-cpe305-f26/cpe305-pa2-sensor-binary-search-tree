#include "sensor_tree.hpp"

#include <cstdlib>
#include <iostream>
#include <string_view>
#include <vector>

namespace {

void require(bool condition, std::string_view message) {
    if (!condition) {
        std::cerr << "FAILED: " << message << '\n';
        std::exit(1);
    }
}

void test_empty_tree() {
    SensorTree tree;
    require(tree.size() == 0, "empty tree has size zero");
    require(tree.find(10) == nullptr, "empty lookup returns nullptr");
    require(tree.readings_in_order().empty(), "empty traversal returns no readings");
}

void test_insert_find_and_order() {
    SensorTree tree;
    tree.insert_or_update({40, 4.0});
    tree.insert_or_update({10, 1.0});
    tree.insert_or_update({70, 7.0});
    tree.insert_or_update({25, 2.5});

    require(tree.size() == 4, "four distinct IDs create four nodes");
    require(tree.find(25) != nullptr, "present ID is found");
    require(tree.find(25)->value == 2.5, "found reading has the stored value");
    require(tree.find(99) == nullptr, "absent ID is not found");

    const std::vector<SensorReading> expected{
        {10, 1.0}, {25, 2.5}, {40, 4.0}, {70, 7.0}};
    require(tree.readings_in_order() == expected,
            "inorder traversal returns increasing IDs");
}

void test_update_preserves_size() {
    SensorTree tree;
    tree.insert_or_update({8, 1.25});
    tree.insert_or_update({8, 9.75});

    require(tree.size() == 1, "updating an ID does not change size");
    require(tree.find(8)->value == 9.75, "update replaces the stored value");
}

}  // namespace

void run_supplied_tests() {
    test_empty_tree();
    test_insert_find_and_order();
    test_update_preserves_size();
}
