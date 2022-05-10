cmake_minimum_required(VERSION 3.21)
project(untitled)

set(CMAKE_CXX_STANDARD 14)

add_executable(untitled main.cpp Graph/Graph.cpp Graph/Graph.h Kruskal/Kruskal.cpp Prim/Prim.cpp Prim/Prim.h Backup/UnionFind.cpp Graph/Edge.h Backup/edgeList.h Graph/Vert.h Backup/QuickSort.h Kruskal/QuickSort.cpp Kruskal/UnionFind.cpp Kruskal/UnionFind.h Kruskal/QuickSort.h)
