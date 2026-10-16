#include "sensor_tree.hpp"

SensorTree::~SensorTree() {
    // TODO: Delete every owned node exactly once, children before parent.
    static_cast<void>(root_);
}

void SensorTree::insert_or_update(SensorReading reading) {
    // TODO: Insert one node for a new ID or update the existing reading.
    static_cast<void>(reading);
}

const SensorReading* SensorTree::find(int sensor_id) const {
    // TODO: Search one branch at each step without modifying the tree.
    static_cast<void>(sensor_id);
    return nullptr;
}

std::vector<SensorReading> SensorTree::readings_in_order() const {
    // TODO: Return copies in strictly increasing sensor-ID order.
    return {};
}

std::size_t SensorTree::size() const {
    return size_;
}
