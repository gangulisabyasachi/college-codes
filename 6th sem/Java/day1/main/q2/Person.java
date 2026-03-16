package com.intro;

public class Person{
    String name;
    int age;
    public static void main(String[] args){
        Person p1 = new Person();
        p1.name = "Sabyasachi";
        p1.age = 22;

        
        System.out.println("Name: " + p1.name);
        System.out.println("Age: " + p1.age);


    }
}