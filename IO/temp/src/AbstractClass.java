public abstract class AbstractClass {
    public void templateMethod() {
        primitiveOperation1();
        primitiveOperation2();
    }

    protected abstract void primitiveOperation1();
    protected abstract void primitiveOperation2();
}

class ConcreteClass1 extends AbstractClass {
    @Override
    protected void primitiveOperation1() {
        System.out.println("PrimitiveOperation1 by ConcreteClass1");
    }

    @Override
    protected void primitiveOperation2() {
        System.out.println("PrimitiveOperation2 by ConcreteClass1");
    }
}

class ConcreteClass2 extends AbstractClass {
    @Override
    protected void primitiveOperation1() {
        System.out.println("PrimitiveOperation1 by ConcreteClass2");
    }

    @Override
    protected void primitiveOperation2() {
        System.out.println("PrimitiveOperation2 by ConcreteClass2");
    }
}
