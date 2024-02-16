#include "iostream"
#include "vector"

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int len = nums.size();
        for (int i{0}; i < len - 1; i++)
        {
            for (int j{i + 1}; j < len; j++)
            {
                if (nums[i] + nums[j] == target)
                {
                    return {i, j};
                }
            }
        }
        return {};
    }
};

int main()
{
    // declaration
    vector<int> nums, result;
    int input, target;
    Solution s;

    // input
    cout << "Enter list numbers, -1 to stop: \n> ";
    while (cin >> input)
    {
        if (input == -1)
        {
            break;
        }
        cout << "> ";
        nums.push_back(input);
    }

    cout << "Enter the target: ";
    cin >> target;

    // processing
    result = s.twoSum(nums, target);

    // output
    if (!result.empty())
    {
        cout << "\nResult: [" << result[0] << ", " << result[1] << "]" << endl;
    }
    else
    {
        cout << "No two elements found that sum up to the target." << endl;
    }

    return 0;
}