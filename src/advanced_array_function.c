#include "../include/advanced_array_function.h"

int max_subarray_sum(int* nums, int size) {
    int max = nums[0];
    for (int length = 0; length < size; length++) {
        for (int start = 0; start < size - length; start++) {
            int local_sum = 0;
            for (int i = 0; i <= length; i++) {
                local_sum += nums[start + i];
            }
            if (local_sum > max) {
                max = local_sum;
            }
        }
    }
    return max;
}

int length_of_lis(int* nums, int numsSize) {
    int max = 1;
    for (int length = 2; length <= numsSize; length++) {
        for (int j = 0; j < numsSize - length; j++) {
            int flag = 1;
            for (int i = 0; i < length - 1; i++) {
                printf("j = %d l = %d a = %d b = %d\n", j, length, nums[j + 1], nums[i + 1]);
                if (nums[j + i] >= nums[j + i + 1]) {
                    flag = 0;
                    break;
                }
            }
            if (flag == 1) {
                max = length;
                break;
            }
        }
    }
    return max;
}

int* merge(int* intervals, int intervalsSize, int* returnSize) {
    int n = intervalsSize / 2;
    int* result = malloc(intervalsSize * sizeof(int));
    int cnt = 0;

    // Сортировка пузырьком
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

