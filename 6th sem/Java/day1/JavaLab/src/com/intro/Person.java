package com.intro;

public class Person{
    String name;
    String age;
    public static void main(String args[]){
        Person p1 = new Person();
        p1.name = args[0];
        p1.age = args[1];

        
        System.out.println("Name: " + p1.name);
        System.out.println("Age: " + p1.age);


    }
}