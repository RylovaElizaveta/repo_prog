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
    if (intervalsSize == 0) {
        *returnSize = 0;
        return NULL;
    }

    int n = intervalsSize;
    int* res = malloc(2 * n * sizeof(int));
    int count = 0;

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
        }
    }

    res[0] = intervals[0];
    res[1] = intervals[1];
    count = 1;

    for (int i = 1; i < n; i++) {
        int current_start = intervals[2*i];
        int current_end = intervals[2*i+1];
        int last_end = res[2*count-1];

        if (current_start <= last_end) {
            if (current_end > last_end) {
                res[2*count-1] = current_end;
            }
        } else {
            res[2*count] = current_start;
            res[2*count+1] = current_end;
            count++;
        }
    }

    *returnSize = count;
    return res;
}

