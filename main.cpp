#include "mesh.h"
#include <iostream>

int main(int argc, char *argv[]){


// domain initialization
// Define the mesh dimensions
    int nx = 22;       // Number of nodes in X direction
    int ny = 11;       // Number of nodes in Y direction
    double lx = 2.0;   // Length of the domain in X direction
    double ly = 1.0;   // Length of the domain in Y direction
    
// Create the mesh
    Mesh mesh(nx, ny, lx, ly);
// Export the mesh to a file
    std::string filename = "simple_mesh.txt";
    mesh.exportMesh(filename);
    std::cout << "Mesh exported to " << filename << std::endl;
// variable initialization
// boundary condition 
// solving NS
return 0;
}
