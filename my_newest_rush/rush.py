# arg = input()
# arg = arg.replace(" ", "")
# print(arg)
# characters = list(arg)
# swap_pattern = [0, 4, 1, 5, 2, 6, 3, 7, 8, 12, 9, 13, 10, 14, 11, 15]
# result_characters = [characters[i] for i in swap_pattern]
# result_str = "".join(result_characters)
# print(result_str)

# arg = "4122132332312214"

from itertools import permutations

# Your count_visible_numbers and reversed_count_visible_numbers functions

def count_visible_numbers(s):
    count = 1
    i = 0
    j = 0
    while i < len(s) - 1:
        if s[i].isdigit():
            if s[j] > s[i + 1]:
                j = j
            else:
                count += 1
                j = i + 1
        i += 1
    return count

def reversed_count_visible_numbers(s):
    count = 1
    i = len(s)
    j = len(s)
    while i > 0 + 1:
        if s[i - 1].isdigit():
            if s[j - 1] > s[i - 2]:
                j = j
            else:
                count += 1
                j = i - 1
        i -= 1
    return count

arg = "4122132332312214"
columns_arg = arg[:8]
rows_arg = arg[8:]
# print(columns_arg)
# print(rows_arg)

def group_possibilities_by_counts(permutations_1234, arg):
    possibilities_dict = {}

    # Iterate through each permutation and apply the functions
    for perm in permutations_1234:
        perm_str = ''.join(perm)
        count = count_visible_numbers(perm_str)
        reversed_count = reversed_count_visible_numbers(perm_str)
        for i in range(len(arg)//2):
             if count == int(arg[2*i]) and reversed_count == int(arg[2*i+1]):
                  possibilities = f"{perm_str} {count} {reversed_count}"
                  possibilities_dict.setdefault((count, reversed_count), []).append(possibilities)

    return possibilities_dict

def group_possibilities_by_counts2(permutations_1234_2, arg):
    possibilities_dict2 = {}

    # Iterate through each permutation and apply the functions
    for perm in permutations_1234_2:
        perm_str = ''.join(perm)
        count = count_visible_numbers(perm_str)
        reversed_count = reversed_count_visible_numbers(perm_str)
        for i in range(len(arg)//2):
             if count == int(arg[2*i]) and reversed_count == int(arg[2*i+1]):
                  possibilities = f"{perm_str} {count} {reversed_count}"
                  possibilities_dict2.setdefault((count, reversed_count), []).append(possibilities)

    return possibilities_dict2


# Generate all permutations of "1234"
permutations_1234 = permutations("1234")
permutations_1234_2 = permutations("1234")

# Group possibilities by counts for columns_arg
columns_possibilities = group_possibilities_by_counts(permutations_1234, columns_arg)

# Group possibilities by counts for rows_arg
rows_possibilities = group_possibilities_by_counts2(permutations_1234_2, rows_arg)

# Now you can access and print the grouped possibilities as needed
print("Columns:")
for key, possibilities in columns_possibilities.items():
    count, reversed_count = key
    print(f"Counts: {count}, Reversed Counts: {reversed_count}")
    for possibility in possibilities:
        print(possibility)

print("\nRows:")
for key, possibilities in rows_possibilities.items():
    count, reversed_count = key
    print(f"Counts: {count}, Reversed Counts: {reversed_count}")
    for possibility in possibilities:
        print(possibility)

