number_list = []
count_list = []

count_sum = 0
number_sum = 0
mod = 1000000007
n = int(input())


a_list = input()
a_list = a_list.split(" ")
for a in a_list:
    number_list.append(int(a))
    count_list.append(pow(10, len(a)))

    count_sum += pow(10, len(a))
    count_sum = count_sum % mod
    number_sum += int(a)
    number_sum = number_sum % mod

answer = 0

for idx in range(n):
    answer += (number_sum-number_list[idx])
    answer += (count_sum-count_list[idx]) * number_list[idx]
    answer = answer % mod

print(answer)