class DisjointSet{
public:
    vector<int> parent,size;

    DisjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1);
        for(int i= 0 ;i <= n ; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findP(int x){
        if (x == parent[x]) return x;
        return parent[x] = findP(parent[x]);
    }

    void unionBySize(int u, int v){
        int pu = findP(u);
        int pv = findP(v);

        if (pu == pv ) return;
        if (size[pu] > size[pv]){
            parent[pv] = pu;
            size[pu] += size[pv];
        }
        else {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        unordered_map<string,int> mpp;
        DisjointSet dis(n);
        // 1 comment
        for(int i = 0; i < n ;i++){
            for(int j = 1 ; j < accounts[i].size() ; j++){
                string mail = accounts[i][j];
                if (mpp.find(mail) == mpp.end()){
                    mpp[mail] = i;
                }
                else {
                    dis.unionBySize(i,mpp[mail]);
                }
            }
        }
        // 2 comment
        vector<string> mailp[n];
        for(auto it: mpp){
            string mail = it.first;
            int node = dis.findP(it.second);
            mailp[node].push_back(mail);
        }

        vector<vector<string>> ans;
        // 3 comment
        for(int i = 0 ;i < n ;i++){
            if (mailp[i].size() == 0) continue;
            string name = accounts[i][0];
            vector<string> temp;
            temp.push_back(name);
            sort(mailp[i].begin(),mailp[i].end());
            for(auto it: mailp[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }

        return ans;
    }
};