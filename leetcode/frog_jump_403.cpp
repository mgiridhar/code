/*
A frog is crossing a river. The river is divided into x units and at each unit there may or may not exist a stone. The frog can jump on a stone, but it must not jump into the water.

Given a list of stones' positions (in units) in sorted ascending order, determine if the frog is able to cross the river by landing on the last stone. Initially, the frog is on the first stone and assume the first jump must be 1 unit.

If the frog's last jump was k units, then its next jump must be either k - 1, k, or k + 1 units. Note that the frog can only jump in the forward direction.

Note:

The number of stones is ≥ 2 and is < 1,100.
Each stone's position will be a non-negative integer < 231.
The first stone's position is always 0.
Example 1:

[0,1,3,5,6,8,12,17]

There are a total of 8 stones.
The first stone at the 0th unit, second stone at the 1st unit,
third stone at the 3rd unit, and so on...
The last stone at the 17th unit.

Return true. The frog can jump to the last stone by jumping 
1 unit to the 2nd stone, then 2 units to the 3rd stone, then 
2 units to the 4th stone, then 3 units to the 6th stone, 
4 units to the 7th stone, and 5 units to the 8th stone.
Example 2:

[0,1,2,3,4,8,9,11]

Return false. There is no way to jump to the last stone as 
the gap between the 5th and 6th stone is too large.
*/
class Solution {
public:
    /*** DFS - fastest solution - optimized with hash-set and handled two too far away stones ***/
    bool canCrossUtil(unordered_set<int> &steps, unsigned int pos, unsigned int k, unsigned int last) {
        if(pos == last) {
            return true;
        }
        if(steps.find(pos+k+1) != steps.end() && canCrossUtil(steps, pos+k+1, k+1, last))
            return true;
        if(steps.find(pos+k) != steps.end() && canCrossUtil(steps, pos+k, k, last))
            return true;
        if(k>1 && steps.find(pos+k-1) != steps.end() && canCrossUtil(steps, pos+k-1, k-1, last))
            return true;
        return false;
    }
    
    bool canCross(vector<int>& stones) {
        if(stones.size() < 2)
            return true;
        if(stones[1] != 1)
            return false;
        
        unordered_set<int> steps;
        steps.insert(stones[0]);
        steps.insert(stones[1]);
        for(int i=2; i<stones.size(); i++) {
            if((stones[i] - stones[i-1]) > i)  // stones that are far away
                return false;
            steps.insert(stones[i]);
        }
        return canCrossUtil(steps, 1, 1, stones[stones.size()-1]);
    }
    
    /*** Accepted - using hash map - values represent the steps that can be taken***/ /*
    bool canCross(vector<int>& stones) {
        if(stones.size() < 2) return true;
        if(stones[1] != 1) return false;
        
        unordered_map<int, unordered_set<int>> hash;
        for(int i=0; i<stones.size(); i++) {
            hash[stones[i]];
        }
        hash[0].insert(1);
        for(int i=0; i<stones.size(); i++) {
            unordered_set<int> steps = hash[stones[i]];
            for(unordered_set<int>::iterator step=steps.begin(); step != steps.end(); step++) {
                int reach = stones[i] + *step;
                if(reach == stones[stones.size()-1])
                    return true;
                if(hash.find(reach) != hash.end()) {
                    hash[reach].insert(*step + 1);
                    hash[reach].insert(*step);
                    if(*step > 1) hash[reach].insert(*step - 1);
                }
            }
        }
        return false;
    }
    */
    
    /*** BFS (using queue) - Memory Limit Exceeded***/
    /*bool canCross(vector<int>& stones) {
        if(stones.size() < 2) {
            return true;
        }
        
        struct element {
            int i, k;
            element(int i, int k):i(i), k(k) {}
        };
        queue<element *> q;
        if(stones[1] == 1) {
             q.push(new element(1, 1));
        }
        while(!q.empty()) {
            element *e = q.front();
            q.pop();
            if(e->i == stones.size()-1)
                return true;
            int j = e->i;
            while(j < stones.size() && stones[j] <= stones[e->i] + e->k + 1) {
                if(stones[j] == stones[e->i] + e->k)
                    q.push(new element(j, e->k));
                else if(e->k > 1 && stones[j] == stones[e->i] + e->k - 1)
                    q.push(new element(j, e->k-1));
                else if(stones[j] == stones[e->i] + e->k + 1)
                    q.push(new element(j, e->k+1));
                j++;
            }
        }
        return false;
    }*/
    
    /*** DFS Time limit exceeded ***/
    /*bool canCrossUtil(vector<int> &stones, unsigned int i, unsigned int k) {
        if(i >= stones.size())
            return false;
        if(i == stones.size()-1)
            return true;
        bool flag = false;
        int j = i + 1;
        while(!flag && j < stones.size() && stones[j] <= stones[i] + k + 1) {
            if(stones[j] == stones[i] + k + 1)
                flag = flag || canCrossUtil(stones, j, k+1);
            else if(stones[j] == stones[i] + k)
                flag = flag || canCrossUtil(stones, j, k);
            else if(k > 1 && stones[j] == stones[i] + k - 1)
                flag = flag || canCrossUtil(stones, j, k-1);
            j++;
        }
        return flag;
    }*/
};
