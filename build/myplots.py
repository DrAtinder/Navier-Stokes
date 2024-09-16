import numpy as np
import matplotlib.pyplot as plt

# Load the mesh data
data = np.loadtxt('simple_mesh.txt')

# Assume the mesh file contains nx * ny points, first half is x, second half is y
# Determine nx and ny from the data (you should know this from how the mesh was generated)
nx = 22 # number of points along x-direction
ny = 11  # number of points along y-direction

# Reshape the data into the grid
x = data[:, 0].reshape((nx, ny))  # Reshape x coordinates
y = data[:, 1].reshape((nx, ny))  # Reshape y coordinates

# Plot the mesh
plt.plot(x, y, 'k-', lw=0.5)  # Grid lines along X
plt.plot(x.T, y.T, 'k-', lw=0.5)  # Grid lines along Y
plt.scatter(x, y, color='red')  # Nodes
plt.xlabel('X')
plt.ylabel('Y')
plt.title('Rectangular Non-Uniform Mesh')
plt.show()

