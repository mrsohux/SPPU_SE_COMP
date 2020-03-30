package P1;
//import P2.*;

class ArithmeticOperations{
	private
	int a, b;
	public
	int x, y;	//Global variables
	int add(){
		a = 10;
		b = 20;
		return a+b;
	}
	int sub(int a, int b){
		return a-b;
	}
	int div(){
		int x, y;	//Local variable
		x = 20;
		y = 10;
		return x/y;
	}
	int mod(){
		return x%y;	//Use of global variable
	}
	int square(int x){	//Formal parameter passed in function
		return x*x;
	}
}

class Calculator extends Multiplication{
	public static void main(String args[]){
		ArithmeticOperations obj = new ArithmeticOperations();
		System.out.print("\n Use of Private Addition :");
		System.out.println(obj.add());
		
		System.out.print("\n Use of Public Subtraction :");
		System.out.println(obj.sub(20, 10));
		
		Multiplication obj1 = new Multiplication();
		System.out.print("\n Use of Protected Multiplication :");
		System.out.println(obj1.mul(10, 20));
		
		System.out.print("\n Use of Scope Rule in Java :");
		System.out.print("\n Division using Local variable :");
		System.out.println(obj.div());
		System.out.print("\n Mod operation using Global variable :");
		obj.x=20;
		obj.y=3;
		System.out.println(obj.mod());
		System.out.print("\n Square of number by passing formal parameter :");
		System.out.println(obj.square(10));	//passed actual parameter in function call
	}
}