/*************************************************************************
	> File Name: 136.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月26日 星期三 14时58分51秒
 ************************************************************************/
/*int singleNumber(int* nums, int numsSize){
    int *arr = (int *)calloc(1000, sizeof(int));
   // memset(arr, 0, sizeof(int) * numsSize);
    for (int i = 0; i < numsSize; i++) {
         arr[i] = 0;
    }
    for (int i = 0; i < numsSize; i++) {
        arr[nums[i]] += 1;
    }
    int ans;
    for (int i = 0; i < numsSize; i++) {
        if (arr[nums[i]] == 1) {
            ans = nums[i];
            break;
        }
        
    }
    return ans;
}*/

int singleNumber(int* nums, int numsSize) {
    int res = 0;
    for(int i = 0; i < numsSize; i++)
        res = nums[i]^res;
    return res;
}
