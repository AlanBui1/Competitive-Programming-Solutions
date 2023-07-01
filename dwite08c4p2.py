def win(board, p):
    
    for i in range(3):
        if board[i] == p+p+p:
            return True
        if board[0][i] == p and board[1][i] == p and board[2][i] == p:
            return True
            
            
    if board[0][0] == p and board[1][1] == p and board[2][2] == p:
        return True
    
    if board[0][2] == p and board[1][1] == p and board[2][0] == p:
        return True
    
    return False


for q in range(5):
    l1 = input()
    l2 = input()
    l3 = input()
    
    board = [l1, l2, l3]
    
    if win(board, "X"):
        print("X")
        
    elif win(board, "O"):
        print("O")
        
    else:
        print(".")