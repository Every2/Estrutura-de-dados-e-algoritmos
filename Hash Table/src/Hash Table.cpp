#include <iostream>
#include <string>
#include <vector>
#include <memory>

struct KeyValue {
    std::string key;
    std::string value;
    std::shared_ptr<KeyValue> next;

    KeyValue(const std::string& k, const std::string& v) : key(k), value(v) {}
};

class HashTable {

public:
    HashTable(int size) : size_(size), table_(size, nullptr) {}
    

    unsigned int hash(const std::string& key) {
        unsigned int hash = 0;
        for (char c: key) {
            hash = (hash + c) %  size_;
        }
        return hash;
    }

    void insert(const std::string& key, const std::string& value) {
        unsigned int index = hash(key);

        std::shared_ptr<KeyValue> current = table_.at(index);
        while(current != nullptr) {
            if (current->key == key) {
                current->value = std::move(value);
                return;
            }
            current = current->next;
        }
        auto newNode = std::make_shared<KeyValue>(std::move(key), std::move(value));

        newNode->next = std::move(table_.at(index));
        table_.at(index) = std::move(newNode);
    }

    std::string lookup(const std::string& key) {
        unsigned int index = hash(key);

        std::shared_ptr<KeyValue> current = table_.at(index);
        while(current != nullptr) {
            if (current->key == key) {
                return current->value;
            }
            current = current->next;
        }

        return "Key not found";
    }
private:
    int size_;
    std::vector<std::shared_ptr<KeyValue>> table_;
};
