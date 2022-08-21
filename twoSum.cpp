class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int maxIndexFirst = 0;
        int minIndexSecond = 0;
        cout << "target is " << target << endl;
        vector<int> finalVect;
        for (int index=0; index<nums.size(); index++) { // numbers that are too large aren't scanned
            if (nums[index] > target) {
                maxIndexFirst = index-1; // No need to compute sum with term larger than sum
            }
            else {
                maxIndexFirst = index; // Every number could be possible term, just scan all of them
            }
        }
        for (int scanIndex=0; scanIndex < maxIndexFirst; scanIndex++) {
            cout << "Scan index #1 is for value: " << nums[scanIndex] << endl;
            minIndexSecond = (scanIndex+1 <= maxIndexFirst) ? scanIndex+1:scanIndex;
            cout << "Starting inner scan at index " << minIndexSecond << endl;
            for (int compIndex=minIndexSecond; compIndex<maxIndexFirst+1; compIndex++) {
                cout << "Comparison index holds value: " << nums[compIndex] << endl;
                if (nums[compIndex] + nums[scanIndex] == target) { // Solution found!
                    finalVect.push_back(scanIndex); // Add scanned number index to solution pair
                    finalVect.push_back(compIndex); // Add compared number's index to solution pair
                    return finalVect; // Exit and return early because solution is found
                }
            }
        }
        return finalVect; // Solution is GUARANTEED so this is just to prevent eroor for non-returning func
    }
};
