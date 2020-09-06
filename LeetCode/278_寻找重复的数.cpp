/*************************************************************************
	> File Name: 278_寻找重复的数.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月27日 星期四 13时41分07秒
 ************************************************************************/
int findDuplicate(int* nums, int numsSize) {
    int p = nums[0], q = nums[0];
    do {
        p = nums[p];
        q = nums[nums[q]];
    } while (p != q);
    p = nums[0];
    while (p != q) {
        p = nums[p];
        q = nums[q];
    }
    return p;
}

/*12ms
int findDuplicate(int* nums, int numsSize){
    int a[100000], ans;
    memset (a, 0, sizeof(a));
    for (int i = 0; i < numsSize; i++) {
        a[nums[i]] += 1;
        if (a[nums[i]] > 1) {
            ans = nums[i];
            break;
        }
       
    }
    return ans;
}*/
