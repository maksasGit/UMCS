public class Main{
    public static void main(String[] args) {
        AbstractClass concreteClass = new ConcreteClass1();
        concreteClass.templateMethod();

        concreteClass = new ConcreteClass2();
        concreteClass.templateMethod();
    }
}