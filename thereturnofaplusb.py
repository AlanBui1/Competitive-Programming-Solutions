n = int(input())

translate = {"one": 1,
             "two": 2,
             "three":3,
             "four":4,
             "five":5,
             "six":6,
             "seven":7,
             "eight":8,
             "nine":9,
             "ten":10,
             
             "un": 1,
             "deux": 2,
             "trois":3,
             "quatre":4,
             "cinq":5,
             "six":6,
             "sept":7,
             "huit":8,
             "neuf":9,
             "dix":10,
             
             "一": 1,
             "二": 2,
             "三":3,
             "四":4,
             "五":5,
             "六":6,
             "七":7,
             "八":8,
             "九":9,
             "十":10
}


for i in range(n):
    line = [i for i in input().split()]
    
    try:
        num1 = int(line[0])

    except:
        num1 = translate[line[0]]

    try:
        num2 = int(line[1])

    except:
        num2 = translate[line[1]]

        
    print(num1+num2)