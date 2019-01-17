# K-Means-Clustering-w-OpenGL-Visualization
K-Means Clustering Algorithm visualized using OpenGL with an extensible interface.

The interface starts with a command-line:
  "Enter the number of clusters:"
  "Random Data (y) or Data from Text File (n):"
    If 'y' (random data), 
      "Enter the number of points:"

Then a OpenGL window will appear and a 3D grid will appear.
  
  'A,' 'S', 'W', 'D' shifts the view of the 3D space
  'Q' will run the K-Means-Clustering algorithm
  'E' will run one iteration of the K-Means-Clustering algorithm
  'R' will reset the graph and regenerate the points
  'T' runs a benchmark to test execution times


To build with Visual Studio Community (2015 or 2017)
  Go to Project -> "Grapher Properties"
    Under the C/C++ tab, for "Additional Include Directories" add "../" and "../freeglut"
    Under the Linker tab, go to "Input", for "Additional Dependencies" add "../freeglut/freeglut.lib"
