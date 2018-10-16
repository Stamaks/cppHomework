-=Все известные мне способы, как тип данных T появляется в классе MyClass=-

1) Создание объекта как поля класса, конструируемого по умолчанию (default constructable):

```template<typename T>
class MyClass {
    T _field;
};```

