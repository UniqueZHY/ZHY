/*************************************************************************
	> File Name: 287_寻找重复数字.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月26日 星期三 18时02分10秒
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

/*int findDuplicate(int* nums, int numsSize){
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
