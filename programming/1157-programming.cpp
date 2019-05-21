
deque<int> q;

for(int i=1;i<=n;i++) {
    while(!q.empty() && i - q.front()  > k) q.pop_front();
 }
