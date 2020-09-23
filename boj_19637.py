
cnt_grade, cnt_user = [int(i) for i in input().split(" ")]
grade = []


def binary(start, end, target):
    
    if(start >= end):
        return grade[end][0]

    mid = int((start+end)/2)
    if target <= grade[mid][1]:
        if mid >= 1 and grade[mid-1][1] < target:
            return grade[mid][0]
        elif mid == 0:
            return grade[mid][0]
        else:
            return binary(start, mid, target)
    else:
        # grade[mid][1] < target
        return binary(mid+1, end, target)



for i in range(cnt_grade):
    g, standard = input().split(" ")
    if grade == [] or grade[-1][1] != int(standard):
        grade.append((g, int(standard)))


for _ in range(cnt_user):
    strength = int(input())
    print(binary(0, len(grade)-1, strength))


    

    
