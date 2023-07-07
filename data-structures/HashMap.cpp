#include <iostream>
#include <unordered_map>
#include <string>

int main() {
    // Create an unordered_map with string keys and integer values
    std::unordered_map<std::string, int> hashMap;

    // Insert elements into the hash map
    hashMap["apple"] = 0;
    hashMap["banana"] = 5;
    hashMap["orange"] = 15;

    // Access elements in the hash map
    std::cout << "Value of apple: " << hashMap["apple"] << std::endl;
    std::cout << "Value of banana: " << hashMap["banana"] << std::endl;
    std::cout << "Value of orange: " << hashMap["orange"] << std::endl;

    // Check if a key exists in the hash map
    if (hashMap.count("apple") > 0) {
        std::cout << "apple exists in the hash map" << std::endl;
    }

    // Modify the value associated with a key
    hashMap["banana"] = 7;
    std::cout << "Updated value of banana: " << hashMap["banana"] << std::endl;

    // Remove an element from the hash map
    hashMap.erase("orange");

    // Iterate over the hash map
    for (const auto& pair : hashMap) {
        std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
    }

    return 0;
}
