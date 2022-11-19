class human: #class의 이름 정의
    def __init__(self, height, age): #class가 처음 호출될 때 실행될 method, 멤버변수
        self.height = height #class 변수
        self.age = age
    def how_old(self): #class 메소드
        print(self.age,"살 입니다.")
    def how_tall(self):
        print(self.height,"cm 입니다.")
        
#변수 부르는 법
#Seunghyun.height
#메소드 호출
#Seunghyun.how_old()
#또는
#human.how_old(Seunghyun)

yubin = human(160, 17)
j = human(180, 17)

yubin.how_old()
human.how_old(yubin)

yubin.how_tall()
print(yubin.height)
#Seunghyun1 == Seunghyun2?
#False!

#똑같은 값을 통해 객체를 생성했지만 objec는 생성될 때 마다 새로운 메모리 공간에 값을 생성하기 때문에 엄밀히 말하면 다른 값이다
# Seunghyun = human(180, 31)
# Seunghyun.weight = 90