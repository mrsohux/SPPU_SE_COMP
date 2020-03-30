package P1;
import P2.*;
class Addition implements Calculate{
	public void getResult(int x, int y) {
		System.out.print("Addition of two numbers: ");
		System.out.println(x+y);
	}
}
class Substraction implements Calculate{
	public void getResult(int x, int y) {
		System.out.print("Subtraction of two numbers: ");
		System.out.println(x-y);
	}
}
class Multiplication implements Calculate{
	public void getResult(int x, int y) {
		System.out.print("Multiplication of two numbers: ");
		System.out.println(x*y);
	}
}
class Division implements Calculate{
	public void getResult(int x, int y) {
		System.out.print("Division of two numbers: ");
		System.out.println(x/y);
	}
}
class Calculator{
	public static void main(String args[]) {
	Addition obj1 = new Addition();
	obj1.getResult(10, 20);
	Substraction obj2 = new Substraction();
	obj2.getResult(20, 10);
	Multiplication obj3 = new Multiplication();
	obj3.getResult(10, 20);
	Division obj4 = new Division();
	obj4.getResult(20, 10);
	}
}