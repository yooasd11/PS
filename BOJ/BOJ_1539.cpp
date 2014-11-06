#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;

//Problem URL : http://www.acmicpc.net/problem/1539
//Problem type : tree
//Input : n - 250,000
//Time limit : 2000ms
//Key concept : calculating depth of all nodes without implementing the actual tree
//Solution : in every input, make them into sorted list. the depth of new node will be :
//           max(depth of left node, depth of right node) + 1
 
typedef long long ll;
int n;
vector<int> P;
map<int, int> dic;
ll ans;
 
int main(){
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d", &n);
    int num, depth;
    scanf("%d", &num);
    dic[num] = 1;
    for (int i = 1; i < n; ++i) {
        scanf("%d", &num);
        auto it = dic.lower_bound(num);
        if (it == dic.end()) depth = (--it)->second + 1;
        else if (it == dic.begin()) depth = it->second + 1;
        else{
            depth = it->second;
            depth = max(depth, (--it)->second) + 1;
        }
        ans += depth;
        dic[num] = depth;
    }
    printf("%lld\n", ans + 1);
    return 0;
}