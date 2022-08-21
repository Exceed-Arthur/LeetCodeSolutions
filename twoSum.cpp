class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int maxIndexFirst = nums.size()-1;
        int minIndexSecond = 0;
        vector<int> finalVect;
        int maxIndex = 0;
        for (int scanIndexForMax=1; scanIndexForMax < nums.size(); scanIndexForMax++) { // Basic Max
            if (nums[scanIndexForMax] >= nums[maxIndex]) {
                maxIndex = scanIndexForMax;
            }
        }
        if (target > 0) {
            for (int index=0; index<nums.size(); index++) { // numbers that are too large aren't scanned
                if (nums[index] > target) {
                    maxIndexFirst = index-1; // No need to compute sum with term larger than sum
                }
                else {
                    maxIndexFirst = index; // Every number could be possible term, just scan all of them
                }
            }
        }
        for (int scanIndex=0; scanIndex < maxIndexFirst+1; scanIndex++) {
            if (nums[scanIndex]+nums[maxIndex] == target) {
                    finalVect.push_back(scanIndex); // Add scanned number index to solution pair
                    finalVect.push_back(maxIndex); // Add compared number's index to solution pair
                    return finalVect; // Exit and return early because solution is found
            }
            else if (nums[scanIndex]+nums[maxIndex] >= target) {
                minIndexSecond = (scanIndex+1 <= maxIndexFirst) ? scanIndex+1:scanIndex;
                for (int compIndex=minIndexSecond; compIndex<maxIndexFirst+1; compIndex++) {
                    if (nums[compIndex] + nums[scanIndex] == target) { // Solution found!
                        finalVect.push_back(scanIndex); // Add scanned number index to solution pair
                        finalVect.push_back(compIndex); // Add compared number's index to solution pair
                        return finalVect; // Exit and return early because solution is found
                    }
                }
            }
        }
        return finalVect; // Solution is GUARANTEED so this is just to prevent eroor for non-returning func
    }
};
