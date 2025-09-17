class Food {
public:
    int ratings;
    string name;
    Food(int ratings, string name) {
        this->ratings = ratings;
        this->name = name;
    }

    bool operator < (const Food& other) const {
        if (ratings == other.ratings) {
            return name > other.name;
        }
        return ratings < other.ratings;
    }
};

class FoodRatings {
public:
    unordered_map<string,int> foodRatingsMp;
    unordered_map<string,string> foodCmap;
    unordered_map<string,priority_queue<Food>> CfoodMap;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i = 0; i < (int)foods.size(); i++) {
            foodRatingsMp[foods[i]] = ratings[i];
            foodCmap[foods[i]] = cuisines[i];
            CfoodMap[cuisines[i]].push(Food(ratings[i], foods[i]));
        }
    }
    
    void changeRating(string food, int newRating) {
        foodRatingsMp[food] = newRating;
        string cuisineName = foodCmap[food];
        CfoodMap[cuisineName].push(Food(newRating, food));
    }
    
    string highestRated(string cuisine) {
        auto highestRated = CfoodMap[cuisine].top();
        while (foodRatingsMp[highestRated.name] != highestRated.ratings) {
            CfoodMap[cuisine].pop();
            highestRated = CfoodMap[cuisine].top();
        }
        return highestRated.name;
    }
};
