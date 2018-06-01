#include <vector>
#include "point.h"
#include "centroid.h"
#include <vector>
#include "cluster.h"

#ifndef kmeansclustering_hpp
#define kmeansclustering_hpp

class kmeans {
	std::vector<cluster> clusters;
public:
	float euclideanDistance2D(point &, centroid &);
	int findNearestCentroid(point &, std::vector<centroid> &);
	void run(std::vector<point> &, std::vector<centroid> &, unsigned int);
};

/*
if(K > total_points)
return;

vector<int> prohibited_indexes;

// choose K distinct values for the centers of the clusters
for(int i = 0; i < K; i++)
{
while(true)
{
int index_point = rand() % total_points;

if(find(prohibited_indexes.begin(), prohibited_indexes.end(),
index_point) == prohibited_indexes.end())
{
prohibited_indexes.push_back(index_point);
points[index_point].setCluster(i);
Cluster cluster(i, points[index_point]);
clusters.push_back(cluster);
break;
}
}
}

int iter = 1;

while(true)
{
bool done = true;

// associates each point to the nearest center
for(int i = 0; i < total_points; i++)
{
int id_old_cluster = points[i].getCluster();
int id_nearest_center = getIDNearestCenter(points[i]);

if(id_old_cluster != id_nearest_center)
{
if(id_old_cluster != -1)
clusters[id_old_cluster].removePoint(points[i].getID());

points[i].setCluster(id_nearest_center);
clusters[id_nearest_center].addPoint(points[i]);
done = false;
}
}

// recalculating the center of each cluster
for(int i = 0; i < K; i++)
{
for(int j = 0; j < total_values; j++)
{
int total_points_cluster = clusters[i].getTotalPoints();
double sum = 0.0;

if(total_points_cluster > 0)
{
for(int p = 0; p < total_points_cluster; p++)
sum += clusters[i].getPoint(p).getValue(j);
clusters[i].setCentralValue(j, sum / total_points_cluster);
}
}
}

if(done == true || iter >= max_iterations)
{
cout << "Break in iteration " << iter << "\n\n";
break;
}

iter++;
}



*/

#endif