words = ('垃圾','陷阱','不要脸','内幕','辣鸡')
text = input()
for word in words:
    if word in text:
        text = text.replace(word,'*')
print(text)
