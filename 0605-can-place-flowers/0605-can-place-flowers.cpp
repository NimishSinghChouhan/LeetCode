class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0;
        for(int i = 0; i < flowerbed.size(); i++){
            if(flowerbed[i] == 0 && (i == 0 || flowerbed[i-1] == 0) && (i == flowerbed.size()-1 || flowerbed[i+1] ==0)) {
                //case 1: i == 0 && i == flowerbed.size()-1(length 1, empty flowerbed)
                //case 2: i == 0 && flowerbed[i+1] == 0(0th and 1st places are empty)
                //case 3: flowerbed[i-1] == 0 && i == flowerbed.size()-1(last and 2nd last places are empty)
                //case 4: flowerbed[i-1] == 0 && flowerbed[i+1] == 0(middle empty place)
                flowerbed[i] = 1;
                count ++;
            }
            if(count >= n) return true;
        }
        return count >= n;
    }
};