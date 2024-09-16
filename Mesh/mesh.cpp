#include "mesh.h"
#include <fstream>
#include <iostream>

// Constructor
Mesh::Mesh(int nx, int ny, double lx, double ly)
    : nx_(nx), ny_(ny), lx_(lx), ly_(ly) {
    dx_ = lx_ / (nx_ - 1);
    dy_ = ly_ / (ny_ - 1);
    initializeGrid();
}

// Initialize the grid nodes
void Mesh::initializeGrid() {
    nodesX_.resize(nx_, std::vector<double>(ny_));
    nodesY_.resize(nx_, std::vector<double>(ny_));

    for (int i = 0; i < nx_; ++i) {
        for (int j = 0; j < ny_; ++j) {
            nodesX_[i][j] = i * dx_;
            nodesY_[i][j] = j * dy_;
        }
    }
}

// Get node X coordinate
double Mesh::getNodeX(int i, int j) const {
    return nodesX_[i][j];
}

// Get node Y coordinate
double Mesh::getNodeY(int i, int j) const {
    return nodesY_[i][j];
}

// Export mesh to a file for visualization or debugging
void Mesh::exportMesh(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    for (int i = 0; i < nx_; ++i) {
        for (int j = 0; j < ny_; ++j) {
            file << nodesX_[i][j] << " " << nodesY_[i][j] << std::endl;
        }
        file << std::endl;  // Separate rows for easier reading
    }
    file.close();
}

