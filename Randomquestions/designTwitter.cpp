class Twitter {
    struct Tweet {
        int tweetId;
        int time;

        Tweet(int _tweetId, int t) :tweetId(_tweetId), time(t) {};
    };


    class comp {
        public:
            bool operator() (const Tweet&a, const Tweet&b) {
                return a.time > b.time;
            }
    };

    // global clock
    int time;

    // map-> userId to tweets
    unordered_map<int, vector<Tweet>> tweets;

    // map-> userId to unordered_set user id, user Id to his followings
    unordered_map<int,unordered_set<int>> following;
public:
    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back(Tweet(tweetId, time++));
    }
    
    // returning the tweetsid of 10 most recent tweets done by me or by my followers
    vector<int> getNewsFeed(int userId) {
        priority_queue<Tweet, vector<Tweet>, comp>minHeap;
        
        //  i need to add userID tweet
        if(tweets.find(userId) != tweets.end()) {
            for(auto tweet: tweets[userId]) {
                minHeap.push(tweet);

                if(minHeap.size() > 10) {
                    // remove the oldest tweet
                    minHeap.pop();
                }
            }
        }


        // I need to add tweets from my followings
        if(following.find(userId) != following.end()) {
            auto myFollowings = following[userId];
            
            for(auto followeeId: myFollowings) {
                for(auto tweet: tweets[followeeId]) {
                    minHeap.push(tweet);

                    if(minHeap.size() > 10) {
                        // remove the oldest tweet
                        minHeap.pop();
                    }
                }
            }
        }

        // now I will have top 10 most recent tweets from userId and from following

        vector<int>newsFeedTweet;

        while(!minHeap.empty()) {
            auto [tweetId, time] = minHeap.top();
            minHeap.pop();

            newsFeedTweet.push_back(tweetId);
        }
        reverse(newsFeedTweet.begin(), newsFeedTweet.end());
        return newsFeedTweet;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId == followeeId) {
            // I cannot follow my self
            return;
        }

        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followerId == followeeId) {
            // I cannot unfollow my self
            return;
        }
        
        if(following.find(followerId) != following.end()) {
            following[followerId].erase(followeeId);
        }

    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */