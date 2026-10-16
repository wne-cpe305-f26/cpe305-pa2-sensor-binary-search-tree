#include "sensor_tree.hpp"

#include <iostream>

int main() {
    SensorTree tree;
    tree.insert_or_update({40, 18.5});
    tree.insert_or_update({12, 20.0});
    tree.insert_or_update({75, 17.25});

    for (const SensorReading& reading : tree.readings_in_order()) {
        std::cout << reading.sensor_id << ": " << reading.value << '\n';
    }
}
