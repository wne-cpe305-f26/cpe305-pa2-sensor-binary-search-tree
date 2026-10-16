#ifndef SENSOR_TREE_HPP
#define SENSOR_TREE_HPP

#include <cstddef>
#include <vector>

struct SensorReading {
    int sensor_id;
    double value;

    bool operator==(const SensorReading&) const = default;
};

struct SensorNode {
    SensorReading reading;
    SensorNode* left;
    SensorNode* right;
};

class SensorTree {
public:
    SensorTree() = default;
    ~SensorTree();

    SensorTree(const SensorTree&) = delete;
    SensorTree& operator=(const SensorTree&) = delete;

    void insert_or_update(SensorReading reading);
    const SensorReading* find(int sensor_id) const;
    std::vector<SensorReading> readings_in_order() const;
    std::size_t size() const;

private:
    SensorNode* root_ = nullptr;
    std::size_t size_ = 0;
};

#endif
