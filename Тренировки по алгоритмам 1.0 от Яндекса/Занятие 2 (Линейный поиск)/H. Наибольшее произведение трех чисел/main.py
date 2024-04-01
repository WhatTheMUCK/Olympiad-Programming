def find_max_product(nums):
    max_positive1 = max_positive2 = max_positive3 = float('-inf')
    min_negative1 = min_negative2 = float('inf')

    for num in nums:
        if num > max_positive1:
            max_positive3, max_positive2, max_positive1 = max_positive2, max_positive1, num
        elif num > max_positive2:
            max_positive3, max_positive2 = max_positive2, num
        elif num > max_positive3:
            max_positive3 = num
        
        if num < min_negative1:
            min_negative2, min_negative1 = min_negative1, num
        elif num < min_negative2:
            min_negative2 = num

    if max_positive1 * max_positive2 * max_positive3 >= min_negative1 * min_negative2 * max_positive1:
        return max_positive1, max_positive2, max_positive3
    else:
        return min_negative1, min_negative2, max_positive1

# Пример использования
nums = [int(x) for x in input().split()]
result = find_max_product(nums)
print(result[0], result[1], result[2])
