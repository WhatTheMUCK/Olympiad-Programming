def find_max_product(nums):
    max_positive1 = max_positive2 = float('-inf')
    min_negative1 = min_negative2 = float('inf')

    for num in nums:
        if num > max_positive1:
            max_positive2, max_positive1 = max_positive1, num
        elif num > max_positive2:
            max_positive2 = num
        
        if num < min_negative1:
            min_negative2, min_negative1 = min_negative1, num
        elif num < min_negative2:
            min_negative2 = num

    if max_positive1 * max_positive2 >= min_negative1 * min_negative2:
        return max_positive2, max_positive1
    else:
        return min_negative1, min_negative2

# Пример использования
nums = [int(x) for x in input().split()]
result = find_max_product(nums)
print(result[0], result[1])
