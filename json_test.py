import json
with open('file/boxes.json','r',encoding='utf8')as fp:
    json_data = json.load(fp)
    l = len(json_data["boxes"])
    index = -1
    for i in range(l):
        name = json_data["boxes"][i]["name"]
        if name == "box_b":
            index = i
    if index != -1:
        print(json_data["boxes"][index]["rectangle"])
        