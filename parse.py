import json
subs = json.load(open('info.json'))
used = {}

for sub_id in subs:
    if subs[sub_id]['problem'] in used:
        continue

    if 'PY' in subs[sub_id]['language']:
        file_extension = '.py'
    elif 'CPP' in subs[sub_id]['language']:
        file_extension = '.cpp'
    elif 'JAVA' in subs[sub_id]['language']:
        file_extension = '.java'
    with open(str(sub_id)+file_extension, 'r') as inFile:
        outFile = open(subs[sub_id]['problem']+file_extension, 'w')
        try:
            for line in inFile:
                outFile.write(line)
        except:
            print(sub_id, subs[sub_id]['problem'])
        outFile.close()

    used[subs[sub_id]['problem']] = 1