class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left=1;
        int right=*max_element(piles.begin(),piles.end());
        while(left<=right){
            int mid=left+(right-left)/2;
            long long hrs=0;
            for(int p:piles) hrs+=ceil((double)p/mid);
            if(hrs<=h) right=mid-1;
            else left=mid+1;
        }
        return left;
    }
};

/*
Algorithm: Minimum Eating Speed (Binary Search)
1. Initialize left = 1 as the min possible eating speed and right = max(piles) as the max possible eating speed.
2. While left <= right, calc the middle speed:
   mid = left + (right - left) / 2.
3. Initialize hrs = 0 to count the total hours needed to finish all banana piles.
4. For each pile p, calc the hours req at speed mid using ceil(p / mid) and add them to hrs.
5. If hrs <= h, the speed is sufficient to finish within the given hours. Try a smaller speed by updating right = mid - 1.
6. Otherwise, the speed is too slow. Increase the min speed by updating left = mid + 1.
7. Return left, which represents the min eating speed that allows all piles to be finished within h hours.

TC: O(nlog M), where n is the num of piles and M is the max pile size.

SC: O(1), as the algo uses only a few extra variables.
*/
