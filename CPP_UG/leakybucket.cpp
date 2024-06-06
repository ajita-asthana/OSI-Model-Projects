#include <iostream>
#include <queue>
#include <thread>
#include <chrono>

class LeakyBucket {

private: 
    int capacity;
    int leakRate;
    int currentSize; 
    std::queue<int> packetQueue;

public:
    LeakyBucket(int capacity, int leakRate) :
        capacity(capacity), leakRate(leakRate), currentSize(0) 
        {}

    void addPacket(int packetSize) {
        if(currentSize + packetSize <= capacity) {
            packetQueue.push(packsetSize);
            currentSize += packetSize;
            std::cout << "Packet of size " << packetSize << endl;
            std::cout << " added. Current bucket size: " << currentSize << endl;
        } else {
            std::cout << "Packet of size " << packetSize << " dropped" << endl;
        }
    }

    void processPackets() {
        while(true) {
            std::this_thread::sleep_for(std::chrono::seconds(1));
            if(!packetQueue.empty()) {
                int packetSize = packetQueue.front();
                packetQueue.pop();
                currentSize -= packetSize;
                std::cout << "Processed packet of size " << packetSize <<
                ". Current bucket size: " << currentSize << endl;
            }
        }
    }
};

int main() {
    LeakyBucket lb(10, 1); //Bucket capacity of 10 units, and leak is 1 unit per second

    //Simulate packet arrivals
    lb.addPacket(4);
    lb.addPacket(5);
    lb.addPacket(2);
    lb.addPacket(3);
    lb.addPacket(1);

    //Process packets
    std::thread processor(&LeakyBucket::processPackets, &lb);

    //Simulate more packet arrivals
    std::this_thread::sleep_for(std::chrono::seconds(3));
    lb.addPacket(6);
    lb.addPacket(7);

    processor.join();
    return 0;
}