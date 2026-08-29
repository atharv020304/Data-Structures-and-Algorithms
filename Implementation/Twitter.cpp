class Twitter {
private:
    int timestamp;
    unordered_map<int, vector<pair<int, int>>> userTweets; // userId -> vector of {timestamp, tweetId}
    unordered_map<int, unordered_set<int>> followees;      // followerId -> set of followeeIds

public:
    Twitter() {
        timestamp = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        userTweets[userId].push_back({timestamp++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {

        followees[userId].insert(userId);
        
        priority_queue<pair<int, int>> pq;
        
        for (int followeeId : followees[userId]) {
            const auto& tweets = userTweets[followeeId];
            int n = tweets.size();
            for (int i = n - 1; i >= max(0, n - 10); --i) {
                pq.push(tweets[i]);
            }
        }
        
        vector<int> feed;
        while (!pq.empty() && feed.size() < 10) {
            feed.push_back(pq.top().second);
            pq.pop();
        }
        
        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        followees[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            followees[followerId].erase(followeeId);
        }
    }
};
