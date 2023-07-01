N = int(input())

for i in range (0,N,1):
    rating = int(input())
    if rating <1000:
        print("Newbie")
    if rating >= 1000:
        if rating>= 1200:
            if rating>= 1500:
                if rating>= 1800:
                    if rating>= 2200:
                        if rating>= 3000:
                            if rating>= 4000:
                                print("Rainbow Master")
                            elif rating <4000:
                                print("Target")
                        elif rating < 3000:
                            print("Grandmaster")
                    elif rating<2200:
                        print("Master")
                elif rating<1800:
                    print("Candidate Master")
            elif rating<1500:
                print("Expert")
        elif rating<1200:
            print("Amateur")