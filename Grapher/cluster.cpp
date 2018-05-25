#include "point.h"
#include "centroid.h"
#include "cluster.h"

void cluster::setID(int k) { id = k; }
int cluster::getID() { return id; }
void cluster::addMember(point p) { members.push_back(p); }
point cluster::getMember(int k) { return members[k]; }
void cluster::setCentroid(centroid k) { c = k; }
centroid cluster::getCentroid() { return c; }