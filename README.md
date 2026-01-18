# Network Topology Simulations with NS-3

This project contains various network topology implementations using the NS-3 network simulator. Each topology demonstrates different network structures and their configurations for educational and research purposes.

## Project Overview

This collection includes implementations of common network topologies with visualization support through NetAnim. Each topology is configured with appropriate network parameters and generates XML animation files for visual representation.

## Available Topologies

### 1. Bus Topology (`bus-topo.cc`)
- **Description**: A linear bus network with 20 nodes connected to a shared medium
- **Technology**: CSMA (Carrier Sense Multiple Access)
- **Configuration**: 
  - Data Rate: 100 Mbps
  - Delay: 6560 nanoseconds
  - IP Range: 10.3.0.0/24
- **Output**: `bus-topo.xml`
- **Visualization**: `bus.png`, `buscode.png`

### 2. Star Topology (`star-topo.cc`)
- **Description**: Central hub with 15 spoke nodes in a star configuration
- **Technology**: Point-to-Point links
- **Configuration**:
  - Data Rate: 5 Mbps per link
  - Delay: 2ms
  - IP Range: 10.1.0.0/24 (each link on separate subnet)
- **Output**: `star-topo.xml`
- **Visualization**: `star1.png`, `starcode1.png`

### 3. Ring Topology (`ring-topo.cc`)
- **Description**: 16 nodes connected in a circular ring pattern
- **Technology**: Point-to-Point links
- **Configuration**:
  - Data Rate: 5 Mbps per link
  - Delay: 2ms
  - IP Range: 10.4.0.0/24 (each link on separate subnet)
- **Output**: `ring-topo.xml`
- **Visualization**: `ring.png`, `ring code.png`

### 4. Hybrid Topology (`hybrid-topo.cc`)
- **Description**: Combination of star and bus topologies with a central hub
- **Technology**: Mixed Point-to-Point and CSMA
- **Configuration**:
  - Star Links: 10 Mbps Point-to-Point
  - Bus Segment: 100 Mbps CSMA
  - IP Range: 10.5.0.0/24
- **Components**: 1 hub, 10 star nodes, 14 bus nodes
- **Output**: `hybrid-topo.xml`
- **Visualization**: `hybrid.png`, `hybridcode.png`

### 5. Tree Topology (`tree.cc`)
- **Description**: Hierarchical tree structure (similar to star but with tree positioning)
- **Technology**: Point-to-Point links
- **Configuration**:
  - Data Rate: 5 Mbps per link
  - Delay: 2ms
  - IP Range: 10.1.0.0/24
- **Components**: 1 root node, 15 child nodes
- **Output**: `star-topo.xml`

### 6. Point-to-Point Chain (`p2p-chain.xml`)
- **Description**: Linear chain of point-to-point connected nodes
- **Configuration**: XML-based topology definition
- **Visualization**: `p2p1 pic.png`, `p2p1.png`

## Prerequisites

- NS-3 Network Simulator (version 3.29 or later recommended)
- NetAnim (Network Animator) for visualization
- C++ compiler (GCC or Clang)
- CMake build system

## Installation and Setup

1. **Install NS-3**:
   ```bash
   # Download and extract NS-3
   wget https://www.nsnam.org/releases/ns-3.35.tar.bz2
   tar xjf ns-3.35.tar.bz2
   cd ns-3.35
   
   # Configure and build
   ./ns3 configure --enable-examples --enable-tests
   ./ns3 build
   ```

2. **Install NetAnim** (if not included):
   ```bash
   # NetAnim is usually included with NS-3
   # If separate installation is needed:
   cd src/netanim
   qmake NetAnim.pro
   make
   ```

## Compilation and Execution

### Compile Individual Topologies

```bash
# Navigate to your NS-3 installation directory
cd /path/to/ns-3

# Compile each topology
./ns3 run scratch/bus-topo
./ns3 run scratch/star-topo
./ns3 run scratch/ring-topo
./ns3 run scratch/hybrid-topo
./ns3 run scratch/tree
```

### Alternative Compilation Method

```bash
# Copy files to NS-3 scratch directory
cp *.cc /path/to/ns-3/scratch/

# Build all
./ns3 build
```

## Visualization

After running the simulations, use NetAnim to visualize the network topologies:

