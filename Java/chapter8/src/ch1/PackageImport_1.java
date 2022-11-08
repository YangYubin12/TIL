package ch1;
public class PackageImport_1 {
	public static void main(String[] args) {
		// 객체 생성
		// A a = new A();
		ch1.A a = new ch1.A();
		// 멤버 활용
		System.out.println(a.m);
		System.out.println(a.n);
		a.print();
	}
}