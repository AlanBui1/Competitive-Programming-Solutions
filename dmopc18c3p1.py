lis = ["A", "A#", "B", "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#"]

def semitones(n1, n2):
    return (lis.index(n2) - lis.index(n1) + 12) %12

triad = [input() for i in range(3)]
rootPos = [i for i in triad]

def cycle():
    return [rootPos[1], rootPos[2], rootPos[0]]

for i in range(3):
    if 3 <= semitones(rootPos[0], rootPos[1]) <= 4 and 3 <= semitones(rootPos[1], rootPos[2]) <= 4:
        break

    rootPos = cycle()

print(rootPos[0])

if semitones(rootPos[0], rootPos[1]) == 3:
    if semitones(rootPos[1], rootPos[2]) == 4:
        print("minor")
    else:
        print("diminished")
else:
    if semitones(rootPos[1], rootPos[2]) == 3:
        print("major")
    else:
        print("augmented")

if rootPos[0] == triad[0]:
    print("root position")
elif rootPos[1] == triad[0]:
    print("first inversion")
else:
    print("second inversion")