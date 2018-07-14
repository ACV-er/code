/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
int* twoSum(int* nums, int numsSize, int target);

int main(void) {
    int nums[7] = {150,24,79,50,88,345,3} , target = 200;
    int * res = twoSum(nums, (int)( sizeof(nums)/sizeof(int) ), target);
    printf("%d %d\n", res[0], res[1]);
}

int* twoSum(int* nums, int numsSize, int target) {
    int i, j;
    for(i = 0; i < numsSize; i++) {
        for( j=numsSize-1; j>i; j--) {
            if( nums[i] + nums[j] == target ) {
                int * res = (int*)malloc( 2*sizeof(int) );
                res[0] = i;
                res[1] = j;
                return res;
            }
        }
    }
    return NULL;
}
//大佬算法
// int* twoSum(int* nums, int numsSize, int target) {
//     int i, min = nums[0];
//     int* indices = malloc(2*sizeof(int));
//     /* find the min of nums[numsSize] */
//     for (i = 1; i < numsSize; i++)
//         if (min > nums[i])
//             min = nums[i];
    
//     int hashSize = target - min - min + 1;
//     printf("%d\n", hashSize);
//     int hash[hashSize];
//     /* initialization of hash */
//     for (i = 0; i < hashSize; i++)
//         hash[i] = INT_MIN;
//     /* loop of nums
//        1 skip the elements larger than target-min
//        2 tag the corresponding element
//        3 when find the tag, return the two indices
//     */
//     for (i = 0; i < numsSize; i++){
//         if (nums[i] > target-min)
//             continue;
//         else if (hash[nums[i]-min] == INT_MIN)
//             hash[target-nums[i]-min] = i;
//         else{
//             indices[0] = hash[nums[i] - min];
//             indices[1] = i;
//             return indices;
//         }
//     }
//     return NULL;
// }
