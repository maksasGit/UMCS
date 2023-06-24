import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class StrategyPattern {
    public static void main(String[] args) {
        Context context = new Context();
        context.changeGenerator(new StringsGenerator());
        context.generate(10);
        context.changeGenerator(new OneStringGenerator());
        context.generate(23);
    }
}

interface IStringsGenerator {
    void generate(int size);
    void traverse();
}

class StringsGenerator implements IStringsGenerator {
    private List<String> strings = new ArrayList<>();

    public void generate(int size) {
        Random random = new Random();
        for (int i = 0; i < size; i++) {
            StringBuilder sb = new StringBuilder();
            int length = random.nextInt(10) + 1;
            for (int j = 0; j < length; j++) {
                char c = (char) (random.nextInt(26) + 'a');
                sb.append(c);
            }
            strings.add(sb.toString());
        }
    }

    public void traverse() {
        for (String str : strings) {
            System.out.print(str + " ");
        }
        System.out.println();
        strings.clear();
    }
}


class OneStringGenerator implements IStringsGenerator {
    private String string;

    public void generate(int size) {
        Random random = new Random();
            StringBuilder sb = new StringBuilder();
            for (int j = 0; j < size; j++) {
                char c = (char) (random.nextInt(26) + 'a');
                sb.append(c);
            }
            string = (sb.toString());
    }

    public void traverse() {
        System.out.println(string);
        System.out.println();
    }
}



class Context {
    private IStringsGenerator generator;

    public void generate(int size) {
        generator.generate(size);
        generator.traverse();
    }

    public void changeGenerator(IStringsGenerator generator) {
        this.generator = generator;
    }
}
