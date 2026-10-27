class Twitter {
public:
// {timestamp, tweetId}
// follower -> set of users they follow
unordered_map<int,vector<pair<int,int>>> tweets;
unordered_map<int,unordered_set<int>> follows;
int time=0;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        follows[userId].insert(userId);
        // {timestamp, tweetId, userId}
        priority_queue<tuple<int,int,int>> pq;
        for(int user:follows[userId]){
            if(!tweets[user].empty()){
                int i=tweets[user].size()-1;
                pq.push({tweets[user][i].first,user,i});
            }
        }
            vector<int> feed;
            while(!pq.empty() && feed.size()<10){
                auto [timestamp,author,i]=pq.top();
                pq.pop();
                feed.push_back(tweets[author][i].second);
                if(i>0){
                    pq.push({
                    tweets[author][i-1].first,
                    author,i-1});
                }
            }
            return feed;
        }
    
    void follow(int followerId, int followeeId) {
        follows[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followerId!=followeeId){
            follows[followerId].erase(followeeId);
        }
    }
};
