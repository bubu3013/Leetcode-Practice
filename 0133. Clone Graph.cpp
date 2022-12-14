// solution 1: DFS

class Solution {
public:
    Node* cloneGraph(Node* node) {
        Node* clone = NULL;
        if (node == NULL){
            clone = NULL;
        }else if (node->neighbors.size() == 0){ // without any neighbors
            clone = new Node(node->val);
        }else {
            clone = helper(node);
        }
        return clone;
    }
private:
    unordered_map<Node*, Node*> m; // <old node, new node>
    Node* helper(Node* cur){
        Node * clone = new Node(cur->val);  // deep copy the node
        m[cur] = clone;                     // update the hashmap
        vector<Node *> clone_nei;
        for (auto& iter: cur->neighbors){   // iterate every neighbor in cur node
            if (m.find(iter) == m.end()){   // if the neighboring node has not been cloned
                Node* tmp = helper(iter);      // dfs() to create the node and push back to its neighbor
                clone_nei.push_back(tmp);
            }else{ // if the node has been cloned
                clone_nei.push_back(m[iter]);// add the corresponding new cloned node to its neighbor 
            }
        }
        clone->neighbors = clone_nei; 
        return clone;
    }
};

// Runtime 11 ms Beats 63.15% 
// Memory 9.2 MB Beats 9.90%

// 2022/12/03

class Solution {
public:
    Node* cloneGraph(Node* node) {
        return node == NULL ? node : helper(node);
    }
    Node* helper(Node* node){
        unordered_map<Node*, Node*> m;
        return dfs(node, m);
    }
    Node* dfs(Node* node, unordered_map<Node*, Node*>& m){
        if (m.find(node) == m.end()){
            m[node] = new Node(node->val);
            vector<Node*> nei;
            for (auto& iter: node->neighbors){
                nei.push_back(dfs(iter, m));
            }
            m[node]->neighbors = nei;
        }
        return m[node];
    }
};

// Runtime 7 ms Beats 87.88% 
// Memory 9 MB Beats 30.50%

// solution 2: BFS

class Solution {
public:
    Node* cloneGraph(Node* node) {
        return node == NULL ? node : helper(node);
    }
private:
    Node* helper(Node * node){
        queue<Node*> q; // for the BFS
        unordered_map<Node*, Node*> m; // <old node, new node>
        
        m[node] = new Node(node->val);
        q.push(node);
        while (q.empty() == false){ // when there are some nodes which needs to do
            Node* tmp = q.front(); q.pop();   // get the first node
            for (auto& iter: tmp->neighbors){ // iterate all the neighbors of tmp
                if (m.find(iter) == m.end()){ // if the neighbor does not have a copy
                    m[iter] = new Node(iter->val);
                    q.push(iter); // since the iter is a node w/p a copy, its neighbors are also a todo -> push into the q
                }
                m[tmp]->neighbors.push_back(m[iter]); // push back its neighbors
            }
            
        }
        return m[node];
    }
};
