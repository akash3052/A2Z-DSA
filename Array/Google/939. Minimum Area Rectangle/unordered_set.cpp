class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        int n = points.size();
        // using set so that we can search the coordinates in logn time
        unordered_set<long long> rectpoints;
        for(int i = 0; i < n; i++){
            rectpoints.insert(((long long)points[i][0] << 32) | points[i][1]);
        }

        int minArea = INT_MAX;
        // Running this i and j loop for finding every possible diagonals
        // once we will have diagonal cordinates, then easily we can find other 2 coordinates of rectangle 
        // as it will parallel to x and y axis
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                // Below condition is to check if they are the diagonal coordinates or not 
                // Because diagonal cordinates can't have either same x cordiante or y coordinate
                if(points[i][0] != points[j][0] && points[i][1] != points[j][1]){
                    int a = points[i][0], b = points[i][1], c = points[j][0], d = points[j][1];
                    // now we have found the diagonal coordiantes : (a,b) and (c,d)
                    // other 2 cordinates of rectangle will be (a,d) and (c,b) -> now, we will check if these are present in input or not
                    if(rectpoints.count(((long long) a << 32 )| d) && rectpoints.count(((long long) c << 32 )| b) ){
                        int area = abs(a-c) * abs(b-d);
                        minArea = min(minArea, area);
                    }
                }
            }
        }
        return minArea != INT_MAX ? minArea : 0;
    }
};

// The overall time complexity is O(N²) (due to the nested loop and set lookups).

// It's time complexity has been reduced to O(1)
