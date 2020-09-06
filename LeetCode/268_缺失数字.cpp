/*************************************************************************
	> File Name: 268_缺失数字.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月26日 星期三 18时55分12秒
 ************************************************************************/

int missingNumber(int* nums, int numsSize){
    for (int i = 0; i < numsSize; i++) {
        while (nums[i] != i && nums[i] != numsSize) {
            int a = nums[i], b = nums[nums[i]];
            nums[a] = a, nums[i] = b;
        }
    }
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] - i) return i;
    }
    return numsSize;//为了预防有序状态例如[0,1],跟本不需要交换，说明缺少的就是numsSize
}

/*int missingNumber(int* nums, int numsSize){
    int a[numsSize + 1], ans;
    memset(a, 0, sizeof(a));
    for (int i = 0; i < numsSize; i++) {
        a[nums[i]] = 1;
    }
    for (int i = 0; i < numsSize + 1; i++) {
        if (a[i] == 0) {
            ans = i;;
            break;
        }
    }
    return ans;
}*/
/*求和
 * int missingNumber(int* nums, int numsSize){
    int ans = (numsSize + 1) * numsSize / 2, i;
    for(i = 0; i < numsSize; i++){
        ans -= nums[i];
    }
    return ans;
}
*/
