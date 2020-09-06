/*************************************************************************
	> File Name: 217_存在重复元素.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年03月04日 星期三 20时00分43秒
 ************************************************************************/
int cmpfunc(int *a,int *b){//比较函数
    return *a > *b;
}
 
bool containsDuplicate(int* nums, int numsSize){
    // if(numsSize == 0 || numsSize == 1) return false;
    qsort(nums,numsSize,sizeof(int),cmpfunc);
    for(int i = 1;i < numsSize; i++){ 
        if(nums[i] == nums[i-1]){
            return true;
        }
    }
    return false;
}
