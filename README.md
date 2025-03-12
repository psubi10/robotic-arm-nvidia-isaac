# robotic-arm-nvidia-isaac
# Multi-Threaded Robotic Arm Simulation with NVIDIA Isaac Sim & C++

This project showcases a **real-time robotic arm simulation** using **C++ multithreading, URDF, and NVIDIA Isaac Sim**. Designed as a showcase for **NVIDIA careers**, it demonstrates **multi-threaded control, ROS 2 integration, and physics-based simulation**.

---

## 🔹 Key Features
✅ **Multi-Threaded Control** (`std::thread`, `std::mutex`) for real-time motion  
✅ **URDF-Based Robotic Arm** (Loads into NVIDIA Isaac Sim)  
✅ **C++ Motion Simulation** with user input & dynamic updates  
✅ **Isaac Sim API Integration** (Realistic physics for robotic arm)  
✅ **Future Expansion** (Reinforcement Learning, Synthetic Data Generation)

---

## 🔹 Technologies Used
- 🛠️ **C++ (`std::thread`, `std::mutex`)**
- 🤖 **NVIDIA Isaac Sim (URDF importer)**
- 📡 **ROS 2 (`rclcpp`, `std_msgs`)**
- 🏗 **URDF (Unified Robot Description Format)**
- 🔄 **Parallel Processing & Thread Safety**

---

## 🔹 Repository Structure
```bash
📂 robotic-arm-nvidia-isaac
 ├── 📂 src
 │   ├── robotic_arm.cpp  # Multi-threaded robotic arm control
 │   ├── robotic_arm_ros2.cpp  # ROS 2 version for Isaac Sim
 │   ├── IsaacSimControl.cpp  # Direct Isaac Sim API control
 ├── 📂 urdf
 │   ├── robotic_arm.urdf  # Robotic arm description file
 ├── 📂 docs
 │   ├── README.md  # Full project documentation
 │   ├── setup_isaac_sim.md  # Step-by-step guide for Isaac Sim
 ├── 📂 assets
 │   ├── robotic_arm.usd  # Converted USD model for Omniverse
 ├── Dockerfile  # Optional Docker setup for Isaac Sim
 ├── LICENSE  # Open-source license
 ├── README.md  # Main project overview

Setup & Installation
1️⃣ Install NVIDIA Isaac Sim(Follow NVIDIA Isaac Sim Installation Guide.)
2️⃣ Load the Robotic Arm in Isaac Sim Sim-python -m omni.isaac.urdf.importer urdf/robotic_arm.urdf
3️⃣ Run the Multi-Threaded C++ Simulationg++ -std=c++11 -pthread src/robotic_arm.cpp -o robotic_arm
./robotic_arm
4️⃣ (Optional) Control Arm Using ROS 2
ros2 run robotic_arm robotic_arm_ros2

Step	Action
✅ Step 1	Convert C++ to URDF
✅ Step 2	Load URDF into Isaac Sim
✅ Step 3	Modify C++ to send Isaac Sim commands
✅ Step 4	Run C++ to move the arm in Isaac Sim


