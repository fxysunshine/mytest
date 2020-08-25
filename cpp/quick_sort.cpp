#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int get_standard(vector<int>& nums, int i, int j)
{
    int key = nums[i];
    while (i < j) {
        while (i < j && nums[j] >= key) {
            j--;
        }
        if (i < j)
            nums[i] = nums[j];
        while (i < j && nums[i] <= key) {
            i++;
        }
        if (i < j)
            nums[j] = nums[i];
    }
    nums[i] = key;
    return i;
}

void quick_sort(vector<int>& nums, int low, int high)
{
    if (low < high) {
        int standard = get_standard(nums, low, high);
        quick_sort(nums, low, standard - 1);
        quick_sort(nums, standard + 1, high);
    }
}

int main()
{
    vector<int> a;
    vector<int> b{1};
    vector<int> c{1, 0};
    vector<int> d{1,0,3};
    vector<int> e{1,1,0,3};
    quick_sort(a, 0, 0);
    quick_sort(b, 0, b.size() - 1);
    quick_sort(c, 0, c.size() - 1);
    quick_sort(d, 0, d.size() - 1);
    quick_sort(e, 0, d.size() - 1);

    for (const int& k : a) cout << k << " "; cout << endl;
    for (const int& k : b) cout << k << " "; cout << endl;
    for (const int& k : c) cout << k << " "; cout << endl;
    for (const int& k : d) cout << k << " "; cout << endl;
    for (const int& k : e) cout << k << " "; cout << endl;
    return 0;
}
