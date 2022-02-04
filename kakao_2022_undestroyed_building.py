def solution(board, skills):
    answer = 0
    r = len(board)
    c = len(board[0])
    diff = [[0] * c for _ in range(r)]
    ddiff = [[0] * c for _ in range(r)]
    
    for t, r1, c1, r2, c2, degree in skills:
        if t == 1 : degree *= -1
        diff[r2][c2] += degree
        if r1 >= 1: diff[r1-1][c2] -= degree
        if c1 >= 1: diff[r2][c1-1] -= degree
        if r1 >= 1 and c1 >= 1: diff[r1-1][c1-1] += degree
            
    for i in range(r-1, -1, -1):
        for j in range(c-1, -1, -1):
            board[i][j] += (diff[i][j] + ddiff[i][j])
            if j >= 1: ddiff[i][j-1] += diff[i][j] + ddiff[i][j]
            if i >= 1: diff[i-1][j] += diff[i][j]
            if board[i][j] > 0: answer += 1
            
    return answer