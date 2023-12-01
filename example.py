nums_dict:dict[str, str] = {"one":"1", "two":"2", "three":"3", "four":"4", "five":"5", "six":"6", "seven":"7", "eight":"8", "nine":"9"}
nums_set:set[str] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"}
from collections import deque

def get_num(line:str):
    tmp:str = ""
    result:list[str] = []
    i:int = 0
    flag:bool = False
    while i < len(line):
        if line[i].isdigit():
            result.append(line[i])
            break
        else:
            tmp += line[i]
            for num in nums_set:
                if num in tmp:
                    result.append(nums_dict[num])
                    flag = True
                    break
            if flag:
                break
                    
        i+=1
    
    flag = False
    j:int = len(line) - 1
    tmp:deque[str] = deque()
    while j > -1:
        if line[j].isdigit():
            result.append(line[j])
            break
        else:
            tmp.appendleft(line[j])
            for num in nums_set:
                if num in "".join(list(tmp)):
                    result.append(nums_dict[num])
                    flag = True
                    break
            if flag:
                break
        j-=1
    return int("".join(result))

result:int = 0
with open("input_data.txt", "r", encoding="utf-8") as file:
    for line in file:
        result += get_num(line)
print(result)
