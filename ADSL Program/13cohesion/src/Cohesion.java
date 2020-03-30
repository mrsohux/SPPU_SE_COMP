// Java program to illustrate Cohesion and Coupling
// Classes Addition, Subtraction, Multiplication and Division are High Cohesive and Loosely Coupled
// Class(Addition, Subtraction, Multiplication, Division) and Cohesion are low Cohesive and tightly coupled
class Addition {
    public int add(int a, int b)
    {
        return a + b;
    }
} 
class Subtraction {
    public int sub(int a, int b)
    {
        return a - b;
    }
} 
class Multiply {
    public int mul(int a, int b)
    {
        return a * b;
    }
} 
class Division {
    public int div(int a, int b)
    {
        return a / b;
    }
} 
class Cohesion{
	public static void main(String args[]) {
		Addition m1 = new Addition();
		System.out.print("Addition of Numbers : ");
        System.out.println(m1.add(10, 20));
        Subtraction m2 = new Subtraction();
        System.out.print("Subtraction of Numbers : ");
        System.out.println(m2.sub(20, 10));
		Multiply m3 = new Multiply();
		System.out.print("Multiplication of Numbers : ");
        System.out.println(m3.mul(10, 20));
        Division m4 = new Division();
        System.out.print("Division of Numbers : ");
        System.out.println(m4.div(20, 10));
	}
}