#ifndef MESH_H
#define MESH_H

#include <vector>
#include <string>

class Mesh {
public:
    // Constructor
    Mesh(int nx, int ny, double lx, double ly);

    // Accessors
    double getNodeX(int i, int j) const;
    double getNodeY(int i, int j) const;
    int getNumNodesX() const { return nx_; }
    int getNumNodesY() const { return ny_; }
    
    // Visualization/Export
    void exportMesh(const std::string& filename) const;

private:
    int nx_, ny_;         // Number of nodes in X and Y directions
    double lx_, ly_;       // Physical dimensions of the grid
    double dx_, dy_;       // Grid spacing in X and Y directions

    std::vector<std::vector<double>> nodesX_;  // X coordinates of nodes
    std::vector<std::vector<double>> nodesY_;  // Y coordinates of nodes

    // Private methods
    void initializeGrid();
};

#endif // MESH_H

