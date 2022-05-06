//
// Created by Omrik on 5/2/2022.
//

#ifndef UNTITLED_DISJOINTSETS_H
#define UNTITLED_DISJOINTSETS_H


class disjointSets {
    unordered_map<int, int> parent;
public:
    void makeSet(vector<int> const &wholeset){
        //perform makeset operation
        for (int i : wholeset) // create n disjoint sets
            (one for each item)
        parent[i] = i;
    }
    int Find(int l) { // Find the root of the set in which element l belongs
        if (parent[l] == l) // if l is root
            return l;
        return Find(parent[l]); // recurs for parent till we find root
    }
    void Union(int m, int n) { // perform Union of two subsets m and n
        int x = Find(m);
        int y = Find(n);
        parent[x] = y;
    }
};


#endif //UNTITLED_DISJOINTSETS_H
