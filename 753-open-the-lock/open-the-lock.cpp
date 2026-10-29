// // //BFS 
// // class Solution {
// // public:
// //     int openLock(vector<string>& deadends, string target) {
// //         unordered_set<string> dead(deadends.begin(), deadends.end());

// //         if (dead.count("0000"))
// //             return -1;

// //         queue<string> q;
// //         unordered_set<string> visited;

// //         q.push("0000");
// //         visited.insert("0000");

// //         int turns = 0;

// //         while (!q.empty()) {
// //             int size = q.size();

// //             while (size--) {
// //                 string curr = q.front();
// //                 q.pop();

// //                 if (curr == target)
// //                     return turns;

// //                 for (int i = 0; i < 4; i++) {
// //                     for (int d : {-1, 1}) {
// //                         string next = curr;
// //                         next[i] = (curr[i] - '0' + d + 10) % 10 + '0';

// //                         if (!dead.count(next) && !visited.count(next)) {
// //                             visited.insert(next);
// //                             q.push(next);
// //                         }
// //                     }
// //                 }
// //             }

// //             turns++;
// //         }

// //         return -1;
// //     }
// // };


// // Bidirectional BFS


// class Solution {
// public:
//     int openLock(vector<string>& deadends, string target) {
//         unordered_set<string> dead(deadends.begin(), deadends.end());

//         if (dead.count("0000"))
//             return -1;

//         if (target == "0000")
//             return 0;

//         unordered_set<string> begin = {"0000"};
//         unordered_set<string> end = {target};
//         unordered_set<string> visited = {"0000", target};

//         int turns = 0;

//         while (!begin.empty() && !end.empty()) {
//             if (begin.size() > end.size())
//                 swap(begin, end);

//             unordered_set<string> nextLevel;

//             for (string curr : begin) {
//                 for (int i = 0; i < 4; i++) {
//                     for (int d : {-1, 1}) {
//                         string next = curr;
//                         next[i] = (curr[i] - '0' + d + 10) % 10 + '0';

//                         if (end.count(next))
//                             return turns + 1;

//                         if (!dead.count(next) &&
//                             !visited.count(next)) {
//                             visited.insert(next);
//                             nextLevel.insert(next);
//                         }
//                     }
//                 }
//             }

//             begin = nextLevel;
//             turns++;
//         }

//         return -1;
//     }
// };


//Dijkstra's Algorithm


class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead(deadends.begin(), deadends.end());

        if (dead.count("0000"))
            return -1;

        priority_queue<pair<int, string>,
                       vector<pair<int, string>>,
                       greater<pair<int, string>>> pq;

        unordered_map<string, int> dist;
        dist["0000"] = 0;
        pq.push({0, "0000"});

        while (!pq.empty()) {
            auto [cost, curr] = pq.top();
            pq.pop();

            if (dist[curr] != cost)
                continue;

            if (curr == target)
                return cost;

            for (int i = 0; i < 4; i++) {
                for (int d : {-1, 1}) {
                    string next = curr;
                    next[i] = (curr[i] - '0' + d + 10) % 10 + '0';

                    if (!dead.count(next) &&
                        (!dist.count(next) || cost + 1 < dist[next])) {
                        dist[next] = cost + 1;
                        pq.push({cost + 1, next});
                    }
                }
            }
        }

        return -1;
    }
};
