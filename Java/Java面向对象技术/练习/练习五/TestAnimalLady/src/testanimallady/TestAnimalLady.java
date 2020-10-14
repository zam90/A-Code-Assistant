/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package testanimallady;

/**
 *
 * @author Zam90
 */
import java.util.Scanner;
public class TestAnimalLady {
    public static void main(String[] args) {
        String pet,color,name;
        Scanner input = new Scanner(System.in);
        Lady lady = new Lady(input.next());
        pet=input.next();
        name=input.next();
        color=input.next();
        if("Cat".equals(pet)){
            Animal cat = new Cat(name,color);
            System.out.print(lady.myPetCry()+pet+"{name="+cat.getName()+";eyesColor="+color+"}};"+cat.cry());
        }
        else if("Dog".equals(pet)){
            Animal dog = new Dog(name,color);
            System.out.println(lady.myPetCry()+pet+"{name="+dog.getName()+";furColor="+color+"}};"+dog.cry());
        }
    }
    
}
abstract class Animal{
    private String name;

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }
    protected Animal(String name){
        this.name=name;
    }
    public abstract String cry();
} 

class Cat extends Animal{
    private String eyesColor;
    String color=eyesColor;
    public Cat(String name,String color){
        super(name);
        this.eyesColor=color;
    }
    public String getEyesColor() {
        return eyesColor;
    }

    public void setEyesColor(String eyesColor) {
        this.eyesColor = eyesColor;
    }
    @Override
    public String cry(){
        return "Her pet cry miaomiao!";
    }
}
class Dog extends Animal{
    private String furColor;
    public Dog(String name,String color){
        super(name);
        this.furColor=color;
    }
    public String getFurColor() {
        return furColor;
    }

    public void setFurColor(String furColor) {
        this.furColor = furColor;
    }
    @Override
    public String cry(){
        return "Her pet cry wangwang!";
    }
}
class Lady{
    private String name;
    Lady(String name){
        this.name=name;
    }
    String myPetCry(){     
        return "Lady{name="+this.name+",pet=";
        }
}
