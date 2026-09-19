class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        // pehele mujhe circle se nearest x or y point find karne hoge
        int xi = 0;
        int yi = 0;

        if(x1 > xCenter) 
            xi = x1;
        
        else if(x2 < xCenter) 
            xi = x2;
        
        else 
            xi = xCenter; // iska matlab hmara rectangel circle k bich m aa rha h
        
        if(y1 > yCenter) 
            yi = y1;
        
        else if(y2 < yCenter) 
            yi = y2;
        
        else 
            yi = yCenter; // iska matlab hmara rectangel circle k bich m aa rha h
        
        // muje nearest point mil gye hai ab mujhe nikalna hai distance 
        // agar mera distance <= r aata h toh matlab overlap kar rahe h

        return sqrt((xi - xCenter) * (xi - xCenter) + (yi - yCenter) * (yi - yCenter)) <= radius;
    }
};


