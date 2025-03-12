#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <chrono>

class RoboticArm {
public:
    RoboticArm() : joint_positions({0.0, 0.0}) {}

    // Function to move joints
    void move_joints(double joint1_delta, double joint2_delta) {
        std::lock_guard<std::mutex> lock(joint_mutex); // Protect shared data
        joint_positions[0] += joint1_delta;
        joint_positions[1] += joint2_delta;
    }

    // Function to simulate movement (runs in a separate thread).this separate thread continuously prints joint positions every 500ms.std::thread runs simulate_motion() independently.
    void simulate_motion() {
        while (running) {
            {
                std::lock_guard<std::mutex> lock(joint_mutex);//Uses std::mutex (std::lock_guard) to avoid race conditions.Ensures safe updates to joint positions.
                std::cout << "Joint 1: " << joint_positions[0] 
                          << " | Joint 2: " << joint_positions[1] << std::endl;
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(500)); // Update every 500ms
        }
    }

    // Start simulation in a separate thread
    void start() {
        running = true;
        sim_thread = std::thread(&RoboticArm::simulate_motion, this);
    }

    // Stop simulation
    void stop() {
        running = false;
        if (sim_thread.joinable()) {
            sim_thread.join();
        }
    }

private:
    std::vector<double> joint_positions;
    std::mutex joint_mutex;
    std::thread sim_thread;
    bool running = false;
};

int main() {
    RoboticArm arm;
    arm.start(); // Start simulation

    // Simulate joint movement (user input). This part is the  user-driven motion in robotic_arm.cpp file which is a console-based interactive control system in C++.his means the program:-
    //✅ Takes user input dynamically
    // ✅ Applies the input to update joint positions
    //✅ Uses multithreading to show continuous joint motion
    for (int i = 0; i < 5; i++) {
        double j1, j2;
        std::cout << "Enter joint movements (J1 J2): ";
        std::cin >> j1 >> j2;//user enters values (e.g., 0.1, -0.2)
        arm.move_joints(j1, j2);//Updates the joint positions
    }

    arm.stop(); // Stop simulation
    return 0;
}
