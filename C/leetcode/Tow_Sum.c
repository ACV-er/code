/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include<stdio.h>
#include<stdlib.h>
int* twoSum(int* nums, int numsSize, int target);

int main(void) {
    int nums[4] = {2, 7, 11, 15} , target = 13;
    int * res = twoSum(nums, (int)sizeof(nums)/sizeof(int), target);
    printf("%d %d\n", res[0], res[1]);
}

int* twoSum(int* nums, int numsSize, int target) {
    sort( nums, numsSize );
    int i;
    for(i = 0; i < numsSize && nums[i] < target; i++) {
        int tmp = find( nums, target - nums[i] , numsSize );
        if( tmp != -1 && tmp != i) {
            int * res = (int*)malloc(2 * sizeof(int));
            res[0] = nums[i];
            res[1] = nums[tmp];
            return res;
        } 
    }

    return NULL;
}