1. **Launch NetAnim**:
   ```bash
   # From NS-3 directory
   ./netanim
   ```

2. **Load Animation Files**:
   - Open NetAnim
   - File → Open XML
   - Select the generated `.xml` files (e.g., `bus-topo.xml`)

3. **Playback Controls**:
   - Use play/pause buttons to control animation
   - Adjust speed slider for playback rate
   - Zoom in/out for better visualization

## File Structure

```
CN NS3/
├── README.md                 # This file
├── bus-topo.cc              # Bus topology implementation
├── bus-topo.xml             # Bus topology animation file
├── bus.png                  # Bus topology visualization
├── buscode.png              # Bus topology code visualization
├── star-topo.cc             # Star topology implementation
├── star-topo.xml            # Star topology animation file
├── star1.png                # Star topology visualization
├── starcode1.png            # Star topology code visualization
├── ring-topo.cc             # Ring topology implementation
├── ring-topo.xml            # Ring topology animation file
├── ring.png                 # Ring topology visualization
├── ring code.png            # Ring topology code visualization
├── hybrid-topo.cc           # Hybrid topology implementation
├── hybrid-topo.xml          # Hybrid topology animation file
├── hybrid.png               # Hybrid topology visualization
├── hybridcode.png           # Hybrid topology code visualization
├── tree.cc                  # Tree topology implementation
├── p2p-chain.xml            # Point-to-point chain definition
├── p2p1 pic.png             # P2P chain visualization
└── p2p1.png                 # P2P chain detailed visualization
```

## Network Parameters

### Common Configurations

| Topology | Data Rate | Delay | Nodes | IP Range |
|----------|-----------|-------|-------|----------|
| Bus | 100 Mbps | 6560 ns | 20 | 10.3.0.0/24 |
| Star | 5 Mbps | 2 ms | 16 | 10.1.0.0/24 |
| Ring | 5 Mbps | 2 ms | 16 | 10.4.0.0/24 |
| Hybrid | 10/100 Mbps | - | 25 | 10.5.0.0/24 |
| Tree | 5 Mbps | 2 ms | 16 | 10.1.0.0/24 |

## Customization

### Modifying Topology Parameters

Each `.cc` file can be customized by modifying:

1. **Number of Nodes**: Change the `Create()` parameter
2. **Data Rates**: Modify `SetDeviceAttribute("DataRate", ...)`
3. **Delays**: Adjust `SetChannelAttribute("Delay", ...)`
4. **IP Addressing**: Update `SetBase()` parameters
5. **Node Positioning**: Modify `SetConstantPosition()` coordinates

### Adding New Topologies

1. Create a new `.cc` file with your topology implementation
2. Include necessary NS-3 modules
3. Configure network parameters
4. Add animation interface for visualization
5. Compile and test

## Troubleshooting

### Common Issues

1. **Compilation Errors**:
   - Ensure NS-3 is properly installed and configured
   - Check that all required modules are enabled
   - Verify file permissions

2. **Animation Not Working**:
   - Ensure NetAnim is properly installed
   - Check that XML files are generated
   - Verify file paths in NetAnim

3. **Missing Modules**:
   ```bash
   # Enable specific modules
   ./ns3 configure --enable-modules=csma,point-to-point,internet
   ```

## Educational Use

This project is designed for:
- **Network Education**: Understanding different topology structures
- **Research**: Protocol testing and performance analysis
- **Visualization**: Network behavior demonstration
- **Comparison**: Performance analysis across topologies

## References

- [NS-3 Official Documentation](https://www.nsnam.org/documentation/)
- [NetAnim User Guide](https://www.nsnam.org/wiki/NetAnim)
- [Network Topology Concepts](https://en.wikipedia.org/wiki/Network_topology)

## License

This project is provided for educational and research purposes. Please refer to the NS-3 license for usage terms.

## Contributing

Feel free to contribute additional topologies, improvements, or bug fixes by:
1. Forking the project
2. Creating feature branches
3. Submitting pull requests

---

**Note**: This project focuses on topology visualization and basic network setup. For advanced simulations with traffic generation, routing protocols, or performance analysis, additional NS-3 modules and configurations may be required.
#   C N - N S 3 - T o p o l o g y - c r e a t i o n  
 