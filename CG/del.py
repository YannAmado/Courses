import numpy as np
#points = np.array([[1,9],[2,1],[2,4],[6,7],[7,2],[10,8],[14,6],[15,3],[18,11],[23,12],[25,5],[27,10]])
#points = np.array([,,[2,4],,[7,2],[10,8],[14,6],[18,11],,[25,5],[27,10]])
from scipy.spatial import Delaunay
import matplotlib.pyplot as plt
points = np.array([[-20,0],[50,0],[15,20],[1,9],[2,1],[2,4],[6,7],[7,2],[10,8],[14,6],[15,3],[18,11],[23,12],[25,5],[27,10]])
tri = Delaunay(points)
plt.triplot(points[:,0], points[:,1], tri.simplices)
plt.plot(points[:,0], points[:,1], 'o')
plt.show()
