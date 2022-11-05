package chapter6;

// 또 다른 나만의 외부 클래스(붕어빵 틀) 정의
class A {
	int m = 3;
	void print( ) {
		System.out.println("객체 생성 및 활용");
	}
}

public class CreateObjectAndUsage {

	public static void main(String[] args) {
		// 클래스로 객체(붕어빵) 생성
		A a = new A();
		
		// 클래스 필드 활(붕어빵 맛있게 먹기)
		a.m = 5;
		System.out.println(a.m);
		
		// 클래스 메서드 활용
		a.print();
	}

}