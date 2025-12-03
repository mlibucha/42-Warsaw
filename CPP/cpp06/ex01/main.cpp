#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"

int main() {
    std::cout << "=== Serialization Test ===" << std::endl;
    
    // Create a Data object
    Data original(42, "Test Data", 3.14159);
    
    std::cout << "Original data: ";
    original.display();
    
    // Get the pointer
    Data* originalPtr = &original;
    std::cout << "Original pointer: " << originalPtr << std::endl;
    
    // Serialize the pointer
    uintptr_t serialized = Serializer::serialize(originalPtr);
    std::cout << "Serialized value: " << serialized << std::endl;
    
    // Deserialize back to pointer
    Data* deserializedPtr = Serializer::deserialize(serialized);
    std::cout << "Deserialized pointer: " << deserializedPtr << std::endl;
    
    // Test if pointers are equal
    std::cout << "\n=== Comparison Results ===" << std::endl;
    std::cout << "Pointers are equal: " 
              << (originalPtr == deserializedPtr ? "YES" : "NO") << std::endl;
    
    // Verify the data is intact
    std::cout << "Original data through deserialized pointer: ";
    deserializedPtr->display();
    
    std::cout << "Data is identical: " 
              << (original == *deserializedPtr ? "YES" : "NO") << std::endl;
    
    // Additional test with dynamic allocation
    std::cout << "\n=== Dynamic Allocation Test ===" << std::endl;
    Data* dynamicData = new Data(100, "Dynamic Data", 2.71828);
    
    std::cout << "Dynamic data: ";
    dynamicData->display();
    
    uintptr_t dynamicSerialized = Serializer::serialize(dynamicData);
    Data* dynamicDeserialized = Serializer::deserialize(dynamicSerialized);
    
    std::cout << "Dynamic pointers equal: " 
              << (dynamicData == dynamicDeserialized ? "YES" : "NO") << std::endl;
    std::cout << "Dynamic data intact: " 
              << (*dynamicData == *dynamicDeserialized ? "YES" : "NO") << std::endl;
    
    delete dynamicData;
    
    return 0;
}