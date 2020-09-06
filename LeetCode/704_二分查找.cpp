/*************************************************************************
	> File Name: 704_二分查找.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年03月02日 星期一 17时20分03秒
 ************************************************************************/
int search(int* nums, int numsSize, int target){
    int l = 0, r = numsSize - 1, mid;
    while (l <= r) {
        mid = (l + r) >> 1;
        if (nums[mid] == target) return mid;
        if (nums[mid] > target) r = mid - 1;
        else l = mid + 1;
    }
    return -1;
}
