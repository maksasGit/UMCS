interface IceCream {
    void prepare();
    void flavor();
}
class VanillaIceCream implements IceCream {
    @Override
    public void prepare() {
        System.out.println("Vanilla ice cream prepared.");
    }

    @Override
    public void flavor() {
        System.out.println("Ice cream has a vanilla flavor.");
    }
}

class ChocolateIceCream implements IceCream {
    @Override
    public void prepare() {
        System.out.println("Chocolate ice cream prepared.");
    }

    @Override
    public void flavor() {
        System.out.println("Ice cream has a chocolate flavor.");
    }
}


interface IceCreamFactory {
    IceCream createIceCream();

}

class VanillaIceCreamFactory implements IceCreamFactory {
    @Override
    public IceCream createIceCream() {
        return new VanillaIceCream();
    }
}

class ChocolateIceCreamFactory implements IceCreamFactory {
    @Override
    public IceCream createIceCream() {
        return new ChocolateIceCream();
    }
}

public class Main {
    public static void main(String[] args) {
        IceCreamFactory vanillaFactory = new VanillaIceCreamFactory();
        IceCream vanillaIceCream = vanillaFactory.createIceCream();
        vanillaIceCream.prepare();
        vanillaIceCream.flavor();

        // Create Chocolate Ice Cream using ChocolateIceCreamFactory
        IceCreamFactory chocolateFactory = new ChocolateIceCreamFactory();
        IceCream chocolateIceCream = chocolateFactory.createIceCream();
        chocolateIceCream.prepare();
        chocolateIceCream.flavor();
    }
}
