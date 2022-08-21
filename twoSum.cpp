class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int maxIndex = 0;
        cout << "target is " << target << endl;
        vector<int> finalVect;
        for (int index=0; index<nums.size(); index++) { // Ensure numbers that are too large aren't scanned
            if (nums[index] > target) {
                maxIndex = index-1;
            }
        }
        cout << "max index is " << maxIndex << endl;
        for (int firstPassIndex=0; firstPassIndex < maxIndex; firstPassIndex++) { // Entry Loop
            for (int compIndex = firstPassIndex; compIndex<maxIndex; compIndex++) { // Comparison Loop
                if (nums[firstPassIndex] + nums[compIndex] == target) {
                    finalVect.push_back(firstPassIndex); // Add first index to vector
                    finalVect.push_back(compIndex); // Add second index to vector
                    return finalVect; // Exit and return early because solution is found
                }
            }
        }
        return finalVect;
    }
};
