/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    int findTime(map<Node*, Node*>& parentMap, Node* targetNode) {
        queue<Node*> q;
        q.push(targetNode);
        map<Node*, int> visited;
        visited[targetNode]=1;
        int timer=0;
        
        while(!q.empty()) {
            int size=q.size();
            int flag=0;
            
            for(int i=0; i<size; i++) {
                Node* node = q.front();
                q.pop();
                if(node->left && !visited[node->left]) {
                    flag=1;
                    visited[node->left]=1;
                    q.push(node->left);
                }
                if(node->right && !visited[node->right]) {
                    flag=1;
                    visited[node->right]=1;
                    q.push(node->right);
                }
                if(parentMap[node] && !visited[parentMap[node]]) {
                    flag=1;
                    visited[parentMap[node]]=1;
                    q.push(parentMap[node]);
                }
            }
            
            if(flag==1) timer++;
        }
        
        return timer;
    }
    
    Node* markParents(Node* root, map<Node*, Node*>& parentMap, int target) {
        queue<Node*> q;
        q.push(root);
        Node* res = nullptr;
        
        while(!q.empty()) {
            Node* curr = q.front();
            q.pop();
            
            if(curr->data == target) res = curr;
            
            if(curr->left) {
                parentMap[curr->left] = curr;
                q.push(curr->left);
            }
            if(curr->right) {
                parentMap[curr->right] = curr;
                q.push(curr->right);
            }
        }
        
        return res;
    }
    
    int minTime(Node* root, int target) {
        // code here
        map<Node*, Node*> parentMap;
        Node* targetNode = markParents(root, parentMap, target);
        return findTime(parentMap, targetNode);
    }
};