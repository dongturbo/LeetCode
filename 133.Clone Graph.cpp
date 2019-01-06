//利用递归算法实现clone
//主要考虑节点克隆去重，利用map去重

UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node, map<int, UndirectedGraphNode *> &map) {
    if (node == nullptr) {
        return nullptr;
    }
    if(map.find(node->label)!=map.end()){
        return map[node->label];
    }
    UndirectedGraphNode *root = new UndirectedGraphNode(node->label);
    map[root->label] = root;
    vector<UndirectedGraphNode *> neighbors;
    for (UndirectedGraphNode *neighbor:node->neighbors) {
        UndirectedGraphNode *graphNode = cloneGraph(neighbor,map);
        neighbors.push_back(graphNode);
    }
    root->neighbors = neighbors;
    return root;
}

UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
    map<int, UndirectedGraphNode *> map;
    return cloneGraph(node,map);
}
