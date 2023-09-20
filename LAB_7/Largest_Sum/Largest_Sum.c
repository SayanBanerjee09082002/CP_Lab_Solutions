#include <stdio.h>

int main()
{
    int nums[4];

    printf("Enter the integers:\n");

    for (int i = 0; i < 4; i++)
        scanf("%d", &nums[i]);

    for (int j = 0; j < 4; j++)
    {
        for (int i = 0; i < 2; i++)
        {
            if (nums[i] < nums[i + 1])
            {
                nums[i] = nums[i + 1] + nums[i];
                nums[i + 1] = nums[i] - nums[i + 1];
                nums[i] = nums[i] - nums[i + 1];
            }
        }
    }

    printf("Largest sum = %d + %d = %d", nums[0], nums[1], nums[0] + nums[1]);

    return 0;
}