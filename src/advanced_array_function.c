#include "../include/advanced_array_function.h"
#include <stdlib.h>
int max_subarray_sum(int* nums, int size) {
    if (size <= 0) return 0;

    int max_sum = nums[0];
    int current_sum = nums[0];

    for (int i = 1; i < size; i++) {
        if (nums[i] > current_sum + nums[i]) {
            current_sum = nums[i];
        } else {
            current_sum = current_sum + nums[i];
        }

        if (current_sum > max_sum) {
            max_sum = current_sum;
        }
    }
    return max_sum;
}

int length_of_lis(int* nums, int numsSize) {
    if (numsSize == 0) return 0;

    int max_len = 1;
    int current_len = 1;

    for (int i = 1; i < numsSize; i++) {
        if (nums[i] > nums[i-1]) {
            current_len++;
            if (current_len > max_len) {
                max_len = current_len;
            }
        } else {
            current_len = 1;
        }
    }

    return max_len;
}

int* merge(int* intervals, int intervalsSize, int* returnSize) {
    int n = intervalsSize / 2;
    int* result = malloc(intervalsSize * sizeof(int));
    int cnt = 0;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (intervals[2*j] > intervals[2*(j+1)]) {
                int t0 = intervals[2*j];
                int t1 = intervals[2*j+1];
                intervals[2*j] = intervals[2*(j+1)];
                intervals[2*j+1] = intervals[2*(j+1)+1];
                intervals[2*(j+1)] = t0;
                intervals[2*(j+1)+1] = t1;
            }
            result[0] = intervals[0];
            result[1] = intervals[1];
            for (int i = 1; i < n; i++) {
                if (intervals[2*i] <= result[2*cnt+1]) {
                    if (intervals[2*i+1] > result[2*cnt+1]) {
                        result[2*cnt+1] = intervals[2*i+1];
                    }
                } else {
                    result[2*++cnt] = intervals[2*i];
                    result[2*cnt+1] = intervals[2*i+1];
                }
            }
        }
    }
    *returnSize = 2 * (cnt + 1);
    return result;
}

